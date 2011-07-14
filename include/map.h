#ifndef MAP_H
#define MAP_H

#include "resources.h"

typedef struct mapElements { 
  int x;
  int y;
  res_t *res;

  struct mapElements* next;
} mapElements_t;

void cons(int x, int y, res_t *res, mapElements_t** xs);
void freeMapElements(mapElements_t* m);

#endif
