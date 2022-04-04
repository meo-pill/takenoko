#ifndef _CREATION_H_
#define _CREATION_H_
#include "texture2.h"
#include "converte.h"
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
/*!
 * \brief permet de creer l'affichage d'un joueur
 * \param renderer : Permet de charger l'affichage de la fenêtre
 * \param x : coordonnée x de l'affichage
 * \param y : coordonnée y de l'affichage
 * \param i : identifiant du joueur
 * \return text_t* : un tableau de texture et de réctangle
 */
extern text_t* Creation_Joueur(SDL_Renderer * renderer,int x,int y,int i);

/*!
 * \brief permet de creer l'affichage d'une main
 * \param renderer : Permet de charger l'affichage de la fenêtre
 * \param W : Largeur de l'écrant
 * \param H : Hauteur de l'écrant
 * \param i : identifiant du joueur
 * \return text_t* : un tableau de texture et de réctangle
 */
extern text_t* Creation_main(SDL_Renderer * renderer,int W,int H,int i);
/*!
 * \author Mewen
 * \brief permet de selectionner une case
 * \param renderer : Permet de charger l'affichage de la fenêtre
 * \param evaluation : la case qui est évaluer
 * \param source : la case qui remplace évaluation
 * \param x : coordonnée x du curseur
 * \param y : coordonnée y du curseur
 * \return int :permet de voir si le curseur et sur la case ou non
 **/
extern int Select_hexa(SDL_Renderer * renderer,
		Texture_t * evaluation,
		Texture_t * source,
		int const curseur_x,
		int const curseur_y);

#endif
