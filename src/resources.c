#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>

#include "resources.h"
#include "helper.h"

/* HELPERS */
char* strdup2(char* orig) {
  char* new = malloc(sizeof(char) * (strlen(orig) + 1));

  strcpy(new, orig);

  return new;
}

res_t* createRes(char *id, char *resname) {
  res_t* r = malloc(sizeof(res_t));

  printf("Loading : %s - %s \n", id, resname);

  r->name = strdup2(id);
  r->img = SDL_LoadBMP(resname);
  stdFormat(&r->img);

  return r;
}

/* Returns a new string */
char* strcat2(char *a, char *b) {
  char *out = malloc(sizeof(char) * (strlen(a) + strlen(b) + 1));

  strcpy(out, a);
  strcat(out, b);

  return out;
}

/* Exported funtions */
resources_t* loadResources(char *dir, char *filename)  {
  char *fp = strcat2(dir, filename);
  FILE *resfile = fopen(fp, "r");
  free(fp);

  if(resfile == NULL) {
    perror("WARNING - Could not find specified resource file");
    return NULL;
  }

  char id[150];
  char resname[150];
  // r is an array of pointers to "res_t"s
  res_t **rs = malloc(sizeof(res_t*));

  // i will contain the number of elements in the array
  int i=0;
  while(!feof(resfile)) {
    if(fscanf(resfile, "%s %s", id, resname) < 2)
      break;

    char *respath = strcat2(dir, resname);
    res_t* r = createRes(id, respath);
    free(respath);

    rs[i] = r;
    i++;
    rs = realloc(rs, (i+1) * sizeof(res_t*));
  }

  resources_t *res = malloc(sizeof(resources_t));

  res->num = i;
  res->rs = rs;

  fclose(resfile);
  return res;
}

void freeResources(resources_t* res) {
  int i;
  for(i=0; i<res->num; i++) {
    free(res->rs[i]->name);
    SDL_FreeSurface(res->rs[i]->img);
  }

  free(res->rs);
  free(res);
}

