/*
 * Definition file
 * Class:        Prog3
 * Date created: 2007-09-22
 * Written by:   Pasquale Barile
 *
 * Based on code written by Dylan Mawhinney
 *
 * Output type: ReturnFunc
 * Input type:  ReturnFunc
 */

using namespace std;
#include "Prog3.h"

Prog3::Prog3(GPConfig* conf) : Function(ReturnFunc::TYPENUM, 3, "prog3", conf)
{
  for (int i = 0; i < maxArgs; i++)
    setArgNReturnType(i, ReturnFunc::TYPENUM);
}

Prog3::~Prog3()
{
}

Function* Prog3::generate(const string &name, GPConfig* conf)
{
  if (name == "" || name == "prog3")
    return new Prog3(conf);

  return NULL;
}

void Prog3::evaluate(ReturnData* out)
{
  if (out->getTypeNum() != ReturnFunc::TYPENUM)
    throw string("Prog3::evaluate : incorrect data type");

  for (int i = 0; i < maxArgs; i++)
  {
    if (getArgNReturnType(i) != getArgN(i)->getReturnType())
      throw string("Prog3::evaluate : Argument has incorrect type");
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

Node* Prog3::copy()
{
  int i;
  Function* tmp = new Prog3(config);

  if (tmp == NULL)
    throw string("Prog3::copy() Error, out of memory");

  for (i = 0; i < getMaxArgs(); i++)
    tmp->setArgN(i, getArgN(i)->copy());

  return dynamic_cast<Node *>(tmp);
}

