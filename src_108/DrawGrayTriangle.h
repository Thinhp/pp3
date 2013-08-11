/*
 * Header file
 * Class:        DrawGrayTriangle
 * Date created: 28 Feb 2010
 * Written by:   Ashkan Izadi
 *
 * To draw a Gray triangle, we need to get 6 Arguments (r=g=b) 
 */

#ifndef DRAW_GRAY_TRIANGLE_H
#define DRAW_GRAY_TRIANGLE_H

class GPConfig;

#include <string>
#include <iostream> 
#include <math.h>
#include "Function.h"
#include "ReturnFunc.h"
#include "ReturnFloat.h"
#include "BezierPathCanvas.h"

extern Canvas* canvas;

class DrawGrayTriangle : public Function
{
private:

public:
  // Constructor
  DrawGrayTriangle(GPConfig* conf);

  // Virtual destructor
  virtual ~DrawGrayTriangle();

  // Generate function
  static Function* generate(const string &name, GPConfig* conf);

  // Evaluate function
  virtual void evaluate(ReturnData* out);

  // Copies this function and its arguments and returns a pointer to the new
  // copy.
  virtual Node* copy();

};

#endif // DRAW_GRAY_TRIANGLE_H
