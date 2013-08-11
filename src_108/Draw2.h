/*
 * Header file
 * Class:        Draw2
 * Date created: Oct 18 2008
 * Written by:   Perry Barile
 *
 * This is a GP Draw function that takes 2 terminal arguments
 */

#ifndef DRAW2_H
#define DRAW2_H

class GPConfig;

#include <string>
#include <iostream> 
#include <math.h>
#include "Function.h"
#include "ReturnFunc.h"
#include "ReturnFloat.h"
#include "Canvas.h"

extern Canvas* canvas;

class Draw2 : public Function
{
private:

public:
  // Constructor
  Draw2(GPConfig* conf);

  // Virtual destructor
  virtual ~Draw2();

  // Generate function
  static Function* generate(const string &name, GPConfig* conf);

  // Evaluate function
  virtual void evaluate(ReturnData* out);

  // Copies this function and its arguments and returns a pointer to the new
  // copy.
  virtual Node* copy();
};

#endif // DRAW2_H
