#ifndef _STRUC_H_
#define _STRUC_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
/**
 *
 *
 *
 *
 */
/** Deffiniton des lib utiliser dans tout le programe */

/**Definition des constante*/
#define MAXNB2J 9
#define MAXNB3J 8
#define MAXNB4J 7
#define LONGPATH 30
#define LONGTYPE 20
#define DESCRIPTION 100
#define NBTUILES 27
#define LACPOS 14
#define NBTUILE 27

/**definition des structurs*/
typedef struct  personnage_s personnage_t;
typedef struct case_plato_s case_plato_t;
typedef struct carte_s carte_t;
typedef struct joueur_s joueur_t;
typedef struct file_s file_t;

/**definition des type enumérer*/
typedef enum couleur_s{jaune,rose,vert}couleur_E;
typedef enum effet_s{rien,bassin,enclos,engrais,lac}effet_E;
typedef enum effDes_s{soleil,pluie,vent,orage,nuage,choixJ}effDes_E;
typedef enum couleurJ_s{bleu,rouge,noir,blanc}couleurJ_E;

/**variable globale*/
joueur_t * J_tab[4];
case_plato_t * piece[NBTUILE];
carte_t * cartePanda[15];
carte_t * carteParcelle[15];
carte_t * carteJardinier[15];
case_plato_t * plateau[NBTUILE][NBTUILE];
file_t * file_tuile_tete;
file_t * file_tuile_queue;
personnage_t panda;
personnage_t jardinier;


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
  char const image [LONGPATH];
};

struct carte_s{
  int (*verif)(struct carte_s * const);
  char type [LONGTYPE];
  char image [LONGPATH];
 	char desc [DESCRIPTION];
 	int point;
};

struct joueur_s{
  char * nom_joueur;
  carte_t * main_J[5];
  carte_t * valide[MAXNB2J];
	int bambou [3];
	int effSpe [3];
	int nbIrigation;
  int nbObjectif;
  couleurJ_E couleurJoueur;
};

#endif