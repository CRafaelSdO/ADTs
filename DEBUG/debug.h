#ifndef DEBUG_H
#define DEBUG_H

#include <stdbool.h>

#define DBG if(
#define WTH )
#define PRNT printf(
#define ENDDBG );

bool assert(int, int);

#endif