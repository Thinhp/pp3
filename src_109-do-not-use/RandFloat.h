/*
 * Header file
 * Class:        RandFloat
 * Date created: 2007-09-17
 * Written by:   Pasquale Barile
 *
 * RandFloat is a derived class of Terminal. It represents a random float valued
 * terminal. Its value is determined at time of construction
 */

#ifndef RANDFLOAT_H
#define RANDFLOAT_H

class GPConfig;

#include <string>
#include <cstdio> // For sprintf
#include <iostream>
#include <string>
#include "Terminal.h"
#include "GPConfig.h"
#include "ReturnFloat.h"

class RandFloat : public Terminal
{
private:
  float value; // The data for this class

public:
  RandFloat(GPConfig* conf);
  explicit RandFloat(float initValue, GPConfig* conf);
  virtual ~RandFloat();

  static Terminal* generate(const string &name, GPConfig* conf);

  virtual void evaluate(ReturnData* out);
  virtual void print(string &s);

  // Copies this terminal and returns a pointer to the copy
  virtual Node* copy();
};

#endif // RANDFLOAT_H
