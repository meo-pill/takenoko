#include "index.h"

int verif_panda (carte_t const * carte, joueur_t const * joueur);

int verif_parcelle_triangle (couleur_E couleur);

carte_t * creer_carte(char * type, char * descrip, char * image, int pt );

void a_null_carte();

int inserer_carte(carte_t *);

void detruire_carte();

void afficher_carte(carte_t * const);