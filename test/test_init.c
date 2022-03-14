#include "../lib/index.h"

void affiche_tuile(case_plato_t *tuile){
    printf("%d,%d,%d\n",tuile->Coul,tuile->Eff,tuile->iriguer);
}

int main(){
    if(extraction_fichier_tuile()){
        printf("erreur extraction\n");
        return(0);
    }
    for(int i=0; i < NBTUILES; i++){
        affiche_tuile(piece[i]);
    }
}