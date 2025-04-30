#ifndef STARDESTROYER_H
#define STARDESTROYER_H

#include "imperialship.h"

namespace P4 {

  class StarDestroyer : public ImperialShip {
  public:
    StarDestroyer(char symbol, uint energy);
    virtual ~StarDestroyer();

    void run_mission() override;
  };

} // namespace P4

#endif /* STARDESTROYER_H */

