#include <SDL/SDL.h>
#include "helper.h"

/* Must call this on every surface creation instance
 * to avoid problems with surfaces having different formats
 */
void stdFormat(SDL_Surface **surf) { 
  SDL_Surface *new = SDL_DisplayFormat(*surf);
  SDL_FreeSurface(*surf);
  *surf = new;
}

int min(int a, int b) {
  if(a<b)
    return a;
  else 
    return b;
}

int max(int a, int b) { 
  if(a<b)
    return b;
  else
    return a;
}

char* strdup2(char* orig) {
  char* new = malloc(sizeof(char) * (strlen(orig) + 1));

  strcpy(new, orig);

  return new;
}

/* Returns a new string */
char* strcat2(char *a, char *b) {
  char *out = malloc(sizeof(char) * (strlen(a) + strlen(b) + 1));

  strcpy(out, a);
  strcat(out, b);

  return out;
}

