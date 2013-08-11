/*
 * Class:   Palette
 * Author:  Perry Barile
 *
 * Date created: Sep 23 2008
 *
 * The Palette creates colour palettes to be used by brush strokes.
 *
 */

#ifndef PALETTE_H
#define PALETTE_H

using namespace std;

#include <cstdlib>
#include <vector>
#include <set>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iostream>

#include "Utility.h"
#include "Target.h"
#include "ColorConverter.h"
#include "Pixel.h"

class Palette
{
private:
  vector<Pixel> colors;

public:
  Palette(Target* target);
  Palette(const char*);
  ~Palette();

  RGB getRandomRGB(float f);
  HSV getRandomHSV(float f);
};

#endif // PALETTE_H


