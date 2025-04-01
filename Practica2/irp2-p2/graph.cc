//graph.cc
#include "graph.h"

GraphPtr    graphCreate      (uint64_t nv, GraphType directed = GraphType::DIRECTED){
    GraphPtr grafo= new Graph;
    grafo->nv = nv;
    grafo->gt = directed;
    grafo->ne = nv;
    grafo->v= nullptr;

    return grafo;
}