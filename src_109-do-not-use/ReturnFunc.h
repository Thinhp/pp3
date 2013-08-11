/*
 * Header file
 * Class:        ReturnFunc
 * Date created: 2007-09-21
 * Written by:   Pasquale Barile
 *
 * ReturnFunc is a derived class of ReturnData. It provides a mechanism for 
 * function nodes, but not terminal nodes, to be input to ProgN nodes.
 */

#ifndef RETURNFUNC_H
#define RETURNFUNC_H

#include "ReturnData.h"

class ReturnFunc : public ReturnData
{
private:
  float data; // The data assigned to or computed for this object

  // sets the TYPENUM to be the type id for this class
  virtual void initTypeNum();

public:
  static const int TYPENUM;

  ReturnFunc();
  virtual ~ReturnFunc();

  void setData(float num);   // Set the data to num
  float getData() const;     // Get the data of this object
};

#endif // RETURNFUNC_H
