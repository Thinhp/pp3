//
// Main entry point
// Author:  Perry Barile
// Modified by: Ashkan Izadi
// 
// Initialise:
//    - target image
//    - canvases
//    - fitness class
//
// Run the run and collate the resultant data
// 

using namespace std;

#include <cstring>

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <math.h>
#include <fstream>
#include <sstream>
#include <sys/stat.h>

// RMITGP
#include "Population.h"
#include "Fitness.h"
#include "TournamentSelection.h"
#include "GeneticProgram.h"
#include "NodeSet.h"
#include "ProgramGenerator.h"
#include "GPConfig.h"

// This implementation of RMITGP
#include "Prog2.h"
#include "Prog3.h"
#include "Prog4.h"
#include "Draw2.h"
#include "Draw4.h"
#include "Draw6.h"
#include "RandFloat.h"
#include "ReturnRoot.h"     // data TYPENUM 0
#include "ReturnFunc.h"     // data TYPENUM 1
#include "ReturnFloat.h"    // data TYPENUM 2
#include "ImageFitness.h"   // Fitness class
#include "Target.h"
#include "Canny.h"
#include "DecalCanvas.h"
#include "BezierPathCanvas.h"
#include "ShroudCanvas.h"
#include "PaletteShroudCanvas.h"
#include "TriangleCanvas.h"
#include "BestCanvas.h"
#include "MaskMaker.h"
#include "ConfigReader.h"
#include "Palette.h"
#include "DrawColorTriangle.h"
#include "DrawGrayTriangle.h"

Target* target;
Canvas* canvas;
ConfigReader* reader;
Palette* palette;

// Global output path
string outputDir;

int main(int argc, char* argv[])
{
  // Init the config file reader
  reader = new ConfigReader();
  reader->readPainterData();

  if (strcmp(argv[1], "-v") == 0)
  {
    cout << "Version: " << reader->getVersion() << endl;
    cout << "Last compiled on " << __DATE__ << " at " << __TIME__ << endl;
    return EXIT_SUCCESS;
  }

  // Output path
  outputDir = argv[1];
  outputDir.append("/");

  // File paths
  string targetFileName = reader->getTargetFileName();
    
  string inputTarget = reader->getPathToTarget();
  inputTarget.append(targetFileName);
  inputTarget.append(".png");
    
  string inputMask = reader->getPathToMask();
  inputMask.append(targetFileName);
  inputMask.append(".png");
    
  string outputTarget = outputDir;
  string outputMask = outputDir;
  outputTarget.append("target.png");
  outputMask.append("mask.png");

  // Check to see if the target and mask files exist
  // Attemp to get file stats. If we can, the files exist
  struct stat fileInfo;
  int intStat = stat(inputTarget.c_str(), &fileInfo);
    
  if (intStat != 0) // file doesn't exist
  {
    // Exit gracefully
    cout << "Target image: \"" << inputTarget;
    cout << "\" doesn't exist!" << endl;
    delete reader;
    exit(1);
  }
    
  intStat = stat(inputMask.c_str(), &fileInfo);
  if (intStat != 0) // Make a mask
  {
    MaskMaker *mm =
      new MaskMaker(inputTarget.c_str(), inputMask.c_str(), 10, 2);
    mm->makeDefaultMask();
    delete mm;
  }
    
  // The target and mask files have been validated/created, so copy them to
  // the output folder
  RGB* tmpImageData;
  unsigned tempW, tempH;
  read_image(inputTarget.c_str(), (color_t**)&tmpImageData, &tempW, &tempH);
  write_image(outputTarget.c_str(), (color_t*)tmpImageData, tempW, tempH);
  read_image(inputMask.c_str(), (color_t**)&tmpImageData, &tempW, &tempH);
  write_image(outputMask.c_str(), (color_t*)tmpImageData, tempW, tempH);
  delete tmpImageData;
    
  // Initialise the target
  Target* target = new Target(inputTarget.c_str(), inputMask.c_str(),
      reader->getSatCannyLo(), reader->getSatCannyHi(), reader->getValCannyLo(),
      reader->getValCannyHi(), reader->getFuzzyEdges());
	
  // Determine the render mode
  int renderMode = reader->getDrawMode();
  
  // Initialise the palette
#pragma mark TODO: New palette functionality
  string paletteFile = reader->getPalette();

  if (paletteFile == "Target")
  {
    palette = new Palette(target);
  }
  else
  {
    string palettePath = reader->getPathToPalette();
    string fullPalettePath =
      (palettePath.append(paletteFile)).append(".hex");
      palette = new Palette(fullPalettePath.c_str());
  }

  // Get the user-defined canvas background
  color_t bgR = reader->getCanvasBG_R();
  color_t bgG = reader->getCanvasBG_G();
  color_t bgB = reader->getCanvasBG_B();

  // Initialise the best canvas
  BestCanvas* bestCanvas = new BestCanvas(target, bgR, bgG, bgB);

  // Determine the canvas type
  if (renderMode == ConfigReader::DRAW_MODE_SHROUD)
    canvas = new ShroudCanvas(target, bgR, bgG, bgB, bestCanvas, reader);
  else if (renderMode == ConfigReader::DRAW_MODE_DECALS)
    canvas = new DecalCanvas(target, bgR, bgG, bgB, bestCanvas, reader);
  else if (renderMode == ConfigReader::DRAW_MODE_SQUIGGLE)
    canvas = new BezierPathCanvas(target, bgR, bgG, bgB, bestCanvas, reader);
  else if (renderMode == ConfigReader::DRAW_MODE_TRIANGLES)
    canvas = new TriangleCanvas(target, bgR, bgG, bgB, bestCanvas, reader);
  else if (renderMode == ConfigReader::DRAW_MODE_PALETTE_SHROUD)
    canvas = new PaletteShroudCanvas(target, bgR, bgG, bgB, bestCanvas, reader);
  else
  {
    cout << "Error -- invalid draw mode\n";
    return EXIT_FAILURE;
  }

  canvas->resetCanvas();
    
  GPConfig gpConfig;

  // Do the default initialisation of the configuration
  gpConfig.defaultInit();

  int tournamentSize = reader->getTournamentSize();
  if (tournamentSize > 0)
  {
    delete gpConfig.selectionOperator;
    gpConfig.selectionOperator = new TournamentSelection(tournamentSize);
  }
    
  // Set population size, log file name, config object
  const int popSize = reader->getPopulation();
  int initPop = reader->getInitialPopulation();

  //LOG FILE=============================================================
  // This was put in by Ashkan. I don't know what it does (perry)
  string logShroudPath = outputDir;
  //logShroudPath.append("shroud-log.txt");
  //cout << "Log Path for Shroud " << logShroudPath << endl;
  char slPath[80];
  strcpy(slPath, logShroudPath.c_str());
  //cout << "path after Strcpy :" << slPath << endl;
  reader->setShroudLogName(slPath);
  //=====================================================================

  // Initialise population
  string runLogPath = outputDir;
  runLogPath.append("run-log.txt");
  char rlPath[80];
  strcpy(rlPath, runLogPath.c_str());

  if (initPop == 0) { initPop = popSize; }
  Population pop(popSize, initPop, rlPath, &gpConfig);

  // Set reproduction numbers. These numbers must add up to the population
  // size.
  pop.setNumForMutation(reader->getMutation());
  pop.setNumForCrossover(reader->getCrossover());
  pop.setNumForElitism(reader->getElitism());
    
  // Set the return type for the programs
  pop.setReturnType(ReturnFunc::TYPENUM);
    
  // Set the minimum and maximum tree depth
  gpConfig.maxDepth = reader->getMaxTree();
  gpConfig.minDepth = reader->getMinTree();
  pop.setDepthLimit(gpConfig.maxDepth);
  pop.setMinDepth(gpConfig.minDepth);
    
  pop.setLogFrequency(1000000);
  //    vc seems to be a problem with 0;
  //    pop.setLogFrequency(0);
    
#ifdef UNIX
  pop.compressGenerationFiles(true);
#endif // UNIX
    
  // Add the terminals
  gpConfig.termSet.addNodeToSet(ReturnFloat::TYPENUM, RandFloat::generate);

  // Add the functions
  if (renderMode == ConfigReader::DRAW_MODE_SHROUD)
    gpConfig.funcSet.addNodeToSet(ReturnFunc::TYPENUM, Draw6::generate);
  else if (renderMode == ConfigReader::DRAW_MODE_DECALS)
    gpConfig.funcSet.addNodeToSet(ReturnFunc::TYPENUM, Draw2::generate);
  else if (renderMode == ConfigReader::DRAW_MODE_SQUIGGLE)
    gpConfig.funcSet.addNodeToSet(ReturnFunc::TYPENUM, Draw6::generate);
  else if (renderMode == ConfigReader::DRAW_MODE_TRIANGLES)
    gpConfig.funcSet.addNodeToSet(ReturnFunc::TYPENUM,
        DrawColorTriangle::generate);
  else if (renderMode == ConfigReader::DRAW_MODE_PALETTE_SHROUD)
    gpConfig.funcSet.addNodeToSet(ReturnFunc::TYPENUM, Draw4::generate);

  if (reader->getProg2())
    gpConfig.funcSet.addNodeToSet(ReturnFunc::TYPENUM, Prog2::generate);

  if (reader->getProg3())
    gpConfig.funcSet.addNodeToSet(ReturnFunc::TYPENUM, Prog3::generate);
    
  if (reader->getProg4())
    gpConfig.funcSet.addNodeToSet(ReturnFunc::TYPENUM, Prog4::generate);

  // Set the random seed
  gpConfig.randomNumGenerator = new Random(reader->getRandomSeed());

  // Create the program generator
  gpConfig.programGenerator = new ProgramGenerator(&gpConfig);

  // Set the fitness class to be used
  gpConfig.fitnessObject = new ImageFitness(&gpConfig);

  pop.generateInitialPopulation();

  system("clear");
  cout << "******************  New run  ******************" << endl;

  double bestFitness;
  try
  {
    string str1 = "";

    const int numGenerations = reader->getGenerations();
      
    if (pop.evolve(numGenerations))
      cout << "\nFound solution\n";
    else
      cout << "\nDid not find solution\n";

    bestFitness = pop.getBest()->getFitness();
      
    cout << "Best program Fitness " << bestFitness << str1 << endl;
  }
  catch(string s)
  {
    cerr << s << endl;
    cerr << "Exiting (an exception has occured)" << endl;
    delete target;
    delete reader;
    delete canvas;
    delete palette;
    exit(1);
  }

  // The following code executes the best program on the training data and
  // outputs the results of the execution to the file results.txt
  cout << endl
    << "***************************************************" << endl
    << "*                                                 *" << endl
    << "*                 End of run                      *" << endl
    << "*                                                 *" << endl
    << "***************************************************" << endl;

  cout << "Writing results to run-log.txt" << endl;

  dynamic_cast<ImageFitness *>(gpConfig.fitnessObject)->
    outputResults(pop.getBest(), "best.pgm", "best.png", bestFitness); 
  gpConfig.cleanUpObjects();
   
  // Clean up globals
  delete target;
  delete reader;
  delete canvas;
  delete palette;

  return EXIT_SUCCESS;
}
