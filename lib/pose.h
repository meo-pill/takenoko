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

extern int contigue(int const xa, int const ya, int const xb, int const yb);

extern int access_lac(int const xa, int const ya, int const xb, int const yb);

int ajout_tuile(case_plato_t const * case_choix, int const x, int const y);

#endif