/*
 * Class:   Palette
 * Author:  Perry Barile
 *
 * See header file for details
 *
 */

using namespace std;
#include "Palette.h"

Palette::Palette(Target* target)
{
  set<int> intSet;

  int w = (int)target->getWidth();
  int h = (int)target->getHeight();

  for (int y = 0; y < h; y++)
  {
    for (int x = 0; x < w; x++)
    {
      Coord c = {x, y};
      HSV hsv = target->getHSV(c);
      int h = hsv.h / 6;
      int s = hsv.s / 4;
      int v = hsv.v / 5;
      h *= 6;
      s *= 4;
      v *= 5;
      int x = h * 1000000 + s * 1000 + v;
      intSet.insert(x);
    }
  }
	
  set<int>::iterator it;
  for (it = intSet.begin(); it != intSet.end(); it++)
  {
    int x = *it;
    int h = x / 1000000;
    x %= 1000000;
    int s = x / 1000;
    int v = x % 1000;
    HSV hsv = {h, s, v};
    Pixel pixel(hsv);
    colors.push_back(pixel);
  }
}

Palette::Palette(const char* filename)
{
  ifstream in(filename);
  if (!in)
  {
    cout << "Could not open Palette file. Make sure it exists.\n";
    exit(1);
  }

  string line, hex;

  while(getline(in, line))
  {
    std::istringstream currentLine(line, std::istringstream::in);
    currentLine >> hex;
    ColorConverter cc;
    RGB rgb = cc.hex2rgb(hex);
    HSV hsv = cc.rgb2hsv(rgb);
    colors.push_back(hsv);
  }

  cout << "*****" << endl;
  cout << "Palette file: " << filename << endl;
  cout << colors.size() << " colours loaded." << endl;
  cout << "*****" << endl;
}

Palette::~Palette()
{
}

RGB Palette::getRandomRGB(float f)
{
  unsigned index = (unsigned)(colors.size() * f);
  HSV hsv = colors.at(index).getHSV();
  ColorConverter cc;
  return cc.hsv2rgb(hsv);
}

HSV Palette::getRandomHSV(float f)
{
  unsigned index = (unsigned)(colors.size() * f);
  HSV hsv = colors.at(index).getHSV();
  return hsv;
}
