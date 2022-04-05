// Mise en oeuvre d'une file de coordonnées par pointeurs
#include "../lib/index.h"

/**
 * @brief initialise la liste
 * @author MAXIME
 * @param l la liste à initialiser
 */
void init_liste_jardinier(t_liste_jardinier *l) {
	l->drapeau = malloc(sizeof(t_coordonees));

	l->drapeau->pred = l->drapeau;
	l->drapeau->succ = l->drapeau;
	l->ec = l->drapeau;
}

/**
 * @brief vérifie que la liste est vide
 * @author MAXIME
 * @param l la liste à vérifier
 * @return int 
 */
int liste_vide_jardinier(t_liste_jardinier *l) {
	return ((l->drapeau->pred == l->drapeau) && (l->drapeau->succ == l->drapeau));
}

/**
 * @brief vérifie que le pointeur de position est hors de la liste
 * @author MAXIME
 * @param l la liste à vérifier
 * @return int 
 * retour d'un booléen de validaiton
 * 0 le pointeur de position est dans la liste
 * 1 le pointeur de position n'est pas dans la liste
 */
int hors_liste_jardinier(t_liste_jardinier *l) {
	return (l->ec == l->drapeau);
}

/**
 * @brief met le pointeur de position en tête de la liste
 * @author MAXIME
 * @param l la liste ou on se met en tête
 */
void en_tete_jardinier(t_liste_jardinier *l) {
	if(!liste_vide_jardinier(l))
		l->ec = l->drapeau->succ;
}

/**
 * @brief met le pointeur de position en queue de la liste
 * @author MAXIME
 * @param l la liste ou on se met en queue
 */
void en_queue_jardinier(t_liste_jardinier *l) {
	if(!liste_vide_jardinier(l))
		l->ec = l->drapeau->pred;
}

/**
 * @brief met le pointeur de position sur le précédent
 * @author MAXIME
 * @param l la liste ou on passe au précédent
 */
void precedent_jardinier(t_liste_jardinier *l) {
	if(!hors_liste_jardinier(l))
		l->ec = l->ec->pred;
}

/**
 * @brief met le pointeur de position sur le suivant
 * @author MAXIME
 * @param l la liste ou on passe au suivant
 */
void suivant_jardinier(t_liste_jardinier *l) {
	if(!hors_liste_jardinier(l))
		l->ec = l->ec->succ;
}

/**
 * @brief on donne a xy la valeur du pointeur de position
 * @author MAXIME
 * @param l la liste de la valeur
 * @param xy le pointeur qui prend la valeur
 */
void valeur_elt_jardinier(t_liste_jardinier *l, t_coordonees* xy) {
	if(!hors_liste_jardinier(l))
		xy = l->ec;
}

/**
 * @brief on enlève la valeur du pointeur de position
 * @author MAXIME
 * @param l la liste de la valeur
 */
void oter_elt_jardinier(t_liste_jardinier *l) {
	if(!hors_liste_jardinier(l)) {
		t_coordonees* p;
		
		p = l->ec;
		(l->ec->pred)->succ = l->ec->succ;
		(l->ec->succ)->pred = l->ec->pred;
		
		precedent_jardinier(l);
		free(p);
	}
}

/**
 * @brief ajoute la valeur du pointeur de coordonnées à la liste
 * @author MAXIME
 * @param l la liste de la valeur ajouter
 * @param xy le pointeur de coordonnées à ajouter
 */
void ajout_droit_jardinier(t_liste_jardinier *l, t_coordonees* xy) {
	if(liste_vide_jardinier(l) || !hors_liste_jardinier(l)) {
		t_coordonees* nouv = malloc(sizeof(t_coordonees));

		nouv = xy;
		nouv->pred = l->ec;
		nouv->succ = l->ec->succ;

		//Mise a jour des chainages des voisins
		(l->ec->succ)->pred = nouv;
		l->ec->succ = nouv;
		//On se positionne sur les nouvelles coordonnées
		l->ec = nouv;
	}
}


/**
 * @brief affiche les valeur de la liste
 * @author MAXIME
 * @param l la liste à afficher
 */
void afficher_jardinier(t_liste_jardinier *l){	// Affiche les valeurs de la liste 	
	t_coordonees*  elem = malloc(sizeof(t_coordonees));
	
	if(liste_vide_jardinier(l))
		printf("La liste est vide\n");
	else{
		printf("\nLa liste contient: \n");
		en_tete_jardinier(l);
		while(!hors_liste_jardinier(l)){
			valeur_elt_jardinier(l, elem);
			printf("x = %i y = %i\n", elem->x, elem->y);
			suivant_jardinier(l);
			printf("1 fois dedant\n");
		}
	}
}

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
int est_dans_liste_jardinier(t_liste_jardinier* l, int const x, int const y){
	en_tete_jardinier(l);
	while (!hors_liste_jardinier(l)){
		if (x==l->ec->x && y==l->ec->y) return (1);
		suivant_jardinier(l);
	}
	return (0);
}

/**
 * @brief vide totalement la liste
 * @author MAXIME
 * @param l la liste vider
 */
void vider_liste_jardinier(t_liste_jardinier *l){	// Supprime toutes les valeurs de la liste
	en_queue_jardinier(l);
	
	while (!hors_liste_jardinier(l)){
		oter_elt_jardinier(l);
	}
}


