//NIF: 74389742Z   
//NOMBRE: ALVARO ANTONIO QUILES RUIZ

#include "p3.h"

Grid createGrid(uint32_t rows, uint32_t cols,float low_threshold, float high_threshold, uint32_t max_idle, float default_temp = 20.0f){
    //Comprobar que los valores son correctos
    if(high_threshold<= low_threshold){ //Coherencia que high > low
        return empty_grid;
    }
    if(high_threshold < -100 || high_threshold > 100 || low_threshold <-100 || low_threshold > 100 || default_temp < -100 || default_temp > 100){
        return empty_grid; //Que se encuentren en el rango de valores validos
    } 
    if(rows == 0 ||cols == 0){ //Si no hay filas  o columnas
        return empty_grid;
    }
    if(max_idle > 50){ //Si se sorbrepasa el valor de max_idle
        return empty_grid;
    }

    Grid grid =  {rows, cols, low_threshold, high_threshold, max_idle, nullptr}; //Inicializar grid con los valores dados
    grid.sensors = new Sensor*[rows]; //Reservar memoria para las filas
    for(uint32_t i=0;i<rows;i++){
        grid.sensors[i]= new Sensor[cols]; //Por cada fila inicializar columnas 
        for(uint32_t j=0;j<cols;j++){ //Rellenar el sensor con sus datos
            grid.sensors[i][j].pos.col=j;
            grid.sensors[i][j].pos.row=i; 
            grid.sensors[i][j].temperature=default_temp;
            grid.sensors[i][j].active=true;
            grid.sensors[i][j].idle_cycles=0;
        }
    }
    

    return grid; //Devolver el grid creado
}


void freeGrid(Grid& grid){
    for(uint32_t i=0;i<grid.rows;i++){
    delete[] grid.sensors[i]; //Liberar la columna de cada fila del sensor
    }
    delete[] grid.sensors; //Liberar la memoria de las filas del sensor

    grid = empty_grid; //Asignar a los valores por defecto

}


void updateTemperature(Grid& grid, uint32_t row, uint32_t col, float new_temp){

    if (row >= grid.rows || col >= grid.cols) {
        return; // Fuera de limites, no hace nada
    }

    Sensor& Sensor= grid.sensors[row][col]; //Crear un sensor con los valores del sensor a cambiar

    //Modificar los valores si el sensor esta activo
    if(Sensor.active == true){
        Sensor.temperature = new_temp;
        Sensor.idle_cycles = 0;
        if(new_temp > grid.high_threshold){
            get_high_temp_signal()(Sensor); //Si sobrepasa la temperatura por arriba manda alerta
        }
        if(new_temp < grid.low_threshold){
            get_low_temp_signal()(Sensor); //Si sobrepasa la temperatura por abajo manda alerta
        } 
    }
}


void simulateStep(Grid& grid){

}


void triggerAlerts(Grid& grid){

}


bool swapSensors(Grid& grid, const Position& a, const Position& b){
    bool swaped;

    return swaped;
}