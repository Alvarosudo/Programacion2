
#include "graph.h"

const char sep = ' ';

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[])
{
  GraphPtr g = graphCreate(7);

  graphInsert(g,0,1);
  graphInsert(g,0,2);

  graphInsert(g,1,3);
  graphInsert(g,1,4);

  graphInsert(g,2,5);

  graphInsert(g,5,4);
  graphInsert(g,5,6);

  graphInsert(g,3,6);
  graphInsert(g,4,6);


  bool r1 = graphVertexSize(g) == 7;
  bool r2 = graphEdgeSize(g) == 9;

  graphDestroy (g);

  auto result = r1 and r2;


  return result ? 0 : 1;
}
