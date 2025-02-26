// -*- mode: c++ -*-
// Compilar con --std=c++17 o superior

#ifndef LIST
#define LIST

#include <cstdint>
#include <string>

///////////////////////////////////////////////////////////////////////////////
//                 Typedefs/Using + Declaraciones adelantadas                //
///////////////////////////////////////////////////////////////////////////////
using Element = char; // Hasta que veamos genericidad usaremos estos
                      // typedef.
using Position = int64_t;
const Position NOPOS = -1;

struct ListNode;
using  ListNodePtr = ListNode*;

///////////////////////////////////////////////////////////////////////////////
//                                    Node                                   //
///////////////////////////////////////////////////////////////////////////////
struct ListNode {
  Element key;
  ListNodePtr next;
};

ListNodePtr listNodeCreate (Element e);
static std::string listNodeToString (ListNodePtr p) {
  std::string s;
  return s + p->key;
}

///////////////////////////////////////////////////////////////////////////////
//                                    List                                   //
///////////////////////////////////////////////////////////////////////////////
struct List;
using  ListPtr = List*;

struct List {
  ListNodePtr head;
};

// Constructor por defecto
ListPtr listCreate        ();

// Inicializacion de datos a valores seguros
void listInit             (ListPtr l);

// Insert
bool listInsert           (ListPtr l, Element x, Position i);

// Locate
Position listLocate       (ListPtr l, Element x);

// Retrieve
ListNodePtr listRetrieve  (ListPtr l, Position i);

// Elimina el elemento en la posicion p
bool listRemove           (ListPtr l, Position p);

// Vacia la lista
void listMakeNull         (ListPtr l);

// Primer elemento
ListNodePtr listFirst     (ListPtr l);

// Devuelve la lista como una cadena usando 'c' como separador
[[maybe_unused]]
static std::string listToString (ListPtr l, char c) {
  std::string s;

  for (ListNodePtr n = l->head; n != nullptr; n = n->next)
    s += c + listNodeToString (n);

  return s;
}

// Devuelve el número de elementos en la lista
uint64_t listSize         (ListPtr l);

#endif
