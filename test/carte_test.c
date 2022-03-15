#include "../lib/index.h"

int test_triangle(){
    return 0;
}

/**
 * @brief 
 * fonction pour tester le teste d'un jardinier
 * 
 */
void test_jardinier(){
    carte_t * carte ;
    carte = creer_carte("jardinier-vert-3-quatre","description","../image/parcelle", 4);
    afficher_carte(carte);

    printf("-------------------teste de la fonction avec un plateau vide --------------------\n");
    if(carte->verif(carte)){
        printf("l'objectif est accomplie\n");
    }
    else
        printf("l'objectif n'est pas accomplie\n");

    plateau[1][1]=piece[25];
    plateau[1][1]->nbBambou = 0;

    printf("-------------------teste de la fonction avec un plateau la(les) mauvaise(s) tuile(s) (pas le bon effet)--------------------\n");
    if(carte->verif(carte)){
        printf("l'objectif est accomplie\n");
    }
    else
        printf("l'objectif n'est pas accomplie\n");

    plateau[2][1]=piece[8];
    plateau[2][1]->nbBambou = 4;

    printf("-------------------teste de la fonction avec un plateau la(les) mauvaise(s) tuile(s) (pas la bonne couleur)--------------------\n");
    if(carte->verif(carte)){
        printf("l'objectif est accomplie\n");
    }
    else
        printf("l'objectif n'est pas accomplie\n");
    
    plateau[3][1]=piece[16];
    plateau[4][1]=piece[17];
    plateau[0][0]=piece[26];
    plateau[0][0]->nbBambou = 0;
    plateau[4][1]->nbBambou = 0;
    plateau[3][1]->nbBambou = 0;

    printf("-------------------teste de la fonction avec un plateau la(les) bonne(s) tuile(s), mais pas le bon nombre de bambou--------------------\n");
    if(carte->verif(carte)){
        printf("l'objectif est accomplie\n");
    }
    else
        printf("l'objectif n'est pas accomplie\n");

    plateau[0][0]->nbBambou = 3;
    plateau[1][1]->nbBambou = 3;
    plateau[4][1]->nbBambou = 3;
    plateau[3][1]->nbBambou = 3;

    printf("-------------------teste de la fonction avec un plateau la(les) bonne(s) tuile(s) et le bon nombre de bambou--------------------\n");
    if(carte->verif(carte)){
        printf("l'objectif est accomplie\n");
    }
    else
        printf("l'objectif n'est pas accomplie\n");

}

int main(){
    extraction_fichier_tuile();
    test_jardinier();
    suprimer();
}
