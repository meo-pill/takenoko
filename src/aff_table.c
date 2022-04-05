#include "../lib/aff_table.h"
extern int palt_test(){
    case_plato_t * tuile;
    tuile = retirer();
    plateau[LACPOS+1][LACPOS+1] = tuile;
    tuile = retirer();
    plateau[LACPOS+1][LACPOS] = tuile;
    tuile = retirer();
    plateau[LACPOS+1][LACPOS-1] = tuile;
    tuile = retirer();
    plateau[LACPOS][LACPOS-1] = tuile;
    tuile = retirer();
    plateau[LACPOS][LACPOS+1] = tuile;
    tuile = retirer();
    plateau[LACPOS-1][LACPOS-1] = tuile;
    tuile = retirer();
    plateau[LACPOS-1][LACPOS] = tuile;
    tuile = retirer();
    plateau[LACPOS-1][LACPOS+1] = tuile;
    return 9;

}

