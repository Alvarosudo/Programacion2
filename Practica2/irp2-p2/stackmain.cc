
#include "stack.h"

// Apilamos y desapilamos

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[])
{
  StackPtr s = stackCreate();


  auto empty = stackEmpty(s);   // true


  for (int p = 0; p < 10; p++) {
    stackPush(s, 'a');
    stackPush(s, 'b');
    stackPush(s, 'c');
  }

  auto count = listSize(&s->l) == 30;

  for (int p = 0; p < 9; p++) {
    [[maybe_unused]] auto t = stackPop(s);
    t = stackPop(s);
    t = stackPop(s);
  }

  [[maybe_unused]] auto t = stackPop(s);
  auto top = stackTop(s) == 'b';

  auto result = empty and count and top;

  listMakeNull(&s->l);
  delete s;

  return result ? 0 : 1;
}
