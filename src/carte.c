#include "../lib/index.h"

void a_null_carte(){
  int i;
  for(i = 0; i<NBCARTE; i++){
    carteJardinier[i] = NULL;
    cartePanda[i] = NULL;
    carteParcelle[i] =NULL;
  }
}

int verif_panda (carte_t const * carte, joueur_t const * joueur){
  switch (carte->type[6]){
    case 'v' :
      return joueur->bambou[vert] > 2;
      break;
    case 'r' :
      return joueur->bambou[rose] > 2;
      break;
    case 'j' :
      return joueur->bambou[jaune] > 2;
      break;
    case 'm' :
      break;
  }
}

int verif_parcelle_triangle (couleur_E couleur){
  int i,j;
  for(i=0;i<NBTUILES;i++){
    for(j=0;j<NBTUILES;j++){
      if(plateau[i][j]->Coul == couleur && plateau[i][j]->iriguer){
        return (plateau[i][j+1]->Coul == couleur && plateau[i+1][j+1]->Coul == couleur);
      }
    }
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