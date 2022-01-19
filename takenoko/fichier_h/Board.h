#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED
#endif // BOARD_H_INCLUDED

typedef struct Joueur{
    char username[100];
    int nbPoints;
    int nbBambous;
}Joueur;

typedef struct terrain{
    int latitude;
    int longitude;
    int irriguee;
    int bambou;
    int valide;
}terrain;

terrain rentree(terrain a);

terrain panda(terrain a,int *nbPanda);

terrain jardinier(terrain a,int *nbBambous);

terrain irriguer(terrain a);

void intialisation (terrain coordonee[100][100]);

int nombreEtNom(Joueur *JA, Joueur *JB, Joueur *JC, Joueur *JD);