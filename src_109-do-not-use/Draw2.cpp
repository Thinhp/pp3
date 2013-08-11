/*
 * Definition
 * Class:        Draw2
 * Date created: Oct 18 2008
 * Written by:   Pasquale Barile
 *
 * See header file for details
 * 
 */

using namespace std;
#include "Draw2.h"

Draw2::Draw2(GPConfig* conf) :
Function(ReturnFunc::TYPENUM, 2, "Draw2", conf)
{
  for (int i = 0; i < maxArgs; i++)
    setArgNReturnType(i, ReturnFloat::TYPENUM);
}

Draw2::~Draw2()
{
}

Function* Draw2::generate(const string &name, GPConfig* conf)
{
  if (name == "" || name == "Draw2")
    return new Draw2(conf);
    
  return NULL;
}

void Draw2::evaluate(ReturnData* out)
{
  if (out->getTypeNum() != ReturnFunc::TYPENUM)
    throw string("Draw2::evaluate, incorrect ReturnData type");
    
  for (int i = 0; i < maxArgs; i++)
  {
    if (getArgNReturnType(i) != getArgN(i)->getReturnType())
      throw string("Draw2::evaluate Error argument has incorrect return type");
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

Node* Draw2::copy()
{
  Function* tmp = new Draw2(config);
    
  if (tmp == NULL)
    throw string("Draw2::copy() Error, out of memory");
    
  for (int i = 0; i < getMaxArgs(); i++)
    tmp->setArgN(i, getArgN(i)->copy());
    
  return dynamic_cast<Node *>(tmp);
}
