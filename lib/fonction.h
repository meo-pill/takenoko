#include "../lib/index.h"

/********************
fonction opérationnel
********************/

/** à chaque tour d'un joueur */

/* ne pas oublier
	#include <time.h>
et dans main
	srand( time(NULL));
*/

char lancer_meteo(){
	char meteo = (effDes_E)( rand()%6 );
	return meteo;
}





/***************************
fonction à finir et à tester
***************************/


/** choix pour 1 joueur */

void choixactionduJ(joueur_t * Joueur, const char meteo);

void ajout_irrigation_stock(joueur_t * Joueur){
	Joueur->nbIrigation++;
}
void retire_irrigation_stock(joueur_t * Joueur){
	Joueur->nbIrigation--;
}

void pioche_1case(){}
void pioche_objetif(joueur_t * Joueur){}
void pioche_effspé(joueur_t * Joueur){}

void ajout_effspé_stock(joueur_t * Joueur, const char effet_E * eff){	/** avec l'ordre eau,stop,plus */
	if (eff=="eau")
		Joueur->effSpe[0] ++;
	else if (eff=="stop")
		Joueur->effSpe[1] ++;
	else if (eff=="plus")
		Joueur->effSpe[2] ++;
	else
		return printf("erreur d'ajout sur eff spé");
}
void retire_effspé_stock(joueur_t * Joueur, const char effet_E * eff){
	if (eff=="eau")
		Joueur->effSpe[0] --;
	else if (eff=="stop")
		Joueur->effSpe[1] --;
	else if (eff=="plus")
		Joueur->effSpe[2] --;
	else
		return printf("erreur de suprimer sur eff spé");
}

void ajout_bambou_stock(joueur_t * Joueur, const int x, const int y){}
void retire_bambou_stock(joueur_t * Joueur, int nb_bb_jaune, int nb_bb_rose, int nb_bb_vert){}

int Vérif_déplacer_perso(const char perso){}	/** jardinier ou Panda et renvoie 1 si c'est bon */

void déplacer_personnage(const char perso){}



/** ajout au plateau */

int vérif_pose_case(const int x, const int y){}	/** Vérifie qu'on peu poser une case (case vide +	| - 2 case non vide adjasante
														| - bassin ) et renvoie 1 si c'est bon */

void ajout_case_plato(const int x, const int y){}

int verif_pose_irrigation_plateau(const int x, const int y){}	/** Vérifie qu'on peu poser une irrigation et renvoie 1 si c'est bon */

void ajout_irrigation_plateau(const int x, const int y){}

void ajout_effspé_plato(const int x, const int y){}



/* retirer au plateau */

void retire_case_plato(const int x, const int y){}

void retire_effspé_plato(const int x, const int y){}





