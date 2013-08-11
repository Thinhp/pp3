//
// Class:  ShroudCanvas
// Author: Pasquale Barile
// 

#ifndef SHROUD_CANVAS_H
#define SHROUD_CANVAS_H

#include <iostream>
#include <cstdio>
#include "Canvas.h"
#include "ConfigReader.h"
#include "BestCanvas.h"
#include "Utility.h"
#include "Pixel.h"

class ShroudCanvas : public Canvas
{
private:
  RGB* shroud;

  ConfigReader* reader; // Defined elsewhere

  // Start point
  Coord startPoint;

  // Draw angle
  float theta;
    
  // Line length 
  int lineLength;

  // Line color
  RGB lineColor;
		
  // Fitness
  float fitnessRGB, fitnessR, fitnessG, fitnessB; 

  // Increment the count of drawing nodes executed -- for statistical purposes
  void newNode() { incrementLines(); }
    
  // Apply a stroke
  void applyPaint();
  void applyFastShroud(Coord c, RGB lineColor);
  void applyBlend();
  void applyNoPixel();
  void applyNoStroke();
  void applyStopStroke();

  // Write a pixel in RGB color space
  void writePixel(Coord, RGB);
    
  // Keep compiler happy
  void writePixel(Coord, HSV) {}
    
  // Mix two pixels with an alpha value in {0,1}
  RGB mixPixels(Coord, RGB, float);
  
  // Print a Coord
  void printCoord(Coord);

public:
  ShroudCanvas(Target* t, color_t r, color_t g, color_t b, BestCanvas* bc,
      ConfigReader* reader);
  ShroudCanvas() {}
  ~ShroudCanvas();
	
  // Paint the canvas
  void paintCanvas(vector<float>);

  // Reset the canvas
  void resetCanvas();
	
  // Compute fitness
  void computeFitness();
	
  float getFitness() { return fitnessRGB; }

  // Save this canvas to a file
  bool saveImage(char* filename) { return saveRGBImage(filename); }
};

#endif // SHROUD_CANVAS_H
