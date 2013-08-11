/*
 * Definition
 * Class:        ReturnRoot
 * Date created: 2008-06-18
 * Written by:   Perry Barile
 *
 * See header file for details
 */

#include "ReturnRoot.h"

const int ReturnRoot::TYPENUM = 0;

ReturnRoot::ReturnRoot() : ReturnData(), data(0.0)
{
  initTypeNum();
}

ReturnRoot::~ReturnRoot()
{
}

void ReturnRoot::initTypeNum()
{
  setTypeNum(ReturnRoot::TYPENUM);
}

void ReturnRoot::setData(float num)
{
  data = num;
}

float ReturnRoot::getData() const
{
  return data;
}

