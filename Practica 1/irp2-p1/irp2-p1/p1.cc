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
        for(int i=0;i<students;i++){
            evaluations.data[i]= NEW(etype_t,subjects);

            for(int j=0;j<subjects;j++){
                evaluations.data[i][j] == v;
            }
        }
    return evaluations;
}


void mfree(Evaluations& e){
    for(int i=0;i<e.students;i++){
        delete[] e.data[i];
    }
    delete[] e.data;
    e=empty_evaluations;

}


void mshow(const Evaluations& e){
    for(int i=0;i<e.students;i++){
        for(int j=0;j<e.subjects;j++){
            cout<<e.data[i][j];
        }
        cout<<endl;
    }   

}


void modify_evaluation(Evaluations& e, uint32_t student_idx, uint32_t subject_idx, etype_t new_evaluation){
    if(student_idx <0 || student_idx >e.students){
        return;
    }
    if(subject_idx <0 || subject_idx >=e.subjects){
        return;
    }
}


Evaluations filter(const Evaluations& m, const std::vector<uint32_t> &student_idxs, const std::vector<uint32_t> &subject_idxs){

}


std::vector<etype_t> average_per_subject(const Evaluations& m){

}


std::vector<etype_t> average_per_student(const Evaluations& m){

}