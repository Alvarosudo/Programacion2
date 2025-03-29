// -*- mode: c++ -*-
// Compilar con --std=c++17 o superior

#ifndef STACK
#define STACK

#include <cstdint>
#include <string>

#include "list.h"


///////////////////////////////////////////////////////////////////////////////
//                 Typedefs/Using + Declaraciones adelantadas                //
///////////////////////////////////////////////////////////////////////////////
using Element = char; // Hasta que veamos genericidad usaremos estos
                      // typedef.

///////////////////////////////////////////////////////////////////////////////
//                                   Stack                                   //
///////////////////////////////////////////////////////////////////////////////
struct Stack {
  List l;
};

using StackPtr = Stack*;

StackPtr stackCreate ();
void     stackPush   (StackPtr s, Element x);
Element  stackTop    (StackPtr s);
Element  stackPop    (StackPtr s);
bool     stackEmpty  (StackPtr s);

[[maybe_unused]]
static std::string stackToString (StackPtr s, char c) {
  return listToString (&s->l, c);
}

#endif
