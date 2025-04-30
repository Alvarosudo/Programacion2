#ifndef TIEFIGHTER_H
#define TIEFIGHTER_H

#include "imperialship.h"

namespace P4 {

  class TIEFighter : public ImperialShip {
  public:
    TIEFighter(char symbol, uint energy);
    virtual ~TIEFighter();
    void run_mission() override;
  };

} // namespace P4

#endif /* TIEFIGHTER_H */

