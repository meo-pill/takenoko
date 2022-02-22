#include "../lib/index.h"
void palt_test(){
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
}

int main(){
    int valider=0;
    initaliser(2);
    plat_test();
    while(valider){
        printf("mettre autre chose que 0 pour arrété");
        scanf("%d",valider);
    }
    suprimer();
}