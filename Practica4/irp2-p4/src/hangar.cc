// NIF: 74389742-Z
// NOMBRE: QUILES RUIZ, ÁLVARO ANTONIO

#include "hangar.h"

using namespace P4;


Hangar::Hangar(const std::string& name): Container(name){}


void Hangar::remove(size_t index){
    if(index < cname.size()){
        remove( index + cname.size());
    }
}

namespace P4{

std::ostream &operator<<(std::ostream &os, const Hangar &h){
    os<<"Ship: "<<h.get_name()<<std::endl;
    os<<"[ "<<h.get_name();
}
}