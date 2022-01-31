#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED
/**
 *
 *
 *
 *
 */
/** Deffiniton des lib utiliser dans tout le programe */
#include <stdio.h>
#include <stdlib.h>

/**Definition des constante*/
#define MAXNB2J 9
#define MAXNB3J 8
#define MAXNB4J 7
/**definition des structurs*/
typedef struct  personnage personnage_t;
typedef struct case_plato case_plato_t;
typedef struct carte carte_t;
typedef struct joueur joueur_t;

/**definition des type enumérer*/
typedef enum couleur {jaune,rose,vert};
typedef enum effet{rien,eau,stop,plus};
typedef enum effDes{soleil,pluie,vent,orage,nuage,choixJ};
typedef enum couleurJ{bleu,rouge,noir,vert};

/**variable globale*/
joueur_t J[4];
case_plato_t piece[27];
carte_t typeCartePanda[4];
carte_t *cartePanda[15];
carte_t carteParcelle[15];
carte_t carteJardinier[15];
case_plato_t * plateau[27][27];


/** des structurs*/
struct personnage{
        int x,y; //coordonnée
        char const image; //l'images du personne
        char const Type[10]; //nom du personnage
        void const (*deplacement)(void); // poiteur sur fonction de déplacement
        void const (*gestionBamboo)(void); //ajout/supression des bamboopar le personnage
};

struct case_plato{
        couleur const C;
        int iriguer;
        int nbBambou;
        effet const E;
};

struct carte{
 	char const desc;
 	int const nbRep;
 	int const point;
};
 
struct joueur{
        char nom_joueur[20];
        carte * carte_panda[15];
        carte * carte_jardinier[15];
        carte * carte_parcelle[15];
	int bambou [3];
	int effSpe [3];
	int nbIrigation;
        int nbObjectif;
};

#endif