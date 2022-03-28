#ifndef _CREATION_H_
#define _CREATION_H_
#include "texture2.h"
/*!
 * \author Morgane Pechon
 * \file Creation.h
 * \brief Permet de créer le texte et de gérer les bouton
*/

/*! Acces à la création de texte sur l'ecran*/
SDL_Texture* Creation_Text(SDL_Renderer *renderer,SDL_Rect *tailText,const char *police,const int tailPolice,const int style,const char *texte,const SDL_Color couleur,const int position_x,const int position_y );

int bout (SDL_Renderer *renderer,text_t * bouton,int x,int y);

/*! Acces au bouton*/
#endif
