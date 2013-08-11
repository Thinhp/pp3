//
// Class:  ShroudCanvas
// Author: Pasquale Barile
//
// See header file for details.
//

using namespace std;

#include <math.h>
#include <vector>
#include "ShroudCanvas.h"
#include "ConfigReader.h"

ShroudCanvas::ShroudCanvas(Target* t, color_t r, color_t g, color_t b,
    BestCanvas* bc, ConfigReader* reader) : Canvas(t, r, g, b, bc),
  reader(reader)
{
  const int size = getSize();
  shroud = new RGB[size];
	
  fitnessR = 0.0f;
  fitnessG = 0.0f;
  fitnessB = 0.0f;
}

ShroudCanvas::~ShroudCanvas()
{
  delete shroud;
}

// Apply some paint to the canvas by drawing some lines
void ShroudCanvas::paintCanvas(vector<float> v)
{
  const unsigned ARGS = 6;
  assert(v.size() == ARGS);

  // Increment the node count
  newNode();

  // Set up the start point
  int pixelIndex = (int)(v.at(0) * getSize());
  startPoint.x = (float)(pixelIndex % getWidth());
  startPoint.y = (float)(pixelIndex / getWidth());

  // Set up the angle
  theta = v.at(1) * TWO_PI;

  // Set up the line length
  int w = getWidth();
  int h = getHeight();
  lineLength = (int)(v.at(2) * sqrt( (float)(w*w + h*h) ));

  // Set up the line color
  int red = (int)(v.at(3) * 256);
  int green = (int)(v.at(4) * 256);
  int blue = (int)(v.at(5) * 256);
  lineColor.r = red;
  lineColor.g = green;
  lineColor.b = blue;

  applyPaint();
}

// Apply paint
void ShroudCanvas::applyPaint()
{
  const int STRATEGY = reader->getShroudPixelStrategy();

  if (STRATEGY == ConfigReader::PIXEL_STRATEGY_BLEND)
    applyBlend();
  else if (STRATEGY == ConfigReader::PIXEL_STRATEGY_NO_PIXEL)
    applyNoPixel();
  else if (STRATEGY == ConfigReader::PIXEL_STRATEGY_NO_STROKE)
    applyNoStroke();
  else if (STRATEGY == ConfigReader::PIXEL_STRATEGY_STOP_STROKE)
    applyStopStroke();
}

void ShroudCanvas::applyFastShroud(Coord c, RGB lineColor)
{
  RGB targetPixel = getTarget()->getRGB(c);
  RGB canvasPixel = getRGBData(getDataOffset(c));

  int targetDiffR = abs(targetPixel.r - lineColor.r);
  int canvasDiffR = abs(canvasPixel.r - lineColor.r);
  int targetDiffG = abs(targetPixel.g - lineColor.g);
  int canvasDiffG = abs(canvasPixel.g - lineColor.g);
  int targetDiffB = abs(targetPixel.b - lineColor.b);
  int canvasDiffB = abs(canvasPixel.b - lineColor.b);

  bool targetRLower = targetDiffR < canvasDiffR;
  bool targetGLower = targetDiffG < canvasDiffG;
  bool targetBLower = targetDiffB < canvasDiffB;

  if (targetRLower || targetGLower || targetBLower)
    writePixel(c, lineColor);
}

void ShroudCanvas::applyBlend()
{
  for (int i = 0; i < lineLength; ++i)
  {
    Coord c = rotate2D(startPoint, 0, i, theta);

    if (insideCanvas(c))
    {
      if (reader->getFastShroud()) // Fast convergence
      {
        applyFastShroud(c, lineColor);
      }
      else
        writePixel(c, lineColor);
    }
  }
}

void ShroudCanvas::applyNoPixel()
{
  for (int i = 0; i < lineLength; i++)
  {
    Coord c = rotate2D(startPoint, 0, i, theta);

    if (insideCanvas(c))
    {
      if (pixelIsDirty(c)) // Don't draw the pixel
        continue;

      if (reader->getFastShroud()) // Fast convergence
        applyFastShroud(c, lineColor);
      else // Slow convergence
        writePixel(c, lineColor);
    }
  }
}

void ShroudCanvas::applyNoStroke()
{
  for (int i = 0; i < lineLength; i++)
  {
    Coord c = rotate2D(startPoint, 0, i, theta);
 
    if (insideCanvas(c))
    {
      if (pixelIsDirty(c)) // Don't draw the stroke
        return;
    }
  }
	
  // If we have reached this point, then no dirty pixels have been found
  applyBlend();
}

void ShroudCanvas::applyStopStroke()
{
  for (int i = 0; i < lineLength; i++)
  {
    Coord c = rotate2D(startPoint, 0, i, theta);

    if (insideCanvas(c))
    {
      if (pixelIsDirty(c)) // Stop drawing the stroke
        return;

      if (reader->getFastShroud()) // Fast convergence
          applyFastShroud(c, lineColor);
      else // Slow convergence
          writePixel(c, lineColor);
    }
  }
}

// Reset the canvas
void ShroudCanvas::resetCanvas()
{
  if (reader->getUsingAdaptiveCanvas())
  {
    for (int y = 0; y < getHeight(); y++)
    {
      for (int x = 0; x < getWidth(); x++)
      {
        Coord c = {x, y};
        RGB rgb = bestCanvas->getRGBPixel(c);
        setRGBData(y * getWidth() + x, rgb);
      }
    }
  }
  else
  {
    RGB rgb = bgColor;
    const int size = getSize();

    for (int i = 0; i < size; ++i)
      setRGBData(i, rgb);
  }

  resetNumDrawNodes();
}

// Write a pixel in RGB color space
void ShroudCanvas::writePixel(Coord c, RGB color)
{
  if (!insideCanvas(c))
    return;
    
  setRGBData(getDataOffset(c), mixPixels(c, color, 0.5f));
}

RGB ShroudCanvas::mixPixels(Coord coord, RGB strokeRGB, float alpha)
{
  RGB canvasRGB = getRGBData(getDataOffset(coord));
  RGB newRGB;
    
  newRGB.r = (int)(strokeRGB.r * alpha + canvasRGB.r * (1 - alpha));
  newRGB.g = (int)(strokeRGB.g * alpha + canvasRGB.g * (1 - alpha));
  newRGB.b = (int)(strokeRGB.b * alpha + canvasRGB.b * (1 - alpha));

  return newRGB;
}

void ShroudCanvas::printCoord(Coord c)
{
  cout << " {" << c.x << "," << c.y << "}";
}

void ShroudCanvas::computeFitness()
{
  int width = getWidth();
  int height = getHeight();

  for (int y = 0; y < height; y++)
  {
    for (int x = 0; x < width; x++)
    {
      Coord c = {x, y};
      RGB targetPixel = getTarget()->getRGB(c);
      RGB canvasPixel = getRGBData(getDataOffset(c));

      fitnessR += abs(targetPixel.r - canvasPixel.r);
      fitnessG += abs(targetPixel.g - canvasPixel.g);
      fitnessB += abs(targetPixel.b - canvasPixel.b);
    }
  }

  int theSize = getSize();
  fitnessR /= theSize;
  fitnessG /= theSize;
  fitnessB /= theSize;

  fitnessR /= 256.0f;
  fitnessG /= 256.0f;
  fitnessB /= 256.0f;

  fitnessRGB = ((fitnessR + fitnessG + fitnessB) / 3);
}

