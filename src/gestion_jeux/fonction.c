#include "../../lib/fonction.h"
#include "../../src/gestion_jeux/pose.c"

/**********************
fonction opérationnelle
***********************/

/* à chaque tour d'un joueur */


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



void pioche_effspe( joueur_t * Joueur){}


/**
 * @brief aide à la verifaction du déplacement si la ligne est pair et que la ligne d'arriver est différente
 * @author MAXIME
 * @param x_d position x de départ
 * @param y_d position y de départ
 * @param x_a nouvelle position x voulue
 * @param y_a nouvelle position y voulue
 * @return int 
 * retour d'un booléen de validaiton
 * 0 le déplacement n'est pas valide
 * 1 le déplacement est valide
 */
int verif_ligne_droite_pair(int const x_d, int const y_d, int const x_a, int const y_a){
  if ((x_d == x_a && y_d != y_a)
  || (x_d != x_a && y_d == y_a)
  || !case_existe(x_d, y_d))
    return 0;

  else if (x_d == x_a && y_d == y_a)
    return 1;

  else{
    if (x_d < x_a){
      if (y_d < y_a)
        verif_ligne_droite_impair(x_d+1, y_d, x_a, y_a);
      
      else
        verif_ligne_droite_impair(x_d+1, y_d-1, x_a, y_a);
    }
    else{
      if (y_d < y_a)
        verif_ligne_droite_impair(x_d-1, y_d, x_a, y_a);
      
      else
        verif_ligne_droite_impair(x_d-1, y_d-1, x_a, y_a);
    }
  }
}

/**
 * @brief aide à la verifaction du déplacement si la ligne est impair et que la ligne d'arriver est différente
 * @author MAXIME
 * @param x_d position x de départ
 * @param y_d position y de départ
 * @param x_a nouvelle position x voulue
 * @param y_a nouvelle position y voulue
 * @return int 
 * retour d'un booléen de validaiton
 * 0 le déplacement n'est pas valide
 * 1 le déplacement est valide
 */
int verif_ligne_droite_impair(int const x_d, int const y_d, int const x_a, int const y_a){
  if ((x_d == x_a && y_d != y_a)
  || (x_d != x_a && y_d == y_a)
  || !case_existe(x_d, y_d))
    return 0;

  else if (x_d == x_a && y_d == y_a)
    return 1;

  else{
    if (x_d < x_a){
      if (y_d < y_a)
        verif_ligne_droite_pair(x_d+1, y_d, x_a, y_a);
      
      else
        verif_ligne_droite_pair(x_d+1, y_d-1, x_a, y_a);
    }
    else{
      if (y_d < y_a)
        verif_ligne_droite_pair(x_d-1, y_d, x_a, y_a);
      
      else
        verif_ligne_droite_pair(x_d-1, y_d-1, x_a, y_a);
    }
  }
}

/**
 * @brief verifaction si on peu déplacer le jardinier ou le Panda
 * @author MAXIME
 * @param perso nom du personnage (la struct porte le même nom) que l'on veut déplacer
 * @param x_a nouvelle position x voulue
 * @param y_a nouvelle position y voulue
 * @return int 
 * retour d'un booléen de validaiton
 * 0 le déplacement n'est pas valide
 * 1 le déplacement est valide
 */
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
      verif_ligne_droite_pair(x_d, x_a, y_d, y_a);
    }
    else{
      verif_ligne_droite_impair(x_d, x_a, y_d, y_a);
    }
  }

  return 1;
}

/**
 * @brief change les coordonnées du jardinier ou du Panda
 * 
 * @param perso nom du personnage (la struct porte le même nom) sélectionné
 * @param x_a nouvelle position x voulue
 * @param y_a nouvelle position y voulue
 */
void deplacer_personnage( personnage_t perso, int const x_a, int const y_a){

  if (Verif_deplacer_perso( perso, x_a, y_a) && case_existe(x_a, y_a)){
	  perso.x = x_a;
	  perso.y = y_a;
  }
  else
    printf(" erreur de déplacement ");
}


/* faire pousser du bambou par le jardinier */

void ajout_bambou_liste_jardinier (couleur_E const couleur, int const x, int const y, t_liste_jardinier* l, t_liste_jardinier* case_verifier){
  t_coordonees* coordonne_verif = malloc(sizeof(t_coordonees));
  coordonne_verif->x = x;
  coordonne_verif->y = y;
printf("x= %i y= %i\n",coordonne_verif->x,coordonne_verif->y);
  if (plateau[x][y]->Coul == couleur
  && plateau[x][y]->iriguer == 1
  && case_existe(x, y))
    ajout_droit_jardinier(l, coordonne_verif);
  return;
  ajout_droit_jardinier(case_verifier, coordonne_verif);

  if (!case_existe(x, y)
  || (x== LACPOS && y == LACPOS)
  || est_dans_liste_jardinier(case_verifier, x, y)
  || est_dans_liste_jardinier(l, x, y))
  {
    if (!est_dans_liste_jardinier(case_verifier, x, y))
      ajout_droit_jardinier(case_verifier, coordonne_verif);
      
    return;
  }
  
  else if ( case_existe(x, y)
          && !est_dans_liste_jardinier(case_verifier, x, y)
          && !est_dans_liste_jardinier(l, x, y)){
    
    ajout_bambou_liste_jardinier ( couleur, x, y+1, l, case_verifier);
    ajout_bambou_liste_jardinier ( couleur, x, y-1, l, case_verifier);
    
    int saut_ligne = 1;
    if (x%2 == 0) saut_ligne == -1;
    
    ajout_bambou_liste_jardinier ( couleur, x+1, y, l, case_verifier);
    ajout_bambou_liste_jardinier ( couleur, x+1, y+saut_ligne, l, case_verifier);

    ajout_bambou_liste_jardinier ( couleur, x-1, y, l, case_verifier);
    ajout_bambou_liste_jardinier ( couleur, x-1, y+saut_ligne, l, case_verifier);
  }
  else
    return;
}

void ajout_bambou_jardinier( int const x, int const y){

  if (x== LACPOS && y == LACPOS) return;

  t_liste_jardinier* liste = malloc(sizeof(t_liste_jardinier));
  init_liste_jardinier(liste);
  t_liste_jardinier* case_verifier = malloc(sizeof(t_liste_jardinier));
  init_liste_jardinier(case_verifier);

  ajout_bambou_liste_jardinier(plateau[x][y]->Coul, x, y, liste, case_verifier);

  en_tete_jardinier(liste);
  while (!hors_liste_jardinier(liste)){
    ajout_bambou_plato(liste->ec->x, liste->ec->y);
    
    suivant_jardinier(liste);
  }

  afficher_jardinier(liste);
  vider_liste_jardinier(liste);
  vider_liste_jardinier(case_verifier);
}

