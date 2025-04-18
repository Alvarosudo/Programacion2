//NIF: 74389742Z   
//NOMBRE: ALVARO ANTONIO QUILES RUIZ

#include "p3.h"


//Declaracion de las alertas
//Declarar de tipo static para que solo se cambie en p3.cc
static high_temp_sig_t high_temp_signal;  
static low_temp_sig_t low_temp_signal;
static inactive_sensor_sig_t inactive_sensor_signal;

// Funciones para acceder a las señales
//Se devuelven referencias a las señales
high_temp_sig_t& get_high_temp_signal() {
    return high_temp_signal;  
}

low_temp_sig_t& get_low_temp_signal() {
    return low_temp_signal;
}

inactive_sensor_sig_t& get_inactive_sensor_signal() {
    return inactive_sensor_signal;
}




//Funciones a implementar

Grid createGrid(uint32_t rows, uint32_t cols,float low_threshold, float high_threshold, uint32_t max_idle, float default_temp){
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
    for(uint32_t i=0; i<grid.rows;i++){
        for(uint32_t j=0;j<grid.cols;j++){
            if(grid.sensors[i][j].active == true){

                grid.sensors[i][j].idle_cycles++;

                if(grid.sensors[i][j].idle_cycles > grid.max_idle){
                    grid.sensors[i][j].active = false;
                    get_inactive_sensor_signal()(grid.sensors[i][j]);

                }          
            }
        }
    }
}


void triggerAlerts(Grid& grid){
    for(uint32_t i=0; i<grid.rows;i++){
        for(uint32_t j=0;j<grid.cols;j++){

            if(grid.sensors[i][j].active == true){

                if(grid.sensors[i][j].temperature < grid.low_threshold){
                    get_low_temp_signal()(grid.sensors[i][j]);
                }

                if(grid.sensors[i][j].temperature > grid.high_threshold){
                    get_high_temp_signal()(grid.sensors[i][j]);
                }
            }            
            if(grid.sensors[i][j].active == false){
                get_inactive_sensor_signal()(grid.sensors[i][j]);
            }

        }
 
    }

}



bool swapSensors(Grid& grid, const Position& a, const Position& b){
    bool swaped = true;
    Sensor aux=grid.sensors[a.row][a.col];

    if(a.col > grid.cols || a.row > grid.rows || b.row >= grid.rows || b.col >= grid.cols){ //No se comprueba si son 0 pues es una posicion valida
        return false;
    }

    grid.sensors[a.row][a.col] = grid.sensors[b.row][b.col];
    grid.sensors[a.row][a.col].pos = a;
    grid.sensors[b.row][b.col] = aux;
    grid.sensors[b.row][b.col].pos = b;


    

    return swaped;
}