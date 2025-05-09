// NIF: 74389742-Z
// NOMBRE: QUILES RUIZ, ÁLVARO ANTONIO

#include "tiefighter.h"

#define TIEFIGHTER_ENERGY_LOST 10

using namespace P4;


TIEFighter::TIEFighter(char symbol, uint energy)
    :ImperialShip(symbol,energy){}

P4::TIEFighter::~TIEFighter() {}

void TIEFighter::run_mission() {
    if(!is_in_mission()){
 
        if(get_energy() == 0){
            std::cout<<"La nave no tiene energia"<<std::endl; 
            set_in_mission(false);
            get_mission_signal()(this);            
        }else{
            reduce_energy(TIEFIGHTER_ENERGY_LOST);
            set_in_mission(true);
            get_mission_signal()(this);
        }
    }else{
            std::cout<<"Nave en mision"<<std::endl;
    }

}