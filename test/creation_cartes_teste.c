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
        printf("    %d\n",(int)cartePanda[i]);
    }
    printf("\n parcelle : \n");
    for(i = 0; i< NBCARTE;i++){
        printf("    %d\n",(int)carteParcelle[i]);
    }
    printf("\n jardinier : \n");
    for(i = 0; i< NBCARTE;i++){
        printf("    %d\n",(int)carteJardinier[i]);
    }

    extraction_fichier_carte();

    printf("affichage des tableaux APRES l'initialisation :\n");

    printf("panda :\n");
    for(i = 0; i< NBCARTE;i++){
        afficher_carte(cartePanda[i]);
    }
    printf("\n parcelle : \n");
    for(i = 0; i< NBCARTE;i++){
       afficher_carte(carteParcelle[i]);
    }
    printf("\n jardinier : \n");
    for(i = 0; i< NBCARTE;i++){
        afficher_carte(carteJardinier[i]);
    }

    detruire_carte();

    printf("affichage des tableaux APRES la destruction (les adresses) :\n");

    printf("panda :\n");
    for(i = 0; i< NBCARTE;i++){
        printf("    %d\n",(int)cartePanda[i]);
    }
    printf("\n parcelle : \n");
    for(i = 0; i< NBCARTE;i++){
        printf("    %d\n",(int)carteParcelle[i]);
    }
    printf("\n jardinier : \n");
    for(i = 0; i< NBCARTE;i++){
        printf("    %d\n",(int)carteJardinier[i]);
    }
    a_null_carte();
}