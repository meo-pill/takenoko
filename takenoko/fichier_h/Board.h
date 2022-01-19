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

S_terrain rentree(S_terrain coordonee[100][100]);

S_terrain panda(S_terrain coordonee[100][100]);

S_terrain jardinier(S_terrain coordonee[100][100]);

S_terrain irriguer(S_terrain coordonee[100][100]);

void intialisation (S_terrain coordonee[100][100]);

int nombreEtNom(S_Joueur *Joueur);