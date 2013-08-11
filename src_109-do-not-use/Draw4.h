/*
 * Header file
 * Class:        Draw4
 * Date created: Oct 18 2008
 * Written by:   Perry Barile
 *
 * This is a GP Draw function that takes 4 terminal arguments
 */

#ifndef DRAW4_H
#define DRAW4_H

class GPConfig;

#include <string>
#include <iostream> 
#include <math.h>
#include "Function.h"
#include "ReturnFunc.h"
#include "ReturnFloat.h"
#include "Canvas.h"

extern Canvas* canvas;

class Draw4 : public Function
{
private:

public:
  // Constructor
  Draw4(GPConfig* conf);

  // Virtual destructor
  virtual ~Draw4();

  // Generate function
  static Function* generate(const string &name, GPConfig* conf);

  // Evaluate function
  virtual void evaluate(ReturnData* out);

  // Copies this function and its arguments and returns a pointer to the new
  // copy.
  virtual Node* copy();
};

#endif // DRAW4_H
