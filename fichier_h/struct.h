#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED
/**
 *
 *
 *
 *
 */
/** Deffiniton des lib utiliser dans tout le programe */
#include "index.h"

/**Definition des constante*/
#define MAXNB2J 9
#define MAXNB3J 8
#define MAXNB4J 7
/**definition des structurs*/
typedef struct  personnage personnage_t;
typedef struct case_plato case_plato_t;
typedef struct carte carte_t;
typedef struct joueur_ joueur_t;
typedef struct file_s file_t;

/**definition des type enumérer*/
typedef enum couleur {jaune,rose,vert}couleur_E;
typedef enum effet{rien,eau,stop,plus}effet_E;
typedef enum effDes{soleil,pluie,vent,orage,nuage,choixJ}effDes_E;
typedef enum couleurJ{bleu,rouge,noir,vert}couleurJ_E;

/**variable globale*/
joueur_t J[4];
case_plato_t * piece[27];
carte_t typeCartePanda[4];
carte_t *cartePanda[15];
carte_t * carteParcelle[15];
carte_t * carteJardinier[15];
case_plato_t * plateau[27][27];
file_t * file_tuile_tete;
file_t * file_tuile_queue;


/** des structurs*/
struct personnage{
        int x,y; //coordonnée
        char const image; //l'images du personne
        char const Type[10]; //nom du personnage
        void const (*deplacement)(void); // poiteur sur fonction de déplacement
        void const (*gestionBamboo)(void); //ajout/supression des bamboopar le personnage
};

struct case_plato{
        couleur_E Coul;
        int iriguer;
        int nbBambou;
        effet_E Eff;
};

struct carte{
 	char const desc;
 	int const nbRep;
 	int const point;
        void (*valid)();
};
 
struct joueur{
        char nom_joueur[20];
        carte_t * carte_panda[15];
        carte_t * carte_jardinier[15];
        carte_t * carte_parcelle[15];
	int bambou [3];
	int effSpe [3];
	int nbIrigation;
        int nbObjectif;
        couleurJ_E couleurJoueur;
};

#endif