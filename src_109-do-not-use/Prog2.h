/*
 * Header file
 * Class:        Prog2
 * Date created: 2007-09-20
 * Written by:   Pasquale Barile
 *
 * Based on code written by Dylan Mawhinney
 *
 * Prog2 accepts two functions and executes both of them in order
 */

#ifndef PROG2_H
#define PROG2_H

class GPConfig;

#include <string>
#include <iostream>
#include <math.h>
#include "Function.h"
#include "ReturnFunc.h"
#include "GPConfig.h"

class Prog2 : public Function
{
private:

public:
  // Constructor
  Prog2(GPConfig* conf);

  // Virtual destructor
  virtual ~Prog2();

  static Function* generate(const string &name, GPConfig *conf);

  // Evaluate function
  virtual void evaluate(ReturnData* out);

  // Copies this function and return a pointer to the new copy
  virtual Node* copy();
};

#endif // PROG2_H
