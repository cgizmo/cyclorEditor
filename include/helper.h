#ifndef HELPER_H
#define HELPER_H

#include <SDL/SDL.h>

void stdFormat(SDL_Surface**);

int min(int, int);
int max(int, int);

char* strdup2(char* orig);
char* strcat2(char *a, char *b);

#endif
