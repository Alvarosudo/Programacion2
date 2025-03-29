//stack.cc
#include "stack.h"


StackPtr stackCreate (){
    StackPtr pila = new Stack;
    //pila->l= *listCreate(); //Por que le tengo que poner * 
    pila->l.head = nullptr; //Por que .head
    //Inicializa la cabeza a nullptr para indicar que la lista esta vacia
    return pila;
}