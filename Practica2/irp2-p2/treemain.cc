#include "tree.h"

void printTree(TreePtr t) {
    std::cout << "Preorden: " << treePreOrder(t, ' ') << std::endl;
    std::cout << "Inorden: " << treeInOrder(t, ' ') << std::endl;
    std::cout << "Postorden: " << treePostOrder(t, ' ') << std::endl;
    std::cout << "Por niveles: " << treeByLevels(t, ' ') << std::endl;
    std::cout << "Altura: " << treeHeight(t) << std::endl;
    std::cout << "Tamaño: " << treeSize(t) << std::endl;
    std::cout << "Hojas: " << treeLeafTreeNodes(t) << std::endl;
}


int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[])
{
    TreePtr tree = treeCreate();

    char elements[] = {'M', 'F', 'T', 'B', 'H', 'R', 'Z', 'A', 'D', 'G', 'I', 'P', 'U'};
    int n = sizeof(elements) / sizeof(elements[0]);

    std::cout << "Insertando elementos en el árbol...\n";
    for (int i = 0; i < n; ++i) {
        treeInsert(tree, elements[i]);
    }

    std::cout << "Árbol tras inserciones:\n";
    printTree(tree);

    std::cout << "\nBuscando elementos en el árbol...\n";
    char searchKeys[] = {'M', 'X', 'B', 'U'};
    for (char key : searchKeys) {
        TreeNodePtr found = treeSearch(tree, key);
        std::cout << "Elemento " << key << (found ? " encontrado" : " no encontrado") << std::endl;
    }

    std::cout << "\nEliminando nodos: B, T, M...\n";
    treeRemove(tree, 'B');
    treeRemove(tree, 'T');
    treeRemove(tree, 'M');

    std::cout << "Árbol tras eliminaciones:\n";
    printTree(tree);

    treeDestroy(tree);
    return 0;
}