#include "../fichier_h/index.h"
/** 
 * fichier avec les fonction d'initialisation et de supression du jeu
 * 
 */

static void extraction_fichier(void){
    /** création et ouverture des fichier contenant les tuile et les carte objectif */
    FILE * ficTuile = NULL;
    FILE * ficCarte = NULL;
    char temp[7];
    
    ficTuile = fopen("../asset/carte_objectif.txt","r");
    ficCarte = fopen("../asset/carte_objectif.txt","r");

    
}



extern void initaliser(void){
    extraction_fichier();
}

extern void suprimer(void){

}

