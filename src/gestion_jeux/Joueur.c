/**
 * @file Joueur.c
 * @author Nail Léo
 * @brief ce fichier rassemble 
 * @version 0.1
 * @date 2022-03-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../../lib/index.h"

/**
 * @brief fonction permettant de tester, pour une case donné, si on peut poser un certain effet 
 * 
 * @param j
 * @param eff 
 * @return int
 * 0 pour non, 1 pour oui
 */
int possede_effet(joueur_t * j, effet_E effet){
    if(j->effSpe[effet] <= 0){
        printf("\n----------------------le joueur %d ne possède pas d'effet %d------------------------\n\n",j->couleurJoueur,effet);
        return 0;
    }
    return 1;
}

/**
 * @brief téléporte le panda sur une case et le fait manger deux bambous si possible
 * 
 * @param x 
 * @param y 
 * @return int 
 * retourn 1 s'il y a eu une erreur, 0 sinon
 */
int orage_panda(int x, int y){
    if(!case_existe(x,y)){
        printf("\n--------------erreur, la case spécifié n'existe pas----------------------\n\n");
        return 1;
    }
    else{
        panda.x = x;
        panda.y = y;
        if(plateau[x][y]->nbBambou < 2)
            plateau[x][y]->nbBambou = 0;
        else
            plateau[x][y]->nbBambou -= 2;
    }
    return 0;
}

extern int victoire_joueur(joueur_t const * J, int const maxpoint){
    return (J->nbObjectif >= maxpoint);
}
