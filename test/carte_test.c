#include "../lib/index.h"

int test_triangle(){
    return 0;
}

int test_jardinier(){
    carte_t * carte ;
    carte = creer_carte("jardinier-vert-4-engrais","description","../image/parcelle", 4);
    afficher_carte(carte);

    printf("-------------------teste de la fonction avec un plateau vide--------------------\n");
    if(carte->verif(carte)){
        printf("la fonction a renvoyé que l'objectif est accomplie\n");
    }
    else
        printf("la fonction renvoie que l'objectif n'est pas accomplie\n");

}

int main(){
    initaliser(0);
    test_jardinier();
    suprimer();
}
