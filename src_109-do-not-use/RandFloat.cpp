/*
 * Definition file
 * Class:        RandFloat
 * Date created: 2007-09-17
 * Written by:   Pasquale Barile
 *
 * See header file for details
 */

using namespace std;
#include "RandFloat.h"

#include <cstring>

RandFloat::RandFloat(GPConfig* conf) :
  Terminal(ReturnFloat::TYPENUM, "float", conf),
  value(config->randomNumGenerator->randReal() * 1.0)
{
}

RandFloat::RandFloat(float initValue, GPConfig* conf) :
  Terminal(ReturnFloat::TYPENUM, "float", conf), value(initValue)
{
}

RandFloat::~RandFloat()
{
}

Terminal* RandFloat::generate(const string &name, GPConfig* conf)
{
  float tmpValue;
  string tmpName("float");
  char copy[50];
    
  strcpy(copy, name.c_str());
    
  if (name == "")
    return new RandFloat(conf);
  else if (name.compare(0, tmpName.size(), tmpName) == 0)
  {
    sscanf(copy, "float%f", &tmpValue);
    return new RandFloat(tmpValue, conf);
  }
    
  return NULL;
}

void RandFloat::evaluate(ReturnData* out)
{
  if (out->getTypeNum() != (ReturnFloat::TYPENUM))
    throw string("RandFloat::evaluate, incorrect ReturnData type");
    
  dynamic_cast<ReturnFloat *>(out)->setData(value);
}

void RandFloat::print(string &s)
{
  char str[20];
  sprintf(str, "%s%f", getName().c_str(), value);
  s.append(str);
}

Node* RandFloat::copy()
{
  Node* tmp = new RandFloat(value, config);
    
  if (tmp == NULL)
    throw string("RandFloat::copy() Error, out of memory");
    
  return tmp;
}
