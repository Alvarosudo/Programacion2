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


// p3.h
#ifndef P3_H
#define P3_H

#include <cstdint>
#include <boost/signals2.hpp>
#include <iostream>
#include <iomanip>

using namespace std;

// Estructura que representa unas coordenadas en el Grid.
struct Position {
    uint32_t row;
    uint32_t col;
};

// Información de un sensor, incluyendo su posición en el grid, su temperatura,
// su estado (si es activo o inactivo) y el número de ciclos que lleva sin cambios.
struct Sensor {
    Position pos;
    float temperature;
    bool active;
    uint32_t idle_cycles;
};

// Representa una red en forma de matriz de sensores.
struct Grid {
    uint32_t rows;
    uint32_t cols;
    float high_threshold;
    float low_threshold;
    uint32_t max_idle;
    Sensor** sensors;
};

// Representa una red de sensores vacía.
const Grid empty_grid = {0, 0, 0.0f, 0.0f, 0, nullptr};

// -------------------------------------------------------------

// Tipos de datos que representan las señales.
using high_temp_sig_t = boost::signals2::signal<void (const Sensor&)>;
using low_temp_sig_t = boost::signals2::signal<void (const Sensor&)>;
using inactive_sensor_sig_t = boost::signals2::signal<void (const Sensor&)>;

// Funciones que devuelven cada una de las señales.
high_temp_sig_t& get_high_temp_signal();
low_temp_sig_t& get_low_temp_signal();
inactive_sensor_sig_t& get_inactive_sensor_signal();

// -------------------------------------------------------------

//Crea un nuevo Grid con memoria dinámica.
Grid createGrid(
			uint32_t rows, uint32_t cols, 
			float low_threshold, float high_threshold, 
			uint32_t max_idle,
			float default_temp = 20.0f);

// Libera la memoria dinámica y borra el contenido del Grid.
void freeGrid(Grid& grid);

// Actualiza la temperatura de un sensor.
void updateTemperature(Grid& grid, uint32_t row, uint32_t col, float new_temp);

// Simula un ciclo, incrementando en 1 los contadores idle_cycles de todos los sensores activos.
void simulateStep(Grid& grid);

// Sin modificar el estado de los sensores, lanza las señales correspondientes si han 
void triggerAlerts(Grid& grid);

// Intercambia un sensor por otro en la red de sensores.
bool swapSensors(Grid& grid, const Position& a, const Position& b);


// -------------------------------------------------------------

//Función que muestra las temperaturas de la red de sensores
[[maybe_unused]]
static void displayGrid(const Grid& grid) {
    std::cout << std::fixed << std::setprecision(1); // Formato global

    for (uint32_t i = 0; i < grid.rows; ++i) {
        for (uint32_t j = 0; j < grid.cols; ++j) {
            const Sensor& s = grid.sensors[i][j];
            if (!s.active) {
                std::cout << "[ X ] ";
            } else {
                std::cout << "[ " << s.temperature << " ] ";
            }
        }
        std::cout << "\n";
    }
}

#endif // P3_H

