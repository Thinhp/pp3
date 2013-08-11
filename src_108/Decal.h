/*
 * Class:  Decal
 * Author: Pasquale Barile
 *
 * The Decal class simulates a painter's decal. This class may serve as a base
 * class for a variety of decals, but at the moment it is a concrete class that
 * handles the following:
 *
 * - Number of bristles (at the moment is an odd number -- aids in symmetry)
 * - Pixel distance between bristles
 * - Decal angle
 */

#ifndef DECAL_H
#define DECAL_H

#include <math.h>
#include <vector>
#include <iostream>
#include "Utility.h"
#include "ColorConverter.h"
#include "ConfigReader.h"

class Decal
{
  // The strokeAngle is measured in radians and refers to the angle of strokes
  // placed on the canvas
  float strokeAngle;

  // The coordinate on the canvas of the central bristle
  Coord baseCoord;

  // For each decal there is some action it performs, eg draw a line, or
  // a circle. The generic term for the size of what it draws (eg line length,
  // circle radius, etc), is the draw length.
  int drawLength;

  // The decal color. The two types always represent the same color.
  RGB rgb;
  HSV hsv;

  ConfigReader* reader;
  int decalWidth;

public:
  Decal(ConfigReader* reader, int minDim, int maxDim);
  ~Decal();

  void setLocation(float f1, float f2);
  void setColor(float f1, float f2, float f3);
  void setColor(HSV col) { hsv = col; }

  Coord getLocation() { return baseCoord; }
  RGB getRGB() { return rgb; }
  HSV getHSV() { return hsv; }
  int getDrawLength() { return drawLength; }
  double getStrokeAngle() { return strokeAngle; }
  int getDecalWidth() { return decalWidth; }
};

#endif // DECAL_H
