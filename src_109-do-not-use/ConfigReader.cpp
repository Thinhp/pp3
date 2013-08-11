/*
 * Class:  ConfigReader
 * Author: Pasquale Barile
 * Modified by: Ashkan Izadi
 *
 * See header file for details.
 */

using namespace std;
#include "ConfigReader.h"

// Constructor
ConfigReader::ConfigReader():
  firstLineLength(0), secondLineLength(0), shape(0), typeTriangle(2),
  population(4), generations(100000), elitism(1), mutation(5), crossover(4),
  maxTree(8), minTree(5), fuzzyEdges(true), satCannyLo(10), satCannyHi(60),
  valCannyLo(10), valCannyHi(40), randomSeed(0), 
  canvasBG_R(255), canvasBG_G(255), canvasBG_B(255),
  fitnessTarget(0.05), targetFileName("rgb"), customDecalFileName("confetti")
{
}

// Destructor
ConfigReader::~ConfigReader()
{
}

// Load and read a program config file
void ConfigReader::readPainterData()
{
  ifstream in("Painter.txt");
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
 
    else if (key == "canvasBG_R")
      currentLine >> canvasBG_R;

    else if (key == "canvasBG_G")
      currentLine >> canvasBG_G;

    else if (key == "canvasBG_B")
      currentLine >> canvasBG_B;
	
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

int ConfigReader::getCanvasBG_R()
{
  return (canvasBG_R < 0 ? 0 : (canvasBG_R > 255 ? 255 : canvasBG_R));
}

int ConfigReader::getCanvasBG_G()
{
  return (canvasBG_G < 0 ? 0 : (canvasBG_G > 255 ? 255 : canvasBG_G));
}

int ConfigReader::getCanvasBG_B()
{
  return (canvasBG_B < 0 ? 0 : (canvasBG_B > 255 ? 255 : canvasBG_B));
}

