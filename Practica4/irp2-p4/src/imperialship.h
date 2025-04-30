#ifndef IMPERIALSHIP_H
#define IMPERIALSHIP_H

#include "ship.h"

namespace P4 {

  class ImperialShip : public Ship {
  public:
    ImperialShip(char symbol, uint energy);
    virtual ~ImperialShip() = default;
  };

} // namespace P4

#endif /* IMPERIALSHIP_H */

