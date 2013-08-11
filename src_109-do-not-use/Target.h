/*
 * Class:   Target
 * Author:  Pasquale Barile
 *
 * The Target class encapsulates image related functions and data contained
 * in target images
 *
 */

#ifndef TARGET_H
#define TARGET_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>
#include <set>

#include "Utility.h"
#include "png.h"
#include "util.h"
#include "ColorConverter.h"
#include "Canny.h"

class Target
{
private:
  RGB* rgbData; // Original source image data
  HSV* hsvData; // rgbData converted to HSV colour model

  RGB* rgbMaskData;
  HSV* hsvMaskData;

  Canny* satEdgeMap; // Edge map of saturation map
  Canny* valEdgeMap; // Edge map of value map

  unsigned width, height, numPixels; // numPixels = width * height

  int st1, st2, vt1, vt2;
  bool fuzzy;
   
  /* Reduced palette functionality */
  std::set<int> hueSet;
  std::set<int> satSet;
  std::set<int> valSet;
  void reducePalette();
    
public:
  Target(const char* targetFile, const char* maskFile, int satT1, int satT2,
      int valT1, int valT2, bool fuzzyEdges);
  ~Target();

  // Accessors
  unsigned getWidth() const { return width; }
  unsigned getHeight() const { return height; }
  int getNumHues() const { return hueSet.size(); }
  int getNumSats() const { return satSet.size(); }
  int getNumVals() const { return valSet.size(); }

  // Return an HSV pixel from this image's palette
  HSV getPaletteHSV(float f1, float f2, float f3);

  // Return a pixel in RGB space
  RGB getRGB(Coord c);

  // Return a pixel in HSV space
  HSV getHSV(Coord c);

  // Return local hue, saturation, value
  int getHue(Coord c);
  int getSat(Coord c);
  int getVal(Coord c);

  // Return local gradients
  int getSatGradient(Coord c) { return satEdgeMap->gradient(c); }
  int getValGradient(Coord c) { return valEdgeMap->gradient(c); }
   
  // Return local gradient directions
  float getSatDirection(Coord c) { return satEdgeMap->angle(c); }
  float getValDirection(Coord c) { return valEdgeMap->angle(c); }

  // Return whether a coordinate is inside a black region in the mask data
  bool isImportant(int offset);

  // Over-ride normal behaviour for custom purposes
  void override(int n);
};

#endif // TARGET_H
