/**
 * @file pioche.c
 * @author Leo Nail et ???
 * @brief contient les fonctions qui permettent de piocher
 * @version 0.1
 * @date 2022-03-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "../../lib/pioche.h"


extern case_plato_t * pioche_une_case(void){
    case_plato_t * choix_de_trois[3];
    if(filevide()){
        return NULL;
    }
    retirer(&choix_de_trois[0]);
    if(!filevide()){
        retirer(&choix_de_trois[1]);
        if(!filevide()){
            retirer(&choix_de_trois[2]);
        }
    }
    return choix_de_trois;
}

/**
 * @brief cette fonction permet de piocher une carte dans un des trois paquets
 * 
 * @param type 
 *  le type de la carte (0 pour panda, 1 pour parcelle et 2 pour jardinier)
 * @return carte_t* 
 *  un pointeur sur la carte qui a été pioché, ou NULL s'il y a eu une erreur
 */
carte_t * pioche_carte (int type){
    if(indique_carte[type] <= NBCARTE){
        indique_carte[type] ++;
        switch (type)
        {
        case 0:
            return cartePanda[indique_carte[type]-1];
        case 1 :
            return carteParcelle[indique_carte[type]-1];
        case 2 :
            return carteJardinier[indique_carte[type]-1];
        default:
            printf("--------------erreur dans la fonction de pioche de carte : mauvais type spécifié-----------------\n");
            return NULL;
        }
    }
    printf("--------------erreur dans la fonction de pioche de carte : plus de carte dans cette pioche-----------------\n");
    return NULL;
}