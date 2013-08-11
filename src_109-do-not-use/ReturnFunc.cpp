/*
 * Definition
 * Class:        ReturnFunc
 * Date created: 2007-09-21
 * Written by:   Pasquale Barile
 *
 * See header file for details
 */

#include "ReturnFunc.h"

const int ReturnFunc::TYPENUM = 1;

ReturnFunc::ReturnFunc() : ReturnData(), data(0.0)
{
  initTypeNum();
}

ReturnFunc::~ReturnFunc()
{
}

void ReturnFunc::initTypeNum()
{
  setTypeNum(ReturnFunc::TYPENUM);
}

void ReturnFunc::setData(float num)
{
  data = num;
}

float ReturnFunc::getData() const
{
  return data;
}
