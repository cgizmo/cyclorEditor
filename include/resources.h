#ifndef RESOURCES_H
#define RESOURCES_H

#include <SDL/SDL.h>

/* One resource */
typedef struct res {
  char *name;
  SDL_Surface *img; // Ptr to img
} res_t;

/* Many resources */
typedef struct resources { 
  res_t* r;
  struct resources *next;
} resources_t;

resources_t* loadResources(char *dir, char *filename);
void freeResources(resources_t* res);

#endif
