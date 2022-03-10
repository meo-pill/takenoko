#include "index.h"

carte_t * creer_carte(char * type, char * descrip, char * image, int pt );

void a_null_carte();

int inserer_carte(carte_t *);

void detruire_carte();

void afficher_carte(carte_t * const);

void melanger_carte();

int (* recherche_fonction_verif(carte_t * const))(carte_t * const);

int (* recherche_fonction_parcelle(carte_t * const))(carte_t * const);

int verif_panda (carte_t * const );
int verif_jardinier(carte_t * const);
int verif_parcelle_triangle (carte_t * const);
int verif_parcelle_losange(carte_t * const);
int verif_parcelle_ligne(carte_t * const);
int verif_parcelle_arc(carte_t * const);