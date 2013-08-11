/*
 * Header file
 * Class:        ImageFitness 
 * Date created: 2007-09-10
 * Written by:   Pasquale Barile
 *
 * Based on code written by Dylan Mawhinney
 *
 * A fitness class that compares a generated image to a target image and
 * computes the pixel-by-pixel difference.
 */

#ifndef IMAGE_FITNESS_H
#define IMAGE_FITNESS_H

#include <float.h> // for FLT_MAX
#include <math.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <sys/types.h>
#include <errno.h>
#include <time.h>

#ifdef UNIX
#include <unistd.h>
#include <sys/wait.h>
#endif

#include "GeneticProgram.h"
#include "Population.h"
#include "Fitness.h"
#include "GPConfig.h"
#include "DecalCanvas.h"
#include "BezierPathCanvas.h"
#include "ShroudCanvas.h"
#include "Canvas.h"
#include "ReturnFloat.h"
#include "ReturnFunc.h"
#include "ConfigReader.h"

class ImageFitness : public Fitness
{
private:
  float fitnessTarget;
        
  // Fitness based on the HSV color model
  float hsvFitnessH, hsvFitnessS, hsvFitnessV; 
  float lastFitnessMilestone, fitnessRenderThreshold;
  
  unsigned int generationCounter;
  int population;
        
  float normalise(float score, float normaliser);
  float computeFitness();
        
public:
  ImageFitness(GPConfig *conf);
        
  virtual void initFitness();
  virtual void assignFitness(GeneticProgram* pop[], int popSize);
  virtual bool solutionFound(GeneticProgram* pop[], int popSize);
  virtual bool isBetter(GeneticProgram* gp1, GeneticProgram* gp2);
  virtual bool isWorse(GeneticProgram* gp1, GeneticProgram* gp2);
  virtual bool isEqual(GeneticProgram* gp1, GeneticProgram* gp2);
        
  virtual double best();
  virtual double worst();
        
  void outputResults(GeneticProgram*, char*, char*, double);
};

#endif // IMAGE_FITNESS_H

