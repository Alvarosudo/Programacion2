#ifndef REBELSHIP_H
#define REBELSHIP_H

#include "ship.h"

namespace P4 {

  class RebelShip : public Ship {
  public:
    RebelShip(char symbol, uint energy);
    virtual ~RebelShip() = default;
  };

} // namespace P4

#endif /* REBELSHIP_H */

