/*
 * Definition file
 * Class:        Prog4
 * Date created: 2007-09-22
 * Written by:   Pasquale Barile
 *
 * Based on code written by Dylan Mawhinney
 *
 * Output type: ReturnFunc
 * Input type:  ReturnFunc
 */

using namespace std;
#include "Prog4.h"

Prog4::Prog4(GPConfig* conf) : Function(ReturnFunc::TYPENUM, 4, "prog4", conf)
{
  for (int i = 0; i < maxArgs; i++)
    setArgNReturnType(i, ReturnFunc::TYPENUM);
}

Prog4::~Prog4()
{
}

Function* Prog4::generate(const string &name, GPConfig* conf)
{
  if (name == "" || name == "prog4")
    return new Prog4(conf);

  return NULL;
}

void Prog4::evaluate(ReturnData* out)
{
  if (out->getTypeNum() != ReturnFunc::TYPENUM)
    throw string("Prog4::evaluate : incorrect data type");

  for (int i = 0; i < maxArgs; i++)
  {
    if (getArgNReturnType(i) != getArgN(i)->getReturnType())
      throw string("Prog4::evaluate : Argument has incorrect type");
  }
   
  float ret = 0;
   
  for (int i = 0; i < maxArgs; i++)
  {
    ReturnFunc rf;
    getArgN(i)->evaluate(&rf);
    float f = rf.getData();
    ret += f;
    if (ret > 1.0f)
      ret--;
  }

  dynamic_cast<ReturnFunc *>(out)->setData(ret);
}

Node* Prog4::copy()
{
  int i;
  Function* tmp = new Prog4(config);

  if (tmp == NULL)
    throw string("Prog4::copy() Error, out of memory");

  for (i = 0; i < getMaxArgs(); i++)
    tmp->setArgN(i, getArgN(i)->copy());

  return dynamic_cast<Node *>(tmp);
}

