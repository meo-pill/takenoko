#ifndef _H_PLATO_INCLUDED
#define _H_PLATO_INCLUDED
#include "Creation.h"
#include "commande.h"
#include <unistd.h>
#include "../lib/index.h"
/*!
 * \author Morgane Pechon
 * \file Plato.h
 * \brief Permet de gérer le plato de jeux
*/

/**
 * @brief fonction principale du jeux
 * 
 * @param W Largeur de l'écrant
 * @param H Hauteur de l'écrant
 * @param nbJoueur nombre de joueur initialiser
 * @param maxpoint nombre de point maximum initialiser
 */
extern void affiche_Plato(int W,int H,int nbJoueur,int maxpoint);

#endif
