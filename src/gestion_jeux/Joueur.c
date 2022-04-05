#include "../../lib/index.h"


int possede_effet(joueur_t * j, effet_E effet){
    if(j->effSpe[effet] <= 0){
        return 0;
    }
    return 1;
}


int orage_panda(int x, int y){
    if(!case_existe(x,y)){
        printf("\n--------------erreur, la case spécifié n'existe pas----------------------\n\n");
        return 1;
    }
    else{
        panda.x = x;
        panda.y = y;
        if(plateau[x][y]->nbBambou < 2)
            plateau[x][y]->nbBambou = 0;
        else
            plateau[x][y]->nbBambou -= 2;
    }
    return 0;
}

extern int victoire_joueur(joueur_t const * J, int const maxpoint){
    return (J->nbObjectif >= maxpoint);
}
