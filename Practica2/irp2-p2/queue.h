// -*- mode: c++ -*-
// Compilar con --std=c++17 o superior

#ifndef QUEUE
#define QUEUE

#include <cstdint>
#include <string>

#include "list.h"

///////////////////////////////////////////////////////////////////////////////
//                 Typedefs/Using + Declaraciones adelantadas                //
///////////////////////////////////////////////////////////////////////////////
using Element = char; // Hasta que veamos genericidad usaremos estos
                      // typedef.

///////////////////////////////////////////////////////////////////////////////
//                                   Queue                                   //
///////////////////////////////////////////////////////////////////////////////
struct Queue {
  List l;
};

using QueuePtr = Queue*;

QueuePtr queueCreate  ();
void     queueEnqueue (QueuePtr q, Element x);
Element  queueHead    (QueuePtr q);
Element  queueDequeue (QueuePtr q);
bool     queueEmpty   (QueuePtr q);

[[maybe_unused]]
static std::string queueToString (QueuePtr q, char c) {
  return listToString (&q->l, c);
}

#endif
