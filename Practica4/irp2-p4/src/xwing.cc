// NIF: 74389742-Z
// NOMBRE: QUILES RUIZ, ÁLVARO ANTONIO

#include "xwing.h"

#define XWING_ENERGY_LOST 20

using namespace P4;


XWing::XWing(char symbol, uint energy)
    :RebelShip(symbol,energy){}


void XWing::run_mission() {
    if(!is_in_mission()){
        reduce_energy(XWING_ENERGY_LOST);
        set_in_mission(true);
        get_mission_signal()(this);
    }else{
        std::cout<<"Nave en mision"<<std::endl;  
    }
}