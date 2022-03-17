#ifndef _TEXTURE_H_
#define _TEXTURE_H_
#include "bibl_SDL.h"
/*! \file texture.h
  \brief Permet de gérer la table de texture
*/

/*!
 * \struct Texture_s
 * \brief assemble texture et son rectagle
 * \typedef Texture_t
 * \brief Type de Texture 
 */
typedef struct Texture_s{
	SDL_Texture* t;
	SDL_Rect* place;
	SDL_Rect* place2;
}Texture_t;

/*!
 * \struct text_s
 * \brief permet la réalisation d'un tableau de texture
 * \brief prend aussi en compte differente fonction utilile à ça réalisation
 * \typedef text_t
 * \brief Type de table de Texture 
 */
typedef struct text_s{
	void (*quit)(SDL_Texture *);
	void (*det)(struct text_s*);
	Texture_t ** Table;
	int Taille;
}text_t;

extern SDL_Rect* lire_Rect(Texture_t* texture,int type_rect);

/*! Acces a la création d'une table Texture */
extern text_t* Crea_Tex(const int nb_text);


#endif
