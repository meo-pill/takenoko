#ifndef DEPLACEMENT_H_INCLUDED
#define DEPLACEMENT_H_INCLUDED
#include "index.h"

extern int case_existe(int const x, int const y);

extern int deplacement_imposible(int const xa, int const ya, int const xn, int const yn);

extern int pose_tuile_impossible(int const x, int const y);
//fonction de coordonée valide de pose de tuile a faire

extern int pose_canal_impossible(int const xa, int const ya, int const xb, int const yb)
//fonction de coordonée valide pour pose de canal a faire

//fonction de déplacement des personage

//fonction tp du panda foudre

#endif