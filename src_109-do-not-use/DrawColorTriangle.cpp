/*
 * Definition
 * Class:        DrawColorTriangle
 * Date created: 03 March 2010
 * Written by:   Ashkan Izadi
 *
 */

using namespace std;
#include "DrawColorTriangle.h"

DrawColorTriangle::DrawColorTriangle(GPConfig* conf) :
Function(ReturnFunc::TYPENUM, 8, "DrawColorTriangle", conf)
{
  for (int i = 0; i < maxArgs; i++)
    setArgNReturnType(i, ReturnFloat::TYPENUM);
}

DrawColorTriangle::~DrawColorTriangle()
{
}

Function* DrawColorTriangle::generate(const string &name, GPConfig* conf)
{
  if (name == "" || name == "DrawColorTriangle")
    return new DrawColorTriangle(conf);
    
  return NULL;
}

void DrawColorTriangle::evaluate(ReturnData* out)
{
  if (out->getTypeNum() != ReturnFunc::TYPENUM)
    throw string("DrawColorTriangle::evaluate, incorrect ReturnData type");
    
  for (int i = 0; i < maxArgs; i++)
  {
    if (getArgNReturnType(i) != getArgN(i)->getReturnType())
      throw string("DrawColorTriangle::evaluate Error argument has incorrect return type");
  }
    
  float ret = 0;
  vector<float> v;
    
  for (int i = 0; i < maxArgs; i++)
  {
    ReturnFloat rf;
    getArgN(i)->evaluate(&rf);
    float f = rf.getData();
    v.push_back(f);
    ret += f;
    if (ret > 1.0f)
      ret--;
  }
    
  canvas->paintCanvas(v);
  dynamic_cast<ReturnFunc *>(out)->setData(ret);
}

Node* DrawColorTriangle::copy()
{
  Function* tmp = new DrawColorTriangle(config);
    
  if (tmp == NULL)
    throw string("DrawColorTriangle::copy() Error, out of memory");
    
  for (int i = 0; i < getMaxArgs(); i++)
    tmp->setArgN(i, getArgN(i)->copy());
    
  return dynamic_cast<Node *>(tmp);
}

