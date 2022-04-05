/**
 * @file carte.h
 * @author nail léo
 * @brief toute les fonctions lié à la gestion des cartes 
 * @version 0.1
 * @date 2022-03-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef CARTE_H_INCLUDED
#define CARTE_H_INCLUDED


#include "index.h"

/**
 * @brief 
 * permet de créer une carte avec tout ses paramètre
 * 
 * @param type 
 * que mettre dans type
 * @param describ 
 * description (pour clarifier les règles pour les joueurs)
 * @param image 
 * lien du fichier de l'image
 * @param pt 
 * nombre de point que raporte d'accomplir l'objectif
 * @return carte_t* 
 * l'adresse de la carte ainsi créer
 */
carte_t * creer_carte(char * type, char * descrip, char * image, int pt );

/**
 * @brief met tout les deck à NULL
 * 
 */
void a_null_carte();

/**
 * @brief 
 * prend une carte et l'insère dans le bon tableau
 * @param carte 
 * 
 * @return int 
 *retourne 1 si il y a eu une erreur; 0 sinon
 */
int inserer_carte(carte_t *);

extern void detruire_one_carte(carte_t** C);

void detruire_carte();

/**
 * @brief cette fonction affiche une carte sur la sortie standard
 *  il s'agit d'une fonction de test
 * @param c 
 * si le paramètre est NULL, la fonction affiche NULL à la place
 */
void afficher_carte(carte_t * const);

/**
 * @brief 
 * appelle trois fois mélanger deck, pour que tous les decks soient mélanger
 * (n'a du sens que si les decks sont pleins)
 * 
 */
void melanger_carte();

/**
 * @brief 
 * fonction de recherche de la bonne fonction de vérification pour un type de carte donnée (jardinier,panda ou parcelle)
 * 
 * @param carte 
 * on cherche la fonction de vérification pour quelle carte (type doit être remplit correctement)
 * @return int(*)(carte_t* const,joueur_t * const) 
 * renvoie un pointeur sur la fonction trouvée (NULL si il ne trouve rien)
 */
int (* recherche_fonction_verif(carte_t * const))(carte_t * const, joueur_t * const);

/**
 * @brief 
 * regarde le type d'une carte parcelle et renvoie la bonne fonction de verification
 * 
 * @param carte 
 * cette carte doit-être de type parcelle
 * 
 * @return int(*)(carte_t* const, joueur_t * const) 
 * renvoie un pointeur sur la fonction trouvée (NULL si il ne trouve rien)
 */
int (* recherche_fonction_parcelle(carte_t * const))(carte_t * const, joueur_t * const);

/**
 * @brief 
 * fonction de verification pour une carte panda
 * pour cela, on prend le joueur courant, et on vérifie s'il a asser de bambou de la bonne couleur
 * 
 * @param carte
 * ce qui nous intéresse ici, c'est la couleur (spécifié dans le type sous forme de "panda-[couleur]")
 * 
 * @param J
 * joueur dont c'est le tour, il est important pour cet objectif
 * 
 * @return int 
 * on retourne 1 si la contrainte est vérifié, -1 en cas d'erreur,  0 sinon
 */
int verif_panda (carte_t * const ,joueur_t * const);

/**
 * @brief fonction de vérification pour jardinier 
 * on parcoure tout le tableau pour vérifier si les objectif de la carte sont accomplie
 * 
 * @param carte 
 * quel est la carte objectif (précisément)
 * 
 * @param J
 * joueur dont c'est le tour
 * 
 * @return int 
 * on retourne 1 si la contrainte est vérifié, -1 en cas d'erreur,  0 sinon
 */
int verif_jardinier(carte_t * const,joueur_t * const);

/**
 * @brief 
 * fonction de verification pour une carte de parcelle, qui a besoin d'un triangle
 * 
 * @param carte 
 * 
 * @param J
 * joueur dont c'est le tour
 * 
 * @return int 
 * on retourne 1 si la contrainte est vérifié, -1 en cas d'erreur,  0 sinon
 */
int verif_parcelle_triangle (carte_t * const,joueur_t * const);

/**
 * @brief 
 * fonction de verification pour une carte de parcelle, qui a besoin d'un losange
 * 
 * @param carte 
 * 
 * @param J
 * joueur dont c'est le tour
 * 
 * @return int 
 * on retourne 1 si la contrainte est vérifié, -1 en cas d'erreur,  0 sinon
 */
int verif_parcelle_losange(carte_t * const,joueur_t * const);

/**
 * @brief 
 * fonction de verification pour une carte de parcelle, qui a besoin d'une ligne
 * 
 * @param carte 
 * 
 * @param J
 * joueur dont c'est le tour
 * 
 * @return int 
 * on retourne 1 si la contrainte est vérifié, -1 en cas d'erreur,  0 sinon
 */
int verif_parcelle_ligne(carte_t * const,joueur_t * const);

/**
 * @brief 
 * fonction de verification pour une carte de parcelle, qui a besoin d'un arc
 * 
 * @param carte 
 * 
 * @param J
 * joueur dont c'est le tour
 * 
 * @return int 
 * on retourne 1 si la contrainte est vérifié, -1 en cas d'erreur,  0 sinon
 */
int verif_parcelle_arc(carte_t * const,joueur_t * const);

/**
 * @brief fonction de calcul des point d'un joueur
 * 
 * @param J poiteur sur une structuer de joueur
 * 
 * @result int somme des point d'un joueur
 */
int nb_point_joueur(joueur_t *J);

#endif
