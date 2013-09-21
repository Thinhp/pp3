/*
 * Header file
 * Class:        DrawGrayEllipse
 * Date created: 19/9/2013
 * Written by:   Tan Thinh
 *
 * To draw a Gray eclipse, we need to get 5 Arguments (r=g=b) 
 */

#ifndef DRAW_GRAY_ELLIPSE_H
#define DRAW_GRAY_ELLIPSE_H

class GPConfig;

#include <string>
#include <iostream> 
#include <math.h>
#include "Function.h"
#include "ReturnFunc.h"
#include "ReturnFloat.h"
#include "BezierPathCanvas.h"

extern Canvas* canvas;

class DrawGrayEllipse : public Function
{
private:

public:
  // Constructor
  DrawGrayEllipse(GPConfig* conf);

  // Virtual destructor
  virtual ~DrawGrayEllipse();

  // Generate function
  static Function* generate(const string &name, GPConfig* conf);

  // Evaluate function
  virtual void evaluate(ReturnData* out);

  // Copies this function and its arguments and returns a pointer to the new
  // copy.
  virtual Node* copy();

};

#endif // DRAW_GRAY_ELLIPSE_H
