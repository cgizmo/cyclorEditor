#include <stdio.h>
#include <stdlib.h>

#include "map.h"
#include "helper.h"
#include "resources.h"

void cons(int x, int y, res_t *res, mapElements_t* xs) { 
  mapE_t* head = malloc(sizeof(mapE_t));

  head->x = x;
  head->y = y;
  head->res = res;
  head->next = xs->head;

  xs->head = head;

  if(xs->last == NULL)
    xs->last = head;
}

void consEnd(int x, int y, res_t *res, mapElements_t *xs) { 
  if(xs->last == NULL) {
    cons(x, y, res, xs);
    xs->last = xs->head;
  }
  else {
    mapE_t* last = malloc(sizeof(mapE_t));

    last->x = x;
    last->y = y;
    last->res = res;
    last->next = NULL;

    xs->last->next = last;
    xs->last = last;
  }
}

void freeMapElements(mapElements_t* m) {
  mapE_t* next;
  mapE_t* curr = m->head;

  while(curr != NULL) { 
    next = curr->next;
    free(curr);
    curr = next;
  }
}
