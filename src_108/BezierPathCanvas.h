/*
 * Class:  BezierPathCanvas
 * Author: Pasquale Barile
 *
 */

#ifndef BEZIER_PATH_CANVAS_H
#define BEZIER_PATH_CANVAS_H

#include <iostream>
#include <cstdio>
#include "Canvas.h"
#include "Decal.h"
#include "ConfigReader.h"
#include "BestCanvas.h"
#include "Palette.h"

class BezierPathCanvas : public Canvas
{
private:
  HSV* bgCanvas;

  ConfigReader* reader; // Defined elsewhere
    
  // End points
  Coord endPoint1, endPoint2;
    
  // Control points
  Coord controlPoint1, controlPoint2;
    
  // Stroke base color
  HSV baseColor;
    
  // Boolean fitness
  float booleanFitness;

  float whiteToBlack;
  float whiteToRed;
    
  // The number of evenly spaced dots to draw along the length of the path
  int baseDivisionsPerStroke; // The default
  int dotDivisionsPerStroke;

  // Increment the count of drawing nodes executed -- just for statistical
  // purposes
  void newNode() { incrementLines(); }
    
  // Setup different length paths
  void setupQuarterLengthPath(float, float, float, float);
  void setupHalfLengthPath(float, float, float, float);
  void setupFullLengthPath(float, float, float, float);
  void setupDividedLengthPath(float, float, float, float, int);
    
  // Apply a stroke
  void applyPaint();

  // Write a pixel in HSV color space
  void writePixel(Coord, HSV);
    
  // Mix two pixels with an alpha value in {0,1}
  HSV mixPixels(Coord, HSV, float);
    
  void applySpotBrush();
  void applyAirBrush();
  void applyPencilTip();
  void applyPixelTip();
    
  // Calculate where a coordinate is along the bezier path
  Coord getCurrentCoord(int i);
    
  // Apply channel matching on a color and return a new color
  HSV applyChannelMatching(HSV, Coord);
    
  void printCoord(Coord);

public:
  BezierPathCanvas(Target* t, color_t bg, BestCanvas* bc, ConfigReader* reader);
  ~BezierPathCanvas();

  // Paint the canvas
  void paintCanvas(vector<float>);
  
  // Reset the canvas
  void resetCanvas();

  // Compute fitness
  void computeFitness();
    
  // Perform boolean fitness evaluation
  void computeBooleanFitness();

  float getFitness();
    
  // Save this canvas to a file
  bool saveImage(char* filename) { return saveHSVImage(filename); }
};

#endif // BEZIER_PATH_CANVAS_H
