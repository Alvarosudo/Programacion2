// NIF: 74389742-Z
// NOMBRE: QUILES RUIZ, ALVARO ANTONIO
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
//Funcion auxiliar para encontrar el mas pequeño

TreeNodePtr& treeMenor (TreePtr t){
    
    if (t->root->lefts.root != nullptr) {
        return treeMenor(&t->root->lefts);  // Buscamos en el subárbol izquierdo
    } else {
        return t->root;  // Si no hay más hijos izquierdos, este es el menor
    }
    

}




//Funciones de Tree Node


TreeNodePtr  treeNodeCreate (Element e){

    TreeNodePtr nodo= new TreeNode;
    nodo->key=e;
    return nodo;

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
        }else if(t->root->key > x){ //Si es mas pequeño lo envia hacia el lado izquierdo
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
    TreeNodePtr menor;
    bool eliminado = true;

    if(treeEmpty(t)){
        return false; //Si el arbol esta vacio no hay nada que eliminar
    }else{
        if(t->root->key == x){ //Cuando encuentra el nodo con el elemento que es igual busca el menor
            if(treeNodeIsLeaf(t->root)){//Si no tiene hijos se elimina

                t->root = nullptr;
                delete t->root;

            }
            if(treeEmpty(&t->root->rights)){ //En caso que el nodo derecho no exista se copia el nodo izquierdo

                TreeNodePtr aux= t->root;
                t->root = t->root->lefts.root;
                delete aux;

            }else if(treeEmpty(&t->root->lefts)){ //En caso que el nodo izquierdo no exista se copia el nodo derecho

                TreeNodePtr aux= t->root;
                t->root = t->root->rights.root;
                delete aux;

            }else{ //Existen los dos nodos

                menor= treeMenor(&t->root->rights); //Copia el nodo, asi tambien copiara sus hijos apuntando a nullptr
                t->root->key = menor->key;
                delete menor; //Se elimina el nodo eliminado

            }
        
        }else if(t->root->key < x){ //Volvemos a iterar hasta llegar al nodo

            eliminado = treeRemove(&t->root->lefts, x);

        }else{

            eliminado = treeRemove(&t->root->rights, x);

        }
    }

    return eliminado;
}

void treeMakeNull (TreePtr t){

    if(t == nullptr || t->root == nullptr){// Arbol vacio o nulo
        
        return;

    } 

        treeMakeNull(&t->root->lefts);
        treeMakeNull(&t->root->rights);
        delete t->root;
        //Para eliminar por completo el arbol se deberia eliminar tambien t

}

uint32_t treeSize (TreePtr t){ //El tamaño será 1(nodo padre)+ sus hijos

    uint32_t tamano=1;
    if(treeEmpty(t)){
        tamano=0;
    }else{
        tamano += treeSize(&t->root->lefts) + treeSize(&t->root->rights);

    }

    return tamano;

}

uint32_t     treeHeight        (TreePtr t){
    uint32_t altura;
    if(treeEmpty(t)){
        altura = 0;
    }else{
        if(treeHeight(&t->root->lefts) > treeHeight(&t->root->rights)){

            altura = 1 + treeHeight(&t->root->lefts);
        }else{
            altura= 1 + treeHeight(&t->root->rights);
        }
    }

    return altura;
}


uint32_t     treeLeafTreeNodes (TreePtr t){

    uint32_t hojas= 0;

    if(treeEmpty(t)){
        hojas=0;
    }else{
        if(t->root->lefts.root == nullptr && t->root->rights.root ==nullptr){
            hojas=1;
        }else{
            hojas += treeLeafTreeNodes(&t->root->lefts);
            hojas += treeLeafTreeNodes(&t->root->rights);
        }

    }

    return hojas;
}


TreeNodePtr  treeSearch (TreePtr t, Element x){
    TreeNodePtr buscado;
    if(treeEmpty(t)){
        buscado =nullptr;
    }else{
        if(t->root->key == x){
            buscado = t->root;
        }else if(t->root->key > x){
                buscado= treeSearch(&t->root->lefts, x);
            }else if(t->root->key < x){

                buscado= treeSearch(&t->root->rights, x);

            }else{
                buscado = nullptr;

            }

        
    }

    return buscado;

}

TreeNodePtr  treeParent        (TreePtr t, Element x){
    TreeNodePtr padre;
    TreePtr aux=t;
    while(aux->root != nullptr){
        if(aux->root == nullptr) {
            padre= nullptr;
            break;
        }
           
    
        if(x > aux->root->key ){
            if(aux->root->rights.root->key == x){
                return aux->root;
            }
            aux=&aux->root->rights;
        }
        if(x < aux->root->key ){
            if(aux->root->lefts.root->key == x){
                return aux->root;
            }
            aux=&aux->root->lefts;
        }

    }
    
    return padre;

}

TreeNodePtr  treeParent        (TreePtr t, TreeNodePtr p){
    TreeNodePtr padre;
    TreePtr aux=t;
    while(aux->root != nullptr){
        if(aux->root == nullptr) {
            padre= nullptr;
            break;
        }
           
    
        if(p > aux->root ){
            if(aux->root->rights.root == p){
                return aux->root;
            }
            aux=&aux->root->rights;
        }
        if(p < aux->root ){
            if(aux->root->lefts.root == p){
                return aux->root;
            }
            aux=&aux->root->lefts;
        }

    }
    
    return padre;

}



TreeNodePtr  treeMaximum       (TreePtr t){
    TreeNodePtr mayor;
    if(t->root->rights.root != nullptr){
        mayor= treeMenor(&t->root->rights);
    }else{
        mayor= t->root;
    }
    

    return mayor;
}


std::string  treePreOrder      (TreePtr t, char c){
    std::string orden = "";
    if(!treeEmpty(t)){
        orden= c + treeNodeToString(t->root);
        orden += treePreOrder(&t->root->lefts, c);
        orden += treePreOrder(&t->root->rights, c);
        
    }
    return orden;
}


std::string  treePostOrder     (TreePtr t, char c){
    std::string postorder = "";

    if(!treeEmpty(t)){
        postorder= treePostOrder(&t->root->lefts,c);
        postorder= treePostOrder(&t->root->rights,c);
        postorder= postorder+ c+ t->root->key;
        
    }


    return postorder;

}


std::string  treeInOrder       (TreePtr t, char c){
    std::string inorder = "";

    if(!treeEmpty(t)){
        inorder= treePostOrder(&t->root->lefts,c);
        inorder= inorder+ c+ t->root->key;
        inorder= treePostOrder(&t->root->rights,c);
        
    }


    return inorder;

}


std::string  treeByLevels      (TreePtr t, char c){
    std::queue<TreeNodePtr> cola;
    std::string porniveles = "";
    TreeNodePtr aux;

    if(!treeEmpty(t)){
        cola.push(t->root);
        while(cola.empty()){
            aux= cola.front();
            cola.pop();
            porniveles= porniveles + c+ aux->key;
            if(aux->lefts.root){
                cola.push(aux->lefts.root);
            }
            if(aux->rights.root){
                cola.push(aux->rights.root);
            }

        }

    }
    return porniveles;
}