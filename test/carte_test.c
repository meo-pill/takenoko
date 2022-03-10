#include "../lib/carte.h"

int test_triangle(){
    return 0;
}


int main(){
    carte_t * carte ;
    carte = creer_carte("parcelle-jaune/rose-losange;","description","../image/parcelle", 4);
    afficher_carte(carte);
    recherche_fonction_verif(carte);
    carte->verif(carte);
}
