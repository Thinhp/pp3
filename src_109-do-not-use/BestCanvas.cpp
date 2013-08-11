/*
 * Class:   BestCanvas
 * Author:  Perry Barile
 * Modified by: Ashkan Izadi
 *
 *
 * See header file for details
 *
 */

using namespace std;
#include "BestCanvas.h"

BestCanvas::BestCanvas(Target* target, color_t red, color_t green, color_t blue)
  : width(target->getWidth()), height(target->getHeight())
{
  numPixels = width * height;
  const int size = numPixels;

  rgbData = new RGB[size];
  hsvData = new HSV[size];

  ColorConverter cc;

  for (int i = 0; i < size; i++)
  {
    RGB rgb = {red, green, blue};
		rgbData[i] = rgb;
    hsvData[i] = cc.rgb2hsv(rgb);
  }
}

BestCanvas::~BestCanvas()
{
  delete rgbData;
  delete hsvData;
}

RGB BestCanvas::getRGBPixel(Coord c)
{
  int offset = (int)c.y * width + (int)c.x;
  return rgbData[offset];
}

HSV BestCanvas::getHSVPixel(Coord c)
{
  int offset = (int)c.y * width + (int)c.x;
  return hsvData[offset];
}

