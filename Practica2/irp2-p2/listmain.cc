#include "list.h"
#include <iostream>


void printList(ListPtr l) {
  std::cout << "Lista: ";
  for (ListNodePtr n = l->head; n != nullptr; n = n->next) {
      std::cout << n->key << " ";
  }
  std::cout << "\n";
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[])
{
    // Crear lista
    ListPtr myList = listCreate();
    std::cout << "Lista creada. Tamaño: " << listSize(myList) << "\n";

    // Insertar elementos
    listInsert(myList, 'A', 1);
    listInsert(myList, 'B', 2);
    listInsert(myList, 'C', 3);
    listInsert(myList, 'D', 4);
    std::cout << "Después de insertar A, B, C, D (en 2da posición):\n";
    printList(myList);

    // Buscar un elemento
    Position pos = listLocate(myList, 'C');
    std::cout << "Elemento 'C' encontrado en la posición: " << pos << "\n";

    // Eliminar un elemento
    if (listRemove(myList, 2)) {
        std::cout << "Elemento en posición 2 eliminado.\n";
    } else {
        std::cout << "Fallo al eliminar en posición 2.\n";
    }
    printList(myList);

    // Obtener un elemento por posición
    ListNodePtr node = listRetrieve(myList, 2);
    if (node) {
        std::cout << "Elemento en posición 2: " << node->key << "\n";
    } else {
        std::cout << "No se encontró el elemento en la posición 2.\n";
    }

    // Vaciar la lista
    listMakeNull(myList);
    std::cout << "Lista vaciada. Tamaño: " << listSize(myList) << "\n";
    printList(myList);

    return 0;
  }