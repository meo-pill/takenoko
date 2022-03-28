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

/**
 * @brief premier fonction d'inisialisaiton pour donner une valeur au varible
 * et faire appelle a la fonction d'inisialisation des tuile et carte
 * 
 * @param nb_joueur atribution du nombre de joueur
 * @param maxpoint atribution du nombre de carte a valider en conséquence
 * @return int pour le retour d'erreur
 */
extern int debut_partie(int const * nb_joueur, int * maxpoint){
    initialiser(*nb_joueur);
    /**
     * @brief établisement la variable du maxpoint en fonciton du nb de joueur
     * 
     */
    switch (*nb_joueur){
    case 2:
        *maxpoint = MAXNB2J;
        break;
    case 3:
        *maxpoint = MAXNB3J;
        break;
    case 4:
        *maxpoint = MAXNB4J;
        break;
    default:
        return(0);
    }
    return(1);
}



extern int victoire_joueur(joueur_t const * J, int const maxpoint){
    return (J->nbObjectif >= maxpoint);
}

