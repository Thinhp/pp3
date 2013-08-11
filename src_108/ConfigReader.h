/*
 * Class:  ConfigReader
 * Author: Pasquale Barile
 * Modified by : Ashkan Izadi
 *
 * Reads an external configuration file and provides accessors for the
 * properties defined in the config file.
 *
 * Configuration variables are declared and defined with default values. Any
 * values set in the config file therefore override the default valus.
 */

#ifndef CONFIG_READER_H
#define CONFIG_READER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class ConfigReader
{
private:
  int firstLineLength, secondLineLength, shape, typeTriangle, population,
      initPop, generations, elitism, mutation, crossover;
  int colourMode, colourUpdater;
	int maxTree, minTree;
  bool fuzzyEdges;
  int satCannyLo, satCannyHi, valCannyLo, valCannyHi;
  int randomSeed;
  int canvasBG;
	int canvasBG_Red,canvasBG_Green,canvasBG_Blue;
	float fitnessTarget;
  std::string pathToTarget;
  std::string pathToMask;
  std::string pathToOutput;
  std::string targetFileName;
  std::string customDecalFileName;
  std::string pathToPalette;
  std::string palette;
  bool lineArtThickness;
  int lineArtColorMode;
  int drawMode;
  float fitnessRenderThreshold;
  bool prog2, prog3, prog4;
  bool usingAdaptiveCanvas;
  bool fastShroud;
  std::string version;
  int shroudPixelStrategy;
  int tournamentSize;

public:
  const static int DRAW_MODE_SHROUD = 0;
  const static int DRAW_MODE_DECALS = 1;
  const static int DRAW_MODE_SQUIGGLE = 2;
	
  ConfigReader();
  ~ConfigReader();

  void readPainterData();

  int getPopulation() { return population; }
  int getInitialPopulation() { return initPop; }
  int getGenerations() { return generations; }
  int getElitism() { return elitism; }
  int getMutation() { return mutation; }
  int getCrossover() { return crossover; }
  int getMaxTree() { return maxTree; }
  int getMinTree() { return minTree; }
  bool getFuzzyEdges() { return fuzzyEdges; }
  int getSatCannyLo() { return satCannyLo; }
  int getSatCannyHi() { return satCannyHi; }
  int getValCannyLo() { return valCannyLo; }
  int getValCannyHi() { return valCannyHi; }
  float getFitnessTarget() { return fitnessTarget; }
  int getRandomSeed() { return randomSeed; }
  // To specify the back ground Colour
	int getCanvasBG();
  int getCanvasBG_Red();
	int getCanvasBG_Green();
	int getCanvasBG_Blue();
	int getColourUpdater() { return colourUpdater; }
	int getColourMode() { return colourMode; }
	//to pass the variable of line length
	int getFirstLineLength() { return firstLineLength; }
	int getSecondLineLength() { return secondLineLength; }
	int getShape() { return shape; }//To check the shape of drawing
	int getTypeTriangle(){return typeTriangle;}

  std::string getCustomDecalFileName() { return customDecalFileName; }
  std::string getPathToTarget() { return pathToTarget; }
  std::string getPathToMask() { return pathToMask; }
  std::string getPathToOutput() { return pathToOutput; }
  std::string getPathToPalette() { return pathToPalette; }
  std::string getTargetFileName() { return targetFileName; }
  std::string getPalette() { return palette; }
  std::string getVersion() { return version; }
  bool getLineArtThickness() { return lineArtThickness; }
  int getDrawMode() { return drawMode; }
  double getFitnessRenderThreshold() { return fitnessRenderThreshold; }
  bool getProg2() { return prog2; }
  bool getProg3() { return prog3; }
  bool getProg4() { return prog4; }
  bool getUsingAdaptiveCanvas() { return usingAdaptiveCanvas; }
  bool getFastShroud() { return fastShroud; }
  int getLineArtColorMode() { return lineArtColorMode; }
  int getShroudPixelStrategy() { return shroudPixelStrategy; }
  int getTournamentSize() { return tournamentSize; }

  //===============================================================
  //to track my new fitness
  char* logFileName;
  bool flag;
  void setShroudLogName(char* newlogFileName){logFileName = newlogFileName;}
  char* getShroudLogName(){return logFileName;}
  void setErrorLogBad(bool newflag){flag=newflag;}
  string getErrorLogBad();
  int currentGenereation;
  //void setCurrentGeneration(int newG){currentGenereation=newG;}
  //int getCurrentGeneration(){return currentGeneration;}
  //===============================================================
};

#endif // CONFIG_READER_H
