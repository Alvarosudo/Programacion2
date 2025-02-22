#include "p1.h"


using namespace std;


Evaluations mreserve(uint32_t students, uint32_t subjects, etype_t v){
    if(students <=0 || subjects <= 0){
        return empty_evaluations;
    }
    //Declarar objeto evaluations
    Evaluations evaluations;
    evaluations.students=students;
    evaluations.subjects=subjects;

    //Reservar memoria para data
    evaluations.data = new student_t[evaluations.students];
        for(uint32_t i=0;i<students;i++){
            evaluations.data[i]= new etype_t(subjects);

            for(uint32_t j=0;j<subjects;j++){
                evaluations.data[i][j] = v;
            }
        }
    return evaluations;
}


void mfree(Evaluations& e){
    if(e.data){
        for(uint32_t i=0;i<e.students;i++){
            delete[] e.data[i];
        }
        delete[] e.data;
    }
    e=empty_evaluations;

}


void mshow(const Evaluations& e){
    for(uint32_t i=0;i<e.students;i++){
        cout<<"[";
        for(uint32_t j=0;j<e.subjects;j++){
            cout<<" "<<e.data[i][j]<<" ";
        }
        cout<<"]"<<endl;
    }   

}


void modify_evaluation(Evaluations& e, uint32_t student_idx, uint32_t subject_idx, etype_t new_evaluation){
    if(student_idx >e.students){ //No se evalua <0 pues uint32_t no puede ser <0
        return;
    }
    if(subject_idx >=e.subjects){//No se evalua <0 pues uint32_t no puede ser <0
        return;
    }
    uint32_t i=0;
    while(i!=student_idx){
        i++;
    }
    uint32_t j=0;
    while(j!=subject_idx){
        j++;
    }
    e.data[i][j]=new_evaluation;
}

std::vector<etype_t> average_per_subject(const Evaluations& m){
    vector<etype_t> almacenado(m.subjects,0);
    for(uint32_t i=0;i<m.students;i++){
        for(uint32_t j=0;j<m.subjects;j++){
            almacenado[j]+=m.data[i][j];
        }
    } 
    
    for(uint32_t i=0;i<m.subjects;i++){
        almacenado[i]=almacenado[i]/m.students;
    }
    
    return almacenado;
}

std::vector<etype_t> average_per_student(const Evaluations& m){
    vector<etype_t> media(m.students,0);
    
    for(uint32_t i=0;i<m.students;i++){
        for(uint32_t j=0;j<m.subjects;j++){
            media[i]+=m.data[i][j];

        }
    }

    for(uint32_t i=0;i<m.students;i++){
        media[i]=media[i]/m.subjects;
    }
    return media;
}

Evaluations filter(const Evaluations& m, const std::vector<uint32_t> &student_idxs, const std::vector<uint32_t> &subject_idxs){
    uint32_t estudiantes, asignaturas;


    //Crear los vectores a copiar
    std::vector<etype_t> students(m.students);
    std::vector<etype_t> subjects(m.subjects);

    //Evaluar los diferentes casos de los estudiantes

    //Comprobar repetidos y eliminarlos

    cout<<"[";
    for(uint32_t i=0;i<student_idxs.size();i++){
        cout<<" "<<student_idxs[i];
    }
    cout<<"]"<<endl;
    cout<<"[";

    for(uint32_t i=0;i<subject_idxs.size();i++){
        cout<<" "<<subject_idxs[i];
    }
    cout<<"]"<<endl;

    bool is_repeated;
    etype_t tamaño=0;
    for(uint32_t i=0;i<student_idxs.size();i++){
        is_repeated=false;
        if(i!=(student_idxs.size()-1)){
            for(uint32_t j=(i+1);j<student_idxs.size();j++){
                if(student_idxs[i]==student_idxs[j]){   
                    is_repeated=true;
                    break;
                }
            } 
        }
        if(!is_repeated){
            cout<<"tamaño: "<<tamaño<<endl;
            cout<<"numero a entrar: "<<student_idxs[i]<<endl;  
                          
            students[tamaño]=student_idxs[i];
            tamaño++;
        }       
    }
    cout<<"tamaño students: "<<students.size()<<endl;
    
    students.resize(tamaño);
    cout<<"tamaño students: "<<students.size()<<endl;

    tamaño=0;
    for(uint32_t i=0;i<subject_idxs.size();i++){
        is_repeated=false;
        if(i!=(student_idxs.size()-1)){
            for(uint32_t j=(i+1);j<subject_idxs.size();j++){
                if(subject_idxs[i]==subject_idxs[j]){   
                    is_repeated=true;
                    break;
                }
            } 
        }
        if(!is_repeated){                     
           subjects[i]=subject_idxs[i];
            tamaño++;
        }       
    }
    subjects.resize(tamaño);
    
    cout<<"[";
    for(uint32_t i=0;i<students.size();i++){
        cout<<" "<<students[i];
    }
    cout<<"]"<<endl;
    cout<<"[";

    for(uint32_t i=0;i<subjects.size();i++){
        cout<<" "<<subjects[i];
    }
    cout<<"]"<<endl;




    //Que no exista el estudiante
    for(etype_t i=0;i<m.students;i++){
        if(students[i]>=m.students){
            students.erase(students.begin() +i);            
        }
    }

    //Que no exista la asignatura
    for(etype_t i=0;i<m.subjects;i++){
        if(subjects[i]>=m.subjects){
            subjects.erase(subjects.begin() +i);            
        }
    }



    //Reservar memoria en filtrado para los estudiantes y asignaturas que se pidan
    estudiantes=static_cast<uint32_t>(size(students));
    asignaturas=static_cast<uint32_t>(size(subjects));
    Evaluations filtrado = mreserve(estudiantes, asignaturas);
    
    //Que no exista ningun estudiante o asignatura que cumplan las condiciones
    if(subjects.empty() || students.empty()){
        filtrado= empty_evaluations;
    }else{
        //Copiar el vector valido en la matriz que se devuelve
        for(etype_t i=0;i<estudiantes;i++){
            for(etype_t j=0;j<asignaturas;j++){
                    filtrado.data[i][j]=m.data[students[i]][subjects[j]];
            }
        }

    }
    
    

    return filtrado;
}


