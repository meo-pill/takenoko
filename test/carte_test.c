/**
 * @file carte_test.c
 * @author Léo Nail
 * @brief ce fichier sert à tester les fonction de vérification
 * @version 0.1
 * @date 2022-03-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../lib/index.h"

/**
 * @brief fonction utilitaire, servant à afficher le plateau sur l'invite de commande
 * 
 */
void afficher_plateau(){
    int i,j;
    int balance = 0;
    for(i = 0; i<NBTUILES;i++){
      if(balance == 1){
        printf("   ");
        balance = 0;
      }
      else
        balance = 1;
      
      for(j=0;j<NBTUILES;j++){
        if(plateau[i][j] != NULL){
          printf(" %5d", plateau[i][j] -> nbBambou);

          if(panda.x == i && panda.y == j)
            printf("P");
          if(panda.x == i && panda.y == j)
            printf("J");
        }
        else
          printf(" %5d", 999);
      }
      printf("\n\n");
    }
}


/**
 * @brief 
 * fonction pour tester la vérification des cartes jardiniers
 * 
 */
void test_jardinier(){
    carte_t * carte ;
    carte = creer_carte("jardinier-vert-3-quatre","description","../image/parcelle", 4);
    afficher_carte(carte);

    printf("-------------------teste de la fonction avec un plateau vide --------------------\n");
    if(carte->verif(carte,J[0])){
        printf("l'objectif est accomplie\n");
    }
    else
        printf("l'objectif n'est pas accomplie\n");

    plateau[1][1]=piece[25];
    plateau[1][1]->nbBambou = 0;

    printf("-------------------teste de la fonction avec un plateau la(les) mauvaise(s) tuile(s) (pas le bon effet)--------------------\n");
    if(carte->verif(carte,J[0])){
        printf("l'objectif est accomplie\n");
    }
    else
        printf("l'objectif n'est pas accomplie\n");

    plateau[2][1]=piece[8];
    plateau[2][1]->nbBambou = 4;

    printf("-------------------teste de la fonction avec un plateau la(les) mauvaise(s) tuile(s) (pas la bonne couleur)--------------------\n");
    if(carte->verif(carte,J[0])){
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
    if(carte->verif(carte,J[0])){
        printf("l'objectif est accomplie\n");
    }
    else
        printf("l'objectif n'est pas accomplie\n");

    plateau[0][0]->nbBambou = 3;
    plateau[1][1]->nbBambou = 3;
    plateau[4][1]->nbBambou = 3;
    plateau[3][1]->nbBambou = 3;

    printf("-------------------teste de la fonction avec un plateau la(les) bonne(s) tuile(s) et le bon nombre de bambou--------------------\n");
    if(carte->verif(carte,J[0])){
        printf("l'objectif est accomplie\n");
    }
    else
        printf("l'objectif n'est pas accomplie\n");

}

/**
 * @brief fonction servant à tester la vérification des cartes panda
 * 
 */
void test_panda(){
    // création du joueur (simplifié)
    J[0] = malloc(sizeof(joueur_t));
    carte_t * panda_vert = creer_carte("panda-vert","description","img",3);
    carte_t * panda_mult = creer_carte("panda-multi","descr","img",6);

    printf("-------------- teste sans bambou ----------\n");
    J[0]->bambou[0] = 0;
    J[0]->bambou[1] = 0;
    J[0]->bambou[2] = 0;

    if(panda_vert->verif(panda_vert,J[0]))
        printf("l'objectif est accomplie pour panda vert\n");
    else
        printf("l'objectif n'est pas accomplie pour panda vert\n");
    
    if(panda_mult->verif(panda_mult,J[0]))
        printf("l'objectif est accomplie pour panda multicolor\n");
    else
        printf("l'objectif n'est pas accomplie pour panda multicolor\n");


    printf("-------------- teste avec 2 bambou de couleur jaune----------\n");
    J[0]->bambou[0] = 2;

    if(panda_vert->verif(panda_vert,J[0]))
        printf("l'objectif est accomplie pour panda vert\n");
    else
        printf("l'objectif n'est pas accomplie pour panda vert\n");
    
    if(panda_mult->verif(panda_mult,J[0]))
        printf("l'objectif est accomplie pour panda multicolor\n");
    else
        printf("l'objectif n'est pas accomplie pour panda multicolor\n");

    printf("-------------- teste avec 2 bambou de couleur verte en plus----------\n");
    J[0]->bambou[2] = 2;

    if(panda_vert->verif(panda_vert,J[0]))
        printf("l'objectif est accomplie pour panda vert\n");
    else
        printf("l'objectif n'est pas accomplie pour panda vert\n");
    
    if(panda_mult->verif(panda_mult,J[0]))
        printf("l'objectif est accomplie pour panda multicolor\n");
    else
        printf("l'objectif n'est pas accomplie pour panda multicolor\n");

    printf("-------------- teste avec 2 bambou de couleur rose en plus----------\n");
    J[0]->bambou[1] = 2;

    if(panda_vert->verif(panda_vert,J[0]))
        printf("l'objectif est accomplie pour panda vert\n");
    else
        printf("l'objectif n'est pas accomplie pour panda vert\n");
    
    if(panda_mult->verif(panda_mult,J[0]))
        printf("l'objectif est accomplie pour panda multicolor\n");
    else
        printf("l'objectif n'est pas accomplie pour panda multicolor\n");
    
    free(J[0]);
}


int main(){
    extraction_fichier_tuile();
    //test_jardinier();
    test_panda();
    suprimer();
}
