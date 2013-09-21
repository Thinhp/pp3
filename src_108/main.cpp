//
// Main entry point
// Author:  Perry Barile
// Modified by: Ashkan Izadi
// Modified by: Tieta Antaresti (15 January 2012)
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
#include "Ralph.h"          // Ralph Bell Curve Fitness Class
#include "Target.h"
#include "Canny.h"
#include "DecalCanvas.h"
#include "BezierPathCanvas.h"
#include "ShroudCanvas.h"
#include "Triangle.h"
#include "Ellipse.h"
#include "BestCanvas.h"
#include "MaskMaker.h"
#include "ConfigReader.h"
#include "Palette.h"
#include "DrawColorTriangle.h"
#include "DrawGrayTriangle.h"
#include "DrawGrayEllipse.h"

Target* target;
Canvas* canvas;
ConfigReader* reader;
Palette* palette;

// Global output path
string outputDir;
const char* configfile;

int main(int argc, char* argv[])
{  
  if (argv[2]==NULL) // e.g. argv[2] = configuration/albert.txt
  {
    configfile="Painter.txt";
    cout<<"test1: "<<configfile<<endl;
  }
  else
  {
    configfile=argv[2];
    cout<<"test2: "<<configfile<<endl;
  }

  // Init the config file reader
  reader = new ConfigReader();
  reader->readPainterData(); // Put every config info into ConfigReader reader object

  /* The argv[1] can't be reached, don't know why this condition is here*/ 
  if (strcmp(argv[1], "-v") == 0)
  {
    cout << "Version: " << reader->getVersion() << endl;
    cout << "Last compiled on " << __DATE__ << " at " << __TIME__ << endl;
    return EXIT_SUCCESS;
  }

// Output path
  outputDir = argv[1]; // e.g. albert_13-08-11-0825-25
  outputDir.append("/"); // e.g. albert_13-08-11-0825-25/
	  
  // File paths
  string targetFileName = reader->getTargetFileName(); // e.g. albert
	    
  string inputTarget = reader->getPathToTarget(); // The method just return a string from the jar file e.g. input/
  inputTarget.append(targetFileName); // input/albert
  inputTarget.append(".png"); // e.g. input/albert.png
	
  string inputMask = reader->getPathToMask(); // mask/
  inputMask.append(targetFileName); // mask/albert
  inputMask.append(".png"); // e.g. mask/albert.png
	    
  string outputTarget = outputDir;
  outputTarget.append("target.png");  // e.g. albert_13-08-11-0825-25/target.png
  string outputMask = outputDir;
  outputMask.append("mask.png");    // e.g. albert_13-08-11-0825-25/mask.png

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
  /*Make a mask
  *The MaskMaker takes an input image and applies a simple convolution mask to
  * it in order to generate a simple black and white image that identifies
  * "interesting" regions.*/
  if (intStat != 0)
  {
    MaskMaker *mm =
      new MaskMaker(inputTarget.c_str(), inputMask.c_str(), 10, 2);
    mm->makeDefaultMask();
    delete mm;
  }
	    
// The target and mask files have been validated/created, so copy them to
// the output folder.
  RGB* tmpImageData;
  unsigned tempW, tempH;
  read_image(inputTarget.c_str(), (color_t**)&tmpImageData, &tempW, &tempH);
  write_image(outputTarget.c_str(), (color_t*)tmpImageData, tempW, tempH);
  read_image(inputMask.c_str(), (color_t**)&tmpImageData, &tempW, &tempH);
  write_image(outputMask.c_str(), (color_t*)tmpImageData, tempW, tempH);
  delete tmpImageData;

  // Initialise the target
  Target* target = new Target(inputTarget.c_str(), 
    inputMask.c_str(),
    reader->getSatCannyLo(), 
    reader->getSatCannyHi(), 
    reader->getValCannyLo(),
    reader->getValCannyHi(), 
    reader->getFuzzyEdges());
	
  // Initialise the palette
  // Getting the number of pixels and unique color in the target image
  string paletteFile = reader->getPalette();

  if (paletteFile == "Target")
  {
    palette = new Palette(target);
  }
  else
  {
    string palettePath = reader->getPathToPalette(); // reader->getPathToPaletter = palette/
    string fullPalettePath = (palettePath.append(paletteFile)).append(".hex");
    palette = new Palette(fullPalettePath.c_str());
  }

  // Get the user-defined canvas background colours
  color_t bgGray = reader->getCanvasBG();
  color_t bgR = reader->getCanvasBG_Red();
  color_t bgG = reader->getCanvasBG_Green();
  color_t bgB = reader->getCanvasBG_Blue();

  // Initialise the best canvas
  BestCanvas* bestCanvasGray; // Canvas gray
  BestCanvas* bestCanvasColour; // Canvas colour
  bestCanvasGray = new BestCanvas(target, bgGray); // Create canvas gray instance
  bestCanvasColour = new BestCanvas(target, bgR, bgG, bgB); // Create canvas colour instance
	
  bool TRIANGLES_MODE = reader->getShape() == 1 ? true : false; // Check if Shape is equal to 1 (if so this bool is true)
  const bool COLOR_MODE = reader->getColourMode() == 1 ? true : false; // check if colourmode is 1 ( if so this bool is true)
  int DRAW_MODE = reader->getDrawMode(); //Drawing mode# 0: Pencil Sketch (The Shroud)# 1: Decals  (Stamps)# 2: Line Art (Squiggle)
  
  // Chosen Ellipse mode
  bool ELLIPSE_MODE = reader->getShape() == 2 ? true : false;

  if(ELLIPSE_MODE){
    TRIANGLES_MODE = false;
  }

  if (DRAW_MODE == 2) {
    TRIANGLES_MODE = false;
    ELLIPSE_MODE = false;
  }

  if (DRAW_MODE == 1){
    ELLIPSE_MODE = false;
    TRIANGLES_MODE = false;
  }

  //Print out to check
  if(ELLIPSE_MODE){
    cout << "************** ELLIPSE_MODE ****************\n";
  }
    

  //Start Triangle here

  if (TRIANGLES_MODE)
  {
    if (COLOR_MODE)
      canvas = new Triangle(target, bgR, bgG, bgB, bestCanvasColour, reader);
    else
      canvas = new Triangle(target, bgGray, bestCanvasGray, reader);
	}
  //Start Ellipse here
	else if(ELLIPSE_MODE){
    //Graycolor
    canvas = new Ellipse(target, bgGray, bestCanvasGray, reader);
  }
  else
	{
    switch (DRAW_MODE)
    {
      case ConfigReader::DRAW_MODE_SHROUD:
        if (COLOR_MODE)
          canvas = new ShroudCanvas(target, bgR, bgG, bgB, bestCanvasColour,
              reader);
        else
          canvas = new ShroudCanvas(target, bgGray, bestCanvasGray, reader);
        break;

      case ConfigReader::DRAW_MODE_DECALS:
        canvas = new DecalCanvas(target, bgGray, bestCanvasGray, reader);
        break;

      case ConfigReader::DRAW_MODE_SQUIGGLE:
        canvas = new BezierPathCanvas(target, bgGray, bestCanvasGray, reader);
        break;
    }
	}

	canvas->resetCanvas();
    
	GPConfig gpConfig;

	// Do the default initialisation of the configuration
	gpConfig.defaultInit();
  
	int tournamentSize = reader->getTournamentSize();
	if (tournamentSize > 0)
	{
		cout << "Using tournament selection (size of " << tournamentSize
             << ")" << endl;
		delete gpConfig.selectionOperator;
		gpConfig.selectionOperator = new TournamentSelection(tournamentSize);
	}
	else
	{
		cout << "Using roulette wheel selection" << endl;
	}
    
	// Set population size, log file name, config object
	const int popSize = reader->getPopulation(); // Triangle,Ellipse case is 4
	int initPop = reader->getInitialPopulation(); // Triangle,Ellipse case is 0

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

	if (initPop == 0) { initPop = popSize; } // If init = 0 -> now Init = 4
	Population pop(popSize, initPop, rlPath, &gpConfig); // In RMITGP folder Population

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
  if (TRIANGLES_MODE) // TRIANGLES_MODE = (Shape = 1)
  {
    if (COLOR_MODE)
    {
      gpConfig.funcSet.addNodeToSet(ReturnFunc::TYPENUM,
          DrawColorTriangle::generate);
    }
    else
    {
        gpConfig.funcSet.addNodeToSet(ReturnFunc::TYPENUM,
            DrawGrayTriangle::generate);
    }
  }
  else if (ELLIPSE_MODE){
    // Gray only
      gpConfig.funcSet.addNodeToSet(ReturnFunc::TYPENUM, DrawGrayEllipse::generate);
  }
  else
  {
    switch(DRAW_MODE)
    {
      case ConfigReader::DRAW_MODE_SHROUD:
        if (COLOR_MODE)
          gpConfig.funcSet.addNodeToSet(ReturnFunc::TYPENUM, Draw6::generate);
        else
          gpConfig.funcSet.addNodeToSet(ReturnFunc::TYPENUM, Draw4::generate);
        break;

      case ConfigReader::DRAW_MODE_DECALS:
        gpConfig.funcSet.addNodeToSet(ReturnFunc::TYPENUM, Draw2::generate);
        break;

      case ConfigReader::DRAW_MODE_SQUIGGLE:
        gpConfig.funcSet.addNodeToSet(ReturnFunc::TYPENUM, Draw6::generate);
        break;
    }
  }

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
	cout << "******************  New run  ******************\n";

	double bestFitness;
	try
	{
		string str1 = "";

		const int NUM_GENERATIONS = reader->getGenerations();
      
		if (pop.evolve(NUM_GENERATIONS))	
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
		                         outputResults(pop.getBest(),
                                 "best.pgm",
                                 "best.png",
                                 bestFitness); 
	gpConfig.cleanUpObjects();
   
	// Clean up globals
	delete target;
	delete reader;
	delete canvas;
	delete palette;
	
	return EXIT_SUCCESS;
}
