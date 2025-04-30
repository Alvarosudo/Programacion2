#ifndef HANGAR_H
#define HANGAR_H

#include "container.h"
#include "ship.h"
#include <string>
#include <sstream>

namespace P4 {

  class Hangar : public Container<ShipPtr> {
    friend std::ostream &operator<<(std::ostream &os, const Hangar &h);
      public:
          Hangar(const std::string& name);
          virtual ~Hangar() = default;

          void remove(size_t index);
  };

} // namespace P4

#endif /* HANGAR_H */

