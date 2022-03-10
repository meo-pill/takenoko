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
#define LONGPATH 70
#define LONGTYPE 40
#define DESCRIPTION 100
#define NBTUILES 27
#define LACPOS 14
#define NBTUILE 27
#define NBIRIG 20
#define NBCARTE 15

/**definition des structurs*/
typedef struct personnage_s personnage_t;
typedef struct case_plato_s case_plato_t;
typedef struct carte_s carte_t;
typedef struct joueur_s joueur_t;
typedef struct file_s file_t;
typedef struct irigation_s irigation_t;

/**definition des type enumérer*/
typedef enum couleur_s{jaune,rose,vert,centre}couleur_E;
typedef enum effet_s{rien,bassin,enclos,engrais,debut}effet_E;
typedef enum effDes_s{soleil,pluie,vent,orage,nuage,choixJ}effDes_E;
typedef enum couleurJ_s{bleu,rouge,noir,blanc}couleurJ_E;

/**variable globale*/
joueur_t * J[4];
case_plato_t * piece[NBTUILE];
carte_t * cartePanda[NBCARTE];
carte_t * carteParcelle[NBCARTE];
carte_t * carteJardinier[NBCARTE];
case_plato_t * plateau[NBTUILE][NBTUILE];
case_plato_t lac;
file_t * file_tuile_tete;
file_t * file_tuile_queue;
personnage_t panda;
personnage_t jardinier;
irigation_t * irig[20];

/** des structurs*/
struct personnage_s{
  void const (*deplacement)(void); // poiteur sur fonction de déplacement
  void const (*gestionBamboo)(void); //ajout/supression des bamboopar le personnage
  int x,y; //coordonnée
  char image[LONGPATH]; //l'images du personne
  char Type[10]; //nom du personnage
};

struct case_plato_s{
  couleur_E Coul;
  int iriguer;
  int nbBambou;
  effet_E Eff;
  char image [LONGPATH];
};

struct carte_s{
  int (*verif)(struct carte_s * const);
  char type [LONGTYPE];
  char image [LONGPATH];
 	char desc [DESCRIPTION];
 	int point;
};

struct joueur_s{
  char nom_joueur[20];
  carte_t * main[5];
  carte_t * valide[MAXNB2J];
	  int bambou [3];
	  int effSpe [3];
	  int nbIrigation;
    int nbObjectif;
  couleurJ_E couleurJoueur;
};

struct irigation_s{
  int x_haut_gauche;
  int y_haut_gauche;
  int x_bas_droit;
  int y_bas_droit;
};

#endif
