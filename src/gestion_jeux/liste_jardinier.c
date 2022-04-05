
#include "../../lib/liste_jardinier.h"


void init_liste_jardinier(t_liste_jardinier *l) {
	l->drapeau = malloc(sizeof(t_coordonees));

	l->drapeau->pred = l->drapeau;
	l->drapeau->succ = l->drapeau;
	l->ec = l->drapeau;
}


int liste_vide_jardinier(t_liste_jardinier *l) {
	return ((l->drapeau->pred == l->drapeau) && (l->drapeau->succ == l->drapeau));
}


int hors_liste_jardinier(t_liste_jardinier *l) {
	return (l->ec == l->drapeau);
}


void en_tete_jardinier(t_liste_jardinier *l) {
	if(!liste_vide_jardinier(l))
		l->ec = l->drapeau->succ;
}


void en_queue_jardinier(t_liste_jardinier *l) {
	if(!liste_vide_jardinier(l))
		l->ec = l->drapeau->pred;
}


void precedent_jardinier(t_liste_jardinier *l) {
	if(!hors_liste_jardinier(l))
		l->ec = l->ec->pred;
}


void suivant_jardinier(t_liste_jardinier *l) {
	if(!hors_liste_jardinier(l))
		l->ec = l->ec->succ;
}


void valeur_elt_jardinier(t_liste_jardinier *l, t_coordonees* xy) {
	if(!hors_liste_jardinier(l))
		xy = l->ec;
}


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


int est_dans_liste_jardinier(t_liste_jardinier* l, int const x, int const y){
	en_tete_jardinier(l);
	while (!hors_liste_jardinier(l)){
		if (x==l->ec->x && y==l->ec->y) return (1);
		suivant_jardinier(l);
	}
	return (0);
}


void vider_liste_jardinier(t_liste_jardinier *l){	// Supprime toutes les valeurs de la liste
	en_queue_jardinier(l);
	
	while (!hors_liste_jardinier(l)){
		oter_elt_jardinier(l);
	}
}


