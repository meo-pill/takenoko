#include "../fichier_h/Board.h"

int rentree(S_terrain coordonee[100][100]){
    int lat = -1, lon = -1;

    printf("donner la latitude longitude de la nouvelle tuile entre 0 et 100 :\n");
    while (lat >= 100 || lat < 0){
        printf("latitude :");
        scanf("%d",&lat);
    }
    while (lon >= 100 || lon < 0){
        printf("longitude :");
        scanf("%d",&lon);
    }

    if (coordonee[lat-1][lon-1].valide==1||coordonee[lat-1][lon].valide==1||coordonee[lat-1][lon+1].valide==1\
    ||coordonee[lat][lon-1].valide==1||coordonee[lat][lon+1].valide==1||coordonee[lat+1][lon-1].valide==1\
    ||coordonee[lat+1][lon].valide==1||coordonee[lat+1][lon+1].valide==1){
        coordonee[lat][lon].valide = 1;
        printf("la tuile a été ajouter au coordonée %d,%d\n",lat,lon);
        return 1;
    }
    else {
        printf("la tuile n'a pas été ajouter car au milieux de rien\n");
        return 0;
    }
}

int irriguer(S_terrain coordonee[100][100]){
    int lat = -1, lon = -1;

    printf("donner la latitude longitude de la tuile a irriguer entre 0 et 100 :\n");
    while (lat >= 100 || lat < 0){
        printf("latitude :");
        scanf("%d",&lat);
    }
    while (lon >= 100 || lon < 0){
        printf("longitude :");
        scanf("%d",&lon);
    }

    if (coordonee[lat-1][lon-1].valide==1||coordonee[lat-1][lon].valide==1||coordonee[lat-1][lon+1].valide==1\
    ||coordonee[lat][lon-1].valide==1||coordonee[lat][lon+1].valide==1||coordonee[lat+1][lon-1].valide==1\
    ||coordonee[lat+1][lon].valide==1||coordonee[lat+1][lon+1].valide==1){
        coordonee[lat][lon].irriguee = 1;
        printf("la tuile a été irriguer au coordonée %d,%d\n",lat,lon);
        return 1;
    }
    else {
        printf("la tuile n'existe pas\n");
        return 0;
    }

}

int panda(S_terrain coordonee[100][100]){
    int lat = -1, lon = -1;

    printf("donner la latitude longitude pour deplacer le panda entre 0 et 100 :\n");
    while (lat >= 100 || lat < 0){
        printf("latitude :");
        scanf("%d",&lat);
    }
    while (lon >= 100 || lon < 0){
        printf("longitude :");
        scanf("%d",&lon);
    }

    if (coordonee[lat][lon].valide==1){
        if (coordonee[lat][lon].bambou >= 1){
            coordonee[lat][lon].bambou ++;
            printf("le panda mange un banboo il en reste %d\n",coordonee[lat][lon].bambou);
            return 1;
        }
        else{
            printf("il n'y a pas de bamboo sur cette tuile\n");
            return 0;
        }
    }
    else{
        printf("la tuile selectionner n'est pas existante\n");
        return 0;
    }

}

int jardinier(S_terrain coordonee[100][100]){
    int lat = -1, lon = -1;

    printf("donner la latitude longitude pour deplacer le jardinier entre 0 et 100 :\n");
    while (lat >= 100 || lat < 0){
        printf("latitude :");
        scanf("%d",&lat);
    }
    while (lon >= 100 || lon < 0){
        printf("longitude :");
        scanf("%d",&lon);
    }

    if (coordonee[lat][lon].valide==1){
        if (coordonee[lat][lon].irriguee >= 1){
            coordonee[lat][lon].bambou ++;
            printf("le jardinier plante un banboo il y en a desormais %d\n",coordonee[lat][lon].bambou);
            return 1;
        }
        else{
            printf("cette tuile n'est pas irriguée on ne peux rien y faire pousser\n");
            return 0;
        }
    }
    else{
        printf("la tuile selectionner n'est pas existante\n");
        return 0;
    }

}

void intialisation (S_terrain coordonee[100][100]){
    int lat = -1, lon = -1;


    printf("initialisaiton de la partie :\n");

    for(int i = 0; i<100; i++){
        for(int j = 0; j<100; j++){
            coordonee[i][j].irriguee = 0;
            coordonee[i][j].bambou = 0;
            coordonee[i][j].valide = 0;
        }
    }

    printf("donner la latitude longitude du lac entre 0 et 100 :\n");
    while (lat >= 100 || lat < 0){
        printf("latitude :");
        scanf("%d",&lat);
    }
    while (lon >= 100 || lon < 0){
        printf("longitude :");
        scanf("%d",&lon);
    }
    printf("le lac se trouve désormait en %d,%d\n",lat,lon);
    coordonee[lat][lon].irriguee = -1;
    coordonee[lat][lon].valide = 1;
}

void nombreEtNom(S_Joueur *Joueur){
    int nbJoueurs = 0;

    while(nbJoueurs < 1){
        printf("Combien y-a-t-il de joueurs ?\n");
        scanf("%d", &nbJoueurs);
    }

    if(nbJoueurs>=2 && nbJoueurs<=4){
       
    }
    else
    {

    }
}
