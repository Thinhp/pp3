/*
 * Class:  Pixel
 * Author: Pasquale Barile
 *
 * See header file for details.
 */

using namespace std;
#include "Pixel.h"

// Constructor
Pixel::Pixel()
{
  RGB color = {0,0,0};
  rgb = color;
  hsv = cc.rgb2hsv(rgb);
  alpha = 1.0f;
}

// Constructor
Pixel::Pixel(RGB col) : rgb(col)
{
  hsv = cc.rgb2hsv(col);
  alpha = 1.0f;
}

// Constructor
Pixel::Pixel(HSV col) : hsv(col)
{
  rgb = cc.hsv2rgb(col);
  alpha = 1.0f;
}

// Destructor
Pixel::~Pixel()
{
}

void Pixel::setColor(RGB color)
{
  rgb = color;
  hsv = cc.rgb2hsv(color);
}

void Pixel::setColor(HSV color)
{
  hsv = color;
  rgb = cc.hsv2rgb(color);
}

void Pixel::setR(color_t channel)
{
  rgb.r = channel;
  hsv = cc.rgb2hsv(rgb);
}

void Pixel::setG(color_t channel)
{
  rgb.g = channel;
  hsv = cc.rgb2hsv(rgb);
}

void Pixel::setB(color_t channel)
{
  rgb.b = channel;
  hsv = cc.rgb2hsv(rgb);
}

void Pixel::setH(int channel)
{
  hsv.h = channel;
  rgb = cc.hsv2rgb(hsv);
}

void Pixel::setS(int channel)
{
  hsv.s = channel;
  rgb = cc.hsv2rgb(hsv);
}

void Pixel::setV(int channel)
{
  hsv.v = channel;
  rgb = cc.hsv2rgb(hsv);
}

bool Pixel::operator<(const Pixel &other)
{
  if (hsv.h < other.getH())
    return true;
  if (hsv.s < other.getS())
    return true;
  if (hsv.v < other.getV())
    return true;
  return false;
}

bool Pixel::operator=(const Pixel &other)
{
  if (hsv.h == other.getH() && hsv.s == other.getS() && hsv.v == other.getV())
    return true;
  return false;
}

void Pixel::toString()
{
  cout << "HSV: {" << hsv.h << "," << hsv.s << "," << hsv.v << "}\n";
}
