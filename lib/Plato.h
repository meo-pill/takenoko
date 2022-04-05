#ifndef _H_PLATO_INCLUDED
#define _H_PLATO_INCLUDED
#include "Creation.h"
#include "commande.h"
/*!
 * \author Morgane Pechon
 * \file Plato.h
 * \brief Permet de gérer le plato de jeux
*/

/*! \brief Acces a la création d'une fenêtre de selection du nombre de joueur
 * \param W : Largeur de l'écrant
 * \param H : Hauteur de l'écrant
 * \return ne retourne ne rien*/
extern void selecte_nb_joueur(int W,int H);
#endif
