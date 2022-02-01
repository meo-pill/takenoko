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
#define LACPOS 14
#define NBTUILE 27

/**definition des structurs*/
typedef struct  personnage_s personnage_t;
typedef struct case_plato_s case_plato_t;
typedef struct carte_s carte_t;
typedef struct joueur_s joueur_t;
typedef struct file_s file_t;

/**definition des type enumérer*/
typedef enum couleur_s{jaune,rose,vert,lac}couleur_E;
typedef enum effet_s{rien,eau,stop,plus,lac}effet_E;
typedef enum effDes_s{soleil,pluie,vent,orage,nuage,choixJ}effDes_E;
typedef enum couleurJ_s{bleu,rouge,noir,vert}couleurJ_E;

/**variable globale*/
joueur_t J[4];
case_plato_t * piece[NBTUILE];
carte_t typeCartePanda[4];
carte_t * cartePanda[15];
carte_t * carteParcelle[15];
carte_t * carteJardinier[15];
case_plato_t * plateau[NBTUILE][NBTUILE];
case_plato_t lac;
file_t * file_tuile_tete;
file_t * file_tuile_queue;


/** des structurs*/
struct personnage_s{
        int x,y; //coordonnée
        char const image; //l'images du personne
        char const Type[10]; //nom du personnage
        void const (*deplacement)(void); // poiteur sur fonction de déplacement
        void const (*gestionBamboo)(void); //ajout/supression des bamboopar le personnage
};

struct case_plato_s{
        couleur_E Coul;
        int iriguer;
        int nbBambou;
        effet_E Eff;
        char image[30];
};

struct carte_s{
 	char const desc;
 	int const nbRep;
 	int const point;
        void (*valid)();
};
 
struct joueur_s{
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