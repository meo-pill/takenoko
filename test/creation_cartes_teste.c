#include <stdio.h>
#include <stdlib.h>
#include "../lib/init_fin.h"
#include "../lib/struct.h"

int main(){
    int i = 0;

    a_null_carte();

    printf("affichage des tableaux AVANT l'initialisation (les adresses) :\n");

    printf("panda :\n");
    for(i = 0; i< NBCARTE;i++){
        printf("    %d\n",cartePanda[i]);
    }
    printf("\n parcelle : \n");
    for(i = 0; i< NBCARTE;i++){
        printf("    %d\n",carteParcelle[i]);
    }
    printf("\n jardinier : \n");
    for(i = 0; i< NBCARTE;i++){
        printf("    %d\n",carteJardinier[i]);
    }

    extraction_fichier_carte();

    printf("affichage des tableaux APRES l'initialisation :\n");

    printf("panda :\n");
    for(i = 0; i< NBCARTE;i++){
        printf("    TYPE : %s IMAGE : %s DESC : %s PT :%d\n",cartePanda[i]->type,cartePanda[i]->image,cartePanda[i]->desc,cartePanda[i]->point);
    }
    printf("\n parcelle : \n");
    for(i = 0; i< NBCARTE;i++){
        printf("    %s\n",carteParcelle[i]->type);
    }
    printf("\n jardinier : \n");
    for(i = 0; i< NBCARTE;i++){
        printf("    %s\n",carteJardinier[i]->type);
    }

    detruire_carte();

}