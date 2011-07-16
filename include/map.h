#ifndef MAP_H
#define MAP_H

#include "resources.h"

typedef struct mapE { 
  int x;
  int y;
  res_t *res;

  struct mapE* next;
} mapE_t;

typedef struct mapElements { 
  mapE_t* head;
  mapE_t* last;
} mapElements_t;

void cons(int x, int y, res_t *res, mapElements_t *xs);
void consEnd(int x, int y, res_t *res, mapElements_t *xs);
void freeMapElements(mapElements_t* m);

#endif
