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


#include "p1.h"

int main() {
    // Crear una matriz de evaluaciones para 3 estudiantes y 4 asignaturas
    Evaluations evaluations = mreserve(3, 4);

    // Rellenar algunas notas de ejemplo
    modify_evaluation(evaluations, 0, 0, 7);  // Estudiante 0, Asignatura 0: nota 7
    modify_evaluation(evaluations, 0, 1, 5);  // Estudiante 0, Asignatura 1: nota 5
    modify_evaluation(evaluations, 0, 2, 9);  // Estudiante 0, Asignatura 2: nota 9
    modify_evaluation(evaluations, 0, 3, 6);  // Estudiante 0, Asignatura 3: nota 6

    modify_evaluation(evaluations, 1, 0, 4);  // Estudiante 1, Asignatura 0: nota 4
    modify_evaluation(evaluations, 1, 1, 8);  // Estudiante 1, Asignatura 1: nota 8
    modify_evaluation(evaluations, 1, 2, 6);  // Estudiante 1, Asignatura 2: nota 6
    modify_evaluation(evaluations, 1, 3, 7);  // Estudiante 1, Asignatura 3: nota 7

    modify_evaluation(evaluations, 2, 0, 9);  // Estudiante 2, Asignatura 0: nota 9
    modify_evaluation(evaluations, 2, 1, 6);  // Estudiante 2, Asignatura 1: nota 6
    modify_evaluation(evaluations, 2, 2, 5);  // Estudiante 2, Asignatura 2: nota 5
    modify_evaluation(evaluations, 2, 3, 8);  // Estudiante 2, Asignatura 3: nota 8

    // Mostrar la matriz completa
    std::cout << "Matriz de evaluaciones completa:" << std::endl;
    mshow(evaluations);

    // Calcular promedios por asignatura
    std::vector<etype_t> subject_avgs = average_per_subject(evaluations);
    std::cout << "\nPromedios por asignatura:" << std::endl;
    for (size_t i = 0; i < subject_avgs.size(); ++i) {
        std::cout << "Asignatura " << i << ": " << subject_avgs[i] << std::endl;
    }

    // Calcular promedios por estudiante
    std::vector<etype_t> student_avgs = average_per_student(evaluations);
    std::cout << "\nPromedios por estudiante:" << std::endl;
    for (size_t i = 0; i < student_avgs.size(); ++i) {
        std::cout << "Estudiante " << i << ": " << student_avgs[i] << std::endl;
    }

    // Ejemplo de filtrado de matriz (seleccionar estudiantes y asignaturas específicos)
    std::vector<uint32_t> selected_students = {1, 2,1,2,2,2,4,1,2};
    std::vector<uint32_t> selected_subjects = {1,3,1};
    
    Evaluations filtered_evaluations = filter(evaluations, selected_students, selected_subjects);

    std::cout << "\nMatriz filtrada (estudiantes 0 y 2, asignaturas 1 y 3):" << std::endl;
    mshow(filtered_evaluations);

    // Liberar memoria
    mfree(evaluations);
    mfree(filtered_evaluations);

    return 0;
}
