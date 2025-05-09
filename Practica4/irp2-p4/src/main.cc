#include <iostream>
#include <vector>
#include <memory>
#include "ship.h"
#include "imperialship.h"
#include "rebelship.h"
#include "tiefighter.h"
#include "stardestroyer.h"
#include "xwing.h" // Para XWing

// Función de callback que se conectará a la señal de misión
void mission_callback(const P4::ShipPtr ship) {
    std::cout << "Mission callback triggered for ship: " 
              << ship->get_drawing_char() 
              << " with energy: " << ship->get_energy() << std::endl;
}

// Función de callback específica para naves imperiales
void imperial_mission_callback(const P4::ShipPtr ship) {
    std::cout << "Imperial ship " << ship->get_drawing_char() 
              << " reported to the Emperor. Energy remaining: " 
              << ship->get_energy() << std::endl;
}

// Función de callback específica para naves rebeldes
void rebel_mission_callback(const P4::ShipPtr ship) {
    std::cout << "Rebel ship " << ship->get_drawing_char() 
              << " reported to the Alliance. Energy remaining: " 
              << ship->get_energy() << std::endl;
}

int main() {
    std::cout << "==== Star Wars Fleet Management System ====" << std::endl;
    
    // Crear varias naves
    P4::TIEFighter tie('T', 200);
    P4::StarDestroyer destroyer('D', 500);
    P4::XWing xwing('X', 250);
    
    // Vector para almacenar punteros a las naves (polimorfismo)
    std::vector<P4::ShipPtr> fleet;
    fleet.push_back(&tie);
    fleet.push_back(&destroyer);
    fleet.push_back(&xwing);
    
    // Conectar señales a callbacks
    for (auto& ship : fleet) {
        // Todas las naves tienen el callback general
        ship->get_mission_signal().connect(mission_callback);
        
        // Adicionalmente, conectamos callbacks específicos según el tipo
        if (dynamic_cast<P4::ImperialShip*>(ship)) {
            ship->get_mission_signal().connect(imperial_mission_callback);
        } else if (dynamic_cast<P4::RebelShip*>(ship)) {
            ship->get_mission_signal().connect(rebel_mission_callback);
        }
    }
    
    // Mostrar estado inicial de la flota
    std::cout << "\n==== Initial Fleet Status ====" << std::endl;
    for (size_t i = 0; i < fleet.size(); ++i) {
        std::cout << i << ": " << *fleet[i] << std::endl;
    }
    
    // Ejecutar misiones para cada nave
    std::cout << "\n==== Running Missions ====" << std::endl;
    for (auto& ship : fleet) {
        ship->run_mission();
        std::cout << "----------------------------------------" << std::endl;
    }
    
    // Intentar ejecutar otra misión con las naves (ya deberían estar en misión)
    std::cout << "\n==== Attempting Second Mission Run ====" << std::endl;
    for (auto& ship : fleet) {
        ship->run_mission();
        std::cout << "----------------------------------------" << std::endl;
    }
    
    // Verificar el estado final de la flota
    std::cout << "\n==== Final Fleet Status ====" << std::endl;
    for (size_t i = 0; i < fleet.size(); ++i) {
        std::cout << i << ": " << *fleet[i] << std::endl;
    }
    
    // Completar misiones (volver del estado de misión)
    std::cout << "\n==== Completing Missions ====" << std::endl;
    for (auto& ship : fleet) {
        ship->set_in_mission(false);
        std::cout << "Ship " << ship->get_drawing_char() << " returned from mission." << std::endl;
    }
    
    // Ejecutar una misión más después de completar las anteriores
    std::cout << "\n==== Running Additional Missions ====" << std::endl;
    for (auto& ship : fleet) {
        ship->run_mission();
        std::cout << "----------------------------------------" << std::endl;
    }
    
    // Estado final después de todas las misiones
    std::cout << "\n==== Final Fleet Status After All Missions ====" << std::endl;
    for (size_t i = 0; i < fleet.size(); ++i) {
        std::cout << i << ": " << *fleet[i] << std::endl;
    }
    
    std::cout << "\n==== Test Complete ====" << std::endl;
    return 0;
}