/*
 * Definition
 * Class:        Draw6
 * Date created: 2007-09-10
 * Written by:   Pasquale Barile
 *
 * See header file for details
 */

using namespace std;
#include "Draw6.h"

Draw6::Draw6(GPConfig* conf) :
Function(ReturnFunc::TYPENUM, 6, "Draw6", conf)
{
  for (int i = 0; i < maxArgs; i++)
    setArgNReturnType(i, ReturnFloat::TYPENUM);
}

Draw6::~Draw6()
{
}

Function* Draw6::generate(const string &name, GPConfig* conf)
{
  if (name == "" || name == "Draw6")
    return new Draw6(conf);
    
  return NULL;
}

void Draw6::evaluate(ReturnData* out)
{
  if (out->getTypeNum() != ReturnFunc::TYPENUM)
    throw string("Draw6::evaluate, incorrect ReturnData type");
    
  for (int i = 0; i < maxArgs; i++)
  {
    if (getArgNReturnType(i) != getArgN(i)->getReturnType())
    throw string("Draw6::evaluate Error argument has incorrect return type");
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

Node* Draw6::copy()
{
  Function* tmp = new Draw6(config);
    
  if (tmp == NULL)
    throw string("Draw6::copy() Error, out of memory");
    
  for (int i = 0; i < getMaxArgs(); i++)
    tmp->setArgN(i, getArgN(i)->copy());
    
  return dynamic_cast<Node *>(tmp);
}

