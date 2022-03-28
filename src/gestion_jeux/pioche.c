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
 * @brief cette fonction fait piocher une carte à un joueur
 * 
 * @param joueur qui pioche ?
 * @param type  quel type de carte (0 pour panda, 1 pour parcelle et 2 pour jardinier) ?
 */
extern
void joueur_pioche_carte(joueur_t * joueur, int type){
    if(type > 2 || type < 0){
        printf("------------------erreur, le type défnie( %d ) n'est pas bon dans la fonction joueur_pioche_carte----------------------\n",type);
        return;
    }
    int i ;
    for(i = 0; i<TAILLE_MAIN ; i++){
        if(joueur->main_J[i] == NULL)
            joueur->main_J[i] = pioche_carte(type);
    }
}

/**
 * @brief cette fonction permet de piocher une carte dans un des trois paquets
 * 
 * @param type 
 *  le type de la carte (0 pour panda, 1 pour parcelle et 2 pour jardinier)
 * @return carte_t* 
 *  un pointeur sur la carte qui a été pioché, ou NULL s'il y a eu une erreur
 */
static
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