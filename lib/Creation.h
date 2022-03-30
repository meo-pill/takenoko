#ifndef _CREATION_H_
#define _CREATION_H_
#include "texture2.h"
/*!
 * \author Morgane Pechon
 * \file Creation.h
 * \brief Permet de créer le texte et de gérer les bouton
*/

/*! Acces à la création de texte sur l'ecran*/
extern SDL_Texture* Creation_Text(SDL_Renderer *renderer,
		SDL_Rect *tailText,
		const char *police,
		const int tailPolice,
		const int style,
		const char *texte,
		const SDL_Color couleur,
		const int position_x,
		const int position_y );

/*! Acces à la création d'une image*/
extern SDL_Texture* Creation_image(SDL_Renderer *renderer,
		SDL_Rect *tailImage,
		const char *nom_image,
		const int position_x,
		const int position_y,
		const int Hauteur,
		const int largeur);
/*! Acces au bouton*/
extern int bout (SDL_Renderer *renderer,text_t * bouton,int x,int y);

/*! inverse l'affichage d'un bouton*/
extern int inv_bout(SDL_Renderer * renderer, text_t * bouton,int x,int y);
#endif
