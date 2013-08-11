/*
 * Class:  Canny
 * Author: Pasquale Barile
 *
 * The Canny class applies a Canny edge detection filter.
 * 
 * First smooth the image to eliminate any noise.
 * 
 * Then find the image gradient to highlight regions with high spatial
 * derivatives.
 * 
 * Then track along these regions and suppress any pixels that are not a local
 * maximum.
 *
 * Then further reduce the array through hysteresis in order to find pixels 
 * that missed suppression.
 * 
 * The hysteresis use two thresholds: T1 and T2. Below T1 signifies no edge,
 * above T2 signifies an edge. Between T1 and T2 signifies no edge unless a path
 * can be found to a gradient above T2.
 */

#ifndef CANNY_H
#define CANNY_H

#include "Utility.h"
#include "png.h"
#include "util.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <assert.h>
#include <math.h>

class Canny
{
  RGB* gradients;
  RGB* tempBuffer;
  RGB* source;
  float* directions;
  int width, height;

  color_t T1, T2;

  // Apply a 5x5 Gaussian mask
  void smooth();

  // Apply a Sobel edge detection filter
  void sobel();

  // Apply non-maximum suppression
  void suppress();

  // Return a local maximum from a group of points
  int getMax(int, int);

  // Apply hysteresis
  void hysteresis();

  // Connect mid-range hysteresis values to high range values
  void connect(int, int);

public:
  Canny(RGB* rgb, int width, int height, int t1, int t2, bool fuzzyEdges);
  ~Canny();

  // Save this object to a file
  bool saveImage(std::string filename);

  // Return gradient value for a pixel
  color_t gradient(Coord c);

  // Return direction value for a pixel
  float angle(Coord c);
};

#endif // CANNY_H
