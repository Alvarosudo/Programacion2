// NIF: 74389742-Z
// NOMBRE: QUILES RUIZ, ÁLVARO ANTONIO

#include "container.h"

using namespace P4;

template <typename T>
Container<T>::Container(const std::string& name="Container"): cname(name) {}

template <typename T>
void Container<T>::set_name(const std::string& name){
    cname=name;
}
template <typename T>
const std::string& Container<T>::get_name() const{
    return cname;
}

template <typename T>
void Container<T>::add(const T& item){
    items.push_back(item);
}

template <typename T>
void Container<T>::remove(const T& item){
    uint16_t total=0;
    while(total <items.size()){
        uint posicion=find(item);
        //Si encuentra el elemento lo elimina
        if(posicion < items.size()){
            items.erase(items.begin() + posicion); 
        }
        total++;
    }
}


template <typename T>
uint16_t Container<T>::find(const T& item) const{
    uint16_t posicion=0;
    for(uint16_t i=0;i< items.size(); i++){
        if(items[i] == item){
            return posicion;
        }else{
            posicion ++;
        }
    }
    return posicion;
}

template <typename T>
T& Container<T>::operator[](size_t i){
    return items[i];
}

template <typename T>
size_t Container<T>::size() const{
    return items.size();
}

namespace P4{
template<typename U>
std::ostream& operator<<(std::ostream& os, const Container<U>& c) {
  if (!c.cname.empty()) {
    os << c.cname << std::endl;
  }
    
  for (const auto& item : c.items) {
    if constexpr (std::is_pointer<U>::value) {
      if (item != nullptr) {
        os << *item << std::endl;
      } else {
        os << "nullptr" << std::endl;
      }
    } else {
      os << item << std::endl;
    }
  }
    
  return os;
}
}