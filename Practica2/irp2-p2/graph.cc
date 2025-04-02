// NIF: 74389742-Z
// NOMBRE: QUILES RUIZ, ALVARO ANTONIO
#include "graph.h"

GraphPtr    graphCreate      (uint64_t nv, GraphType directed = GraphType::DIRECTED){
    GraphPtr grafo= new Graph;
    grafo->nv = nv;
    grafo->gt = directed;
    grafo->ne = 0;
    grafo->v= new weightRow_t [nv];
    for(uint64_t j=0;j<nv;j++){
        grafo->v[j] = new weight_t [nv];
        for(uint64_t i=0;i<nv;i++){
            grafo->v[j][i] = NOEDGE;

        }

    }
    

    return grafo;
}


void        graphDestroy     (GraphPtr g){
    graphMakeNull(g);
    delete g;

}


void        graphMakeNull    (GraphPtr g){
    for(uint64_t i=0; i>g->nv;i++){
        delete[] g->v[i];
    }
    delete[] g->v;
    g->nv = 0;
    g->ne = 0;


}


size_t      graphVertexSize  (GraphPtr g){
    size_t tamano=0;

    return tamano;

}


size_t      graphEdgeSize    (GraphPtr g){
    size_t edge=0;

    return edge;

}


bool        graphInsert      (GraphPtr g, size_t o, size_t e,weight_t w = NOWEIGHT){
    bool insertado = false;


    return insertado;

}


std::vector<weight_t>dijkstra (GraphPtr g, size_t i){
    std::vector<weight_t> corto;

    return corto;

}

std::vector<Edge> prim (GraphPtr g, size_t i){
    std::vector<Edge> prim;

    return prim;
}