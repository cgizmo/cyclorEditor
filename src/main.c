#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

int main() {
  if(SDL_Init(SDL_INIT_VIDEO) == -1) {
    perror("FATAL - SDL Init failed");
    exit(1);
  }

  SDL_Quit();
  return 0;
}
