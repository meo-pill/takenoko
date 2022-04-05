/**
 * @file fonction.h
 * @authors MAXIME
 * @brief fonction de gestion des stock 
 * @version 0.1
 * @date 2022-04-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _FONCTION_H_
#define _FONCTION_H_
#include "../lib/index.h"

/********************
fonction opérationnelle
****************** */

/** à chaque tour d'un joueur*/

/**
 * @brief ajoute au stock du joueur sélectionné un effet spécial
 * @author MAXIME
 * @param Joueur le joueur sélectionné
 * @param eff l'effet spécial à ajouté
 */
void ajout_effspe_stock( joueur_t * Joueur, effet_E const eff);

/**
 * @brief retire au stock du joueur sélectionné un effet spécial
 * @author MAXIME
 * @param Joueur le joueur sélectionné
 * @param eff l'effet spécial à ajouté
 */
void retrait_effspe_stock( joueur_t * Joueur, effet_E const eff);

/**
 * @brief ajoute au stock du joueur sélectionné un bambou
 * @author MAXIME
 * @param Joueur le joueur sélectionné
 * @param coul la couleur du bambou
 */
void ajout_bambou_stock( joueur_t * Joueur, couleur_E const coul);

/**
 * @brief retire au stock du joueur sélectionné un bambou
 * @author MAXIME
 * @param Joueur le joueur sélectionné
 * @param nb_bb_jaune le nombre de bambou jaune à enlever
 * @param nb_bb_rose le nombre de bambou rose à enlever
 * @param nb_bb_vert le nombre de bambou vert à enlever
 */
void retire_bambou_stock( joueur_t * Joueur, int const nb_bb_jaune, int const nb_bb_rose, int const nb_bb_vert);

/**
 * @brief ajoute au stock du joueur sélectionné une irrigation
 * @author MAXIME
 * @param Joueur le joueur sélectionné
 */
void ajout_irrigation_stock( joueur_t * Joueur);

/**
 * @brief retire au stock du joueur sélectionné une irrigation
 * @author MAXIME
 * @param Joueur Joueur le joueur sélectionné
 */
void retire_irrigation_stock( joueur_t * Joueur);



/** à chaque déplacement d'un personnage */



/* * ajout au plateau */

/**
 * @brief ajoute a la case du plateau sélectionner l'atribue irriguer( 1 ) et lui donne un bambou
 * @author MAXIME
 * @param x position x voulue pour poser
 * @param y position y voulue pour poser
 */
void ajout_irrigation_case ( int const x, int const y);

/**
 * @brief ajoute a la case du plateau sélectionner un effet spécial sélectionné
 * @author MAXIME
 * @param effet l'effet spécial sélectionné
 * @param x position x voulue pour poser l'effet spécial
 * @param y position y voulue pour poser l'effet spécial
 */
void ajout_effspe_plato( effet_E effet, int const x, int const y);

/**
 * @brief ajoute a la case du plateau sélectionner 1 ou 2 bambou selon son effet spécial
 * @author MAXIME
 * @param x position x voulue pour poser le bambou
 * @param y position y voulue pour poser le bambou
 */
void ajout_bambou_plato( int const x, int const y);

/**
 * @brief retire a la case du plateau sélectionner 1 seul bambou
 * @author MAXIME
 * @param x position x voulue pour retirer le bambou
 * @param y position y voulue pour retirer le bambou
 */
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


/**
 * @brief verifaction si on peu déplacer le jardinier ou le Panda
 * @author MAXIME
 * @param perso nom du personnage (la struct porte le même nom) que l'on veut déplacer
 * @param x_a nouvelle position x voulue
 * @param y_a nouvelle position y voulue
 * @return int 
 * retour d'un booléen de validaiton
 * 0 le déplacement n'est pas valide
 * 1 le déplacement est valide
 */
int Verif_deplacer_perso( personnage_t perso, int const x_a, int const y_a);    /* jardinier ou Panda et renvoye 1 si c'est bon */

/**
 * @brief change les coordonnées du jardinier ou du Panda
 * 
 * @param perso nom du personnage (la struct porte le même nom) sélectionné
 * @param x_a nouvelle position x voulue
 * @param y_a nouvelle position y voulue
 */
void deplacer_personnage( personnage_t * perso, int const x_a, int const y_a);



#endif
