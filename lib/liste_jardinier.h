#ifndef liste_jardinier_H_INCLUDED
#define liste_jardinier_H_INCLUDED

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

void init_liste_jardinier(t_liste_jardinier *l);

int liste_vide_jardinier(t_liste_jardinier *l);
int hors_liste_jardinier(t_liste_jardinier *l);

void en_tete_jardinier(t_liste_jardinier *l);
void en_queue_jardinier(t_liste_jardinier *l);

void precedent_jardinier(t_liste_jardinier *l);
void suivant_jardinier(t_liste_jardinier *l);

void valeur_elt_jardinier(t_liste_jardinier *l, t_coordonees* f);

void oter_elt_jardinier(t_liste_jardinier *l);
void ajout_droit_jardinier(t_liste_jardinier *l, t_coordonees* f);

void afficher_jardinier(t_liste_jardinier *l);
int est_dans_liste_jardinier(t_liste_jardinier* l, int const x, int const y);
void vider_liste_jardinier(t_liste_jardinier *l);


#endif