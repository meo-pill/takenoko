#ifndef _TEXTURE_H_
#define _TEXTURE_H_
#include "index.h"

typedef struct text_s{
	void (*quit)(SDL_Texture *);
	void (*det)(struct text_s*);
	void (*aff)(struct text_s* const,SDL_Renderer *const,const SDL_Rect *const,const SDL_Rect *const);
	SDL_Texture* Table;
	int Taille;
}text_t;

void Crea_table_Tex(text_t* tab,int nb_text);

#endif
