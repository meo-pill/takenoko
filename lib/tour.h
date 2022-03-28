
#ifndef INIT_FIN_H_INCLUDED
#define INIT_FIN_H_INCLUDED

#include "index.h"

static int debut_partie(int const * nb_joueur, int * maxpoint);
static int victoire_joueur(joueur_t const * J, int const maxpoint);
extern void tour_jeux(int const nb_joueur);

#endif