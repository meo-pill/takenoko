#ifndef _COMMANDE_H_
#define _COMMANDE_H_
#include "bibl_SDL.h"
#define QUIT -1
#define CONT 1
typedef int quit_t;

extern quit_t evenment( SDL_Event event,SDL_Window* pWindow,int * fullscreen);
#endif
