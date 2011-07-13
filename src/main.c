#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include "resources.h"
#include "helper.h"

#define TRUE 1
#define FALSE 0

#define WIDTH 800
#define HEIGHT 600

#define CONTROL_SIZE 80

void loop(SDL_Surface*, resources_t*);

int main(int argc, char **argv) {
  SDL_Surface *screen;

  if(SDL_Init(SDL_INIT_VIDEO) == -1) {
    perror("FATAL - SDL Init failed");
    exit(1);
  }

  if(TTF_Init() == -1) {
    perror("FATAL - TTF Init failed");
    exit(1);
  }

  screen = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  if(screen == NULL) {
    perror("FATAL - Could not create screen surface");
    exit(1);
  }

  SDL_WM_SetCaption("CYCLOR - Editeur de niveau", NULL);

  resources_t* res = loadResources("res/", "resources");
  if(res == NULL)
    exit(1);

  loop(screen, res);

  freeResources(res);
  TTF_Quit();
  SDL_Quit();
  return 0;
}

void loop(SDL_Surface *screen, resources_t* res) {
  int loop = TRUE;
  SDL_Event ev;
  TTF_Font *font = TTF_OpenFont("res/dejavu.ttf", 25);

  /* The user control panel to select blocks */
  SDL_Surface *control = NULL;
  SDL_Rect controlPos;

  control = SDL_CreateRGBSurface(SDL_HWSURFACE, WIDTH, CONTROL_SIZE, 32, 0, 0, 0, 0);
  controlPos.x = 0;
  controlPos.y = HEIGHT - CONTROL_SIZE;
  stdFormat(&control);

  /* The map area */
  SDL_Surface *map = NULL;
  SDL_Rect mapPos;

  map = SDL_CreateRGBSurface(SDL_HWSURFACE, WIDTH, HEIGHT - CONTROL_SIZE, 32, 0, 0, 0, 0);
  mapPos.x = 0;
  mapPos.y = 0;
  stdFormat(&map);

  SDL_FillRect(control, NULL, SDL_MapRGB(screen->format, 255, 0, 0));
  SDL_FillRect(map, NULL, SDL_MapRGB(screen->format, 0, 0, 255));

  while(loop) {
    SDL_PollEvent(&ev);

    switch(ev.type) {
      case SDL_QUIT: loop = FALSE; break;
      default: break;
    }
    
    SDL_BlitSurface(map, NULL, screen, &mapPos);
    SDL_BlitSurface(control, NULL, screen, &controlPos);
    SDL_Flip(screen);

  }

  SDL_FreeSurface(control);
  SDL_FreeSurface(map);

  TTF_CloseFont(font);
}


