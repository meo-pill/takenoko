#ifndef _CREATION_H_
#define _CREATION_H_

#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

extern SDL_Texture* CreationText(SDL_Renderer *renderer,SDL_Rect *tailText,const char *police,const int tailPolice,const int style,const char *texte,const SDL_Color couleur,const int position_x,const int position_y );
#endif
