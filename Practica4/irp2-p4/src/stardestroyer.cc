// NIF: 74389742-Z
// NOMBRE: QUILES RUIZ, ÁLVARO ANTONIO

#include "stardestroyer.h"

#define STARDESTROYER_ENERGY_LOST 50

using namespace P4;

StarDestroyer::StarDestroyer(char symbol, uint energy)
    :ImperialShip(symbol, energy){}

    
void StarDestroyer::run_mission() {
    if(!is_in_mission()){
        reduce_energy(STARDESTROYER_ENERGY_LOST);
        set_in_mission(true);
        get_mission_signal()(this);
    }else{
        std::cout<<"Está en una mision"<<std::endl;
    }
}