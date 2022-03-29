/**
 * @file tour.c
 * @author MEWEN
 * @brief gestion principale des tour du jeux
 * @version 0.1
 * @date 2022-03-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "../../lib/tour.h"




extern int victoire_joueur(joueur_t const * J, int const maxpoint){
    return (J->nbObjectif >= maxpoint);
}

