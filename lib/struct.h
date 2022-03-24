#ifndef _STRUC_H_
#define _STRUC_H_

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
#define LONGPATH 100
#define LONGTYPE 100
#define DESCRIPTION 100
#define NBTUILES 27
#define LACPOS 14
#define NBIRIG 20
#define NBCARTE 15

/**definition des structurs*/
typedef struct  personnage_s personnage_t;
typedef struct case_plato_s case_plato_t;
typedef struct carte_s carte_t;
typedef struct joueur_s joueur_t;
typedef struct file_s file_t;
typedef struct irig_s irig_t;

/**definition des type enumérer*/
typedef enum couleur_s{jaune,rose,vert,water}couleur_E;
typedef enum effet_s{sans_effet,bassin,enclos,engrais,effet_lac}effet_E;
typedef enum couleurJ_s{bleu,rouge,noir,blanc}couleurJ_E;

typedef enum effDes_s{soleil,pluie,vent,orage,nuage,choixJ}effDes_E;
typedef enum choixJ_s{rien,parcelle,irrigation,choix_jardinier,choix_panda,objectif}choixJ_E;

/**variable globale*/
joueur_t * J[4];
case_plato_t * piece[NBTUILES];
carte_t * cartePanda[NBCARTE];
carte_t * carteParcelle[NBCARTE];
carte_t * carteJardinier[NBCARTE];
case_plato_t * plateau[NBTUILES][NBTUILES];
case_plato_t lac;
file_t * file_tuile_tete;
file_t * file_tuile_queue;
personnage_t panda;
personnage_t jardinier;
irig_t * irig[NBIRIG];
int indique_carte[3] = {0,0,0}; /*sert à undiquer pour chaque pioche de carte (cartePanda, carteParcelle et carteJardinier) à quelle endroit on est (quelle est la prochaine carte)*/


/** des structurs*/
struct personnage_s{
  void (*deplacement)(void); // poiteur sur fonction de déplacement
  void (*gestionBamboo)(void); //ajout/supression des bamboopar le personnage
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
  int (*verif)(struct carte_s * const,joueur_t * const);
  char type [LONGTYPE];
  char image [LONGPATH];
 	char desc [DESCRIPTION];
 	int point;
};

struct joueur_s{
  char * nom_joueur;
  carte_t * main_J[5];
  carte_t * valide[MAXNB2J];
	int bambou [3]; /*dans l'ordre : jaune rose vert*/
	int effSpe [3]; 
	int nbIrigation;
  int nbObjectif;
  couleurJ_E couleurJoueur;
};

struct irig_s{
  int x_haut_gauche;
  int y_haut_gauche;
  int x_bas_droit;
  int y_bas_droit;
};

#endif