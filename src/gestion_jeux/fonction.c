#include "fonction.h"
#include "pose.h"


/**********************
fonction opérationnelle
***********************/

/* à chaque tour d'un joueur */

/**
 * @brief renvoie aléatoirement un des temps de météo
 * @author MAXIME
 * @return char la valeur du temps obtenue
 */
char  lancer_meteo (){
	char meteo = (effDes_E)( rand ()% 6 );
	return meteo;
}

/**
 * @brief ajoute au stock du joueur sélectionné un effet spécial
 * @author MAXIME
 * @param Joueur le joueur sélectionné
 * @param eff l'effet spécial à ajouté
 */
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

/**
 * @brief retire au stock du joueur sélectionné un effet spécial
 * @author MAXIME
 * @param Joueur le joueur sélectionné
 * @param eff l'effet spécial à ajouté
 */
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

/**
 * @brief ajoute au stock du joueur sélectionné un bambou
 * @author MAXIME
 * @param Joueur le joueur sélectionné
 * @param coul la couleur du bambou
 */
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

/**
 * @brief retire au stock du joueur sélectionné un bambou
 * @author MAXIME
 * @param Joueur le joueur sélectionné
 * @param nb_bb_jaune le nombre de bambou jaune à enlever
 * @param nb_bb_rose le nombre de bambou rose à enlever
 * @param nb_bb_vert le nombre de bambou vert à enlever
 */
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

/**
 * @brief ajoute au stock du joueur sélectionné une irrigation
 * @author MAXIME
 * @param Joueur le joueur sélectionné
 */
void ajout_irrigation_stock ( joueur_t * Joueur){
	Joueur-> nbIrigation ++;
}

/**
 * @brief retire au stock du joueur sélectionné une irrigation
 * @author MAXIME
 * @param Joueur Joueur le joueur sélectionné
 */
void retire_irrigation_stock ( joueur_t * Joueur){
  if (Joueur-> nbIrigation > 0)
    Joueur-> nbIrigation --;
  else
    printf ( " erreur pour retier 1 irrigation " );
}



/* à chaque déplacement d'un personnage */



/* pour le plateau */

/*   ajout au plateau */



/**
 * @brief ajoute a la case du plateau sélectionner l'atribue irriguer( 1 ) et lui donne un bambou
 * @author MAXIME
 * @param x position x voulue pour poser
 * @param y position y voulue pour poser
 */
void ajout_irrigation_case ( int const x, int const y){	/* Vérifie qu'on peu poser une irrigation et s'éxécute si c'est bon */
  if (case_existe(x, y) && plateau[x][y]-> iriguer == 0){
    plateau[x][y]-> iriguer = 1;
    plateau[x][y]-> nbBambou ++;
  }
  else
    printf(" erreur pour poser une irrigation \n");
}

/**
 * @brief ajoute a la case du plateau sélectionner un effet spécial sélectionné
 * @author MAXIME
 * @param effet l'effet spécial sélectionné
 * @param x position x voulue pour poser l'effet spécial
 * @param y position y voulue pour poser l'effet spécial
 */
void ajout_effspe_plato( effet_E effet, int const x, int const y){		/* Vérifie qu'on peu poser un effet spécial et s'éxécute si c'est bon */
  if (case_existe(x, y) && plateau[x][y]-> Eff == sans_effet){
    plateau[x][y]-> Eff = effet;
    if (effet == bassin)
      ajout_irrigation_case(x, y);
  }
  else
    printf(" erreur pour poser une effspe \n");
}

/**
 * @brief ajoute a la case du plateau sélectionner 1 ou 2 bambou selon son effet spécial
 * @author MAXIME
 * @param x position x voulue pour poser le bambou
 * @param y position y voulue pour poser le bambou
 */
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

/**
 * @brief retire a la case du plateau sélectionner 1 seul bambou
 * @author MAXIME
 * @param x position x voulue pour retirer le bambou
 * @param y position y voulue pour retirer le bambou
 */
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

void choixactionduJ ( joueur_t * Joueur, char const meteo, choixJ_E memaction[2]){}


/**
 * @brief change les coordonnées du jardinier ou du Panda
 * 
 * @param perso nom du personnage (la struct porte le même nom) sélectionné
 * @param x_a nouvelle position x voulue
 * @param y_a nouvelle position y voulue
 */
void deplacer_personnage( personnage_t * perso, int const x_a, int const y_a){

  if (Verif_deplacer_perso( *perso, x_a, y_a)){
	  perso->x = x_a;
	  perso->y = y_a;
  }
  else
    printf(" erreur de déplacement ");
    
}
