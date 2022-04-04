#ifndef _FONCTION_H_
#define _FONCTION_H_
#include "../lib/index.h"

/********************
fonction opérationnelle
****************** */

/** à chaque tour d'un joueur*/


void ajout_effspe_stock( joueur_t * Joueur, effet_E const eff);
void retrait_effspe_stock( joueur_t * Joueur, effet_E const eff);

void ajout_bambou_stock( joueur_t * Joueur, couleur_E const coul);
void retire_bambou_stock( joueur_t * Joueur, int const nb_bb_jaune, int const nb_bb_rose, int const nb_bb_vert);

void ajout_irrigation_stock( joueur_t * Joueur);
void retire_irrigation_stock( joueur_t * Joueur);



/** à chaque déplacement d'un personnage */



/* * ajout au plateau */


void ajout_irrigation_case ( int const x, int const y);

void ajout_effspe_plato( effet_E effet, int const x, int const y);

void ajout_bambou_plato( int const x, int const y);
void retrait_bambou_plato( int const x, int const y);




/***************************
fonction à finir et à tester
***************************/


/* * choix pour 1 joueur */

void choixactionduJ( joueur_t * Joueur, char const meteo, choixJ_E memaction[2]);

void pioche_objetif( joueur_t * Joueur);
void pioche_effspe( joueur_t * Joueur);


int verif_ligne_droite_pair(int const x_d, int const y_d, int const x_a, int const y_a);
int verif_ligne_droite_impair(int const x_d, int const y_d, int const x_a, int const y_a);
int Verif_deplacer_perso( personnage_t perso, int const x_a, int const y_a);    /* jardinier ou Panda et renvoye 1 si c'est bon */

void deplacer_personnage( personnage_t perso, int const x_a, int const y_a);



#endif
