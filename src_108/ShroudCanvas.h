/*
 * Class:  ShroudCanvas
 * Author: Ashkan Izadi
 * Date: 18 Dec 2010
 *
 */

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

  /***** Start of changes made by Ashkan *****/
  float rgbFitnessR, rgbFitnessG, rgbFitnessB, selectedFitness;
  Coord crossPoint, endPointSecondLine;
  Target* target;
  HSV* hsvData; // Canvas image data in HSV color mode
  int width, height, numPixels; // numPixel = width * height
  /*****   End of changes made by Ashkan *****/

  /***** Start of original *****/
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

  // Increment the count of drawing nodes executed
  // Just for statistical purposes
  void newNode() { incrementLines(); }
    
  // Apply a stroke
  void applyPaint();
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

  /*****   End of original *****/
	
public:
  /***** Start of changes made by Ashkan *****/
  ShroudCanvas(Target* t, color_t bg_Red, color_t bg_Green, color_t bg_Blue,
      BestCanvas* bc, ConfigReader* reader);

  //for fast shroud colour full Scale(Whole Pixels)
  void fastColourTechnique3(RGB targetPixel, RGB canvasPixel, RGB lineColor,
      Coord c);
	
  //for fast shroud colour full Scale(Best Cahnnel)
  void fastColourTechnique2(RGB targetPixel, RGB canvasPixel, RGB lineColor,
      Coord c);
	
  //for fast shroud Gray Scale
  void fastGrayTechnique(RGB targetPixel, RGB canvasPixel, RGB lineColor,
      Coord c);
	
  //To swap between gray and colour full scale to reset a canvas
  void swipResetConvas(RGB rgb);
	
  // Perform proper fitness evaluation
  void computeSelectedFitness();
   
  // Perform grayscale fitness evaluation
  void computeGrayFitness();
   
  // Perform clourfull fitness evaluation
  void computeColourFitness();
	
  void applyFastShroud(Coord c,RGB lineColor);
	
  /*****   End of changes made by Ashkan *****/

  /***** Start of original *****/
  ShroudCanvas(Target* t, color_t bg, BestCanvas* bc, ConfigReader* reader);
  ~ShroudCanvas();
	
  // Paint the canvas
  void paintCanvas(vector<float>);

  // Reset the canvas
  void resetCanvas();
	
  // Compute fitness
  void computeFitness() { computeSelectedFitness(); }
    
  float getFitness() { return selectedFitness; }
	 
  // Save this canvas to a file
  bool saveImage(char* filename) { return saveRGBImage(filename); }

  /*****   End of original *****/
};

#endif // SHROUD_CANVAS_H
