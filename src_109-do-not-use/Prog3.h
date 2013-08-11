/*
 * Header file
 * Class:        Prog3
 * Date created: 2007-09-22
 * Written by:   Pasquale Barile
 *
 * Based on code written by Dylan Mawhinney
 *
 * Prog2 accepts three functions and executes both of them in order
 */

#ifndef PROG3_H
#define PROG3_H

class GPConfig;

#include <string>
#include "Function.h"
#include "ReturnFunc.h"
#include "ReturnRoot.h"
#include "GPConfig.h"

class Prog3 : public Function
{
public:
  // Constructor
  Prog3(GPConfig* conf);

  // Virtual destructor
  virtual ~Prog3();

  static Function* generate(const string &name, GPConfig *conf);

  // Evaluate function
  virtual void evaluate(ReturnData* out);

  // Copies this function and return a pointer to the new copy
  virtual Node* copy();
};

#endif // PROG3_H
