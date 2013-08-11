/*
 * Definition
 * Class:        Draw4
 * Date created: Oct 18 2008
 * Written by:   Pasquale Barile
 *
 * See header file for details
 * 
 */

using namespace std;
#include "Draw4.h"

Draw4::Draw4(GPConfig* conf) :
Function(ReturnFunc::TYPENUM, 4, "Draw4", conf)
{
  for (int i = 0; i < maxArgs; i++)
    setArgNReturnType(i, ReturnFloat::TYPENUM);
}

Draw4::~Draw4()
{
}

Function* Draw4::generate(const string &name, GPConfig* conf)
{
  if (name == "" || name == "Draw4")
    return new Draw4(conf);
    
  return NULL;
}

void Draw4::evaluate(ReturnData* out)
{
  if (out->getTypeNum() != ReturnFunc::TYPENUM)
    throw string("Draw4::evaluate, incorrect ReturnData type");
    
  for (int i = 0; i < maxArgs; i++)
  {
    if (getArgNReturnType(i) != getArgN(i)->getReturnType())
      throw string( "Draw4::evaluate Error argument has incorrect return type");
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
  dynamic_cast<ReturnFunc*>(out)->setData(ret);
}

Node* Draw4::copy()
{
  Function* tmp = new Draw4(config);
    
  if (tmp == NULL)
    throw string("Draw4::copy() Error, out of memory");
    
  for (int i = 0; i < getMaxArgs(); i++)
    tmp->setArgN(i, getArgN(i)->copy());
    
  return dynamic_cast<Node *>(tmp);
}

