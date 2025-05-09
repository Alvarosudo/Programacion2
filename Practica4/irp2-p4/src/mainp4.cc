#include <iostream>
#include "tiefighter.h"
#include "stardestroyer.h"
#include "xwing.h"  // Incluye XWing

using namespace P4;

// Función que se conectará a la señal de misión
void on_mission(const ShipPtr s) {
    std::cout << "[SEÑAL] Misión lanzada por nave:\n" << *s << "\n";
}

int main() {
    // Crear instancias de naves
    TIEFighter tf('T', 100);
    StarDestroyer sd('S', 200);
    XWing xw('X', 150);

    // Conectar señales
    tf.get_mission_signal().connect(&on_mission);
    sd.get_mission_signal().connect(&on_mission);
    xw.get_mission_signal().connect(&on_mission);

    // Mostrar estado inicial
    std::cout << "=== ESTADO INICIAL ===\n";
    std::cout << tf << "\n";
    std::cout << sd << "\n";
    std::cout << xw << "\n";

    // Ejecutar misiones
    std::cout << "\n=== LANZANDO MISIONES ===\n";
    tf.run_mission();
    sd.run_mission();
    xw.run_mission();

    // Mostrar estado final
    std::cout << "\n=== ESTADO FINAL ===\n";
    std::cout << tf << "\n";
    std::cout << sd << "\n";
    std::cout << xw << "\n";

    return 0;
}
