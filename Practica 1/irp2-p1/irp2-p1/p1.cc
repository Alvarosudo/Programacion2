#include "p1.h"

#define NEW(tipo,cantidad) ((tipo*) malloc((cantidad) * (size_t) sizeof(tipo)));

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
    evaluations.data = NEW(student_t,students);
        for(uint32_t i=0;i<students;i++){
            evaluations.data[i]= NEW(etype_t,subjects);

            for(uint32_t j=0;j<subjects;j++){
                evaluations.data[i][j] = v;
            }
        }
    return evaluations;
}


void mfree(Evaluations& e){
    for(uint32_t i=0;i<e.students;i++){
        delete[] e.data[i];
    }
    delete[] e.data;
    e=empty_evaluations;

}


void mshow(const Evaluations& e){
    for(uint32_t i=0;i<e.students;i++){
        cout<<"[";
        for(uint32_t j=0;j<e.subjects;j++){
            cout<<e.data[i][j];
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

}
