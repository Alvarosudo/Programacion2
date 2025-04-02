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

int main() {
    std::cout << std::fixed << std::setprecision(1); // Formateo global para poner 1 decimal en los decimales.

    Grid grid = createGrid(3, 3, 10.0f, 30.0f, 2, 22.0f);

    // Conectar señales
    get_high_temp_signal().connect(alert_high_temp);
    get_low_temp_signal().connect(alert_low_temp);
    get_inactive_sensor_signal().connect(alert_inactive);

    // Modificar temperaturas con decimales específicos
    updateTemperature(grid, 0, 0, 25.866f);
    updateTemperature(grid, 0, 1, 23.05f);
    updateTemperature(grid, 0, 2, 21.12f);
    updateTemperature(grid, 1, 0, 5.499f);   // por debajo del umbral (alerta baja)
    updateTemperature(grid, 1, 1, 35.44f);   // por encima del umbral (alerta alta)

    std::cout << "--- Initial Grid State ---\n";
    displayGrid(grid);

    // Simulación de pasos
    for (int i = 0; i < 3; ++i) {
        simulateStep(grid);
        updateTemperature(grid, 0, 2, 21.12f+(float)i);
    }

    std::cout << "--- Triggering alerts manually ---\n";
    triggerAlerts(grid);

    std::cout << "--- Swapping two sensors ---\n";
    Position a = {0, 0};
    Position b = {0, 2};
    if (swapSensors(grid, a, b)) {
        std::cout << "Sensors swapped successfully.\n";
    } else {
        std::cout << "Invalid positions for swap.\n";
    }

    std::cout << "--- Final Grid State ---\n";
    displayGrid(grid);

    freeGrid(grid);
    return 0;
}

