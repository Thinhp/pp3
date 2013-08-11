/*
 * Class:  Triangle
 * Author: Ashkan Izadi
 * Date: 25 Feb 2010
 *
 */

#ifndef TRIANGEL_H
#define TRIANGEL_H

#include <iostream>
#include <cstdio>
#include "Canvas.h"
#include "ConfigReader.h"
#include "BestCanvas.h"
#include "Utility.h"
#include "Pixel.h"


class Triangle : public Canvas
{
private:
  float rgbFitnessR,rgbFitnessG,rgbFitnessB;
  RGB* triangle;

  Target* target; // Target image

  HSV* hsvData; // Canvas image data in HSV color mode

  // Start point
  Coord startPoint, crossPoint, endPointSecondLine;
    
  // Draw angle /or Angles for other shapes
  float theta,theta1,theta2, theta3;
    
  // Line length 
  int lineLength;
  float lineLength1, lineLength2, lineLength3;
	
  // Fitness
  float selectedFitness;

  int width, height, numPixels; // numPixel = width * height

  // Increment the count of drawing nodes executed -- just for statistical
  // purposes
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

protected:
  ConfigReader* reader; 
	
public:
  Triangle(Target* t, color_t bg, BestCanvas* bc, ConfigReader* reader);
  Triangle(Target* t, color_t bg_Red, color_t bg_Green, color_t bg_Blue,
      BestCanvas* bc, ConfigReader* reader);
	
  ~Triangle();

  // Line color Original
  RGB lineColor;

  //for fast shroud colour full Scale(Whole Pixels)
  void fastColourTechnique3(RGB targetPixel, RGB canvasPixel, RGB lineColor,
      Coord c);
	
  //for fast shroud colour full Scale(Best Cahnnel)
  void fastColourTechnique2(RGB targetPixel, RGB canvasPixel, RGB lineColor,
      Coord c );
	
  //for fast shroud Gray Scale
  void fastGrayTechnique(RGB targetPixel, RGB canvasPixel, RGB lineColor,
      Coord c);
	
  // Paint the canvas
  void paintCanvas(vector<float>);

  // Reset the canvas
  void resetCanvas();
	
  //To swap between gray and colour full scale to reset a canvas
  void swipResetConvas(RGB rgb);
	
  // Compute proper fitness
  void computeFitness() { computeSelectedFitness(); }
	
  // Perform proper fitness evaluation
  void computeSelectedFitness();
   
  // Perform grayscale fitness evaluation
  void computeGrayFitness();
   
  // Perform clourfull fitness evaluation
  void computeColourFitness();
    
  float getFitness() { return selectedFitness; }
	    
  // Save this canvas to a file
  bool saveImage(char* filename) { return saveRGBImage(filename); }
	
  bool applyTriangle();

  void applyFastShroud(Coord c,RGB lineColor);
		
  bool flagDraw;

  int line1, line2, line3;
	
  bool barycentric(Coord c);
  void fillUpTriangle(float,float,float,float);

  /*LOG file
  ofstream shroudlogFile;
  int numberGrayFitness;
  void setNumberGrayFitness(int numbern){ numberGrayFitness = numbern;}
  int getNumberGrayFitness(){return numberGrayFitness;}
  int numberCircule;
  void writeLogShroudCanvas(float r,float maxTarget, float minTarget,
      int number);//, int minCanvas, int maxCanvas, int number);
  void setNumberCircule(int newNumberCircule){numberCircule=newNumberCircule;}
  int getNumberCircule(){return numberCircule;}
  */
};

#endif // TRIANGEL_H
