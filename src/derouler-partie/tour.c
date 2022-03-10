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
#include "../../lib/index.h"

/**
 * @brief premier fonction d'inisialisaiton pour donner une valeur varible
 * 
 * @param nb_joueur 
 * @param maxpoint 
 * @return int 
 */
static int debut_partie(int * nb_joueur, int * maxpoint){
    *nb_joueur = 0;
    while(nb_joueur>4 || nb_joueur < 1){
        printf("donner le nb joueur :\n");
        scanf("%d",nb_joueur);
    }
    initaliser(*nb_joueur);
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
        return(1);
        break;
    }
    return(0);
}

extern void tour_jeux(void){
    int nb_joueur, maxpoint;
    if (debut_partie(&nb_joueur, &maxpoint)){
        printf("problème de selection du nb joueur");
        return;
    }

    
}