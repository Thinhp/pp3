/*
 * Definition
 * Class:        DrawGrayEllipse
 * Date created: 19/9/2013
 * Written by:   Ngo Tan Thinh
 *
 */

using namespace std;
#include "DrawGrayEllipse.h"

DrawGrayEllipse::DrawGrayEllipse(GPConfig* conf) :
Function(ReturnFunc::TYPENUM, 5, "DrawGrayEllipse", conf)
{
  for (int i = 0; i < maxArgs; i++)
    setArgNReturnType(i, ReturnFloat::TYPENUM);
}

DrawGrayEllipse::~DrawGrayEllipse()
{
}

Function* DrawGrayEllipse::generate(const string &name, GPConfig* conf)
{
  if (name == "" || name == "DrawGrayEllipse")
    return new DrawGrayEllipse(conf);
    
  return NULL;
}

void DrawGrayEllipse::evaluate(ReturnData* out)
{
  if (out->getTypeNum() != ReturnFunc::TYPENUM)
    throw string("DrawGrayEllipse::evaluate, incorrect ReturnData type");
    
  for (int i = 0; i < maxArgs; i++)
  {
    if (getArgNReturnType(i) != getArgN(i)->getReturnType())
    throw string("DrawGrayEllipse::evaluate, incorrect return type");
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

Node* DrawGrayEllipse::copy()
{
  Function* tmp = new DrawGrayEllipse(config);
    
  if (tmp == NULL)
    throw string("DrawGrayEllipse::copy() Error, out of memory");
    
  for (int i = 0; i < getMaxArgs(); i++)
    tmp->setArgN(i, getArgN(i)->copy());
    
  return dynamic_cast<Node *>(tmp);
}

