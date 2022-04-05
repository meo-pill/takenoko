/**
 * @file Joueur.h
 * @author Nail Léo
 * @brief ce fichier rassemble les fonction de joueur
 * @version 0.1
 * @date 2022-03-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED

#include "index.h"

/**
 * @brief fonction permettant de tester, pour une case donné, si on peut poser un certain effet 
 * 
 * @param j
 * @param eff 
 * @return int
 * 0 pour non, 1 pour oui
 */
int possede_effet(joueur_t * j, effet_E effet)

/**
 * @brief téléporte le panda sur une case et le fait manger deux bambous si possible
 * 
 * @param x 
 * @param y 
 * @return int 
 * retourn 1 s'il y a eu une erreur, 0 sinon
 */
int orage_panda(int x, int y);

/**
 * @brief fonction retourant la victoire d'un joueur
 * 
 * @param J poiteur sur joueur
 * @param maxpoint quantiter maximal de point en fonction des point
 * @return int 
 * boolenen de validation
 */
extern int victoire_joueur(joueur_t const * J, int const maxpoint);

#endif