
#include "../lib/pioche.h"
#include "../lib/init_fin.h"

int main(){
    carte_t * panda;
    carte_t * jardinier;
    carte_t * parcelle;
    int  i;

    initialiser(0);

    printf("test d'une première pioche :\n");
    panda = pioche_carte(0);
    parcelle = pioche_carte(1);
    jardinier = pioche_carte(2);

    afficher_carte(panda);
    afficher_carte(parcelle);
    afficher_carte(jardinier);

    printf("on continue de piocher des parcelles jusqu'à ce que la fonction renvoie une erreur : \n");

    for(i = 0; i<NBCARTE;i++){
        parcelle = pioche_carte(1);
        afficher_carte(parcelle);
    }

    

    suprimer();
}