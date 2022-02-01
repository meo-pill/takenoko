#include <stdio.h>
#include <stdlib.h>

/*

\cd Documents
\cd projet
\cd takenoko_fonction

gcc test_fct.c 
./a.out

*/

typedef enum effDes_s {soleil, pluie, vent, orage, nuage, choixJ} effDes_E;
typedef enum effet_s{rien,eau,stop,plus}effet_E;

typedef struct joueur_s joueur_t;
struct joueur_s{
        char nom_joueur[20];
        carte_t * carte_panda[15];
        carte_t * carte_jardinier[15];
        carte_t * carte_parcelle[15];
	int bambou [3];
	int effSpe [3];
	int nbIrigation;
        int nbObjectif;
        couleurJ_E couleurJoueur;
};





void ajout_irrigation_stock(joueur_t * Joueur){
	Joueur->nbIrigation++;
}
void retire_irrigation_stock(joueur_t * Joueur){
	Joueur->nbIrigation--;
}



void main(){
	
	
	
	effDes_E met = lancer_meteo();
	printf("meteo random : %d \n", met);
}





