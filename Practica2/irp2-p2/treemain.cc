
////////////////////////////////////////
// treeEmpty & treeSize && treeInsert //
////////////////////////////////////////

#include "tree.h"

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[])
{
  TreePtr t = treeCreate ();

  auto r1 = (t) and (treeEmpty (t));

  treeInsert (t, 'g');
  treeRemove (t, 'g');

  treeInsert (t, 'e');
  treeRemove (t, 's');

  treeInsert (t, 'b');
  treeInsert (t, 'h');
  treeRemove (t, 's');

  auto r2 = treeSize (t) == 3;

  treeDestroy (t);

  return r1 and r2 ? 0 : 1;
}
