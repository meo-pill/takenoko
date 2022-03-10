#include "fonction.h"

/**********************
fonction opérationnelle
***********************/

/** à chaque tour d'un joueur */

char  lancer_meteo (){
	char meteo = (effDes_E)( rand ()% 6 );
	return meteo;
}


void ajout_effspe_stock( joueur_t * Joueur, const effet_E eff){	 /* * avec l'ordre bassin,enclos,engrais */
  printf("1 effspe");
  if (eff == bassin )
    Joueur-> effSpe [ 0 ] ++;
  else if (eff == enclos )
    Joueur-> effSpe [ 1 ] ++;
  else if (eff == engrais )
    Joueur-> effSpe [ 2 ] ++;
  else
    printf ( " erreur d'ajout sur eff spé " );
}
void retrait_effspe_stock(joueur_t * Joueur, const effet_E eff) {
  if (eff == bassin )
    Joueur-> effSpe[0] --;
  else if (eff == enclos )
    Joueur-> effSpe[1] --;
  else if (eff == engrais )
    Joueur-> effSpe[2] --;
  else
    printf(" erreur de suprimer sur eff spé ");
}


void ajout_bambou_stock ( joueur_t * Joueur, const couleur_E coul, const int nb_B){	 /** coul : avec l'ordre jaune,rose,vert */
  if ( coul == jaune )
    Joueur-> bambou [ 0 ] ++;
  else if ( coul == rose )
    Joueur-> bambou [ 1 ] ++;
  else if ( coul == vert )
    Joueur-> bambou [ 2 ] ++;
  else
    printf ( " erreur d'ajout sur bambou " );
}
void  retire_bambou_stock ( joueur_t * Joueur, const int nb_bb_jaune, const int nb_bb_rose, const int nb_bb_vert){
  if (Joueur-> bambou[0] >= nb_bb_jaune)
    Joueur-> bambou[0] -= nb_bb_jaune;
  else
    printf(" pas asser de bambou jaune \n");
  
  if (Joueur-> bambou[1] >= nb_bb_rose)
    Joueur-> bambou[1] -= nb_bb_rose;
  else
    printf(" pas asser de bambou rose \n");
  
  if (Joueur-> bambou[2] >= nb_bb_vert)
    Joueur-> bambou[2] -= nb_bb_vert;
  else
    printf(" pas asser de bambou vert \n");
}


void ajout_irrigation_stock ( joueur_t * Joueur){
	Joueur-> nbIrigation ++;
}
void retire_irrigation_stock ( joueur_t * Joueur){
  if (Joueur-> nbIrigation > 0)
    Joueur-> nbIrigation --;
  else
    printf ( " erreur pour retier 1 irrigation " );
}



/** à chaque déplacement d'un personnage */




/***************************
fonction à finir et à tester
****************************/


/* * choix pour 1 joueur */

void choixactionduJ ( joueur_t * Joueur, const char meteo);


void pioche_1case (){}
void pioche_objetif ( joueur_t * Joueur){}
void pioche_effspe( joueur_t * Joueur){}



int Verif_deplacer_perso( personnage_t * perso, const int x_a, const int y_a){	 /** jardinier ou Panda et renvoyé 1 si c'est bon */
  int x_d = perso -> x, y_d = perso -> y;
  int dist_x = x_a - x_d , dist_y = y_a - y_d ;
  
  if (dist_x == 0 && dist_y == 0)
    return 0;

  if (dist_x == 0){  /** Cas 1 : x = x_a et seul y change */
    if (dist_y > 0){
      for (int j = 1 ; j < dist_y ; j++){
        if (plateau[x_d][y_d + j] == NULL)
          return 0;
      }
    }
    else{
      for (int j = 1 ; j > dist_y ; j--){
        if (plateau[x_d][y_d + j] == NULL)
          return 0;
      }
    }
  }
  
  else if (dist_y == 0){  /** Cas 2 : y = y_a et seul x change */
    if (dist_y > 0){
      for (int i = 1 ; i < dist_x ; i++){
        if (plateau[x_d + i][y_d] == NULL)
          return 0;
      }
    }
    else{
      for (int i = 1 ; i < dist_x ; i--){
        if (plateau[x_d + i][y_d] == NULL)
          return 0;
      }
    }
  }
  
  else if(dist_x == dist_y){ /** Cas 3 : y et x change (x+1/y+1 ou x-1/y-1)*/
    if (dist_y > 0){
      for (int ij = 0 ; ij < dist_x ; ij++){
          if (plateau[x_d + ij][y_d + ij] == NULL)
            return 0;
      }
    }
    else{
      for (int ij = 0 ; ij > dist_x ; ij--){
          if (plateau[x_d + ij][y_d + ij] == NULL)
            return 0;
      }
    }
  }
  else
    printf(" erreur de déplacement ");
  
  return 1;
}
void deplacer_personnage( personnage_t * perso, const int x_a, const int y_a){
  if (Verif_deplacer_perso(perso, x_a, y_a) == 1){
	  perso-> x = x_a;
	  perso-> y = y_a;
  }
  else
    printf(" erreur de déplacement ");
}



/* ajout au plateau */

int verif_pose_case( const int x, const int y){	 /** Vérifie qu'on peu poser une case	(case vide +	| - 2 case non vide adjasante) et renvoyé 1 si c'est bon
												(		| - bassin 		      )			*/
  int nb_case_autour = 0, facteur_temp = 0;
  
  while (nb_case_autour > 1 || facteur_temp > 0){
    if (plateau[x+1][y]-> Eff == lac)		/** case à droite et gauche : départ */
      nb_case_autour += 2;
    if (plateau[x-1][y]-> Eff == lac)
      nb_case_autour += 2;
  
    if (plateau[x-1][y]-> Eff == lac)		/** case en haut-droite et bas-gauche : départ */
      nb_case_autour += 2;
    if (plateau[x+1][y]-> Eff == lac)
      nb_case_autour += 2;
  
    if (plateau[x-1][y-1]-> Eff == lac)	/** case en haut-gauche et bas-droite : départ */
      nb_case_autour += 2;
    if (plateau[x+1][y+1]-> Eff == lac)
      nb_case_autour += 2;
    
    
    if (plateau[x+1][y] != NULL)		/** case à droite et gauche : en cour de partie */
      nb_case_autour ++;
    if (plateau[x-1][y] != NULL)
      nb_case_autour ++;
    
    if (plateau[x][y-1] != NULL)		/** case en haut-droite et bas-gauche : en cour de partie */
      nb_case_autour ++;
    if (plateau[x][y+1] != NULL)
      nb_case_autour ++;
    
    if (plateau[x-1][y-1] != NULL)		/** case en haut-gauche et bas-droite : en cour de partie */
      nb_case_autour ++;
    if (plateau[x+1][y+1] != NULL)
      nb_case_autour ++;
	
	facteur_temp = 1;
  }

  if (plateau[x][y] == NULL && (nb_case_autour > 1))
    return 1;
  else
    return 0;
}
void ajout_case_plato ( case_plato_t * case_a, const int x, const int y){
  if (verif_pose_case( x, y) == 1){
	  plateau[x][y] = case_a;
  }
  else
    printf(" erreur pour poser une case ");
}


void ajout_irrigation_plateau ( const int x, const int y){	/** Vérifie qu'on peu poser une irrigation et s'éxécute si c'est bon */
  if (plateau[x][y] != NULL && plateau[x][y]-> iriguer == 0)
    plateau[x][y]-> iriguer = 1;
  else
    printf(" erreur pour poser une irrigation ");
}
void ajout_effspe_plato( effet_E * effet, const int x, const int y){		/** Vérifie qu'on peu poser un effet spécial et s'éxécute si c'est bon */
  if (plateau[x][y] != NULL && plateau[x][y]-> Eff == rien)
    plateau[x][y]-> Eff = *effet;
  else
    printf(" erreur pour poser une irrigation ");
}



/* retirer au plateau */

void retrait_case_plato ( const int x, const int y){
  free(plateau[x][y]);
  plateau[x][y] = NULL;
}

