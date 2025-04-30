

#include "tiefighter.h"
#include "stardestroyer.h"
#include "xwing.h"
#include "hangar.h"
#include "deathstar.h"

#include <iostream>
#include <string>

using namespace P4;

void mission_event(const Ship *s) {
  std::cout << "Signal: Ship " << s->get_drawing_char() << " now has " << s->get_energy() << " energy.\n";
}

int main() {
  // Crear la Estrella de la Muerte
  DeathStar ds("Estrella de la Muerte");

  // Crear hangares
  HangarPtr h1 = new Hangar("Hangar I");
  HangarPtr h2 = new Hangar("Hangar II");
  HangarPtr h3 = new Hangar("Hangar III");

  // Añadir naves a los hangares
  auto t1 = new TIEFighter('T', 100);
  auto t2 = new TIEFighter('X', 100);
  t1->get_mission_signal().connect(mission_event);
  t2->get_mission_signal().connect(mission_event);
  h1->add(t1);
  h1->add(t2);

  auto d1 = new StarDestroyer('D', 500);
  d1->get_mission_signal().connect(mission_event);
  h2->add(d1);

  auto s1 = new XWing('W', 200);
  s1->get_mission_signal().connect(mission_event);
  h3->add(s1);

  // Añadir hangares a la DeathStar
  ds.add(h1);
  ds.add(h2);
  ds.add(h3);

  // Mostrar estado inicial
  std::cout << "======== ESTADO INICIAL ========\n";
  std::cout << ds << "\n";

  // Ejecutar misiones (eliminando naves de los hangares)
  std::cout << "\n======== ENVIANDO NAVES A MISION ========\n";
  ds.send_all_on_mission();

  // Mostrar estado intermedio (naves fuera)
  std::cout << "\n======== HANGARES VACIOS ========\n";
  std::cout << ds << "\n";

  // Recuperar naves a los hangares originales
  std::cout << "\n======== ORDEN DE REGRESO A LOS HANGARES ========\n";
  ds.recall_ship_to_hangar(t1, h1);
  ds.recall_ship_to_hangar(t2, h1);
  ds.recall_ship_to_hangar(d1, h2);

  // Estado final
  std::cout << "\n======== ESTADO FINAL ========\n";
  std::cout << ds;

  return 0;
}
