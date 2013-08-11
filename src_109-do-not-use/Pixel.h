/*
 * Class:  Pixel
 * Author: Pasquale Barile
 *
 * The Pixel class represents the color base of a pixel. The pixel is
 * represented in the rgb model and the hsv model.
 */

#ifndef PIXEL_H
#define PIXEL_H

using namespace std;

#include <iostream>
#include <vector>
#include "Utility.h"
#include "ColorConverter.h"

class Pixel
{
private:
  RGB rgb;
  HSV hsv;
  float alpha;
  ColorConverter cc;

public:
  Pixel(RGB);
  Pixel(HSV);
  Pixel();
  ~Pixel();

  RGB getRGB() { return rgb; }
  HSV getHSV() { return hsv; }
  color_t getR() { return rgb.r; }
  color_t getG() { return rgb.g; }
  color_t getB() { return rgb.b; }
  int getH() const { return hsv.h; }
  int getS() const { return hsv.s; }
  int getV() const { return hsv.v; }

  void setColor(RGB);
  void setColor(HSV);
  void setR(color_t channel);
  void setG(color_t channel);
  void setB(color_t channel);
  void setH(int channel);
  void setS(int channel);
  void setV(int channel);

  bool operator<(const Pixel&);
  bool operator=(const Pixel&);

  void toString();
};

#endif // PIXEL_H
