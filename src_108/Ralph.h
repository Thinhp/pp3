/*
 *  Ralph.h
 *  
 *  Created by Perry Barile on 2008-07-05.
 *
 *  Implements Raplh's Bell Curve function for computing aesthetic fitness.
 */

#ifndef RALPH_H
#define RALPH_H

#include <cstdlib>
#include <math.h>
#include <iostream>

#include "Utility.h"

const double ERROR = 32768;

class Ralph
{
private:
  double responseSquaredTotal, responseTotal, mean, variance, stddev;
  double* responses;
  double* histogram;
  double histogramArea;
  double binWidth;
  int numResponses;
  int numBins;
    
  void computeResponses(RGB* image, int width, int height);
  void computeStandardDeviation();
  void computeHistogram();
  double computeDFN();
  double computePredictedProbability(double);
    
public:
  double computeRGBImage(RGB* image, int width, int height);
  double computeHSVImage(HSV* image, int width, int height);
};

#endif // RALPH_H

