/*
 * Copyright (C) 2024
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


// mainp3.cc
#include "p3.h"
#include <iostream>
#include <iomanip> // para std::fixed y std::setprecision

void alert_high_temp(const Sensor& s) {
    std::cout << "[HIGH TEMP] Sensor at (" << s.pos.row << "," << s.pos.col 
              << ") reads " << s.temperature << "°C\n";
}

void alert_low_temp(const Sensor& s) {
    std::cout << "[LOW TEMP] Sensor at (" << s.pos.row << "," << s.pos.col 
              << ") reads " << s.temperature << "°C\n";
}

void alert_inactive(const Sensor& s) {
    std::cout << "[INACTIVE] Sensor at (" << s.pos.row << "," << s.pos.col 
              << ") is inactive after " << s.idle_cycles << " cycles\n";
}


void handle_inactive(const Sensor& s) {
    std::cout << "[TEST] Sensor (" << s.pos.row << "," << s.pos.col << ") inactivo\n";
}
void handle_high(const Sensor& s) {
    std::cout << "[ALERTA] Alta temperatura: " << s.temperature << "°C\n";
}
void handle_low(const Sensor& s) {
    std::cout << "[ALERTA] Baja temperatura: " << s.temperature << "°C\n";
}

int main() {
    get_high_temp_signal().connect(handle_high);
    get_low_temp_signal().connect(handle_low);

    Grid g = createGrid(1, 2, 10.0f, 30.0f, 3);

    updateTemperature(g, 0, 0, 5.0f);   // Debería lanzar baja
    updateTemperature(g, 0, 1, 35.0f);  // Debería lanzar alta

    triggerAlerts(g); // Lanza otra vez

    return 0;
}