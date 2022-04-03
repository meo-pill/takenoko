#ifndef CARTE_H_INCLUDED
#define CARTE_H_INCLUDED
/**
 * @file carte.h
 * @author nail léo
 * @brief 
 * @version 0.1
 * @date 2022-03-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "index.h"

carte_t * creer_carte(char * type, char * descrip, char * image, int pt );

void a_null_carte();

int inserer_carte(carte_t *);

extern void detruire_one_carte(carte_t** C);

void detruire_carte();

void afficher_carte(carte_t * const);

void melanger_carte();

int (* recherche_fonction_verif(carte_t * const))(carte_t * const, joueur_t * const);

int (* recherche_fonction_parcelle(carte_t * const))(carte_t * const, joueur_t * const);

int verif_panda (carte_t * const ,joueur_t * const);
int verif_jardinier(carte_t * const,joueur_t * const);
int verif_parcelle_triangle (carte_t * const,joueur_t * const);
int verif_parcelle_losange(carte_t * const,joueur_t * const);
int verif_parcelle_ligne(carte_t * const,joueur_t * const);
int verif_parcelle_arc(carte_t * const,joueur_t * const);

/**
 * @brief fonction de calcul des point d'un joueur
 * 
 * @param J poiteur sur une structuer de joueur
 * 
 * @result int somme des point d'un joueur
 */
int nb_point_joueur(joueur_t *J)

#endif