// NIF: 74389742-Z
// NOMBRE: QUILES RUIZ, ÁLVARO ANTONIO

#include "tiefighter.h"

#define TIEFIGHTER_ENERGY_LOST 10

using namespace P4;


TIEFighter::TIEFighter(char symbol, uint energy)
    :ImperialShip(symbol,energy){}


void TIEFighter::run_mission() {
    if(!is_in_mission()){
        reduce_energy(TIEFIGHTER_ENERGY_LOST);
        set_in_mission(true);

        get_mission_signal()(this);
    }else{
        std::cout<<"En mision"<<std::endl;
    }

}