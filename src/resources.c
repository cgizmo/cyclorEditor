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

void cons(resources_t** res, res_t* r) {
  resources_t *head = malloc(sizeof(resources_t));

  head->r = r;
  head->next = *res;

  *res = head;
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
  resources_t *res = NULL;

  while(!feof(resfile)) {
    if(fscanf(resfile, "%s %s", id, resname) < 2)
      break;

    char *respath = strcat2(dir, resname);
    cons(&res, createRes(id, respath));
    free(respath);
  }

  fclose(resfile);
  return res;
}

void freeResources(resources_t* res) {
  resources_t* next = res;

  while(next != NULL) {
    res = next;

    free(res->r->name);
    SDL_FreeSurface(res->r->img);
    free(res->r);

    next = res->next;
    free(res);
  }
}

