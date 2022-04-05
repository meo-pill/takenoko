/**
 * @file struct.h
 * @authors MEWEN MORGANE LEO MAXIME
 * @brief deffiniton des structure/paramèttre globaux
 * @version 0.1
 * @date 2022-04-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
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
#define TAILLE_MAIN 5

/**definition des structurs*/
typedef struct  personnage_s personnage_t;
typedef struct case_plato_s case_plato_t;
typedef struct carte_s carte_t;
typedef struct joueur_s joueur_t;
typedef struct file_s file_t;
typedef struct irig_s irig_t;
typedef struct coord_s coordonne_t;

/**definition des type enumérer*/

/**
 * @brief liste des couleur de tuile / bambou
 * 
 */
typedef enum couleur_s{jaune,rose,vert,water}couleur_E;

/**
 * @brief liste des effet de case posbile
 * 
 */
typedef enum effet_s{sans_effet,bassin,enclos,engrais,effet_lac}effet_E;

/**
 * @brief liste des couleur de joueurs
 * 
 */
typedef enum couleurJ_s{bleu,rouge,noir,blanc}couleurJ_E;

/**
 * @brief liste des effet de dée
 * 
 */
typedef enum effDes_s{soleil,pluie,vent,orage,nuage,choixJ}effDes_E;

/**
 * @brief liste des choix possible d'action
 * 
 */
typedef enum choixJ_s{rien,parcelle,irrigation,choix_jardinier,choix_panda,objectif}choixJ_E;

/**variable globale*/

/**
 * @brief tableau de joueur
 * 
 */
joueur_t * J[4];

/**
 * @brief pioche de carte type panda
 * 
 */
carte_t * cartePanda[NBCARTE];

/**
 * @brief pioche de carte type parcelle
 * 
 */
carte_t * carteParcelle[NBCARTE];

/**
 * @brief pioche de carte type jardinier
 * 
 */
carte_t * carteJardinier[NBCARTE];

/**
 * @brief sert à indiquer pour chaque pioche de carte (cartePanda, carteParcelle et carteJardinier) à quelle endroit on est (quelle est la prochaine carte)
 * 
 */
int indique_carte[3]; 

/**
 * @brief memoire des piece sauvegarger
 * 
 */
case_plato_t * piece[NBTUILES];

/**
 * @brief plateau de jeux
 * 
 */
case_plato_t * plateau[NBTUILES][NBTUILES];

/**
 * @brief case du lac stoquer a part
 * 
 */
case_plato_t lac;

/**
 * @brief tete de la file
 * 
 */
file_t * file_tuile_tete;

/**
 * @brief queue de la file
 * 
 */
file_t * file_tuile_queue;

/**
 * @brief struture de panda
 * 
 */
personnage_t panda;

/**
 * @brief structure de jardiner
 * 
 */
personnage_t jardinier;

/**
 * @brief memoire des irigation placer
 * 
 */
irig_t * irig[NBIRIG];


/**definiton des structure

/**
 * @brief structure de pressonage
 * 
 */
struct personnage_s{
  int x,y; //coordonnée
};

/**
 * @brief strture de stockage de coordonnée
 * 
 */
struct  coord_s
{
  int x;
  int y;
};

/**
 * @brief structure de case
 * 
 */
struct case_plato_s{
  couleur_E Coul;
  int iriguer;
  int nbBambou;
  effet_E Eff;
  char image [LONGPATH];
};

/**
 * @brief structure de carte
 * 
 */
struct carte_s{
  int (*verif)(struct carte_s * const,joueur_t * const);
  char type [LONGTYPE];
  char image [LONGPATH];
  char desc [DESCRIPTION];
  int point;
};

/**
 * @brief structure de Joueur
 * 
 */
struct joueur_s{
  char * nom_joueur;
  carte_t * main_J[TAILLE_MAIN];
  carte_t * valide[MAXNB2J];
  int score;
	int bambou [3]; /*dans l'ordre : jaune rose vert*/
	int effSpe [3]; 
	int nbIrigation;
  int nbObjectif;
  couleurJ_E couleurJoueur;
};

/**
 * @brief structure contenant les coordone des case autour d'une irigation
 * 
 */
struct irig_s{
  int x_haut_gauche;
  int y_haut_gauche;
  int x_bas_droit;
  int y_bas_droit;
};

#endif
