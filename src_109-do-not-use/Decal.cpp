/*
 * Class:  Decal
 * Author: Pasquale Barile
 *
 * See header file for details
 */

using namespace std;
#include "Decal.h"

Decal::Decal(ConfigReader* reader, int width, int height) : reader(reader)
{
  baseCoord.x = 0.0f;
  baseCoord.y = 0.0f;
}

Decal::~Decal() { }

// Set the initial location for this decal
void Decal::setLocation(float x, float y)
{
  baseCoord.x = x;
  baseCoord.y = y;
}

// Set decal color
void Decal::setColor(float r, float g, float b)
{
  RGB rgb = { (color_t)(r * 256), (color_t)(g * 256), (color_t)(b * 256) };
  ColorConverter cc;
  hsv = cc.rgb2hsv(rgb);
}
