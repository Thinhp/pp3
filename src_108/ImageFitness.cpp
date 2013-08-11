/*
 * Definition file
 * Class:        ImageFitness
 * Date created: 2007-09-17
 * Written by:   Pasquale Barile
 *
 * See header file for details
 */

using namespace std;
#include "ImageFitness.h"

#include <cstring>
#include <iomanip>

extern ConfigReader* reader;
extern Target* target;
extern Canvas* canvas;
extern Ralph* ralph;

ImageFitness::ImageFitness(GPConfig *conf) : Fitness(conf),
  fitnessTarget(reader->getFitnessTarget()), hsvFitnessH(0.0f),
  hsvFitnessS(0.0f), hsvFitnessV(0.0f), lastFitnessMilestone(360.0f),
  generationCounter(0)
{
  initFitness();
}

/* 
 * Initialise the fitness object
 */
void ImageFitness::initFitness()
{
  fitnessTarget = reader->getFitnessTarget(); 
  hsvFitnessH = 0.0f;
  hsvFitnessS = 0.0f;
  hsvFitnessV = 0.0f;
  lastFitnessMilestone = 360.0f;
  fitnessRenderThreshold = reader->getFitnessRenderThreshold();
  generationCounter = 0;
}

void ImageFitness::assignFitness(GeneticProgram* pop[], int popSize)
{
  ReturnFunc rf;
  population = popSize;
    
  // Compute fitness for each program
  for(int i = 0; i < popSize; i++)
  { 
    canvas->resetCanvas();

    pop[i]->setFitness(worst());
		pop[i]->evaluate(&rf); // This is where everything gets drawn
    pop[i]->setFitness(computeFitness());
  }
    
  int bestIndex = 0;
  double bestFitness = pop[0]->getFitness();
  char pgmFile[20], pngFile[20];
    
  for (int i = 1; i < popSize; i++)
  {
    double fitness = pop[i]->getFitness();
        
    if (fitness < bestFitness)
    {
      bestFitness = fitness;
      bestIndex = i;
    }
  }
    
  if (lastFitnessMilestone - bestFitness >= fitnessRenderThreshold)
  {
    lastFitnessMilestone = bestFitness;
    sprintf(pgmFile, "gen.%06d.pgm", generationCounter);
    sprintf(pngFile, "gen.%06d.png", generationCounter);
    outputResults(pop[bestIndex], pgmFile, pngFile, bestFitness);
  }

  generationCounter++;
}

float ImageFitness::computeFitness()
{
  canvas->computeFitness();
  return canvas->getFitness();
}

bool ImageFitness::solutionFound(GeneticProgram* pop[], int popSize)
{
  for (int i = 0; i < popSize; i++)
  {
    if (pop[i]->getFitness() <= fitnessTarget)
      return true;
  }
  return false;
}

bool ImageFitness::isBetter(GeneticProgram* gp1, GeneticProgram* gp2)
{
  return (gp1->getFitness() < gp2->getFitness());
}

bool ImageFitness::isWorse(GeneticProgram* gp1, GeneticProgram* gp2)
{
  return (gp1->getFitness() > gp2->getFitness());
}

bool ImageFitness::isEqual(GeneticProgram* gp1, GeneticProgram* gp2)
{
  return (gp1->getFitness() == gp2->getFitness());
}

double ImageFitness::best()
{
  return 0.0;
}

double ImageFitness::worst()
{
  return FLT_MAX;
}

void ImageFitness::outputResults(GeneticProgram* program, char* pgmFile,
                                 char* pngFile, double bestFitness)
{
	extern string outputDir;

  // Output PGM file
  /**/
	char pgmPath[80];

	strcpy(pgmPath, outputDir.c_str());
	strcat(pgmPath, "pgm/");
	strcat(pgmPath, pgmFile);

  ofstream pgmOut;
  pgmOut.open(pgmPath);
    
  if (pgmOut.bad())
  {
    cerr << "ImageFitness::outputResults -- Could not open output PGM file\n";
    return;
  }
    
  string progString;
  program->print(progString);

  const int w = canvas->getWidth();
  const int h = canvas->getHeight();
    
  pgmOut << "P2" << endl 
         << "Width " << w << endl
         << "Height " << h << endl
         << "255" << endl
         << "# program: " << progString << endl;
  pgmOut.close();
  /**/

  char pngPath[80];

	strcpy(pngPath, outputDir.c_str());
	strcat(pngPath, "png/");
	strcat(pngPath, pngFile);

  canvas->resetCanvas();
  ReturnFunc rf;
  program->evaluate(&rf);
    
  cout << "Generation: " << generationCounter;
 
  cout << "\tNodes: " << canvas->getNumDrawNodes();
  // Suggestion from Jeremy Murphy 
  //    char fitnessString[6];
  //    sprintf(fitnessString, "%1.4f", bestFitness);
  //    cout << "\tFitness: " << fitnessString << endl;
  cout << "\tFitness: " << setprecision(4) << bestFitness << endl;
  canvas->saveImage(pngPath);

  if (reader->getUsingAdaptiveCanvas())
    canvas->updateBestCanvas();
}

