#ifndef DEATHSTAR_H
#define DEATHSTAR_H

#include "container.h"
#include "hangar.h"
#include <string>
#include <iostream>
#include <vector>  // necesario para mission_ships

namespace P4 {

  using HangarPtr = Hangar*;

  class DeathStar : public Container<HangarPtr> {
      public:
          DeathStar(const std::string& name);
          virtual ~DeathStar();

          
          /// Lanza todas las naves de todos los hangares a una misión
          void send_all_on_mission();

          /// Hace que vuelva una nave a un hangar determinado
          void recall_ship_to_hangar(ShipPtr ship, HangarPtr hangar);

      private:
          Container<ShipPtr> mission_ships;
  };

} // namespace P4

#endif /* DEATHSTAR_H */
