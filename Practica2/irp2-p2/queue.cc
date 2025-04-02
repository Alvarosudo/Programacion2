// NIF: 74389742-Z
// NOMBRE: QUILES RUIZ, ALVARO ANTONIO
#include "queue.h"
#include "lib/error.h"


QueuePtr queueCreate  (){
    QueuePtr cola;
    cola= new Queue;
    cola->l.head=nullptr;

    return cola;
}

void queueEnqueue (QueuePtr q, Element x){
    uint64_t tamano= listSize(&q->l);
    listInsert(&q->l, x, tamano+1);

}

Element  queueHead    (QueuePtr q){
    Element cabeza;
    if(q->l.head != nullptr){
        cabeza= q->l.head->key;
    }else{
        set_error(1);
    }

    return cabeza;
}

Element  queueDequeue (QueuePtr q){
    Element cabeza= ' ';
    if(q->l.head != nullptr){
        cabeza= q->l.head->key;
        listRemove(&q->l,1);
    }else{
        set_error(1);
    }

    return cabeza;
}


bool queueEmpty   (QueuePtr q){
    return q->l.head == nullptr;
}