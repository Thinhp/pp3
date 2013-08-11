/*
 * Definition 
 * Class:        ReturnFloat
 * Date created: 2007-09-12
 * Written by:   Pasquale Barile
 *
 * See header file for details
 */

#include "ReturnFloat.h"

const int ReturnFloat::TYPENUM = 2;

ReturnFloat::ReturnFloat() : ReturnData(), data(0.0)
{
  initTypeNum();
}

ReturnFloat::~ReturnFloat()
{
}

void ReturnFloat::initTypeNum()
{
  setTypeNum(ReturnFloat::TYPENUM);
} 

void ReturnFloat::setData(float num)
{
  data = num;
}

float ReturnFloat::getData() const
{
  return data;
}

