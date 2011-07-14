#include <stdio.h>
#include <stdlib.h>

#include "map.h"
#include "helper.h"
#include "resources.h"

void cons(int x, int y, res_t *res, mapElements_t** xs) { 
  mapElements_t* head = malloc(sizeof(mapElements_t));

  head->x = x;
  head->y = y;
  head->res = res;
  head->next = *xs;

  *xs = head;
}

void freeMapElements(mapElements_t* m) {
  mapElements_t* next;

  while(m != NULL) { 
    next = m->next;
    free(m);
    m = next;
  }
}
