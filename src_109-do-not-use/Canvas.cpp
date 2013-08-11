/*
 * Class:   Canvas
 * Author:  Pasquale Barile
 * modified By: Ashkan Izadi
 *
 * See header file for details
 *
 */

using namespace std;
#include "Canvas.h"
#include "ConfigReader.h"
#include <assert.h>

//To get back ground of canvas with different Colourful scale aspect
Canvas::Canvas(Target* t, color_t r, color_t g, color_t b, BestCanvas* bc) :
  target(t), bestCanvas(bc)
{
  RGB tmpColor = {r, g, b};
  bgColor = tmpColor;

  width = target->getWidth();
  height = target->getHeight();

  numPixels = width * height;
  numDrawNodes = 0;
    
  hsvFitnessH = 0.0f;
  hsvFitnessS = 0.0f;
  hsvFitnessV = 0.0f;
    
  const int size = numPixels;
  rgbData = new RGB[size];
  hsvData = new HSV[size];
}

Canvas::~Canvas()
{
  delete rgbData;
  delete hsvData;
}

// Save this canvas to a file
bool Canvas::saveHSVImage(char* filename)
{
  ColorConverter cc;
    
  for (int i = 0; i < numPixels; i++)
    rgbData[i] = cc.hsv2rgb(hsvData[i]);
    
  write_image(filename, (color_t*)rgbData, width, height);
  return true;
}

// Save this canvas to a file
bool Canvas::saveRGBImage(char* filename)
{
  write_image(filename, (color_t*)rgbData, width, height);
  return true;
}

// Determine whether a point is inside the boundaries of the canvas
bool Canvas::insideCanvas(Coord c)
{
  int x = (int)c.x;
  int y = (int)c.y;
    
  if (x >= width || y >= height || x < 0 || y < 0)
    return false;
    
  return true;
}

// Return an offset to the data ptr
int Canvas::dataOffset(Coord c)
{
  int x = (int)c.x;
  int y = (int)c.y;
  return y * width + x;
}

// Return hsv fitness data. See header file for details.
void Canvas::computeHSVFitness()
{
  hsvFitnessH = 0.0f;
  hsvFitnessS = 0.0f;
  hsvFitnessV = 0.0f;
    
  for (int y = 0; y < height; y++)
  {
    for (int x = 0; x < width; x++)
    {
      Coord c = {x, y};
      HSV targetPixel = target->getHSV(c);
      HSV canvasPixel = hsvData[y * width + x];
            
      int hDiff = abs(targetPixel.h - canvasPixel.h);
      if (hDiff > 180)
        hDiff = abs(hDiff - 360);
            
      hsvFitnessH += hDiff;
      hsvFitnessS += abs(targetPixel.s - canvasPixel.s);
      hsvFitnessV += abs(targetPixel.v - canvasPixel.v);
    }
  }
    
  hsvFitnessH /= numPixels;
  hsvFitnessS /= numPixels;
  hsvFitnessV /= numPixels;

  // Normalise
  hsvFitnessH /= 180.0;
  hsvFitnessS /= 100.0;
  hsvFitnessV /= 100.0;
}

// Rotate a point about a 2D rotational matrix
Coord Canvas::rotate2D(Coord c, float dx, float dy, float theta)
{
  const float x = dx * cos(theta) - dy * sin(theta);
  const float y = dx * sin(theta) + dy * cos(theta);
    
  Coord ret = {c.x + x, c.y + y};
  return ret;
}

// Set RGB pixel data
void Canvas::setRGBData(int offset, RGB pixel)
{
  rgbData[offset] = pixel;
}

// Set HSV pixel data
void Canvas::setHSVData(int offset, HSV pixel)
{
  hsvData[offset] = pixel;
}

// Return the distance in degrees between two hues
int Canvas::degreesOfSeparation(int d1, int d2)
{
  int diff = abs(d1 - d2);
    
  if (diff > 180)
    diff = abs(diff - 360);
    
  return diff;
}

// Print out an RGB pixel
void Canvas::printColor(RGB color)
{
  cout << "{"
    << (int)color.r << " "
    << (int)color.g << " "
    << (int)color.b << "}";
}

// Print out an HSV pixel
void Canvas::printColor(HSV color)
{
  cout << "{"
    << (int)color.h << " "
    << (int)color.s << " "
    << (int)color.v << "}";
}

// Try to match hue
int Canvas::matchHue(Coord c, int brushHue)
{
  int targetHue = target->getHue(c);
  int canvasHue = hsvData[dataOffset(c)].h;
    
  int brushDiff = degreesOfSeparation(targetHue, brushHue);
  int canvasDiff = degreesOfSeparation(targetHue, canvasHue);
    
  if (canvasDiff < brushDiff)
    return canvasHue;
    
  return brushHue;
}

// Try to match sat
int Canvas::matchSat(Coord c, int brushSat)
{
  int targetSat = target->getSat(c);
  int canvasSat = hsvData[dataOffset(c)].s;
    
  if ( abs(targetSat - canvasSat) < abs(targetSat - brushSat) )
    return canvasSat;
    
  return brushSat;
}

bool Canvas::pixelIsDirty(Coord c)
{
  int offset = getDataOffset(c);
  RGB pixel = getRGBData(offset);
    
  if (pixel.r == bgColor.r && pixel.g == bgColor.g && pixel.b == bgColor.b)
    return false;

  return true;
}

bool Canvas::pixelIsWhite(Coord c)
{
	RGB pixel = getRGBData(getDataOffset(c));
	if (pixel.r == 255 && pixel.g == 255 && pixel.b == 255)
    return false;
    
	return true;
}

// Try to match val
int Canvas::matchVal(Coord c, int brushVal)
{
  int targetVal = target->getVal(c);
  int canvasVal = hsvData[dataOffset(c)].s;
    
  if ( abs(targetVal - canvasVal) < abs(targetVal - brushVal) )
    return canvasVal;
    
  return brushVal;
}

void Canvas::updateBestCanvas()
{
  for (int i = 0; i < numPixels; i++)
  {
    RGB rgb = rgbData[i];
    HSV hsv = hsvData[i];
    bestCanvas->setRGBPixel(i, rgb);
    bestCanvas->setHSVPixel(i, hsv);
  }
}
