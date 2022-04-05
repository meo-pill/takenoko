/**
 * @file texture2.h
 * @author Morgane Pechon
 * @brief Permet de gérer la table des texture
 * @version 0.1
 * @date 2022-04-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _TEXTURE_H_
#define _TEXTURE_H_
#include "bibl_SDL.h"


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
/*! Lecture d'un rectangle
 * \param texture texture de rectangle
 * \param type_rect 0 = premier texture t selectiée
 * 	1 = second rectangle selection
 * 	
 * \result SDL_Rect 
 * retourne un rectangle
 *  */
extern SDL_Rect* lire_Rect(Texture_t* texture,int type_rect);

/*! Permet de lire la texture*/
extern SDL_Texture* lire_Texture(Texture_t* texture);

/*! Permet de copier les valeur d'un rectangle*/
extern void copie_rect(SDL_Rect* rect_cible,const SDL_Rect* rect_source);

/*! Acces a la création d'une table Texture */
extern text_t* Crea_Tex(const int nb_text);

/*! Permet de deffinir un rectangle*/
extern void positionne_rect(SDL_Rect* rect,const int x,const int y,const int h,const int w);

/*! Regarde l'existance d'une texture*/
extern int texture_existe(Texture_t* texture);

#endif
