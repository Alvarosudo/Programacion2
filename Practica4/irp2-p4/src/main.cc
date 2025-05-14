#include "container.h"
#include <iostream>
using namespace P4;

int main() {
    Container<std::string> c("TestContainer");

    c.add("X-Wing");
    c.add("TIE Fighter");

    std::cout << "Antes de eliminar:\n" << c;

    c.remove("Death Star");  // No existe

    std::cout << "Después de intentar eliminar 'Death Star':\n" << c;

    return 0;
}
