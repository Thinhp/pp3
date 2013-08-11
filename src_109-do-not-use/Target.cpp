/*
 * Class:   Target
 * Author:  Pasquale Barile
 *
 * See header file for details
 *
 */

using namespace std;
#include "Target.h"

extern string outputDir;

Target::Target(const char* targetFile, const char* maskFile, int satT1,
    int satT2, int valT1, int valT2, bool fuzzyEdges) : rgbData(NULL),
  hsvData(NULL), rgbMaskData(NULL), hsvMaskData(NULL), satEdgeMap(NULL),
  valEdgeMap(NULL), st1(satT1), st2(satT2), vt1(valT1), vt2(valT2),
  fuzzy(fuzzyEdges)
{
  read_image(targetFile, (color_t**)&rgbData, &width, &height);
  read_image(maskFile, (color_t**)&rgbMaskData, &width, &height);
  numPixels = width * height;
  const unsigned size = numPixels;

  hsvData = new HSV[size];
  hsvMaskData = new HSV[size];
  RGB* satMap = new RGB[size];
  RGB* valMap = new RGB[size];

  ColorConverter cc;

  for (unsigned i = 0; i < size; i++)
  {
	  hsvData[i] = cc.rgb2hsv(rgbData[i]); 
    hsvMaskData[i] = cc.rgb2hsv(rgbMaskData[i]); 
  }

  reducePalette();

  // Re-write the target
  for (unsigned i = 0; i < size; i++)
    rgbData[i] = cc.hsv2rgb(hsvData[i]);

	string targetOut = outputDir;
	targetOut.append("target.png");
	
	string satOut = outputDir;
	satOut.append("sat.png");
	
	string valOut = outputDir;
	valOut.append("val.png");
	
	string satEdgeOut = outputDir;
	satEdgeOut.append("satEdgeMap.png");
	
	string valEdgeOut = outputDir;
	valEdgeOut.append("valEdgeMap.png");
	
  write_image(targetOut.c_str(), (color_t*)rgbData, width, height);

  for (unsigned i = 0; i < size; i++)
  {
	  color_t satColor = (color_t)((float)(hsvData[i].s) / 100.0f * 255);
	  color_t valColor = (color_t)((float)(hsvData[i].v) / 100.0f * 255);

    RGB satRGB = {satColor, satColor, satColor};
    satMap[i] = satRGB;
      
    RGB valRGB = {valColor, valColor, valColor};
    valMap[i] = valRGB;
  }

  write_image(satOut.c_str(), (color_t*)satMap, width, height);
  write_image(valOut.c_str(), (color_t*)valMap, width, height);

  // Saturation map
  satEdgeMap = new Canny(satMap, width, height, st1, st2, fuzzy);
  satEdgeMap->saveImage(satEdgeOut);
  delete satMap;

  // Value map
  valEdgeMap = new Canny(valMap, width, height, vt1, vt2, fuzzy);
  valEdgeMap->saveImage(valEdgeOut);
  delete valMap;
}

// Reduce the palette by scanning the three channels in every pixel and as a
// unique value is found, it is added to the relevant set.
void Target::reducePalette()
{
  for (unsigned i = 0; i < numPixels; i++)
  {
    hueSet.insert(hsvData[i].h);
    satSet.insert(hsvData[i].s);
    valSet.insert(hsvData[i].v);
  }
}

// Delete any objects that may have been initialised
Target::~Target()
{
  if (rgbData != NULL)       { delete rgbData; }
  if (hsvData != NULL)       { delete hsvData; }
  if (satEdgeMap != NULL)    { delete satEdgeMap; }
  if (valEdgeMap != NULL)    { delete valEdgeMap; }
  if (rgbMaskData != NULL) { delete rgbMaskData; }
  if (hsvMaskData != NULL) { delete hsvMaskData; }
}

// Return an HSV pixel from this image's palette range
HSV Target::getPaletteHSV(float f1, float f2, float f3)
{
  int hueValue = (int)(f1 * 360);
  int satValue = (int)(f2 * 100);
  int valValue = (int)(f3 * 100);

  int hit = *(hueSet.upper_bound(hueValue)) - 1;
  int sit = *(satSet.upper_bound(satValue)) - 1;
  int vit = *(valSet.upper_bound(valValue)) - 1;

  HSV ret = {hit, sit, vit};
  return ret;
}

// Return a pixel in RGB space
RGB Target::getRGB(Coord c) 
{ 
  int offset = (int)c.y * width + (int)c.x;
  return rgbData[offset];
}

// Return a pixel in HSV space
HSV Target::getHSV(Coord c) 
{ 
  int offset = (int)c.y * width + (int)c.x;
  return hsvData[offset];
}

// Return local hue, saturation, value
int Target::getHue(Coord c) 
{ 
  int offset = (int)c.y * width + (int)c.x;
  return hsvData[offset].h; 
}

int Target::getSat(Coord c) 
{ 
  int offset = (int)c.y * width + (int)c.x;
  return hsvData[offset].s; 
}

int Target::getVal(Coord c) 
{ 
  int offset = (int)c.y * width + (int)c.x;
  return hsvData[offset].v; 
}

// Return whether a coordinate is inside a black region in the mask data
bool Target::isImportant(int offset)
{
  return (hsvMaskData[offset].v == 0);
}

// Over-ride normal behaviour for custom purposes
void Target::override(int n)
{
  if (rgbData) { delete rgbData; }
  if (hsvData) { delete hsvData; }
  if (satEdgeMap) { delete satEdgeMap; }
  if (valEdgeMap) { delete valEdgeMap; }
  if (rgbMaskData) { delete rgbMaskData; }
  if (hsvMaskData) { delete hsvMaskData; }

  char source[45], mask[45];
  sprintf(source, "input/blend_%d.png", n);
  sprintf(mask, "input/blend_%d_mask.png", n);

  cout << source << "\t" << mask << endl;

  read_image(source, (color_t**)&rgbData, &width, &height);
  read_image(mask, (color_t**)&rgbMaskData, &width, &height);

  numPixels = width * height;
  const unsigned size = numPixels;

  hsvData = new HSV[size];
  hsvMaskData = new HSV[size];
  RGB* satMap = new RGB[size];
  RGB* valMap = new RGB[size];

  ColorConverter cc;

  //smooth();

  for (unsigned i = 0; i < size; i++)
  {
    hsvData[i] = cc.rgb2hsv(rgbData[i]); 
    hsvMaskData[i] = cc.rgb2hsv(rgbMaskData[i]); 
  }

  reducePalette();

  // Re-write the target
  for (unsigned i = 0; i < size; i++)
    rgbData[i] = cc.hsv2rgb(hsvData[i]);

  write_image("output/target.png", (color_t*)rgbData, width, height);

  for (unsigned i = 0; i < size; i++)
  {
    color_t satColor = (color_t)((float)(hsvData[i].s) / 100.0f * 255);
    color_t valColor = (color_t)((float)(hsvData[i].v) / 100.0f * 255);

    RGB satRGB = {satColor, satColor, satColor};
    satMap[i] = satRGB;
      
    RGB valRGB = {valColor, valColor, valColor};
    valMap[i] = valRGB;
  }

  write_image("output/sat.png", (color_t*)satMap, width, height);
  write_image("output/val.png", (color_t*)valMap, width, height);

  // Saturation map
  satEdgeMap = new Canny(satMap, width, height, st1, st2, fuzzy);
  satEdgeMap->saveImage("output/satEdgeMap.png");
  delete satMap;

  // Value map
  valEdgeMap = new Canny(valMap, width, height, vt1, vt2, fuzzy);
  valEdgeMap->saveImage("output/valEdgeMap.png");
  delete valMap;
}

