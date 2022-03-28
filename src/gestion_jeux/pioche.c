/**
 * @file pioche.c
 * @author Leo Nail et Mewen Puren
 * @brief contient les fonctions qui permettent de piocher
 * @version 0.1
 * @date 2022-03-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "../../lib/pioche.h"


extern int pioche_une_case(void){
    int choix = -1, nb_choix =2;
    case_plato_t * choix_de_trois[3];
    case_plato_t * case_ajout;
    int x,y;
    if(filevide()){
        printf ("plus de case en file");
        return 0;
    }
    retirer(&choix_de_trois[0]);
    if(!filevide()){
        retirer(&choix_de_trois[1]);
        if(!filevide()){
            retirer(&choix_de_trois[2]);
        }
        
        printf("le joueur pioche une case");
        // a faire sdl
        while (choix < 0 && choix > nb_choix){
            scanf("%d",&choix);
        }
        for(int i = 0; i<nb_choix+1; i++){
            if(i!= choix+1){
                ajouter(choix_de_trois[i]);
            }
        }
    }
    else{
        case_ajout = choix_de_trois[0];
    }
    printf("donner position de case a ajouter");
    scanf("%d", &x);
    scanf("%d", &y);   
    ajout_tuile(case_ajout,x,y);
    return 1;
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
    if(indique_carte[type] < NBCARTE){
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