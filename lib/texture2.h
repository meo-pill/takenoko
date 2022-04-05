#ifndef _TEXTURE_H_
#define _TEXTURE_H_
#include "bibl_SDL.h"
/*!
 * \author Morgane Pechon
 * \file texture.h
 * \brief Permet de gérer la table de texture
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
/*! Lecture d'un rectangle
 * \param texture texture de rectangle
 * \param type_rect 0 = premier texture t selectiée
 * 	1 = second rectangle selection
 * 	
 * \result SDL_Rect 
 * retourne un rectangle
 *  */
extern SDL_Rect* lire_Rect(Texture_t* texture,int type_rect);

/*! \brief Permet de lire la texture
 * \param texture : prend la Texture_t ou on veux lire la texture
 * \return une SDL_Texture*/
extern SDL_Texture* lire_Texture(Texture_t* texture);

/*! \brief Permet de copier les valeur d'un rectangle
 * \param rect_cible : prend le rectangle ou la source sera copier
 * \param rect_source : prend le rectangle à copier*/
extern void copie_rect(SDL_Rect* rect_cible,const SDL_Rect* rect_source);

/*! \brief Acces a la création d'une table Texture 
 * \param nb_text: le nombre de texture souhaiter*/
extern text_t* Crea_Tex(const int nb_text);

/*! \brief Permet de deffinir un rectangle
 * \param rect : prend le rectangle à positionner 
 * \param x : position du rectangle sur l'axe x
 * \param y : position du rectangle sur l'axe y
 * \param h : hauteur du rectangle
 * \param w : largeur du rectangle*/
extern void positionne_rect(SDL_Rect* rect,const int x,const int y,const int h,const int w);

/*! \brief Regarde l'existance d'une texture
 * \param texture : texture à testé*/
extern int texture_existe(Texture_t* texture);

#endif
