#include <stdio.h>
#include <stdlib.h>
#include "../fichier_h/Board.h"



int main(){
    int mem = 1;
    int irrigation;
    int posjardinier;
    int pospanda;
    int action;
    int nbPanda=0;
    int nbBambous=0;
    int nbJoueurs;
    S_terrain takenoko[100];
    S_Joueur * Joueur;

    srand(time(NULL));
    nbJoueurs = nombreEtNom(*Joueur);


    if(nbJoueurs==2){
        printf("J1 ton objectif est de faire pousser 4 bambous ou plus sur 3 parcelles diff�rentes\n");
        printf("J2 ton objectif est de faire manger au panda 12 bambous\n");
        int nbBambous=0;
        int nbPousse=0;
    }
    else if(nbJoueurs==4){
        switch(rand()%4 + 1){
            case 1:
            printf("J1, ton objectif est de faire pousser 4 bambous de haut sur 3 parcelles diff�rentes\n");
            printf("J2, J3 et J4, vous devez faire nourrir 12 bambous au panda\n");
            break;
            case 2:
            printf("J2, ton objectif est de faire pousser 4 bambous de haut sur 3 parcelles diff�rentes\n");
            printf("J1, J3 et J4, vous devez faire nourrir 12 bambous au panda\n");
            break;
            case 3:
            printf("J3, ton objectif est de faire pousser 4 bambous de haut sur 3 parcelles diff�rentes\n");
            printf("J1, J2 et J4, vous devez faire nourrir 12 bambous au panda\n");
            break;
            case 4:
            printf("J4, ton objectif est de faire pousser 4 bambous de haut sur 3 parcelles diff�rentes\n");
            printf("J1, J2 et J3, vous devez faire nourrir 12 bambous au panda\n");
            break;
            }
    }
    else if(nbJoueurs==3){
        switch(rand()%3 + 1){
            case 1:
            printf("J1, ton objectif est de faire pousser 4 bambous de haut sur 3 parcelles diff�rentes\n");
            printf("J2 et J3, vous devez faire nourrir 12 bambous au panda\n");
            break;
            case 2:
            printf("J2, ton objectif est de faire pousser 4 bambous de haut sur 3 parcelles diff�rentes\n");
            printf("J1 et J3 vous devez faire nourrir 12 bambous au panda\n");
            break;
            case 3:
            printf("J3, ton objectif est de faire pousser 4 bambous de haut sur 3 parcelles diff�rentes\n");
            printf("J1 et J2 et vous devez faire nourrir 12 bambous au panda\n");
            break;
            }
    }
    do {
        printf("Vous mettez un terrain(1) ou d�placer le panda(2) / jardinier(3) / irriguer(4) / arr�ter(0) ?\n");
        scanf("%d",&action);
        if (action==1){
            takenoko[mem] = rentree(takenoko[mem]);
            mem = mem+1;
        }
        if (action==2){
            printf("Sur quel terrain va le panda ?\n");
            scanf("%d",&pospanda);
            takenoko[pospanda] = panda(takenoko[pospanda],&nbPanda);
        }
        if (action==3){
            printf("Sur quel terrain va le jardinier ?\n");
            scanf("%d",&posjardinier);
            takenoko[posjardinier] = jardinier(takenoko[posjardinier],&nbBambous);
        }
        if (action==4){
            printf("Sur quel terrain creusez-vous ?\n");
            scanf("%d",&irrigation);
            takenoko[irrigation] = irriguer(takenoko[irrigation]);
        }
        if (nbBambous==4){
            action=0;
            printf("Le jardinier � remplit son objectif, f�licitations.\n");
        }
        if (nbPanda==12){
            action=0;
            printf("Le panda est rassasi�, f�licitations.\n");
        }
    }while (action != 0);
    return(0);
}
