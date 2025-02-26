// -*- mode: c++ -*-

// Compilar con --std=c++17 o superior

#ifndef GRAPH
#define GRAPH

#include <cstdint>
#include <iostream>
#include <queue>
#include <sstream>      // std::ostringstream
#include <iomanip>
#include <limits>
#include <cassert>

///////////////////////////////////////////////////////////////////////////////
//                 Typedefs/Using + Declaraciones adelantadas                //
///////////////////////////////////////////////////////////////////////////////
struct Graph;
using GraphPtr = Graph*;

using weight_t = double;
using weightRow_t = weight_t*;
using weightMatrix_t = weight_t**;

enum class GraphType {
  DIRECTED,
  NOTDIRECTED
};

///////////////////////////////////////////////////////////////////////////////
//                                   Graph                                   //
///////////////////////////////////////////////////////////////////////////////
struct Graph {
  weightMatrix_t v;             // Vertex adjacency matrix
  size_t         nv;            // N vertices
  size_t         ne;            // N edges
  GraphType      gt;            // Is directed?
};

///////////////////////////////////////////////////////////////////////////////
//                                    Edge                                   //
///////////////////////////////////////////////////////////////////////////////
struct Edge {
  size_t o;                     // Origin and...
  size_t e;                     // End of edge
};

const auto   NOEDGE       = std::numeric_limits<weight_t>::max();
const auto   EDGEINFINITY = NOEDGE;
const double NOWEIGHT                = 0.0;

//--------------------------------------------------------------------

GraphPtr    graphCreate      (uint64_t nv, GraphType directed = GraphType::DIRECTED);
void        graphDestroy     (GraphPtr g);
void        graphMakeNull    (GraphPtr g);
size_t      graphVertexSize  (GraphPtr g);
size_t      graphEdgeSize    (GraphPtr g);
bool        graphInsert      (GraphPtr g, size_t o, size_t e,
                              weight_t w = NOWEIGHT);

std::vector<weight_t>
dijkstra (GraphPtr g, size_t i); // Shortest-path from
                                 // node-i to the rest.

std::vector<Edge>
prim (GraphPtr g, size_t i);    // Prim's algorithm from node-i.

[[maybe_unused]]
static void showVector (std::vector<weight_t>& d) {
  for (auto e = 0u; e < d.size(); e++)
    std::cout << "d[" << e << "]= " << d[e] << '\n';
}

[[maybe_unused]]
static void showVector (std::vector<Edge>& d) {
  for (auto e = 0u; e < d.size(); e++)
    std::cout << "edge[" << d[e].o << ", " << d[e].e << "]" << '\n';
}

[[maybe_unused]]
static std::string graphToString (GraphPtr g) {
  std::string s;
  std::ostringstream oss;

  if (g == nullptr) return "";

  for (size_t i = 0; i < g->nv; i++) {
    s += "[";
    for (size_t j = 0; j < g->nv; j++) {
      oss << std::setiosflags(std::ios::fixed)
          << std::setprecision(2)
          << std::setw(6)
          << g->v[i][j] << ", ";
    }
    s += oss.str() + "]\n";
    oss.str("");
    oss.clear();
  }
  return s;
}

#endif
