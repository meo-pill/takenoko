#ifndef INIT_FIN_H_INCLUDED
#define INIT_FIN_H_INCLUDED

#include "index.h"

extern int debut_partie(int const  nb_joueur, int * maxpoint);
extern void suprimer(void);
extern int extraction_fichier_carte(void);
extern int extraction_fichier_tuile(void);
extern void mise_en_file(void);

#endif
