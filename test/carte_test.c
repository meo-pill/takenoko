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
          printf(" %5d", plateau[i][j] -> Coul+10*(plateau[i][j]->iriguer));

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
 * @brief cette fonction sert à tester les cartes parcelles ayant une forme de triangle
 * 
 */
void test_triangle(){

    printf("----------------creation de la carte------------------\n");
    carte_t * carte = creer_carte("parcelle-verte-triangle","desc","img",4);

    printf("-----------------------creation et initialisation du plateau---------------------------\n");
    plateau[1][0] = piece[26];
    plateau[1][1] = piece[25];
    plateau[0][1] = piece[24];

    plateau[1][0]->iriguer = 1;
    plateau[1][1]->iriguer = 1;
    plateau[0][1]->iriguer = 1;

    printf("-------------------------afichage du plateau-----------------------------\n");
    afficher_plateau();


    printf("---------------------test avec les bonnes conditions (triangle avec pointe vers le haut)------------------------\n");
    if(carte->verif(carte,J[0]) == 1){
        printf("l'objectif est accomplie\n");
    }
    else
        printf("l'objectif n'est pas accomplie\n");
    
    printf("---------------------test avec les bonnes conditions (triangle avec pointe vers le bas)------------------------\n");
    plateau[1][0] = NULL;
    plateau[0][2] = piece[24];

    printf("-------------------------afichage du plateau-----------------------------\n");
    afficher_plateau();

    if(carte->verif(carte,J[0]) == 1){
        printf("l'objectif est accomplie\n");
    }
    else
        printf("l'objectif n'est pas accomplie\n");

    printf("------------------test dans les mêmes conditions sans irrigation-------------------------------------\n");

    plateau[0][2]->iriguer = 0;
    plateau[1][1]->iriguer = 0;
    plateau[0][1]->iriguer = 0;

    if(carte->verif(carte,J[0]) == 1){
        printf("l'objectif est accomplie\n");
    }
    else
        printf("l'objectif n'est pas accomplie\n");


}

/**
 * @brief cette fonction sert à tester les cartes parcelles ayant une forme de ligne
 * 
 */
void test_ligne(){
    printf("début du test sur les carte parcelle ligne");
    printf("----------------creation de la carte------------------\n");
    carte_t * carte = creer_carte("parcelle-verte-ligne","desc","img",4);

    printf("--------creation et initialisation du plateau---------\n");
    plateau[0][1] = piece[26];
    plateau[0][2] = piece[25];
    plateau[0][3] = piece[24];
    plateau[1][0] = piece[23];
    plateau[1][1] = piece[22];
    plateau[2][0] = piece[21];
    plateau[2][1] = piece[20];
    plateau[2][2] = piece[19];
    plateau[3][0] = piece[18];
    plateau[3][2] = piece[17];

    plateau[0][1]->iriguer = 0;
    plateau[0][2]->iriguer = 0;
    plateau[0][3]->iriguer = 0;
    plateau[1][0]->iriguer = 0;
    plateau[1][1]->iriguer = 0;
    plateau[2][0]->iriguer = 0;
    plateau[2][1]->iriguer = 0;
    plateau[2][2]->iriguer = 0;
    plateau[3][0]->iriguer = 0;
    plateau[3][2]->iriguer = 0;

    printf("-------------------------afichage du plateau-----------------------------\n");
    afficher_plateau();
    
    printf("----------------------------test sans irigation--------------------------\n");

    if(carte->verif(carte,J[0]) == 1){
        printf("l'objectif est accomplie\n");
    }
    else
        printf("l'objectif n'est pas accomplie\n");

    printf("-----------------------------test horizontal-----------------------------\n");
    plateau[0][1]->iriguer = 1;
    plateau[0][2]->iriguer = 1;
    plateau[0][3]->iriguer = 1;

    afficher_plateau();

    if(carte->verif(carte,J[0]) == 1)
        printf("l'objectif est accomplie\n");
    else
        printf("l'objectif n'est pas accomplie\n");
    
    printf("-----------------------------test vertical droit(ligne paire)------------\n");
    plateau[0][1]->iriguer = 1;
    plateau[0][2]->iriguer = 0;
    plateau[0][3]->iriguer = 0;
    plateau[1][1]->iriguer = 1;
    plateau[2][2]->iriguer = 1;

    afficher_plateau();

    if(carte->verif(carte,J[0]) == 1)
        printf("l'objectif est accomplie\n");
    else
        printf("l'objectif n'est pas accomplie\n");
    
    printf("-----------------------------test vertical gauche(ligne paire)------------\n");
    plateau[0][1]->iriguer = 1;
    plateau[1][1]->iriguer = 0;
    plateau[2][2]->iriguer = 0;
    plateau[1][0]->iriguer = 1;
    plateau[2][0]->iriguer = 1;

    afficher_plateau();

    if(carte->verif(carte,J[0]) == 1)
        printf("l'objectif est accomplie\n");
    else
        printf("l'objectif n'est pas accomplie\n");
    
    printf("-----------------------------test vertical droit(ligne impaire)------------\n");
    plateau[0][1]->iriguer = 0;
    plateau[1][0]->iriguer = 0;
    plateau[2][0]->iriguer = 0;
    plateau[1][1]->iriguer = 1;
    plateau[2][2]->iriguer = 1;
    plateau[3][2]->iriguer = 1;
    

    afficher_plateau();

    if(carte->verif(carte,J[0]) == 1)
        printf("l'objectif est accomplie\n");
    else
        printf("l'objectif n'est pas accomplie\n");
    
    printf("-----------------------------test vertical gauche(ligne paire)------------\n");
    plateau[2][2]->iriguer = 0;
    plateau[3][2]->iriguer = 0;
    plateau[2][1]->iriguer = 1;
    plateau[3][0]->iriguer = 1;

    afficher_plateau();

    if(carte->verif(carte,J[0]) == 1)
        printf("l'objectif est accomplie\n");
    else
        printf("l'objectif n'est pas accomplie\n");

}


void test_losange(){
    printf("début du test sur les carte parcelle losange");
    printf("----------------creation de la carte------------------\n");
    carte_t * carte_verte = creer_carte("parcelle-verte/verte-losange","desc","img",3);
    carte_t * carte_multi = creer_carte("parcelle-jaune/verte-losange","des","img",3);

    printf("--------creation et initialisation du plateau---------\n");
    plateau[0][1] = piece[26];
    plateau[0][2] = piece[25];
    plateau[1][0] = piece[0];
    plateau[1][1] = piece[24];
    plateau[1][2] = piece[23];
    plateau[2][1] = piece[1];
    plateau[2][2] = piece[22];
    plateau[2][3] = piece[21];
    plateau[3][1] = piece[2];
    plateau[3][2] = piece[20];

    plateau[0][1]->iriguer = 0;
    plateau[0][2]->iriguer = 0;
    plateau[1][0]->iriguer = 0;
    plateau[1][1]->iriguer = 0;
    plateau[1][2]->iriguer = 0;
    plateau[2][1]->iriguer = 0;
    plateau[2][2]->iriguer = 0;
    plateau[2][3]->iriguer = 0;
    plateau[3][1]->iriguer = 0;
    plateau[3][2]->iriguer = 0;

     printf("-------------------------afichage du plateau-----------------------------\n");
    afficher_plateau();
    
    printf("----------------------------test sans irigation--------------------------\n");

    if(carte_verte->verif(carte_verte,J[0]) == 1){
        printf("l'objectif vert est accomplie\n");
    }
    else
        printf("l'objectif vert n'est pas accomplie\n");

    if(carte_multi->verif(carte_multi,J[0]) == 1){
        printf("l'objectif multicolor est accomplie\n");
    }
    else
        printf("l'objectif multicolor n'est pas accomplie\n");

    printf("------------------------test avec losange multicolor paire--------------\n");

    plateau[0][1]->iriguer = 1;
    plateau[1][0]->iriguer = 1;
    plateau[1][1]->iriguer = 1;
    plateau[2][1]->iriguer = 1;

    afficher_plateau();

    if(carte_verte->verif(carte_verte,J[0]) == 1){
        printf("l'objectif vert est accomplie\n");
    }
    else
        printf("l'objectif vert n'est pas accomplie\n");

    if(carte_multi->verif(carte_multi,J[0]) == 1){
        printf("l'objectif multicolor est accomplie\n");
    }
    else
        printf("l'objectif multicolor n'est pas accomplie\n");
    
    printf("------------------------test avec losange multicolor impaire------------\n");

    plateau[0][1]->iriguer = 0;
    plateau[1][0]->iriguer = 0;
    plateau[2][2]->iriguer = 1;
    plateau[3][1]->iriguer = 1;

    afficher_plateau();

    if(carte_verte->verif(carte_verte,J[0]) == 1){
        printf("l'objectif vert est accomplie\n");
    }
    else
        printf("l'objectif vert n'est pas accomplie\n");

    if(carte_multi->verif(carte_multi,J[0]) == 1){
        printf("l'objectif multicolor est accomplie\n");
    }
    else
        printf("l'objectif multicolor n'est pas accomplie\n");

    printf("------------------------test avec losange vert paire-------------------\n");
    plateau[2][1]->iriguer = 0;
    plateau[3][1]->iriguer = 0;
    plateau[0][2]->iriguer = 1;
    plateau[1][2]->iriguer = 1;

    afficher_plateau();

    if(carte_verte->verif(carte_verte,J[0]) == 1){
        printf("l'objectif vert est accomplie\n");
    }
    else
        printf("l'objectif vert n'est pas accomplie\n");

    if(carte_multi->verif(carte_multi,J[0]) == 1){
        printf("l'objectif multicolor est accomplie\n");
    }
    else
        printf("l'objectif multicolor n'est pas accomplie\n");

    printf("------------------------test avec losange vert impaire-----------------\n");
    plateau[0][2]->iriguer = 0;
    plateau[1][1]->iriguer = 0;
    plateau[2][3]->iriguer = 1;
    plateau[3][2]->iriguer = 1;

    afficher_plateau();

    if(carte_verte->verif(carte_verte,J[0]) == 1){
        printf("l'objectif vert est accomplie\n");
    }
    else
        printf("l'objectif vert n'est pas accomplie\n");

    if(carte_multi->verif(carte_multi,J[0]) == 1){
        printf("l'objectif multicolor est accomplie\n");
    }
    else
        printf("l'objectif multicolor n'est pas accomplie\n");
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

/**
 * @brief cette fonction sert à tester les cartes parcelles ayant une forme d'arc
 * 
 */
void test_arc(){
    printf("début du test sur les carte parcelle arc");
    printf("----------------creation de la carte------------------\n");
    carte_t * carte = creer_carte("parcelle-verte-arc","desc","img",4);

    printf("--------creation et initialisation du plateau---------\n");
    plateau[0][1] = piece[26];
    plateau[1][0] = piece[23];
    plateau[1][1] = piece[22];
    plateau[2][1] = piece[20];
    plateau[2][2] = piece[19];
    plateau[3][1] = piece[17];

    plateau[0][1]->iriguer = 0;
    plateau[1][0]->iriguer = 0;
    plateau[1][1]->iriguer = 0;
    plateau[2][1]->iriguer = 0;
    plateau[2][2]->iriguer = 0;
    plateau[3][1]->iriguer = 0;

    printf("-------------------------afichage du plateau-----------------------------\n");
    afficher_plateau();
    
    printf("----------------------------test sans irigation--------------------------\n");

    if(carte->verif(carte,J[0]) == 1){
        printf("l'objectif est accomplie\n");
    }
    else
        printf("l'objectif n'est pas accomplie\n");

    printf("-----------------------------test vertical gauche(ligne paire)------------\n");
    plateau[0][1]->iriguer = 1;
    plateau[1][0]->iriguer = 1;
    plateau[2][1]->iriguer = 1;

    afficher_plateau();

    if(carte->verif(carte,J[0]) == 1)
        printf("l'objectif est accomplie\n");
    else
        printf("l'objectif n'est pas accomplie\n");
    
    printf("-----------------------------test vertical droit(ligne paire)------------\n");
    plateau[1][1]->iriguer = 1;
    plateau[1][0]->iriguer = 0;

    afficher_plateau();

    if(carte->verif(carte,J[0]) == 1)
        printf("l'objectif est accomplie\n");
    else
        printf("l'objectif n'est pas accomplie\n");
    
    printf("-----------------------------test vertical gauche(ligne impaire)------------\n");
    plateau[0][1]->iriguer = 0;
    plateau[3][1]->iriguer = 1;
    

    afficher_plateau();

    if(carte->verif(carte,J[0]) == 1)
        printf("l'objectif est accomplie\n");
    else
        printf("l'objectif n'est pas accomplie\n");
    
    printf("-----------------------------test vertical droit(ligne impaire)------------\n");
    plateau[2][2]->iriguer = 1;
    plateau[2][1]->iriguer = 0;

    afficher_plateau();

    if(carte->verif(carte,J[0]) == 1)
        printf("l'objectif est accomplie\n");
    else
        printf("l'objectif n'est pas accomplie\n");

}

int main(){
    extraction_fichier_tuile();
    /*test_jardinier();*/
    /*test_panda();*/
    /*test_ligne();*/
    /*test_losange*/
    test_arc();
    
    suprimer(0);
}
