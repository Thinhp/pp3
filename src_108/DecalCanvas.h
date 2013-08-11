/*
 * Class:  DecalCanvas
 * Author: Pasquale Barile
 *
 */

#ifndef DECAL_CANVAS_H
#define DECAL_CANVAS_H

#include <iostream>
#include <cstdio>
#include "Canvas.h"
#include "Decal.h"
#include "ConfigReader.h"
#include "BestCanvas.h"
#include "Palette.h"

class DecalCanvas : public Canvas
{
private:
  Decal* decal;   // The decal 
  HSV* bgCanvas;
  ConfigReader* reader; // Defined elsewhere
  int strokeWidth, strokeHeight;
  int *strokeArea; // Pre-computed array of a decal stroke

  // Increment the count of drawing nodes executed -- just for statistical
  // purposes
  void newNode() { incrementLines(); }

  // Rotate decal bristles to match decal orientation
  Coord rotateBristles(Coord c, float dx, float dy, float theta);

  // Apply a decal stroke
  void applyPaint();

  // Write a pixel in RGB color space
  void writePixel(Coord, RGB);

  // Write a pixel in HSV color space
  void writePixel(Coord, HSV);

  // Return whether a saturation or value channel is 255 in the local
  // Moore neighbourhood
  bool edgeFound(Coord c, HSV_CHANNEL chan);

public:
  DecalCanvas(Target* t, color_t bg, BestCanvas* bc, ConfigReader* reader);
  ~DecalCanvas();

  // Paint the canvas
  void paintCanvas(vector<float>);

  // Reset the canvas
  void resetCanvas();

  // Return a pointer to the decal
  Decal* getDecal() { return decal; }

  // Pre-compute a decal stroke
  void computeStroke(); // Calls one of the following methods
    
  // Compute fitness
  void computeFitness() { computeHSVFitness(); }
    
  // Return fitness
  float getFitness() { return (hsvFitnessH + hsvFitnessS + hsvFitnessV) / 3; }
    
  // Save this canvas to a file
  bool saveImage(char* filename) { return saveHSVImage(filename); }
};

#endif // DECAL_CANVAS_H
