/*
 * Class:  BezierPathCanvas
 * Author: Pasquale Barile
 *
 * See header file for details.
 *
 */

using namespace std;
#include "BezierPathCanvas.h"

BezierPathCanvas::BezierPathCanvas(Target* t, color_t bg, BestCanvas* bc, ConfigReader* reader)
: Canvas(t, bg, bc), reader(reader), baseDivisionsPerStroke(400)
{
  const int size = getSize();
  bgCanvas = new HSV[size];

  // Calculate black to white ratio
  int white = 0;
  int black = 0;

  for (int y = 0; y < getHeight(); y++)
  {
    for (int x = 0; x < getWidth(); x++)
    {
      Coord c = {x, y};

      HSV targetPixel = getTarget()->getHSV(c);

      if (targetPixel.v == 0)
        black++;
      else
        white++;
    }
  }

  if (white > black)
    whiteToBlack = (float)white / black;
  else if (black > white)
    whiteToBlack = (float)black / white;
  else
    whiteToBlack = 1.0f;

  cout << "White/black: " << (double)white/black << endl;
}

BezierPathCanvas::~BezierPathCanvas()
{
  delete bgCanvas;
}

// Apply some paint to the canvas by drawing some lines
// Expecting 6 floats in the vector argument
void BezierPathCanvas::paintCanvas(vector<float> v)
{
  const unsigned ARGS = 6;
  assert(v.size() == ARGS);
    
  // Increment the node count
  newNode();
    
  // Determine whether we are drawing quarter length, half length, or full
  // length paths
  if (v.at(0) < 0.6f)
    setupQuarterLengthPath(v.at(1), v.at(2), v.at(3), v.at(4));
  else if (v.at(0) < 0.9f)
    setupHalfLengthPath(v.at(1), v.at(2), v.at(3), v.at(4));
  else
    setupFullLengthPath(v.at(1), v.at(2), v.at(3), v.at(4));

  float option = v.at(5);

  switch(reader->getLineArtColorMode())
  {
    case 0:
      // Just black
      baseColor.h = 0;
      baseColor.s = 0;
      baseColor.v = 0;
      break;

    case 1:
      if (option < 0.5) // black
      {
        baseColor.h = 0;
        baseColor.s = 0;
        baseColor.v = 0;
      }
      else // white
      {
        baseColor.h = 0;
        baseColor.s = 0;
        baseColor.v = 100;
      }
      break;

    case 2:
      if (option < 0.5) // black
      {
        baseColor.h = 0;
        baseColor.s = 0;
        baseColor.v = 0;
      }
      else // red
      {
        baseColor.h = 0;
        baseColor.s = 100;
        baseColor.v = 100;
      }
      break;

    case 3:
      if (option < 0.333) // black
      {
        baseColor.h = 0;
        baseColor.s = 0;
        baseColor.v = 0;
      }
      else if (option < 0.666) // red
      {
        baseColor.h = 0;
        baseColor.s = 100;
        baseColor.v = 100;
      }
      else // white
      {
        baseColor.h = 0;
        baseColor.s = 0;
        baseColor.v = 100;
      }
  }

  applyPaint();
}

void BezierPathCanvas::setupDividedLengthPath(float f1,
                                              float f2,
                                              float f3,
                                              float f4,
                                              int n)
{
  // 1st end point
  int pixelIndex = (int)(f1 * getSize());
  endPoint1.x = (float)(pixelIndex % getWidth());
  endPoint1.y = (float)(pixelIndex / getWidth());
    
  float spx = endPoint1.x;
  float spy = endPoint1.y;
    
  // 2nd end point
  pixelIndex = (int)(f2 * getSize());
  float fx = (float)(pixelIndex % getWidth());
  float fy = (float)(pixelIndex / getWidth());
  endPoint2.x = (fx - spx) / n + spx;
  endPoint2.y = (fy - spy) / n + spy;
    
  // 1st control point
  pixelIndex = (int)(f3 * getSize());
  fx = (float)(pixelIndex % getWidth());
  fy = (float)(pixelIndex / getWidth());
  controlPoint1.x = (fx - spx) / n + spx;
  controlPoint1.y = (fy - spy) / n + spy;
    
  // 2nd control point
  pixelIndex = (int)(f4 * getSize());
  fx = (float)(pixelIndex % getWidth());
  fy = (float)(pixelIndex / getWidth());
  controlPoint2.x = (fx - spx) / n + spx;
  controlPoint2.y = (fy - spy) / n + spy;
}

void BezierPathCanvas::setupQuarterLengthPath(float f1,
                                              float f2,
                                              float f3,
                                              float f4)
{
  dotDivisionsPerStroke = baseDivisionsPerStroke / 4;
  setupDividedLengthPath(f1, f2, f3, f4, 4);
}

void BezierPathCanvas::setupHalfLengthPath(float f1,
                                           float f2,
                                           float f3,
                                           float f4)
{
  dotDivisionsPerStroke = baseDivisionsPerStroke / 2;
  setupDividedLengthPath(f1, f2, f3, f4, 2);
}

void BezierPathCanvas::setupFullLengthPath(float f1,
                                           float f2,
                                           float f3,
                                           float f4)
{
  dotDivisionsPerStroke = baseDivisionsPerStroke;
    
  // In order to spread more coverage near the edges of the canvas, we need to 
  // increase the size of the canvas. Multiply both height and width by 
  // sqrt(2), ie double the size of the canvas
    
  int virtualSize = getSize() * 2;
  int virtualWidth = (int)(getWidth() * ROOT2);
  int offset = (virtualWidth - getWidth()) / 2;
    
  // 1st end point
  int pixelIndex = (int)(f1 * virtualSize);
  endPoint1.x = (float)(pixelIndex % virtualWidth) - offset;
  endPoint1.y = (float)(pixelIndex / virtualWidth) - offset;
    
  // 2nd end point
  pixelIndex = (int)(f2 * virtualSize);
  endPoint2.x = (float)(pixelIndex % virtualWidth) - offset;
  endPoint2.y = (float)(pixelIndex / virtualWidth) - offset;
    
  // 1st control point
  pixelIndex = (int)(f3 * virtualSize);
  controlPoint1.x = (float)(pixelIndex % virtualWidth) - offset;
  controlPoint1.y = (float)(pixelIndex / virtualWidth) - offset;
    
  // 2nd control point
  pixelIndex = (int)(f4 * virtualSize);
  controlPoint2.x = (float)(pixelIndex % virtualWidth) - offset;
  controlPoint2.y = (float)(pixelIndex / virtualWidth) - offset;
}

// Apply paint
void BezierPathCanvas::applyPaint()
{
  //applySpotBrush();
  //applyAirBrush();
  if (reader->getLineArtThickness())
    applyPixelTip();
  else
    applyPencilTip();
}

// Apply channel matching on a color and return a new color
HSV BezierPathCanvas::applyChannelMatching(HSV color, Coord c)
{
  if (getTarget()->isImportant(getDataOffset(c)))
  {
    color.s = matchSat(c, color.s);
    color.v = matchVal(c, color.v);
  }
  /*
  else
  {
    if (targetSatGradient(c) >= reader->getSatCannyHi())
      color.s = matchSat(c, color.s);
        
    if (targetValGradient(c) >= reader->getValCannyHi())
      color.v = matchVal(c, color.v);
  }
  */
    
  color.h = matchHue(c, color.h);
    
  return color;
}

/*
 * (1-t)^3 * endPoint1          +
 * 3t(1-t)^2 * controlPoint1    +
 * 3t^2(1-t) * controlPoint2    +
 * t^3 * endPoint2
 */
Coord BezierPathCanvas::getCurrentCoord(int i)
{
  float t = (float)(i) / dotDivisionsPerStroke;
    
  Coord ep1, ep2, cp1, cp2;
  float e1; // (1 - t)^3
  float c1; // 3t(1 - t)^2
  float c2; // 3t^2(1-t)
  float e2; // t^3
    
  e1 = (1.0f - t) * (1.0f - t) * (1.0f - t);
  c1 = 3 * t * (1.0f - t) * (1.0f - t);
  c2 = 3 * t * t * (1.0f - t);
  e2 = t * t * t;
    
  ep1.x = e1 * endPoint1.x;
  ep1.y = e1 * endPoint1.y;
    
  ep2.x = e2 * endPoint2.x;
  ep2.y = e2 * endPoint2.y;
    
  cp1.x = c1 * controlPoint1.x;
  cp1.y = c1 * controlPoint1.y;
    
  cp2.x = c2 * controlPoint2.x;
  cp2.y = c2 * controlPoint2.y;
    
  Coord ret;
    
  ret.x = ep1.x + ep2.x + cp1.x + cp2.x;
  ret.y = ep1.y + ep2.y + cp1.y + cp2.y;

  return ret;
}

void BezierPathCanvas::applyPixelTip()
{
  for (int i = 0; i <= dotDivisionsPerStroke; i++)
    writePixel(getCurrentCoord(i), baseColor);
}

void BezierPathCanvas::applyPencilTip()
{
  Coord current;
  HSV color = baseColor;
    
  for (int i = 0; i <= dotDivisionsPerStroke; i++)
  {
    current = getCurrentCoord(i);
        
    for (int dx = -1; dx <= 1; dx++)
    {
      for (int dy = -1; dy <= 1; dy++)
      {
        Coord spotPixel = {current.x + dx, current.y + dy};
            
        if (!insideCanvas(spotPixel))
          continue;
                
        /*
        int index = dx*dx + dy*dy;
        float alpha[] = {1.00f, 0.5f, 0.25f};

        if (index != 0)
          color = mixPixels(spotPixel, baseColor, alpha[index]);
            
        color = applyChannelMatching(color, spotPixel);
        */
        writePixel(spotPixel, color);
      }
    }
  }
}

void BezierPathCanvas::applyAirBrush()
{
  Coord current;
  HSV color = baseColor;
    
  int offset = 7;
  for (int i = 0; i <= dotDivisionsPerStroke; i++)
  {
    current = getCurrentCoord(i);
        
    for (int dx = -offset; dx <= offset; dx++)
    {
      for (int dy = -offset; dy <= offset; dy++)
      {
        Coord spotPixel = {current.x + dx, current.y + dy};
                
        if (!insideCanvas(spotPixel))
          continue;
                
        int index = dx * dx / 4 + dy * dy / 4 + 1;
                
        int r = rand() % index;
                
        if (r > 1)
          continue;
        else
        {
          color = mixPixels(spotPixel, baseColor, 0.5);
          color = applyChannelMatching(color, spotPixel);
          writePixel(spotPixel, color);
        }
      }
    }
  }
}

void BezierPathCanvas::applySpotBrush()
{
  Coord current;
  HSV color;
    
  for (int i = 0; i <= dotDivisionsPerStroke; i++)
  {
    current = getCurrentCoord(i);
        
    /*
    if (i == divisions)
    {
      printCoord(endPoint1);
      printCoord(controlPoint1);
      printCoord(controlPoint2);
      printCoord(endPoint2);
      printCoord(current);
      cout << endl;
    }
    */
        
    for (int dx = -3; dx<= 3; dx++)
    {
      for (int dy = -3; dy <= 3; dy++)
      {
        Coord spotPixel = {current.x + dx, current.y + dy};
                
        if (!insideCanvas(spotPixel))
          continue;
                
        int index = dx * dx + dy * dy;
                
        switch (index)
        {
          case 18:
            continue;
                        
          case 13:
            color = mixPixels(spotPixel, baseColor, 0.1);
            break;
                        
          case 10:
            color = mixPixels(spotPixel, baseColor, 0.21);
            break;
                        
          case 9:
            color = mixPixels(spotPixel, baseColor, 0.25);
            break;
                        
          case 8:
            color = mixPixels(spotPixel, baseColor, 0.29);
            break;
                        
          case 5:
            color = mixPixels(spotPixel, baseColor, 0.44);
            break;
                        
          case 4:
            color = mixPixels(spotPixel, baseColor, 0.5);
            break;
                        
          case 2:
            color = mixPixels(spotPixel, baseColor, 0.65);
            break;
                        
          case 1:
            color = mixPixels(spotPixel, baseColor, 0.75);
            break;
                        
          case 0:
            color = baseColor;
        }

        color = applyChannelMatching(color, spotPixel);
        writePixel(spotPixel, color);
      }
    }
  }
}

// Reset the canvas
void BezierPathCanvas::resetCanvas()
{
  ColorConverter cc;
  int h = getHeight();
  int w = getWidth();

  if (reader->getUsingAdaptiveCanvas())
  {
    for (int y = 0; y < h; y++)
    {
      for (int x = 0; x < w; x++)
      {
        Coord c = {x, y};
        RGB rgb = bestCanvas->getRGBPixel(c);
        HSV hsv = cc.rgb2hsv(rgb);
        setRGBData(y * getWidth() + x, rgb);
        setHSVData(y * getWidth() + x, hsv);
      }
    }
  }
  else
  {
    const color_t bg = getBGColor();
    RGB rgb = {bg, bg, bg};
    HSV hsv = cc.rgb2hsv(rgb);
    
    const int size = getSize();
    for (int i = 0; i < size; i++)
    {
      setRGBData(i, rgb);
      setHSVData(i, hsv);
    }
  }
    
  resetNumDrawNodes();
    
  setHSVFitnessH(0.0f);
  setHSVFitnessS(0.0f);
  setHSVFitnessV(0.0f);
}

/*
 * Write a pixel in HSV color space
 */
void BezierPathCanvas::writePixel(Coord c, HSV color)
{
  if (!insideCanvas(c))
    return;
    
  setHSVData(getDataOffset(c), color);
}

HSV BezierPathCanvas::mixPixels(Coord coord, HSV strokeHSV, float alpha)
{
  ColorConverter cc;
    
  HSV canvasHSV = getHSVData(getDataOffset(coord));
  RGB canvasRGB = cc.hsv2rgb(canvasHSV);
  RGB strokeRGB = cc.hsv2rgb(strokeHSV);
    
  RGB newRGB;
  newRGB.r = (int)(strokeRGB.r * alpha + canvasRGB.r * (1 - alpha));
  newRGB.g = (int)(strokeRGB.g * alpha + canvasRGB.g * (1 - alpha));
  newRGB.b = (int)(strokeRGB.b * alpha + canvasRGB.b * (1 - alpha));

  HSV ret = cc.rgb2hsv(newRGB);
  return ret;
}

void BezierPathCanvas::printCoord(Coord c)
{
  cout << " {" << c.x << "," << c.y << "}";
}

void BezierPathCanvas::computeFitness()
{
  int option = reader->getLineArtColorMode();

  if (option == 2 || option == 3)
  {
    //cout << "DEBUG: computing HSV fitness\n";
    computeHSVFitness();
  }
  else
  {
    //cout << "DEBUG: computing BOOLEAN fitness\n";
    computeBooleanFitness();
  }
}

float BezierPathCanvas::getFitness()
{
  int option = reader->getLineArtColorMode();

  if (option == 2 || option == 3)
    return (hsvFitnessH + hsvFitnessS + hsvFitnessV) / 3.0f;

  return booleanFitness;
}

/*
 * Assign fitness according to the following conditions:
 * painted on       Punishment
 * Black            Black   0
 * White            White   0
 * Black            White   1.0
 * White            Black   this::whiteToBlack 
 */
void BezierPathCanvas::computeBooleanFitness()
{
  float ret = 0.0f;
  int width = getWidth();
  int height = getHeight();

  for (int y = 0; y < height; y++)
  {
    for (int x = 0; x < width; x++)
    {
      Coord c = {x, y};
      HSV targetPixel = getTarget()->getHSV(c);
      HSV canvasPixel = getHSVData(getDataOffset(c));

      bool bt = (targetPixel.v == 0) ? false : true;
      bool bc = (canvasPixel.v == 0) ? false : true;
        
      if (! bt && bc)
        ret += whiteToBlack;
      else if (bt && ! bc)
        ret += 1.0f;
    }
  }

  ret /= getSize();

  booleanFitness = ret;
}

