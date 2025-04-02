#include "stack.h"
#include <iostream>

// Apilamos y desapilamos

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[])
{

  // Crear una pila
  StackPtr stack = stackCreate();

  // Apilar algunos elementos
  std::cout << "Apilando elementos..." << std::endl;
  stackPush(stack, 'A');
  stackPush(stack, 'B');
  stackPush(stack, 'C');

  // Verificar el elemento en la cabeza de la pila
  std::cout << "Elemento en la cabeza de la pila (stackTop): " << stackTop(stack) << std::endl;

  // Desapilar elementos
  std::cout << "Desapilando elementos..." << std::endl;
  std::cout << "Elemento desapilado (stackPop): " << stackPop(stack) << std::endl;
  std::cout << "Elemento desapilado (stackPop): " << stackPop(stack) << std::endl;
  std::cout << "Elemento desapilado (stackPop): " << stackPop(stack) << std::endl;

  // Intentar desapilar de una pila vacía (debería llamar a set_error)
  std::cout << "Intentando desapilar de una pila vacía..." << std::endl;
  std::cout << "Elemento desapilado (stackPop): " << stackPop(stack) << std::endl;

  // Liberar memoria de la pila (esto debería hacerse para evitar fugas de memoria)
  delete stack;

  return 0;
}