/*
 * Definition file
 * Class:        Prog2
 * Date created: 2007-09-20
 * Written by:   Pasquale Barile
 *
 * Based on code written by Dylan Mawhinney
 *
 * Output type: ReturnFunc
 * Input type:  ReturnFunc
 */

using namespace std;
#include "Prog2.h"

Prog2::Prog2(GPConfig* conf): Function(ReturnFunc::TYPENUM, 2, "prog2", conf)
{
  for (int i = 0; i < maxArgs; i++)
    setArgNReturnType(i, ReturnFunc::TYPENUM);
}

Prog2::~Prog2()
{
}

Function* Prog2::generate(const string &name, GPConfig* conf)
{
  if (name == "" || name == "prog2")
    return new Prog2(conf);

  return NULL;
}

void Prog2::evaluate(ReturnData* out)
{
  if (out->getTypeNum() != ReturnFunc::TYPENUM)
    throw string("Prog2::evaluate : incorrect data type");

  for (int i = 0; i < maxArgs; i++)
  {
    if (getArgNReturnType(i) != getArgN(i)->getReturnType())
      throw string("Prog2::evaluate : Argument has incorrect type");
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

Node* Prog2::copy()
{
  int i;
  Function* tmp = new Prog2(config);

  if (tmp == NULL)
    throw string("Prog2::copy() Error, out of memory");

  for (i = 0; i < getMaxArgs(); i++)
    tmp->setArgN(i, getArgN(i)->copy());

  return dynamic_cast<Node *>(tmp);
}

