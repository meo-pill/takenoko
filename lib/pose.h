#ifndef DEPLACEMENT_H_INCLUDED
#define DEPLACEMENT_H_INCLUDED
#include "index.h"

extern int contigue(int const xa, int const ya, int const xb, int const yb);

extern int case_existe(int const x, int const y);

extern int pose_tuile_impossible(int const x, int const y);

extern int pose_canal_impossible(int const xa, int const ya, int const xb, int const yb);

extern int case_differente(int const xa, int const ya, int const xn, int const yn);

extern int deplacement_imposible(int const xa, int const ya, int const xn, int const yn);

extern int pose_tuile_impossible(int const x, int const y);

extern void pose_tuiles_possible(coordonne_t * tab);

extern int contigue(int const xa, int const ya, int const xb, int const yb);

extern int access_lac(int const xa, int const ya, int const xb, int const yb);

int ajout_tuile(case_plato_t * case_choix, int const x, int const y);

/**
 * @brief fonction de rangement des coordonner
 * la plus en haut a gauche en premier
 * 
 * @param xa coordoner x de la premier case  a ordoner
 * @param ya coordoner y de la premier case  a ordoner
 * @param xb coordoner x de la seconde case a ordoner
 * @param yb coordoner y de la seconde case a ordoner
 */
extern void ranger(int * xa, int * ya, int * xb, int * yb);

#endif