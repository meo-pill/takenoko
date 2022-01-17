#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED
#endif // BOARD_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Joueur{
    char username[100];
    int nbPoints;
    int nbBambous;
}Joueur;

Joueur J0 = {"", 0, 0};
Joueur J1 = {"", 0, 0};
Joueur J2 = {"", 0, 0};
Joueur J3 = {"", 0, 0};
Joueur J4 = {"", 0, 0};

typedef struct terrain{
    int latitude;
    int longitude;
    int irriguee;
    int bambou;
}terrain;

terrain rentree(terrain a){
    printf("entr�e latitude: ");
    scanf("%d",&(a.latitude));
    printf("entr�e longitude: ");
    scanf("%d",&(a.longitude));
    return a ;
}

terrain panda(terrain a,int *nbPanda){
    a.bambou -= 1;
    printf("Le panda est arriv�, il mange un bambou.\n");
    nbPanda++;
    return(a);
}

terrain jardinier(terrain a,int *nbBambous){
    if (a.irriguee==1){
        a.bambou += 1;
        printf("Le jardinier fait pousser un bambou\n");
    }
    if(a.bambou>=4){
        nbBambous++;
    }
    return(a);
}

terrain irriguer(terrain a){
    a.irriguee = 1;
    printf("Le terrain est maintenant irrigu�");
    return(a);
}

int nombreEtNom(Joueur *JA, Joueur *JB, Joueur *JC, Joueur *JD);
int nbJoueurs = 0 ;
int nombreEtNom(Joueur *JA, Joueur *JB, Joueur *JC, Joueur *JD)
{
    printf("Combien y-a-t-il de joueurs ?\n");
    scanf("%d", &nbJoueurs);
    if(nbJoueurs>=2 && nbJoueurs<=4)
    {
        printf("Entrez le nom du premier joueur :\n");
        scanf("%s", JA->username);
        printf("Entrez le nom du deuxieme joueur:\n");
        scanf("%s", JB->username);
        if(nbJoueurs>=3)
        {
            printf("Entrez le nom du troisieme joueur :\n");
            scanf("%s", JC->username);
        }
        if(nbJoueurs==4)
        {
            printf("Entrez le nom du quatrieme joueur :\n");
            scanf("%s", JD->username);
        }
    }
    else
    {

    }
    return nbJoueurs;
}

int main(){
    int mem = 1;
    int irrigation;
    int posjardinier;
    int pospanda;
    int action;
    int nbPanda=0;
    int nbBambous=0;
    terrain takenoko[100];

    srand(time(NULL));
    printf("Combien de joueurs ?\n");
    scanf("%d",&nbJoueurs);
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
