/*
 * Class:   Canvas
 * Author:  Pasquale Barile
 *Modified by: Ashkan Izadi
 *
 *modified Date: Nov 20 2009
 *
 * The Canvas class encapsulates image related functions and data drawn by
 * evolved programs. This is an abstract class and is extended by derived
 * classes.
 */

#ifndef CANVAS_H
#define CANVAS_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <assert.h>
#include <math.h>
#include <vector>

#include "Utility.h"
#include "png.h"
#include "util.h"
#include "Target.h"
#include "Canny.h"
#include "ColorConverter.h"
#include "Ralph.h"
#include "BestCanvas.h"
#include "ConfigReader.h"

class Canvas
{
private:
  RGB* rgbData; // Canvas image data in RGB color mode
  HSV* hsvData; // Canvas image data in HSV color mode
        
  Target* target; // Target image
        
	ConfigReader* reader; // Defined elsewhere

	// The backgound color of this image
  color_t bgColor;
    
	color_t bgColor_Red;
	color_t bgColor_Green;
	color_t bgColor_Blue;

  int numDrawNodes;
     
	int width, height, numPixels; // numPixel = width * height
        
  // Write a pixel in HSV color space
  virtual void writePixel(Coord, HSV) = 0;
  
  // Apply a brush stroke
  virtual void applyPaint() = 0;
        
  // Return an offset to the data ptr
  int dataOffset(Coord);
        
  // Compute Ralph value
  void computeRalphValue();
        
protected:
  BestCanvas* bestCanvas;

  // Fitness values
  float hsvFitnessH, hsvFitnessS, hsvFitnessV;
        
  // Reset numDrawNodes
  void resetNumDrawNodes() { numDrawNodes = 0; }
        
  // Increment the number of drawing nodes that have called this instance
  void incrementLines() { numDrawNodes++; }
        
  // Set the background color for this canvas
  void setBackground(color_t bg) { bgColor = bg; }
    
	void setBackground_Red(color_t bg) { bgColor_Red = bg; }
	void setBackground_Green(color_t bg) { bgColor_Green = bg; }
	void setBackground_Blue(color_t bg) { bgColor_Blue = bg; }

  // Simple accessors
  const color_t getBGColor() { return bgColor; }
  const color_t getbgColor_Red() { return bgColor_Red; }
	const color_t getbgColor_Green() { return bgColor_Green; }
	const color_t getbgColor_Blue() { return bgColor_Blue; }

  //	const int getDataOffset(Coord c) { return dataOffset(c); }
  Target* getTarget() { return target; }
  //RGB getRGBData(int offset) { return rgbData[offset]; }
  HSV getHSVData(int offset) { return hsvData[offset]; }
        
  // Set pixel data
  //void setRGBData(int offset, RGB pixel);
  void setHSVData(int offset, HSV pixel);
        
  // Set HSV fitness values
  void setHSVFitnessH(float f) { hsvFitnessH = f; }
  void setHSVFitnessS(float f) { hsvFitnessS = f; }
  void setHSVFitnessV(float f) { hsvFitnessV = f; }
        
  // Return the distance in degrees between two hues
  int degreesOfSeparation(int, int);
        
  // Print out an RGB pixel
  void printColor(RGB color);
        
  // Print out an HSV pixel
  void printColor(HSV color);
        
  // Target: RGB & HSV Pixels
  RGB targetPixelRGB(Coord c) { return target->getRGB(c); }
  HSV targetPixelHSV(Coord c) { return target->getHSV(c); }
        
  // Target: hue, saturation value
  int targetHue(Coord c) { return target->getHue(c); }
  int targetSat(Coord c) { return target->getSat(c); }
  int targetVal(Coord c) { return target->getVal(c); }
        
  // Target: gradients, directions
  int targetSatGradient(Coord c) { return target->getSatGradient(c); }
  int targetValGradient(Coord c) { return target->getValGradient(c); }
  float targetSatDirection(Coord c) { return target->getSatDirection(c); }
  float targetValDirection(Coord c) { return target->getValDirection(c); }
        
  // Try to match hue, sat, val
  int matchHue(Coord c, int h);
  int matchSat(Coord c, int s);
  int matchVal(Coord c, int v);
	
  // Compute / return HSV fitness values
  void computeHSVFitness();
        
public:
  Canvas(Target* t, color_t bg, BestCanvas* bc);
  Canvas(Target* t, color_t bg_Red, color_t bg_Green, color_t bg_Blue,
      BestCanvas* bc);
	//Canvas();
	virtual ~Canvas();
     
	//virtual void writeRGBPixel(Coord, RGB) = 0;
	
	// Set pixel data
  void setRGBData(int offset, RGB pixel);
    
	const int getDataOffset(Coord c) { return dataOffset(c); }
	
	RGB getRGBData(int offset) { return rgbData[offset]; }

  // Determine whether a point is inside the boundaries of the canvas
  bool insideCanvas(Coord);
        
  // Rotate a point about a 2D rotational matrix
  Coord rotate2D(Coord c, float dx, float dy, float theta);
    
	// Save this canvas to a file
  virtual bool saveImage(char* filename) = 0;
  bool saveHSVImage(char* filename);
  bool saveRGBImage(char* filename);
        
  // Reset the canvas
  virtual void resetCanvas() = 0;
        
  // Paint the canvas
  virtual void paintCanvas(vector<float>) = 0;
        
  int getNumDrawNodes() { return numDrawNodes; }
    
	virtual void computeFitness() = 0;
  virtual float getFitness() = 0;        
    
	// Simple accessor
  const int getSize() { return numPixels; }

  // Has a pixel on this canvas been written?
  bool pixelIsDirty(Coord c);

	bool pixelIsWhite(Coord c);

  void updateBestCanvas();

  const int getWidth() { return width; }
  const int getHeight() { return height; }
};

#endif // CANVAS_H
