#ifndef _MENU_H_
#define _MENU_H_
#include "Plato.h"
/*!
 * \author Morgane Pechon
 * \file menu.h
 * \brief Permet de gérer le menu de jeux
*/

/*! \brief Acces a la création d'une fenêtre de selection des differente action du jeux */
void menu();

/*! \brief Acces a la création d'une fenêtre de selection du nombre de joueur
 * \param W : Largeur de l'écrant
 * \param H : Hauteur de l'écrant
 * \return ne retourne ne rien*/
extern void selecte_nb_joueur(int W,int H);

#endif
