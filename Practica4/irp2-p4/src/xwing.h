#ifndef XWING_H
#define XWING_H

#include "rebelship.h"

namespace P4 {

  class XWing : public RebelShip {
  public:
    XWing(char symbol, uint energy);
    virtual ~XWing();

    void run_mission() override;
  };

} // namespace P4

#endif /* XWING_H */