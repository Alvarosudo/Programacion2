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

// ---------------------------------------------------------------
// No modifiques este fichero. Debes implementar las funciones en p1.cc
// ---------------------------------------------------------------

#ifndef P1_H
#define P1_H

#include <iostream>
#include <vector>
#include <cstdint>

// -- Typdefs: ------------------------------------------------------------
/** El tipo de los elementos de la matriz de bajo nivel. */
using etype_t  = uint32_t;
/// El tipo de la fila de la matriz de bajo nivel
using student_t    = etype_t*;
//! El tipo matriz de bajo nivel.
using matrix_t = student_t*;

// Estructura que contiene los datos de la matriz de evaluaciones
struct Evaluations {
    uint32_t students;
    uint32_t subjects;
    matrix_t data;
};

// Constante que representa un dato de tipo Evaluations que no tiene información 
// (con la matriz nula y número de estudiantes y de asignaturas con el valor 0)
const Evaluations empty_evaluations = {0, 0, nullptr};

// Funciones a implementar:

// Funciones para crear un registro de Evaluations utilizando memoria dinámica
// para construir los datos de acuerdo a la cantidad de estudiantes y asignaturas
Evaluations mreserve(uint32_t students, uint32_t subjects, etype_t v=0);

// Libera la memoria creada con memoria dinámica 
void mfree(Evaluations& e);

//Visualiza en pantalla los datos de las notas en forma de matriz. Las filas son los estudiantes y las columnas las asignaturas.
void mshow(const Evaluations& e);

// Función para modificar la evaluación de un alumno en una determinada asignatura
void modify_evaluation(Evaluations& e, uint32_t student_idx, uint32_t subject_idx, etype_t new_evaluation);



// Función que filtra las evaluaciones creando un nuevo registro con una copia de las evaluaciones para determinados estudiantes y asignaturas.
Evaluations filter(const Evaluations& m, const std::vector<uint32_t> &student_idxs, const std::vector<uint32_t> &subject_idxs);

// Función que devuelve el promedio de las evaluaciones por asignatura en forma de vector.  
std::vector<etype_t> average_per_subject(const Evaluations& m);

// Función que devuelve el promedio de las evaluaciones por estudiante en forma de vector.
std::vector<etype_t> average_per_student(const Evaluations& m);

#endif // P1_H
