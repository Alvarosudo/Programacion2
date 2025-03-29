//stack.cc
#include "stack.h"
#include "lib/error.h"


StackPtr stackCreate (){
    StackPtr pila = new Stack;
    //pila->l= *listCreate(); //Por que le tengo que poner * 
    pila->l.head = nullptr; //Por que .head
    //Inicializa la cabeza a nullptr para indicar que la lista esta vacia
    return pila;
}


void stackPush (StackPtr s, Element x){
    listInsert(&s->l, x, 1);
}


Element  stackTop (StackPtr s){
    Element top;
    if(s->l.head != nullptr){
        top= s->l.head->key;
    }else{
       set_error(1); 
    }

    return top;
}


Element  stackPop (StackPtr s){
    Element cabeza;

    if(s->l.head != nullptr){
        cabeza= s->l.head->key;
        listRemove(&s->l, 1);
    }else{
        set_error(1);
        cabeza= ' ';
    }

    return cabeza;
}


bool     stackEmpty  (StackPtr s){
    bool vacio=false;
    if(s->l.head == nullptr){
        vacio= true;
    }
    return vacio;
}