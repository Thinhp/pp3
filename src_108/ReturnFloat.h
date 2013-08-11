/*
 * Header file
 * Class:        ReturnFloat
 * Date created: 2007-09-12
 * Written by:   Pasquale Barile
 *
 * ReturnFloat is a derived class of ReturnData. It represents a float 
 * returned from a GP node.
 */

#ifndef RETURNFLOAT_H
#define RETURNFLOAT_H

#include "ReturnData.h"

class ReturnFloat : public ReturnData
{
private:
  float data; //The data for this class 

  // sets the typeNum to be the typeid of the class
  virtual void initTypeNum();

public:
  static const int TYPENUM;

  ReturnFloat();
  virtual ~ReturnFloat();

  void setData(float num); // set the data to num
  float getData() const; // get the data of this class
};

#endif // RETURNFLOAT_H
