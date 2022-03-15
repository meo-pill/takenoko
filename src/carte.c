#include "../lib/index.h"

void a_null_carte(){
  int i;
  for(i = 0; i<NBCARTE; i++){
    carteJardinier[i] = NULL;
    cartePanda[i] = NULL;
    carteParcelle[i] =NULL;
  }
}

int inserer_carte(carte_t * carte){
  //prend une carte et l'insère dans le bon tableau
  //retourne 1 si il y a eu une erreur; 0 sinon
  //type peut prendre les valeurs 0,1,2,3 selon le tableau (respectivement rien, panda, parcelle et jardinier)
  int type = 0;
  int i = 0;

  if(carte->type[0] == 'j')
    type = 3;
  else if(carte->type[2] == 'r')
    type = 2;
  else
    type = 1;
  
  if(!type){
    printf("erreur d'insertion, le type de la carte spécifié ne répond pas aux critères de la fonction");
    return(1) ;
  }

  for(i = 0;i<NBCARTE;i++){
    switch (type)
    {
    case 1:
      if(cartePanda[i] == NULL){
        cartePanda[i] = carte;
        return 0;
      }
      break;
    case 2 :
      if(carteParcelle[i] == NULL){
        carteParcelle[i] = carte;
        return 0;
      }
      break;
    case 3 :
      if(carteJardinier[i] == NULL){
        carteJardinier[i] = carte;
        return 0;
      }
      break;
    }
  }
  printf("erreur d'insertion, erreur probable : plus de place dans le tableau sensé acueillir la carte; ");
  return 1;
}

carte_t * creer_carte(char * type, char * describ, char * image, int pt ){
  carte_t * carte = malloc(sizeof(carte_t));

  strcpy(carte->type,type);
  strcpy(carte->image,image);
  strcpy(carte->desc,describ);
  carte->point = pt;

  carte -> verif = recherche_fonction_verif(carte);

  return carte ;
}

void detruire_carte(){
  int i =0 ;
  for(i = 0; i<NBCARTE;i++){
    free(cartePanda[i]);
    cartePanda[i] = NULL;
  }
  for(i = 0; i<NBCARTE;i++){
    free(carteJardinier[i]);
    carteJardinier[i] = NULL;
  }
  for(i = 0; i<NBCARTE;i++){
    free(carteParcelle[i]);
    carteParcelle[i] = NULL;
  }
}

void afficher_carte(carte_t * const c){
  printf("----------------------\n TYPE : %s \n IMAGE : %s \n DESCRIPTION : %s\n VALEUR : %d \n----------------------\n",c->type,c->image,c->desc,c->point);
}

static void melanger_deck (carte_t * deck [NBCARTE]){
  // cette fonction mélange un deck de carte, en passant par un tableau neutre
  carte_t * tab[NBCARTE];
  int i;
  int place;

  for(i = 0; i<NBCARTE;i++)
    tab[i] = NULL;

  i = 0;
  while(i < NBCARTE){
    place = rand()%NBCARTE;
    if(tab[place] == NULL){
      tab[place] = deck[i];
      i++;
    }
  }

  for(i = 0;i<NBCARTE;i++){
    deck[i] = tab[i];
  }
}

void melanger_carte (){
  melanger_deck(cartePanda);
  melanger_deck(carteParcelle);
  melanger_deck(carteJardinier);
}

int (* recherche_fonction_verif(carte_t * const carte))(carte_t * const){
  if(carte -> type[0] == 'j'){
    return verif_jardinier;
  }
  if(carte -> type[2] == 'n'){
    return verif_panda;
  }
  else if(carte -> type[2] == 'r')
    return recherche_fonction_parcelle(carte);
  else{
    printf("\n--------------------------\n erreur dans la recherche de fonction de recherche de la fonction de verification \n ----------------------------\n");
    return NULL;
  }
}

int (*recherche_fonction_parcelle(carte_t * const carte))(carte_t * const){
  //regarde le type d'une carte et renvoie la bonne fonction de verification

  printf("------------------ Lancement de la fonction <recherche fonction parcelle> ---------------\n");
  char forme [10];
  sscanf(carte->type,"%[^;-];",forme);
  printf("après sscanf : forme = %s\n",forme);
  if(strcmp(forme,"triangle")){
    return verif_parcelle_triangle;
  }
  else if (strcmp(forme,"losange")){
    return verif_parcelle_losange;
  }
  else if (strcmp(forme,"ligne")){
    return verif_parcelle_ligne;
  }
  else if (strcmp(forme,"arc")){
    return verif_parcelle_arc;
  }
  else{
    printf("\n-----------------------\n erreur dans la recherche de fonction parcelle, type non correct \n------------------------\n");
    return NULL;
  }
}

int verif_jardinier(carte_t * const carte){
  printf("on lance la vérification d'une carte jardinier\n");
  return 0;
}

int verif_panda(carte_t * const carte){
  printf("on lance la vérification d'une carte panda\n");
  return 0;
}

int verif_parcelle_triangle (carte_t * const carte){
  /*printf("on lance la vérification d'une carte parcelle triangle\n");
  int i,j;

  couleur_E couleur;

  for(i=0;i<NBTUILES;i++){
    for(j=0;j<NBTUILES;j++){
      if(plateau[i][j]->Coul == couleur && plateau[i][j]->iriguer){
        return (plateau[i][j+1]->Coul == couleur && plateau[i+1][j+1]->Coul == couleur);
      }
    }
  }*/
  return 0;
}

int verif_parcelle_losange(carte_t * const carte){
  printf("on lance la vérification d'une carte parcelle losange\n");
  return 0;
}

int verif_parcelle_ligne(carte_t * const carte){
  printf("on lance la vérification d'une carte parcelle ligne\n");
  return 0;
}
int verif_parcelle_arc(carte_t * const carte){
  printf("on lance la vérification d'une carte parcelle arc\n");
  return 0;
}
