/*
 * Header file
 * Class:        Draw6
 * Date created: Oct 18 2008
 * Written by:   Pasquale Barile
 *
 * This is a GP Draw function that takes 6 arguments
 */

#ifndef DRAW6_H
#define DRAW6_H

class GPConfig;

#include <string>
#include <iostream> 
#include <math.h>
#include "Function.h"
#include "ReturnFunc.h"
#include "ReturnFloat.h"
#include "BezierPathCanvas.h"

extern Canvas* canvas;

class Draw6 : public Function
{
private:

public:
  // Constructor
  Draw6(GPConfig* conf);

  // Virtual destructor
  virtual ~Draw6();

  // Generate function
  static Function* generate(const string &name, GPConfig* conf);

  // Evaluate function
  virtual void evaluate(ReturnData* out);

  // Copies this function and its arguments and returns a pointer to the new
  // copy.
  virtual Node* copy();
};

#endif // DRAW6_H
