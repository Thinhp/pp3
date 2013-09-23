/*
 * Header file
 * Class:        DrawColorEllipse
 * Date created: 03 March 2010
 * Written by:   Ashkan Izadi
 *
 * To draw a colour full a triangle, we need to get two more arguments instead
 * of 6 we have to get 8 because for colours we have R,G,B
 */

#ifndef DRAW_COLOR_ELLIPSE_H
#define DRAW_COLOR_ELLIPSE_H

class GPConfig;

#include <string>
#include <iostream> 
#include <math.h>
#include "Function.h"
#include "ReturnFunc.h"
#include "ReturnFloat.h"
#include "BezierPathCanvas.h"

extern Canvas* canvas;

class DrawColorEllipse : public Function
{
private:

public:
  // Constructor
  DrawColorEllipse(GPConfig* conf);

  // Virtual destructor
  virtual ~DrawColorEllipse();

  // Generate function
  static Function* generate(const string &name, GPConfig* conf);

  // Evaluate function
  virtual void evaluate(ReturnData* out);

  // Copies this function and its arguments and returns a pointer to the new
  // copy.
  virtual Node* copy();
};

#endif // DRAW_COLOR_ELLIPSE_H
