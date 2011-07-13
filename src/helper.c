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
