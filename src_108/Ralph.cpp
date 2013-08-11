/*
 *  Ralph.cpp
 *  
 *
 *  Created by Perry Barile on 2008-07-05.
 *
 */

using namespace std;

#include "Ralph.h"

double Ralph::computeRGBImage(RGB* image, int width, int height)
{
  computeResponses(image, width, height);
  computeStandardDeviation();
  computeHistogram();
  double dfn = computeDFN();
    
  delete responses;
  delete histogram;
  return dfn;
}

double Ralph::computeDFN()
{
  double retval = 0;
    
  for (int i = 0; i < numBins; i++)
  {
    double observed = histogram[i] / histogramArea;
    if (observed == 0)
      continue;
        
    double predicted = computePredictedProbability(binWidth * i);
    if (predicted == 0)
      continue;
    
    retval += (observed * log(observed / predicted));
  }
  retval *= 1000;
    
  DEBUG(mean);
  DEBUG(stddev);
  return retval;
}

double Ralph::computePredictedProbability(double x)
{
  double P;
    
  double multiplier = 1.0 / (stddev * sqrt(TWO_PI));
  //DEBUG(multiplier);
    
  double exponent = (-1 * pow((x - mean), 2.0)) / (2 * variance);
  //DEBUG(exponent);
    
  P = exp(exponent) * multiplier;
    
  return P;
}

void Ralph::computeResponses(RGB* image, int width, int height)
{
  int w = width - 1;
  int h = height - 1;
    
  double d = sqrt((float)(width*width + height*height));
  d /= 2;
  d *= 0.001;
    
  numResponses = w * h;
  responses = new double[numResponses];
  responseSquaredTotal = 0.0f;
  responseTotal = 0.0f;
    
  for (int y = 0; y < h; y++)
  {
    for (int x = 0; x < w; x++)
    {
      int offsetA = y * width + x;
      int offsetB = (y+1) * width + x+1;
      int offsetC = y * width + x+1;
      int offsetD = (y+1) * width + x;
            
      RGB rgbA = image[offsetA];
      RGB rgbB = image[offsetB];
      RGB rgbC = image[offsetC];
      RGB rgbD = image[offsetD];
    
      int ABr = ((int)rgbA.r - (int)rgbB.r);
      int ABg = ((int)rgbA.g - (int)rgbB.g);
      int ABb = ((int)rgbA.b - (int)rgbB.b);
            
      int CDr = ((int)rgbC.r - (int)rgbD.r);
      int CDg = ((int)rgbC.g - (int)rgbD.g);
      int CDb = ((int)rgbC.b - (int)rgbD.b);
            
      double denominator = d * d;
            
      double rValue = (ABr * ABr + CDr * CDr) / denominator;
      double gValue = (ABg * ABg + CDg * CDg) / denominator;
      double bValue = (ABb * ABb + CDb * CDb) / denominator;
            
      double stimulus = sqrt(rValue + gValue + bValue);
      if (stimulus == 0)
      {
        responses[y * w + x] = ERROR;
        continue;
      }
            
      double response = log(stimulus / 2);
      responses[y * w + x] = response;
      responseTotal += response;
      responseSquaredTotal += (response * response);
    }
  }
  mean = responseSquaredTotal / responseTotal;
}

void Ralph::computeStandardDeviation()
{
  double responseCalc = 0;

  for (int i = 0; i < numResponses; i++)
  {
    if (responses[i] == ERROR)
      continue;
        
    double deviation = responses[i] - mean;
    double deviationSquared = deviation * deviation;
    responseCalc += (responses[i] * deviationSquared);
  }
    
  variance = responseCalc / responseTotal;
  stddev = sqrt(variance);
}

void Ralph::computeHistogram()
{
  binWidth = stddev / 100;
    
  // get the max response
  double max = 0;
    
  for (int i = 0; i < numResponses; i++)
  {
    if (responses[i] == ERROR)
      continue;
        
    if (responses[i] > max)
      max = responses[i];
  }
  numBins = (int)(max / binWidth + 1);

  histogram = new double[numBins];
    
  for (int i = 0; i < numBins; i++)
    histogram[i] = 0;
    
  histogramArea = 0;
  for (int i = 0; i < numResponses; i++)
  {
    if (responses[i] == ERROR)
      continue;
        
    int binNum = (int)(responses[i] / binWidth);
    histogram[binNum] += responses[i];
    histogramArea += responses[i];
  }
}

double Ralph::computeHSVImage(HSV* image, int width, int height)
{
  double ret = 32767.0;
  return ret;
}

