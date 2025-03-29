#include "list.h"
#include <iostream>

// Insertamos en lista

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[])
{
  ListPtr l = listCreate();

  for (char c='g'; c >= 'a'; c--)
    listInsert (l, c, 1);

  listInsert (l, 'z', 1);

  auto s = listToString (l,':');
  auto p = listLocate (l, 'e');
  auto r = s == ":a:b:c:d:e:f:g" and p == 5;

  listMakeNull(l);
  delete l;
  std::cout << s;

  return r ? 0 : 1;
}
