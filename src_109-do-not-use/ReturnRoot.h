/*
 * Header file
 * Class:        ReturnRoot
 * Date created: 2008-06-18
 * Written by:   Perry Barile
 */

#ifndef RETURN_ROOT_H
#define RETURN_ROOT_H

#include "ReturnData.h"

class ReturnRoot : public ReturnData
{
private:
  float data; // The data assigned to or computed for this object

  // sets the TYPENUM to be the type id for this class
  virtual void initTypeNum();

public:
  static const int TYPENUM;

  ReturnRoot();
  virtual ~ReturnRoot();

  void setData(float num);   // Set the data to num
  float getData() const;     // Get the data of this object
};

#endif // RETURN_ROOT_H
