/**
 * @file liste_jardinier.h
 * @author MAXIME
 * @brief Mise en oeuvre d'une file de coordonnées par pointeurs
 * @version 0.1
 * @date 2022-04-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef liste_jardinier_H_INCLUDED
#define liste_jardinier_H_INCLUDED

#include "index.h"

typedef struct s_coordonees {
	int x;
	int y;
	struct s_coordonees* pred;
	struct s_coordonees* succ;
} t_coordonees;

typedef struct s_liste_jardinier{
	t_coordonees* drapeau;
	t_coordonees* ec;
}t_liste_jardinier;

/**
 * @brief initialise la liste
 * @author MAXIME
 * @param l la liste à initialiser
 */
void init_liste_jardinier(t_liste_jardinier *l);

/**
 * @brief vérifie que la liste est vide
 * @author MAXIME
 * @param l la liste à vérifier
 * @return int 
 */
int liste_vide_jardinier(t_liste_jardinier *l);

/**
 * @brief vérifie que le pointeur de position est hors de la liste
 * @author MAXIME
 * @param l la liste à vérifier
 * @return int 
 * retour d'un booléen de validaiton
 * 0 le pointeur de position est dans la liste
 * 1 le pointeur de position n'est pas dans la liste
 */
int hors_liste_jardinier(t_liste_jardinier *l);

/**
 * @brief met le pointeur de position en tête de la liste
 * @author MAXIME
 * @param l la liste ou on se met en tête
 */
void en_tete_jardinier(t_liste_jardinier *l);

/**
 * @brief met le pointeur de position en queue de la liste
 * @author MAXIME
 * @param l la liste ou on se met en queue
 */
void en_queue_jardinier(t_liste_jardinier *l);

/**
 * @brief met le pointeur de position sur le précédent
 * @author MAXIME
 * @param l la liste ou on passe au précédent
 */
void precedent_jardinier(t_liste_jardinier *l);

/**
 * @brief met le pointeur de position sur le suivant
 * @author MAXIME
 * @param l la liste ou on passe au suivant
 */
void suivant_jardinier(t_liste_jardinier *l);

/**
 * @brief on donne a xy la valeur du pointeur de position
 * @author MAXIME
 * @param l la liste de la valeur
 * @param xy le pointeur qui prend la valeur
 */
void valeur_elt_jardinier(t_liste_jardinier *l, t_coordonees* f);

/**
 * @brief on enlève la valeur du pointeur de position
 * @author MAXIME
 * @param l la liste de la valeur
 */
void oter_elt_jardinier(t_liste_jardinier *l);

/**
 * @brief ajoute la valeur du pointeur de coordonnées à la liste
 * @author MAXIME
 * @param l la liste de la valeur ajouter
 * @param xy le pointeur de coordonnées à ajouter
 */
void ajout_droit_jardinier(t_liste_jardinier *l, t_coordonees* f);

/**
 * @brief affiche les valeur de la liste
 * @author MAXIME
 * @param l la liste à afficher
 */
void afficher_jardinier(t_liste_jardinier *l);

/**
 * @brief  vérifie que la liste contient les coordonnées
 * @author MAXIME
 * @param l la liste à vérifier
 * @param x coordonnées x
 * @param y coordonnées y
 * @return int 
 * retour d'un booléen de validaiton
 * 0 les coordonnées ne sont pas dans la liste
 * 1 les coordonnées sont dans la liste
 */
int est_dans_liste_jardinier(t_liste_jardinier* l, int const x, int const y);

/**
 * @brief vide totalement la liste
 * @author MAXIME
 * @param l la liste vider
 */
void vider_liste_jardinier(t_liste_jardinier *l);


#endif