#include "tree.h"
using namespace std;

void printTree(TreePtr t) {
    std::cout << "Preorden: " << treePreOrder(t, '-') << std::endl;
    std::cout << "Inorden: " << treeInOrder(t, '-') << std::endl;
    std::cout << "Postorden: " << treePostOrder(t, '-') << std::endl;
    std::cout << "Por niveles: " << treeByLevels(t, '-') << std::endl;
    std::cout << "Altura: " << treeHeight(t) << std::endl;
    std::cout << "Tamaño: " << treeSize(t) << std::endl;
    std::cout << "Hojas: " << treeLeafTreeNodes(t) << std::endl;
}


int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[])
{
    TreePtr tree = treeCreate();

    treeInsert(tree, 'A');
    treeInsert(tree, 'D');
    treeInsert(tree, 'H');
    treeInsert(tree, 'C');
    TreeNodePtr x=treeSearch(tree, 'C');
    if(x != nullptr){
        cout<<"No es nullptr"<<endl;
    }else{
        cout<<"Es nullptr"<<endl;
    }

    if(treeNodeIsLeaf(x)){
        cout<<"Es hoja"<<endl;
    }else{
        cout<<"No es hoja"<<endl;
    }
    treeDestroy(tree);


    return 0;
}