/*
 * Definition
 * Class:        DrawColorEllipse
 * Date created: 22/9/2013
 * Written by:   Ngo Tan Thinh
 *
 */

using namespace std;
#include "DrawColorEllipse.h"

DrawColorEllipse::DrawColorEllipse(GPConfig* conf) :
Function(ReturnFunc::TYPENUM, 7, "DrawColorEllipse", conf)
{
  for (int i = 0; i < maxArgs; i++)
    setArgNReturnType(i, ReturnFloat::TYPENUM);
}

DrawColorEllipse::~DrawColorEllipse()
{
}

Function* DrawColorEllipse::generate(const string &name, GPConfig* conf)
{
  if (name == "" || name == "DrawColorEllipse")
    return new DrawColorEllipse(conf);
    
  return NULL;
}

void DrawColorEllipse::evaluate(ReturnData* out)
{
  if (out->getTypeNum() != ReturnFunc::TYPENUM)
    throw string("DrawColorEllipse::evaluate, incorrect ReturnData type");
    
  for (int i = 0; i < maxArgs; i++)
  {
    if (getArgNReturnType(i) != getArgN(i)->getReturnType())
      throw string("DrawColorEllipse::evaluate, incorrect return type");
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

Node* DrawColorEllipse::copy()
{
  Function* tmp = new DrawColorEllipse(config);
    
  if (tmp == NULL)
    throw string("DrawColorEllipse::copy() Error, out of memory");
    
  for (int i = 0; i < getMaxArgs(); i++)
    tmp->setArgN(i, getArgN(i)->copy());
    
  return dynamic_cast<Node *>(tmp);
}

