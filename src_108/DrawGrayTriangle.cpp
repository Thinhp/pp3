/*
 * Definition
 * Class:        DrawGrayTriangle
 * Date created: 28 Feb 2010
 * Written by:   Ashkan Izadi
 *
 */

using namespace std;
#include "DrawGrayTriangle.h"

DrawGrayTriangle::DrawGrayTriangle(GPConfig* conf) :
Function(ReturnFunc::TYPENUM, 6, "DrawGrayTriangle", conf)
{
  for (int i = 0; i < maxArgs; i++)
    setArgNReturnType(i, ReturnFloat::TYPENUM);
}

DrawGrayTriangle::~DrawGrayTriangle()
{
}

Function* DrawGrayTriangle::generate(const string &name, GPConfig* conf)
{
  if (name == "" || name == "DrawGrayTriangle")
    return new DrawGrayTriangle(conf);
    
  return NULL;
}

void DrawGrayTriangle::evaluate(ReturnData* out)
{
  if (out->getTypeNum() != ReturnFunc::TYPENUM)
    throw string("DrawGrayTriangle::evaluate, incorrect ReturnData type");
    
  for (int i = 0; i < maxArgs; i++)
  {
    if (getArgNReturnType(i) != getArgN(i)->getReturnType())
    throw string("DrawGrayTriangle::evaluate, incorrect return type");
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

Node* DrawGrayTriangle::copy()
{
  Function* tmp = new DrawGrayTriangle(config);
    
  if (tmp == NULL)
    throw string("DrawGrayTriangle::copy() Error, out of memory");
    
  for (int i = 0; i < getMaxArgs(); i++)
    tmp->setArgN(i, getArgN(i)->copy());
    
  return dynamic_cast<Node *>(tmp);
}

