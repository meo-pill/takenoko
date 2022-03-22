#ifndef _COMMANDE_H_
#define _COMMANDE_H_
#include "bibl_SDL.h"
#define QUIT 0
#define CONT 1
typedef int qui_t;

extern qui_t evenment(SDL_Event event,SDL_Window* pWindow);
#endif
