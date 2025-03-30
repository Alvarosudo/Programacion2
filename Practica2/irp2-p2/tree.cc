#include"tree.h"


/*  1: Is vacio?
    2:Existe Hijo Derecho?
    3:Comprobar ruta(menor->izquierda ; mayor->derecha ; si es igual no se inserta)
    
bool PtrActual=t->root;
while(PtrActual){
    3>6
    actual=right->root;
    3<6
    actual=left->root;
    3==6
    fin
}
*/

//Funciones de Tree Node

TreePtr treeCreate (){
    TreePtr arbol= new Tree;
    arbol->root=nullptr;
    return arbol;
}

TreePtr treeNodeLeftSibling  (TreeNodePtr p){
    return &p->lefts;
}

TreePtr treeNodeRightSibling  (TreeNodePtr p){
    return &p->rights;
}

Element&  treeNodeKey (TreeNodePtr p){
    return p->key;
}


bool treeNodeIsLeaf (TreeNodePtr p){
    return (p->lefts.root == nullptr) && (p->rights.root == nullptr);
}

//Funciones de Tree


TreePtr treeCreate (){
    TreePtr arbol= new Tree;
    arbol->root=nullptr;

    return arbol;
}

void treeDestroy (TreePtr t){
    if(t->root != nullptr){
        treeDestroy(&t->root->lefts); //Acceder recursivamente al subarbol izquierdo
        treeDestroy(&t->root->rights); //Acceder recursivamente al subarbol derecho
        delete t->root; //Eliminar el nodo del subarbol
    }else{
        delete t; //Elimina finalmente el arbol cuando ya no quedan hijos
    }
}


TreeNodePtr& treeRoot (TreePtr t){
    return t->root;
}

bool treeEmpty (TreePtr t){
    return t == nullptr || t->root == nullptr;
    //t->root == nullptr problema si t == nullptr
    //para esto se agrega la siguiente condicion t==nullptr
    //si primero se verifica t->root se causa un segmentation fault
}

bool treeInsert (TreePtr t, Element x){
    bool insertado=true;

    if(treeEmpty(t)){
        t->root = treeNodeCreate(x); //Si no existe arbol se crea el nodo raíz
    }else{
        if(t->root->key == x){
            return false; //Si el elemento ya existe devuelve falso
        }else if(t->root->key < x){ //Si es mas pequeño lo envia hacia el lado izquierdo
            if(t->root->lefts.root == nullptr){   
                t->root->lefts.root = treeNodeCreate(x); //En caso de que no exista nodo lo creo
            }else{
                //Si existe el nodo se vuelve a llamar a la funcion para que compruebe ese subarbol
                insertado =treeInsert(&t->root->lefts, x); 
            }
        }else{ //Si es mas grande lo envia hacia el lado derecho
            if(t->root->rights.root == nullptr){
                t->root->rights.root = treeNodeCreate(x);
            }else{
                insertado =treeInsert(&t->root->rights, x);
            }
        }
    }
    return insertado;
}

 
bool treeRemove (TreePtr t, Element x){ 
//Al eliminar un nodo, el elemento mas pequeño del subarbol derecho se convierte en el neuvo nodo
}