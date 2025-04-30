#ifndef SHIP_H
#define SHIP_H

#include <iostream>
#include <boost/signals2.hpp>

namespace P4 {

  class Ship;
  
  using ShipPtr = Ship*;
  using mission_sig_t = boost::signals2::signal<void(const ShipPtr)>;
  
  class Ship {
      friend std::ostream &operator<<(std::ostream &os, const Ship& s);

      public:
          Ship(char c, uint energy);
          Ship() = delete;
          virtual ~Ship() = default;

          void set_drawing_char(char c);
          char get_drawing_char() const;

          void set_in_mission(bool in_mission);
          bool is_in_mission() const;

          uint get_energy() const;
          void set_energy(uint energy);
          void reduce_energy(uint energy);

          virtual void run_mission() = 0;

          mission_sig_t &get_mission_signal();

      private:
          char c;               ///carácter que representa la nave
          bool in_mission = false; ///indica si la nave está actualmente fuera del hangar
          uint energy; //energía de la nave
          mission_sig_t mission_sig;
  };

} // namespace P4

#endif /* SHIP_H */

