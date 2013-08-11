/*
 * Class:   BestCanvas
 * Author:  Perry Barile
 * Modified by: Ashkan Izadi
 *
 * Date created: Sep 23 2008
 * Date modified: Dec 18 2009
 *
 * The BestCanvas represents the best current phenotype. It is updated as the
 * best fitness is updated.
 *
 */

#ifndef BEST_CANVAS_H
#define BEST_CANVAS_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <assert.h>
#include <math.h>

#include "Utility.h"
#include "png.h"
#include "util.h"
#include "Target.h"
#include "ColorConverter.h"

class BestCanvas
{
private:
  RGB* rgbData;
  HSV* hsvData;

  unsigned width, height, numPixels;

public:
  BestCanvas(Target* target, color_t red, color_t green, color_t blue);
	~BestCanvas();

  void setRGBPixel(int offset, RGB pixel) { rgbData[offset] = pixel; }
  void setHSVPixel(int offset, HSV pixel) { hsvData[offset] = pixel; }

  RGB getRGBPixel(Coord c);
  HSV getHSVPixel(Coord c);
};

#endif // BEST_CANVAS_H


