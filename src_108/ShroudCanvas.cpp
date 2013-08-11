/*
 * Class:  ShroudCanvas
 * Author: Pasquale Barile & Ashkan Izadi
 * last mified: 18 Dec 2009
 *
 * See header file for details.
 *
 */

using namespace std;

#include "ShroudCanvas.h"
#include "ConfigReader.h"
#include "Triangle.h"
#include <math.h>
#include <vector>

/** Original **/

ShroudCanvas::ShroudCanvas(Target* t, color_t bg, BestCanvas* bc,
    ConfigReader* reader) : Canvas(t, bg, bc), reader(reader)
{
  const int size = getSize();
  shroud = new RGB[size];
}

ShroudCanvas::~ShroudCanvas()
{
  delete shroud;
}

// Apply some paint to the canvas by drawing some lines
void ShroudCanvas::paintCanvas(vector<float> v)
{
  if(reader->getColourMode())
  {
    const unsigned ARGS = 6;
    assert(v.size() == ARGS);

    // Set up the line color
    int red = (int)(v.at(3) * 256);
    int green = (int)(v.at(4) * 256);
    int blue = (int)(v.at(5) * 256);
    lineColor.r = red;
    lineColor.g = green;
    lineColor.b = blue;
  }
  else
  {
    const unsigned ARGS = 4;
    assert(v.size() == ARGS);
	     
    // Set up the line color
    int gray = (int)(v.at(3) * 256);
    lineColor.r = gray;
    lineColor.g = gray;
    lineColor.b = gray;
  }

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

  //if the Line length is equal to zero, as a default pass the noraml linelength
  if(reader->getFirstLineLength() == 0)
  {
    lineLength = (int)(v.at(2) * sqrt( (float)(w*w + h*h) ));
  }
  //if it is not equal to zero, it will pass the variable from painter.txt file
  else
  {
    float templine = reader->getFirstLineLength();
    lineLength = (int)(v.at(2) * templine);
  }
  applyPaint();
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
    if(reader->getColourMode())
		{
      const color_t bg_Red = getbgColor_Red();
      const color_t bg_Green = getbgColor_Green();
      const color_t bg_Blue = getbgColor_Blue();
			
      RGB rgb= {bg_Red, bg_Green, bg_Blue};
      swipResetConvas(rgb);
    }
    else
    {
      const color_t bg = getBGColor();
      RGB rgb = {bg, bg, bg};
      swipResetConvas(rgb);
    }
  }
  resetNumDrawNodes();
}

void ShroudCanvas::computeSelectedFitness()
{
  if(reader->getColourMode())
    computeColourFitness();
  else
    computeGrayFitness();
}

/** Ashkan **/

Triangle* triangle;

ShroudCanvas::ShroudCanvas(Target* t, color_t bg_Red, color_t bg_Green,
    color_t bg_Blue, BestCanvas* bc, ConfigReader* reader) : Canvas(t, bg_Red,
      bg_Green, bg_Blue, bc), reader(reader)
{
  const int size = getSize();
  shroud = new RGB[size];
	
  rgbFitnessR=0.0f;
  rgbFitnessG=0.0f;
  rgbFitnessB=0.0f;
}

void ShroudCanvas::fastColourTechnique3(RGB targetPixel, RGB canvasPixel,
    RGB lineColor, Coord c)
{
  int RedNewlineToTargetDiff = abs(targetPixel.r - lineColor.r);
  int RedCanvasToTargetDiff = abs(targetPixel.r - canvasPixel.r);
  if (RedNewlineToTargetDiff> RedCanvasToTargetDiff)
    lineColor.r=canvasPixel.r;
		
  int GreenNewlineToTargetDiff = abs(targetPixel.g - lineColor.g);
  int GreenCanvasToTargetDiff = abs(targetPixel.g - canvasPixel.g);
  if (GreenNewlineToTargetDiff  > GreenCanvasToTargetDiff )
    lineColor.g=canvasPixel.g;
	
  int BlueNewlineToTargetDiff = abs(targetPixel.b - lineColor.b);
  int BlueCanvasToTargetDiff = abs(targetPixel.b - canvasPixel.b);
  if (BlueNewlineToTargetDiff> BlueCanvasToTargetDiff )
    lineColor.b=canvasPixel.b;
	
  if ((RedNewlineToTargetDiff < RedCanvasToTargetDiff ) ||
      (GreenNewlineToTargetDiff < GreenCanvasToTargetDiff) ||
      (BlueNewlineToTargetDiff < BlueCanvasToTargetDiff ))
    writePixel(c, lineColor);
}

void ShroudCanvas::fastColourTechnique2(RGB targetPixel, RGB canvasPixel,
    RGB lineColor,Coord c)
{
  int RedNewlineToTargetDiff = abs(targetPixel.r - lineColor.r);
  int RedCanvasToTargetDiff = abs(targetPixel.r - canvasPixel.r);
						
  int GreenNewlineToTargetDiff = abs(targetPixel.g - lineColor.g);
  int GreenCanvasToTargetDiff = abs(targetPixel.g - canvasPixel.g);
						
  int BlueNewlineToTargetDiff = abs(targetPixel.b - lineColor.b);
  int BlueCanvasToTargetDiff = abs(targetPixel.b - canvasPixel.b);
						
  int TotalNewLineToTargetDiff = RedNewlineToTargetDiff +
    GreenNewlineToTargetDiff + BlueNewlineToTargetDiff;
  int TotalCanvasToTargetDiff = RedCanvasToTargetDiff +
    GreenCanvasToTargetDiff + BlueCanvasToTargetDiff ;
						
  if (TotalNewLineToTargetDiff< TotalCanvasToTargetDiff)
    writePixel(c, lineColor);
}

void ShroudCanvas::fastGrayTechnique(RGB targetPixel, RGB canvasPixel,
    RGB lineColor,Coord c)
{
  int brushToTargetDiff = abs(targetPixel.r - lineColor.r);
  int brushToCanvasDiff = abs(canvasPixel.r - lineColor.r);

  if (brushToTargetDiff < brushToCanvasDiff)
    writePixel(c, lineColor);
}

// Apply paint
void ShroudCanvas::applyPaint()
{
  const int BLEND = 0;
  const int NO_PIXEL = 1;
  const int NO_STROKE = 2;
  const int STOP_STROKE = 3;

  const int STRATEGY = reader->getShroudPixelStrategy();

  switch (STRATEGY)
  {
    case BLEND:
      applyBlend();
      break;
    case NO_PIXEL:
      applyNoPixel();
      break;
    case NO_STROKE:
      applyNoStroke();
      break;
    case STOP_STROKE:
      applyStopStroke();
  }
}

void ShroudCanvas::applyFastShroud(Coord c, RGB lineColor)
{
  RGB targetPixel = getTarget()->getRGB(c);
  RGB canvasPixel = getRGBData(getDataOffset(c));
				
  if(reader->getColourMode())
  {
    if(reader->getColourUpdater())
      fastColourTechnique3(targetPixel,canvasPixel,lineColor,c);						
    else
      fastColourTechnique2(targetPixel,canvasPixel,lineColor,c);
  }
  else
    fastGrayTechnique(targetPixel,canvasPixel,lineColor,c);
}

void ShroudCanvas::applyBlend()
{
  if (reader->getFastShroud()) // Fast convergence
  {
    for (int i = 0; i < lineLength; i++)
    {
      Coord c = rotate2D(startPoint, 0, i, theta);
      if (insideCanvas(c))
        applyFastShroud(c, lineColor);
    }
  }
  else// slow convergence
  {
    for (int i = 0; i < lineLength; i++)
    {
      Coord c = rotate2D(startPoint, 0, i, theta);
      if (insideCanvas(c))
        writePixel(c, lineColor);
    }	
  }
}

// It says if the stroke has got same color with a canvas do NOT draw the
// specific pixel
void ShroudCanvas::applyNoPixel()
{
  for (int i = 0; i < lineLength; i++)
  {
    Coord c = rotate2D(startPoint, 0, i, theta);
    if (insideCanvas(c))
    {
      //if (pixelIsDirty(c)) // Don't draw the pixel
      if (pixelIsWhite(c))
        continue;
      else
      {
        if (reader->getFastShroud()) // Fast convergence
          applyFastShroud(c, lineColor);
        else // Slow convergence
          writePixel(c, lineColor);
      }
    }
  }
}

// if even one pixel is same on the canvas, Do not write that image(line or
// triangle) at all
void ShroudCanvas::applyNoStroke()
{
  for (int i = 0; i < lineLength; i++)
  {
    Coord c = rotate2D(startPoint, 0, i, theta);
        
    if (insideCanvas(c))
    {
      //if (pixelIsDirty(c)) // Don't draw the stroke
      if(pixelIsWhite(c))				
        return;
    }
  }
	
  // If we have reached this point, then no dirty pixels have been found
  applyBlend();
}

// if any pixel of image reached to the another image on the canvas, stop to
// draw rest of the image.
void ShroudCanvas::applyStopStroke()
{
  for (int i = 0; i < lineLength; i++)
  {
    Coord c = rotate2D(startPoint, 0, i, theta);
    if (insideCanvas(c))
    {
      //if (pixelIsDirty(c)) // Stop drawing the stroke
      if(pixelIsWhite(c))					
        return;
      else
      {
        if (reader->getFastShroud()) // Fast convergence
          applyFastShroud(c, lineColor);
        else // Slow convergence
          writePixel(c, lineColor);
      }
    }
  }
}

void ShroudCanvas::swipResetConvas(RGB rgb)
{
  const int size = getSize();
  for (int i = 0; i < size; i++)
    setRGBData(i, rgb);
}

/*
 * Write a pixel in RGB color space
 */
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

void ShroudCanvas::computeColourFitness()
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
			
			rgbFitnessR += abs(targetPixel.r - canvasPixel.r);
			rgbFitnessG += abs(targetPixel.g - canvasPixel.g);
			rgbFitnessB += abs(targetPixel.b - canvasPixel.b);
    }
  }

  int theSize= getSize();
  rgbFitnessR /= theSize;
  rgbFitnessG /= theSize;
  rgbFitnessB /= theSize;
	   
  rgbFitnessR /= 256.0f;
  rgbFitnessG /= 256.0f;
  rgbFitnessB /= 256.0f;

  selectedFitness = ( (rgbFitnessR + rgbFitnessG + rgbFitnessB) / 3);
}

void ShroudCanvas::computeGrayFitness()
{
  float ret = 0.0f;
  int width = getWidth();
  int height = getHeight();

  for (int y = 0; y < height; y++)
  {
    for (int x = 0; x < width; x++)
    {
      Coord c = {x, y};
      RGB targetPixel = getTarget()->getRGB(c);
      RGB canvasPixel = getRGBData(getDataOffset(c));

      int diff = abs(targetPixel.r - canvasPixel.r);
      ret += diff;
    }
  }

  ret /= getSize();
  ret /= 256.0f;
  selectedFitness = ret; 
}

