/*
 * Class:  ColorConverter
 * Author: Pasquale Barile
 *
 * See header file for details
 *
 */

#include "ColorConverter.h"
using namespace std;

ColorConverter::ColorConverter(): grayR(0.3086), grayG(0.6094), grayB(0.082)
{
}

ColorConverter::~ColorConverter()
{
}

// The 3 channels are normalised

color_t ColorConverter::rgb2gray(RGB data)
{
  float r = grayR * data.r;
  float g = grayG * data.g;
  float b = grayB * data.b;

  return (color_t)(r + g + b);
}

//-----------------
/* 
 * r,g and b values are first converted to floats: [0, 1]
 * Values are then processed and finally converted to int.
 * int h = [0 ... 359]
 * int s = [0 ... 100]
 * int v = [0 ... 100]
 */
HSV ColorConverter::rgb2hsv(RGB data)
{
  const int DIV = 255;

  // Deal with grayscales
  if (data.r == data.g && data.r == data.b)
  {
    float v = (float)data.r / DIV;
    HSV result = {0, 0, roundOff(v, 100)};
    return result;
  }

  float r = (float)data.r / DIV;
  float g = (float)data.g / DIV;
  float b = (float)data.b / DIV;

  float h = 0.0f, s = 0.0f, v = 0.0f;

  float MIN = std::min(r, g);
  MIN = std::min(MIN, b);

  float MAX = std::max(r, g);
  MAX = std::max(MAX, b);

  // Define v
  v = MAX;

  float delta = MAX - MIN;

  // Define s
  s = delta / MAX;

  float deltaR = (((MAX - r) / 6) + (delta / 2)) / delta;
  float deltaG = (((MAX - g) / 6) + (delta / 2)) / delta;
  float deltaB = (((MAX - b) / 6) + (delta / 2)) / delta;

  if (r == MAX)
    h = deltaB - deltaG;
  else if (g == MAX)
    h = (1.0f / 3) + deltaR - deltaB;
  else if (b == MAX)
    h = (2.0f / 3) + deltaG - deltaR;

  if (h < 0)
    h += 1;

  if (h > 1)
    h -= 1;

  HSV result = {roundOff(h, 360), roundOff(s, 100), roundOff(v, 100)};
  return result;
}

RGB ColorConverter::hsv2rgb(HSV data)
{
  if (data.s == 0) // Grayscale
  {
    float v = (float)data.v / 100.0f;
    color_t c = (color_t)(v * 255);
    RGB result = {c, c, c};
    return result;
  }

  if (data.v == 0) // Black
  {
    RGB result = {0, 0, 0};
    return result;
  }

  // Convert hsv channels to floats in [0.0 ... 1.0]
  float h = (float)data.h / 360.0f;
  float s = (float)data.s / 100.0f;
  float v = (float)data.v / 100.0f;

  h *= 6;

  if (h > 5.999999f) // == 6
    h = 0.0f;

  int i = (int)h; // i in [0,1,2,3,4,5]

  float v1 = v * (1 - s);
  float v2 = v * (1 - s * (h - i));
  float v3 = v * (1 - s * (1 - (h - i)));

  float r = 0.0f, g = 0.0f, b = 0.0f;

  switch(i)
  {
    case 0:
      r = v;
      g = v3;
      b = v1;
      break;
    case 1:
      r = v2;
      g = v;
      b = v1;
      break;
    case 2:
      r = v1;
      g = v;
      b = v3;
      break;
    case 3:
      r = v1;
      g = v2;
      b = v;
      break;
    case 4:
      r = v3;
      g = v1;
      b = v;
      break;
    case 5:
      r = v;
      g = v1;
      b = v2;
  }

  RGB result = {roundOff(r, 255), roundOff(g, 255), roundOff(b, 255)};
  return result;
}

// Convert a float to an int using nearest neighbour
int ColorConverter::roundOff(float f, int i)
{
  float x = f * i;
  float y = floor(x);
  float fractional = x - y;
  int result = (int)x;
  if (fractional >= 0.5)
    result++;
  return result;
}

// Convert a hexadecimal string to RGB
RGB ColorConverter::hex2rgb(std::string hex)
{
  string sr = hex.substr(0,2);
  string sg = hex.substr(2,2);
  string sb = hex.substr(4,2);

  int r = (int)(strtol(sr.c_str(), NULL, 16));
  int g = (int)(strtol(sg.c_str(), NULL, 16));
  int b = (int)(strtol(sb.c_str(), NULL, 16));

  RGB ret = {r, g, b};
  return ret;
}

