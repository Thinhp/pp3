/*
 * Class:  ColorConverter
 * Author: Pasquale Barile
 *
 * A convenience class written for the following conversions:
 *    RGB colour --> RGB grayscale
 *    RGB <--> HSV
 *
 */

#ifndef COLOR_CONVERTER_H
#define COLOR_CONVERTER_H

#include <algorithm>
#include <math.h>
#include <string>
#include <iostream>
#include "Utility.h"

using namespace std;

class ColorConverter
{
private:
  // Colour to grayscale converter multipliers
  float grayR, grayG, grayB;

public:
  ColorConverter();
  ~ColorConverter();

  color_t rgb2gray(RGB);
  HSV rgb2hsv(RGB);
  RGB hsv2rgb(HSV);
  RGB hex2rgb(std::string);
  // Convert a float to an int using nearest neighbour
  int roundOff(float, int);
};

#endif // COLOR_CONVERTER_H
