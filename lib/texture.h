#ifndef _TEXTURE_H_
#define _TEXTURE_H_
#include "bibl_SDL.h"

typedef struct text_s{
	void (*quit)(SDL_Texture *);
	void (*det)(struct text_s*);
	void (*aff)(struct text_s* const,SDL_Renderer *const,const SDL_Rect *const,const SDL_Rect *const);
	SDL_Texture** Table;
	int Taille;
}text_t;

text_t* Crea_table_Tex(int nb_text);

#endif
