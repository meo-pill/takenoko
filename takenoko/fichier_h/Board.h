#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED
#endif // BOARD_H_INCLUDED

typedef struct T_Joueur{
    char username[100];
    int nbPoints;
    int nbBambous;
}S_Joueur;

typedef struct T_terrain{
    int latitude;
    int longitude;
    int irriguee;
    int bambou;
    int valide;
}S_terrain;

int rentree(S_terrain coordonee[100][100]);

int panda(S_terrain coordonee[100][100]);

int jardinier(S_terrain coordonee[100][100]);

int irriguer(S_terrain coordonee[100][100]);

void intialisation (S_terrain coordonee[100][100]);

int nombreEtNom(S_Joueur *Joueur);