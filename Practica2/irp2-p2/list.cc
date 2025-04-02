// NIF: 74389742-Z
// NOMBRE: QUILES RUIZ, ALVARO ANTONIO
#include "list.h"

ListNodePtr listNodeCreate (Element e){
    ListNodePtr nodo =new ListNode;
    nodo->key = e;
    nodo->next = nullptr;
    return nodo;
}

  
ListPtr listCreate (){
    ListPtr lista = new List;
    lista->head=nullptr;

    return lista;
}


void listInit (ListPtr l){
    l->head= new ListNode;
    Element e= ' ';
    l->head= listNodeCreate(e);

}

bool listInsert (ListPtr l, Element x, Position i){
    bool insertado= false;
    ListNodePtr aux= l->head;
    Position contador= 1;
    ListNodePtr ayuda;
    //Terminar condiciones
    if(i<1){
        return false;
    }
    while(aux != nullptr ){
        if(contador == i){
            ayuda= aux;
            aux= listNodeCreate(x);
            aux->next= ayuda;
            insertado= true;
            break;

        }else{
            if(aux->next == nullptr){
                aux->next= listNodeCreate(x);
                insertado= true;
                break;
            }
            aux= aux->next;
            contador++;
        }
    }
    
    
    return insertado;
}

Position listLocate (ListPtr l, Element x){
    Position encontrado= 1;
    ListNodePtr aux= l->head;
    
    while(aux != nullptr ){
        if(aux->key == x){
            return encontrado;

        }else{
            aux= aux->next;
            encontrado++;
        }
    }

    return NOPOS;
}

ListNodePtr listRetrieve  (ListPtr l, Position i){
    Position contador= 1;
    ListNodePtr aux= l->head;
    
    while(aux != nullptr ){
        if(contador == i){
            return aux;

        }else{
            aux= aux->next;
            contador++;
        }
    }

    return nullptr;    
}

bool listRemove (ListPtr l, Position p){
    bool eliminado= false;
    ListNodePtr aux1= l->head;
    Position contador= 2;
    ListNodePtr aux2= aux1->next;
    //Mirar posibilidad de la primera posicion
    if(p == 1){
        l->head=aux1->next;
        delete aux1;
        return true;
    }


    while(aux2 != nullptr ){
        if(contador == p){
            aux1->next= aux2->next;
            delete aux2;
            eliminado= true;
            break;

        }else{
            aux1= aux1->next;
            aux2= aux2->next;
            contador++;
        }
    }
    
    
    return eliminado;

}

void listMakeNull (ListPtr l){
    ListNodePtr aux1=  l->head;
    while(aux1 != nullptr){
        ListNodePtr aux2= l->head;
        aux1= aux1->next;
        delete aux2;
    }
    l->head= nullptr;
}


ListNodePtr listFirst (ListPtr l){
    return l->head;
}


uint64_t listSize  (ListPtr l){
    uint64_t elementos= 0;
    ListNodePtr aux1= l->head;
    while(aux1 != nullptr){
        elementos++;
        aux1= aux1->next;
    }
    return elementos;
}