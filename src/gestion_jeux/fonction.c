#include "../../lib/fonction.h"


/**********************
fonction opérationnelle
***********************/

/* à chaque tour d'un joueur */


void ajout_effspe_stock( joueur_t * Joueur, effet_E const eff){	 /* dans l'ordre bassin,enclos,engrais */
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


void retrait_effspe_stock(joueur_t * Joueur, effet_E const eff) {
  if (eff == bassin )
    Joueur-> effSpe[0] --;
  else if (eff == enclos )
    Joueur-> effSpe[1] --;
  else if (eff == engrais )
    Joueur-> effSpe[2] --;
  else
    printf(" erreur de suprimer sur eff spé ");
}


void ajout_bambou_stock ( joueur_t * Joueur, couleur_E const coul){	 /* dans l'ordre jaune,rose,vert */
  if ( coul == jaune )
    Joueur-> bambou [ 0 ] ++;
  else if ( coul == rose )
    Joueur-> bambou [ 1 ] ++;
  else if ( coul == vert )
    Joueur-> bambou [ 2 ] ++;
  else
    printf ( " erreur d'ajout sur bambou " );
}


void  retire_bambou_stock ( joueur_t * Joueur, int const nb_bb_jaune, int const nb_bb_rose, int const nb_bb_vert){
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



/* à chaque déplacement d'un personnage */



/* pour le plateau */

/*   ajout au plateau */




void ajout_irrigation_case ( int const x, int const y){	/* Vérifie qu'on peu poser une irrigation et s'éxécute si c'est bon */
  if (case_existe(x, y) && plateau[x][y]-> iriguer == 0){
    plateau[x][y]-> iriguer = 1;
    plateau[x][y]-> nbBambou ++;
  }
  else
    printf(" erreur pour poser une irrigation \n");
}


void ajout_effspe_plato( effet_E effet, int const x, int const y){		/* Vérifie qu'on peu poser un effet spécial et s'éxécute si c'est bon */
  if (case_existe(x, y) && plateau[x][y]-> Eff == sans_effet){
    plateau[x][y]-> Eff = effet;
    if (effet == bassin)
      ajout_irrigation_case(x, y);
  }
  else
    printf(" erreur pour poser une effspe \n");
}


void ajout_bambou_plato( int const x, int const y){		/* Vérifie qu'on peu poser un effet spécial et s'éxécute si c'est bon */
  
  if (case_existe(x, y) && plateau[x][y]-> iriguer == 1 && plateau[x][y]-> nbBambou < 4){
    if (plateau[x][y] -> Eff != engrais)  /* sans engrais */
      plateau[x][y]-> nbBambou += 1;

    else if (plateau[x][y] -> Eff == engrais) /* avec engrais et limite */
      if(plateau[x][y]-> nbBambou == 3)
        plateau[x][y]-> nbBambou += 1;
      else
        plateau[x][y]-> nbBambou += 2;
    else
      printf(" erreur pour poser un bambou \n");
  }
  else
    printf(" erreur pour poser un bambou \n");
}


void retrait_bambou_plato( int const x, int const y){		/* Vérifie qu'on peu poser un effet spécial et s'éxécute si c'est bon */
  if (!case_existe(x, y) && plateau[x][y]-> iriguer == 1 && plateau[x][y]-> nbBambou > 0)
    plateau[x][y]-> nbBambou --;
  else
    printf(" erreur pour retirer un bambou \n");
}











/***************************
fonction à finir et à tester
****************************/


/* * choix pour 1 joueur */

//void choixactionduJ ( joueur_t * Joueur, char const meteo, choixJ_E memaction[2]){}



//void pioche_effspe( joueur_t * Joueur){}





int verif_ligne_droite_pair(int const x_d, int const y_d, int const x_a, int const y_a){
  if ((x_d == x_a && y_d != y_a)
  || !case_existe(x_d, y_d))
    return 0;

  else if (x_d == x_a && y_d == y_a)
    return 1;

  else{
    if (x_d < x_a){
      if (y_d < y_a)
        return (verif_ligne_droite_impair(x_d+1, y_d, x_a, y_a));
      
      else
        return (verif_ligne_droite_impair(x_d+1, y_d-1, x_a, y_a));
    }
    else{
      if (y_d < y_a)
        return (verif_ligne_droite_impair(x_d-1, y_d, x_a, y_a));
      
      else
        return (verif_ligne_droite_impair(x_d-1, y_d-1, x_a, y_a));
    }
  }
}


int verif_ligne_droite_impair(int const x_d, int const y_d, int const x_a, int const y_a){
  if ((x_d == x_a && y_d != y_a)
  || !case_existe(x_d, y_d))
    return 0;

  else if (x_d == x_a && y_d == y_a)
    return 1;

  else{
    if (x_d < x_a){
      if (y_d < y_a)
        return (verif_ligne_droite_pair(x_d+1, y_d, x_a, y_a));
      
      else
        return (verif_ligne_droite_pair(x_d+1, y_d-1, x_a, y_a));
    }
    else{
      if (y_d < y_a)
        return (verif_ligne_droite_pair(x_d-1, y_d, x_a, y_a));
      
      else
        return (verif_ligne_droite_pair(x_d-1, y_d-1, x_a, y_a));
    }
  }
}


int Verif_deplacer_perso( personnage_t perso, int const x_a, int const y_a){	 /* jardinier ou Panda et renvoie 1 si c'est bon */

  int x_d = perso.x, y_d = perso.y;
  int dist_x = x_a - x_d , dist_y = y_a - y_d;
  
  if (dist_x == 0 && dist_y == 0) /* Si on choisi la case de départ */
    return 0;

  if (dist_x == 0 && dist_y !=0){          /* Cas 1 même ligne : x = x_a et seul y change */
    if (dist_y > 0){
      for (int j = 1 ; j < dist_y ; j++){
        if (!case_existe(x_d, y_d + j)) return 0;
      }
    }
    else{
      for (int j = -1 ; j > dist_y ; j--){
        if (!case_existe(x_d, y_d + j)) return 0;
      }
    }
  }

  
  else{    /* Cas 2 même colone : y = y_a et seul x change */
    if (x_d%2 == 0){
      return (verif_ligne_droite_pair(x_d, x_a, y_d, y_a));
    }
    else{
      return (verif_ligne_droite_impair(x_d, x_a, y_d, y_a));
    }
  }

  return 1;
}


/* void deplacer_personnage( personnage_t perso, int const x_a, int const y_a){

  if (Verif_deplacer_perso( perso, x_a, y_a) && case_existe(x_a, y_a)){
	  perso.x = x_a;
	  perso.y = y_a;
  }

  if (perso.Type == "jardinier") ajout_bambou_jardinier(x_a, y_a);
}
*/


