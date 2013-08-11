/*
 * Header file
 * Class:        Prog4
 * Date created: 2007-09-22
 * Written by:   Pasquale Barile
 *
 * Based on code written by Dylan Mawhinney
 *
 * Prog2 accepts three functions and executes both of them in order
 */

#ifndef PROG4_H
#define PROG4_H

class GPConfig;

#include <string>
#include "Function.h"
#include "ReturnFunc.h"
#include "ReturnRoot.h"
#include "GPConfig.h"

class Prog4 : public Function
{
public:
  // Constructor
  Prog4(GPConfig* conf);

  // Virtual destructor
  virtual ~Prog4();

  static Function* generate(const string &name, GPConfig *conf);

  // Evaluate function
  virtual void evaluate(ReturnData* out);

  // Copies this function and return a pointer to the new copy
  virtual Node* copy();
};

#endif // PROG4_H
