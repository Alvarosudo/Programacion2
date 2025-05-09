// NIF: 74389742-Z
// NOMBRE: QUILES RUIZ, ÁLVARO ANTONIO
/*porque usar friend?
porque le queremos dar permiso de los atributos privados de la clase de una libreria externa
para que la clase externa pueda acceder a los atributos privados

El color del rombo indica el tipo
negro->composicion tiene control de los objetos que contiene
blanco->agregacion no tiene control de los objetos que contiene
*/
#include "ship.h"
using namespace P4;


mission_sig_t &get_mission_signal(){
    static mission_sig_t mission_signal_t;
    return mission_signal_t;
}

Ship::Ship(char c, uint energy)
    : c(c), energy(energy) {}

void Ship::set_drawing_char(char c){
    this->c=c;
}


char Ship::get_drawing_char() const{
    return c;
}


void Ship::set_in_mission(bool in_mission){
    this->in_mission=in_mission;
}


bool Ship::is_in_mission() const{
    return in_mission;
}


uint Ship::get_energy() const{
    return energy;
}


void Ship::set_energy(uint energy){
    this->energy=energy;
}


void Ship::reduce_energy(uint energy){
    if(this->energy - energy <= 0){
        this->energy = 0;
    }else{        
        this->energy -= energy;
    }
}