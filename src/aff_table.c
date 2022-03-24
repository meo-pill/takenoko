#include "../lib/aff_table.h"
extern int palt_test(){
    case_plato_t * tuile;
    retirer(&tuile);
    plateau[LACPOS+1][LACPOS+1] = tuile;
    retirer(&tuile);
    plateau[LACPOS+1][LACPOS] = tuile;
    retirer(&tuile);
    plateau[LACPOS+1][LACPOS-1] = tuile;
    retirer(&tuile);
    plateau[LACPOS][LACPOS-1] = tuile;
    retirer(&tuile);
    plateau[LACPOS][LACPOS] = tuile;
    retirer(&tuile);
    plateau[LACPOS][LACPOS+1] = tuile;
    retirer(&tuile);
    plateau[LACPOS-1][LACPOS-1] = tuile;
    retirer(&tuile);
    plateau[LACPOS-1][LACPOS] = tuile;
    retirer(&tuile);
    plateau[LACPOS-1][LACPOS+1] = tuile;
    return 9;

}


