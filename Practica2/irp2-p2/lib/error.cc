#include "error.h"

static int8_t error = 0;

int8_t get_error() { return error; }
void set_error(int8_t e) { error = e; }
