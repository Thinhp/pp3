/*
 * Class:  DecalCanvas
 * Author: Pasquale Barile
 *
 * See header file for details.
 *
 */

using namespace std;

#include "DecalCanvas.h"

extern Palette* palette;

DecalCanvas::DecalCanvas(Target* t, color_t r, color_t g, color_t b,
    BestCanvas* bc, ConfigReader* reader) : Canvas(t, r, g, b, bc),
  reader(reader)
{
  decal = new Decal(reader, getWidth(), getHeight());

  const int size = getSize();
  bgCanvas = new HSV[size];

  computeStroke();
}

DecalCanvas::~DecalCanvas()
{
  delete decal;
  delete bgCanvas;
  delete strokeArea;
}

// Apply some paint to the canvas by drawing some lines
// Expect 2 floats in the argument vector
void DecalCanvas::paintCanvas(vector<float> v)
{
  const unsigned ARGS = 2;
  assert(v.size() == ARGS);
  float args[ARGS];
    
  for (unsigned i = 0; i < ARGS; i++)
    args[i] = v.at(i);
    
  newNode();

  // Determine starting x,y
  int pixelIndex = (int)(args[0] * getSize());
  float x = (float)(pixelIndex % getWidth());
  float y = (float)(pixelIndex / getWidth());
    
  decal->setLocation(x, y);
  HSV hsv = palette->getRandomHSV(args[1]);
  decal->setColor(hsv);

  applyPaint();
}

// Apply paint
void DecalCanvas::applyPaint()
{
  Coord location = decal->getLocation();

  for (int y = 0; y < strokeHeight; y++)
  {
    for (int x = 0; x < strokeWidth; x++)
    {
      Coord c = {location.x + x, location.y + y};
      // Adjust Coord to centre the stroke
      c.x -= strokeWidth/2;
      c.y -= strokeHeight/2;

      if (!insideCanvas(c))
        continue;

      int alphaValue = strokeArea[y * strokeWidth + x];
			
      if (alphaValue > 0)
      {
        HSV color;

        // Apply the alpha value to the new color and the current color
        ColorConverter cc;

        HSV currentHSV = getHSVData(getDataOffset(c));
        RGB currentRGB = cc.hsv2rgb(currentHSV);
        RGB colorRGB = cc.hsv2rgb(decal->getHSV());

        int rDiff = colorRGB.r - currentRGB.r;
        int gDiff = colorRGB.g - currentRGB.g;
        int bDiff = colorRGB.b - currentRGB.b;

        float alpha = (float)alphaValue / 100.0f;
        colorRGB.r = (int)(currentRGB.r + (rDiff * alpha));
        colorRGB.g = (int)(currentRGB.g + (gDiff * alpha));
        colorRGB.b = (int)(currentRGB.b + (bDiff * alpha));

        color = cc.rgb2hsv(colorRGB);

        // Now apply color calculations
        if (getTarget()->isImportant(getDataOffset(c)))
        {
          color.s = matchSat(c, color.s);
          color.v = matchVal(c, color.v);
        }
        else
        {
          bool satEdge = (targetSatGradient(c) >= reader->getSatCannyHi());
          bool valEdge = (targetValGradient(c) >= reader->getValCannyHi());

          if (satEdge)
            color.s = matchSat(c, color.s);

          if (valEdge) 
            color.v = matchVal(c, color.v);
        }

        color.h = matchHue(c, color.h);
   
        writePixel(c, color);
      }
    }
  }
}

// Reset the canvas
void DecalCanvas::resetCanvas()
{
  ColorConverter cc;
    
  if (reader->getUsingAdaptiveCanvas())
  {
    for (int y = 0; y < getHeight(); y++)
    {
      for (int x = 0; x < getWidth(); x++)
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
    RGB rgb = bgColor;
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
void DecalCanvas::writePixel(Coord c, HSV color)
{
  if (!insideCanvas(c))
    return;

  setHSVData(getDataOffset(c), color);
}

// Write a pixel in RGB color space
void DecalCanvas::writePixel(Coord c, RGB newColor)
{
  if (!insideCanvas(c))
    return;

  const int offset = getDataOffset(c);

  RGB rgbTarget = targetPixelRGB(c);
  RGB rgbCanvas = getRGBData(offset);

  // Compute best red channel
  int tcr = abs(rgbTarget.r - rgbCanvas.r);
  int tnr = abs(rgbTarget.r - newColor.r);

  // Compute best green channel
  int tcg = abs(rgbTarget.g - rgbCanvas.g);
  int tng = abs(rgbTarget.g - newColor.g);

  // Compute best blue channel
  int tcb = abs(rgbTarget.b - rgbCanvas.b);
  int tnb = abs(rgbTarget.b - newColor.b);

  if (tcr < tnr)
    newColor.r = rgbCanvas.r;

  if (tcg < tng)
    newColor.g = rgbCanvas.g;

  if (tcb < tnb)
    newColor.b = rgbCanvas.b;

  setRGBData(offset, newColor);
}

// Return whether a saturation or value channel is 255 in the local
// Moore neighbourhood
bool DecalCanvas::edgeFound(Coord c, HSV_CHANNEL chan)
{
  for (int y = -1; y <= 1; y++)
  {
    for (int x = -1; x <= 1; x++)
    {
      Coord cc = {c.x + x, c.y + y};
         
      if (insideCanvas(cc))
      {
        if (chan == VAL && targetValGradient(cc) > 40)
          return true;

        if (chan == SAT && targetSatGradient(cc) > 60)
          return true;
      }
    }
  }
  return false;
}

// Rotate decal bristles to match decal orientation
Coord DecalCanvas::rotateBristles(Coord c, float dx, float dy, float theta)
{
  Coord ret;

  const float cost = cos(theta);
  const float sint = sin(theta);
  const float x = dx * cost - dy * sint;
  const float y = dx * sint + dy * cost;

  ret.x = c.x + x;
  ret.y = c.y + y;

  return ret;
}

// Pre-compute the shape of a decal stroke
void DecalCanvas::computeStroke()
{
  RGB *decalRGBData = NULL;
    
  string fName = "decals/" + reader->getCustomDecalFileName() + ".png";
    
  unsigned sWidth, sHeight;
  read_image(fName.c_str(), (color_t**)&decalRGBData, &sWidth, &sHeight);
  strokeWidth = (int)sWidth;
  strokeHeight = (int)sHeight;
    
  const int size = strokeWidth * strokeHeight;
  strokeArea = new int[size];
    
  ColorConverter cc;
    
  for (int i = 0; i < size; i++)
  {
    HSV hsvColor = cc.rgb2hsv(decalRGBData[i]);
    strokeArea[i] = 100 - hsvColor.v;
  }
    
  delete decalRGBData;
}

