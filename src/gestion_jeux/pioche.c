#include "../../lib/pioche.h"


extern case_plato_t ** pioche_une_case(void){
    case_plato_t ** choix_de_trois=NULL;
    choix_de_trois=malloc(sizeof(case_plato_t *));
    if(filevide()){
        return NULL;
    }
    choix_de_trois[0]=retirer();
    if(!filevide()){
        choix_de_trois[1]=retirer();
        if(!filevide()){
            (choix_de_trois)[2]=retirer();
        }
	else
		(choix_de_trois)[2]=NULL;
    }
    else{
	    choix_de_trois[1]=NULL;
	    (choix_de_trois)[2]=NULL;
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
static carte_t * pioche_carte (int type){
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

extern void joueur_pioche_carte(joueur_t * joueur, int type){
    if(type > 2 || type < 0){
        printf("------------------erreur, le type défnie( %d ) n'est pas bon dans la fonction joueur_pioche_carte----------------------\n",type);
        return;
    }
    int i ;
    for(i = 0; i<TAILLE_MAIN ; i++){
        if(joueur->main_J[i] == NULL){
            joueur->main_J[i] = pioche_carte(type);
	    return;
	}
    }
}

