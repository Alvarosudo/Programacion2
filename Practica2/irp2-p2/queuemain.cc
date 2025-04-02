#include "queue.h"
#include "lib/error.h"
#include <iostream>


// Crear cola y cola vacia
int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[])
{
  // Crear una cola
  QueuePtr queue = queueCreate();

  // Verificar si la cola está vacía al principio
  std::cout << "¿La cola está vacía? " << (queueEmpty(queue) ? "Sí" : "No") << std::endl;

  // Encolar elementos
  std::cout << "Encolando elementos..." << std::endl;
  queueEnqueue(queue, 'A');
  queueEnqueue(queue, 'B');
  queueEnqueue(queue, 'C');

  // Verificar la cabeza de la cola después de encolar
  std::cout << "Elemento en la cabeza de la cola (queueHead): " << queueHead(queue) << std::endl;

  // Desencolar elementos y mostrar el resultado
  std::cout << "Desencolando elementos..." << std::endl;
  std::cout << "Elemento desencolado (queueDequeue): " << queueDequeue(queue) << std::endl;
  std::cout << "Elemento desencolado (queueDequeue): " << queueDequeue(queue) << std::endl;
  std::cout << "Elemento desencolado (queueDequeue): " << queueDequeue(queue) << std::endl;

  // Intentar desencolar de una cola vacía (debería invocar set_error)
  std::cout << "Intentando desencolar de una cola vacía..." << std::endl;
  std::cout << "Elemento desencolado (queueDequeue): " << queueDequeue(queue) << std::endl;

  // Verificar si la cola está vacía después de desencolar todos los elementos
  std::cout << "¿La cola está vacía después de desencolar todos los elementos? "
            << (queueEmpty(queue) ? "Sí" : "No") << std::endl;

  // Liberar memoria de la cola (esto debería hacerse para evitar fugas de memoria)
  delete queue;

  return 0;
}