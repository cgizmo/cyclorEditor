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

void consEnd(int x, int y, res_t *res, mapElements_t **xs) { 
  if(*xs == NULL)
    cons(x, y, res, xs);
  else {
    mapElements_t *i = *xs;
    while(i->next != NULL) {
      i = i->next;
    }

    mapElements_t* last = malloc(sizeof(mapElements_t));
    last->x = x;
    last->y = y;
    last->res = res;
    last->next = NULL;

    i->next = last;
  }
}

void freeMapElements(mapElements_t* m) {
  mapElements_t* next;

  while(m != NULL) { 
    next = m->next;
    free(m);
    m = next;
  }
}
