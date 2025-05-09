#include "xwing.h"
#include "tiefighter.h"
#include "stardestroyer.h"
#include <iostream>

using namespace P4;

void print_ship(const Ship& s) {
    std::cout << s << std::endl;
}

int main() {
    // Caso 1: Energía exactamente igual al coste de misión
    XWing x1('X', 20);
    TIEFighter t1('T', 10);
    StarDestroyer s1('S', 50);

    std::cout << "== Caso 1: Energía exacta para una misión ==" << std::endl;
    print_ship(x1);
    print_ship(t1);
    print_ship(s1);

    x1.run_mission();
    t1.run_mission();
    s1.run_mission();

    print_ship(x1); // energía = 0
    print_ship(t1); // energía = 0
    print_ship(s1); // energía = 0

    std::cout << "\n== Caso 2: Energía insuficiente para una misión ==" << std::endl;
    XWing x2('x', 5);  // requiere 20
    TIEFighter t2('t', 1); // requiere 10

    print_ship(x2);
    print_ship(t2);

    x2.run_mission();  // energía debe quedar en 0
    t2.run_mission();  // energía debe quedar en 0

    print_ship(x2);
    print_ship(t2);

    std::cout << "\n== Caso 3: Nave ya en misión (debe imprimir aviso) ==" << std::endl;
    x2.run_mission(); // No debe hacer nada
    t2.run_mission(); // No debe hacer nada

    std::cout << "\n== Caso 4: Nave con energía alta y múltiples misiones ==" << std::endl;
    StarDestroyer s2('D', 200);
    print_ship(s2);

    for (int i = 0; i < 5; ++i) {
        s2.set_in_mission(false); // Manualmente permitir otra misión
        s2.run_mission();
        print_ship(s2);
    }

    return 0;
}
