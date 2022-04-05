/**
 * @file pioche.h
 * @author Leo Nail et Mewen Puren
 * @brief contient les fonctions qui permettent de piocher
 * @version 0.1
 * @date 2022-03-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef PIOCHE_H_INCLUDED
#define PIOCHE_H_INCLUDED

#include "../lib/index.h"

/**
 * @brief fonction de pioche des tuile
 * 
 * @return case_plato_t** 
 * retour un talbleau de poiteur sur case
 */
extern case_plato_t ** pioche_une_case(void);

/**
 * @brief cette fonction fait piocher une carte à un joueur
 * 
 * @param joueur qui pioche ?
 * @param type  quel type de carte (0 pour panda, 1 pour parcelle et 2 pour jardinier) ?
 */
extern void joueur_pioche_carte(joueur_t * joueur, int type);


#endif