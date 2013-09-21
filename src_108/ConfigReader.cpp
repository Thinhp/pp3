/*
 * Class:  ConfigReader
 * Author: Pasquale Barile
 * Modified by: Ashkan Izadi
 * Modified by: Tieta Antaresti 
 * See header file for details.
 */

using namespace std;
#include "ConfigReader.h"

// Constructor
ConfigReader::ConfigReader(): firstLineLength(0), secondLineLength(0), shape(0),
  typeTriangle(2), population(4), generations(100000), elitism(1), mutation(5),
  crossover(4), maxTree(8), minTree(5), fuzzyEdges(true), satCannyLo(10),
  satCannyHi(60), valCannyLo(10), valCannyHi(40), randomSeed(0), canvasBG(255),
  canvasBG_Red(255), canvasBG_Green(255), canvasBG_Blue(255),
  fitnessTarget(0.05), targetFileName("marsha"), customDecalFileName("confetti")
{
}

// Destructor
ConfigReader::~ConfigReader()
{
}

// Load and read a program config file
void ConfigReader::readPainterData()
{
  extern char* configfile;
  cout<<"CONFIGFILE IS: " <<configfile<<endl;
  ifstream in(configfile);
  if (!in)
    cout << "Could not open Painter.data, so using default values.\n";

  string line, key;

  while (getline(in,line))
  {
    std::istringstream currentLine(line, std::istringstream::in);
      
    if (line[0] == '#' || line.length() == 0)
      continue;
    else
      currentLine >> key;

    if (key == "targetFilename")
      currentLine >> targetFileName;

  		// For ellipse
  		else if (key == "ellipseHorizontal")
  			currentLine >> ellipseHorizontal;

  		else if (key == "ellipseVertical")
  			currentLine >> ellipseVertical;
  		
		else if (key == "colourMode")
		  currentLine >> colourMode;

		else if (key == "colourUpdater")
		  currentLine >> colourUpdater;

		else if (key == "drawMode")
		  currentLine >> drawMode;

		else if (key == "customDecal")
		  currentLine >> customDecalFileName; 

		else if (key == "minTreeSize")
		  currentLine >> minTree;

		else if (key == "maxTreeSize")
		  currentLine >> maxTree;
		
		else if (key == "fitnessTarget")
		  currentLine >> fitnessTarget;
		
		else if (key == "numGen")
		  currentLine >> generations;

		else if (key == "pop")
		  currentLine >> population;

		else if (key == "initPop")
		  currentLine >> initPop;
		
		else if (key == "elitism")
		  currentLine >> elitism;
		
		else if (key == "mutation")
		  currentLine >> mutation;
		
		else if (key == "crossover")
		  currentLine >> crossover;
		
		else if (key == "fuzzyEdges")
		  currentLine >> fuzzyEdges;
		
		else if (key == "satCannyLo")
		  currentLine >> satCannyLo;
		
		else if (key == "satCannyHi")
		  currentLine >> satCannyHi;
		
		else if (key == "valCannyLo")
		  currentLine >> valCannyLo;
		
		else if (key == "valCannyHi")
		  currentLine >> valCannyHi;

		else if (key == "randomSeed")
		  currentLine >> randomSeed;
		
		else if (key == "canvasBG")
			currentLine >> canvasBG;
		
		else if (key == "canvasBG_Red")
			currentLine >> canvasBG_Red;
		
		else if (key == "canvasBG_Green")
			currentLine >> canvasBG_Green;
		
		else if (key == "canvasBG_Blue")
			currentLine >> canvasBG_Blue;
	
		else if(key == "shape")
			currentLine >> shape;

		else if(key == "typeTriangle")
			currentLine >> typeTriangle;
		
		else if (key == "firstLineLength")
			currentLine >> firstLineLength;
        
		else if (key == "secondLineLength")
			currentLine >> secondLineLength;

		else if (key == "pathToTarget")
		  currentLine >> pathToTarget;
			
		else if (key == "pathToMask")
		  currentLine >> pathToMask;
		
		else if (key == "pathToOutput")
		  currentLine >> pathToOutput;

		else if (key == "pathToPalette")
		  currentLine >> pathToPalette;

		else if (key == "lineArtThickness")
		  currentLine >> lineArtThickness;
		
		else if (key == "fitnessRenderThreshold")
		  currentLine >> fitnessRenderThreshold;

		else if (key == "Prog2")
		  currentLine >> prog2;

		else if (key == "Prog3")
		  currentLine >> prog3;

		else if (key == "Prog4")
		  currentLine >> prog4;

		else if (key == "usingAdaptiveCanvas")
		  currentLine >> usingAdaptiveCanvas;

		else if (key == "palette")
		  currentLine >> palette;

		else if (key == "fastShroud")
		  currentLine >> fastShroud;

		else if (key == "lineArtColorMode")
		  currentLine >> lineArtColorMode;

		else if (key == "version")
		  currentLine >> version;

		else if (key == "pixelReplacement")
		  currentLine >> shroudPixelStrategy;

		else if (key == "tournamentSize")
		  currentLine >> tournamentSize;
	}
}
int ConfigReader::getCanvasBG()
{
  return (canvasBG < 0 ? 0 : (canvasBG > 255 ? 255 : canvasBG));
}

int ConfigReader::getCanvasBG_Red()
{
  return (canvasBG_Red < 0 ? 0 : (canvasBG_Red > 255 ? 255 : canvasBG_Red));
}

int ConfigReader::getCanvasBG_Green()
{
  return
    (canvasBG_Green < 0 ? 0 : (canvasBG_Green > 255 ? 255 : canvasBG_Green));
}

int ConfigReader::getCanvasBG_Blue()
{
  return (canvasBG_Blue < 0 ? 0 : (canvasBG_Blue > 255 ? 255 : canvasBG_Blue));
}

