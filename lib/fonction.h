#ifndef _FONCTION_H_
#define _FONCTION_H_
#include "struct.h"

/**
*
* stdlib et stdio déjà dans index
*/

/********************
fonction opérationnelle
****************** */

/** à chaque tour d'un joueur*/


char lancer_meteo();

void ajout_effspe_stock( joueur_t * Joueur, const effet_E eff);
void retrait_effspe_stock( joueur_t * Joueur, const effet_E eff);

void ajout_bambou_stock( joueur_t * Joueur, const couleur_E x, const int y);
void retire_bambou_stock( joueur_t * Joueur, const int nb_bb_jaune, const int nb_bb_rose, const int nb_bb_vert);

void ajout_irrigation_stock( joueur_t * Joueur);
void retire_irrigation_stock( joueur_t * Joueur);



/** à chaque déplacement d'un personnage */






/***************************
fonction à finir et à tester
***************************/


/* * choix pour 1 joueur */

void choixactionduJ( joueur_t * Joueur, const char meteo, choixJ_E mem_action[2]);

void pioche_1case ();
void pioche_objetif( joueur_t * Joueur);
void pioche_effspe( joueur_t * Joueur);



int Verif_deplacer_perso( personnage_t * perso, const int x_a, const int y_a);
/** jardinier ou Panda et renvoye 1 si c'est bon */

void deplacer_personnage( personnage_t * perso, const int x_a, const int y_a);



/* * ajout au plateau */

int verif_pose_case( const int x, const int y);
/* * Vérifie qu'on peu poser une case (case vide + | - 2 case non vide adjasante| - bassin ) et renvoie 1 si c'est bon */

void ajout_case_plato ( case_plato_t case_a, const int x, const int y);

int verif_pose_irrigation_plateau ( const int x, const int y);	/* * Vérifie qu'on peu poser une irrigation et renvoie 1 si c'est bon */

void ajout_irrigation_case ( const int x, const int y);

void ajout_effspe_plato( effet_E * effet, const int x, const int y);



/* retirer au plateau */

void retrait_case_plato ( const int x, const int y);

void retrait_effspe_plato( const int x, const int y);


#endif