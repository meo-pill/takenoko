
#include "../lib/carte.h"


void a_null_carte(){
  int i;
  for(i = 0; i<NBCARTE; i++){
    carteJardinier[i] = NULL;
    cartePanda[i] = NULL;
    carteParcelle[i] =NULL;
  }
}


int inserer_carte(carte_t * carte){
  /*type peut prendre les valeurs 0,1,2,3 selon le tableau (respectivement rien, panda, parcelle et jardinier)*/
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
extern void detruire_one_carte(carte_t** C){
	free(*C);
	C=NULL;
}

void detruire_carte(){
  int i;
  for(i = 0; i<NBCARTE;i++){
    detruire_one_carte(&cartePanda[i]);
    detruire_one_carte(&carteJardinier[i]);
    detruire_one_carte(&carteParcelle[i]);
  }
  free(*cartePanda);
  free(*carteJardinier);
  free(*carteParcelle);
  *cartePanda=NULL;
  *carteJardinier=NULL;
  *carteParcelle=NULL;
}


void afficher_carte(carte_t * const c){
  printf("----------------------\n");
  if(c == NULL)
    printf("NULL\n");
  else
    printf("TYPE : %s \n IMAGE : %s \n DESCRIPTION : %s\n VALEUR : %d \n",c->type,c->image,c->desc,c->point);
  printf("---------------------\n");
}
/**
 * @brief 
 * cette fonction mélange un deck de carte, en passant par un tableau neutre
 * @param deck 
 * le deck à mélanger
 */
static void melanger_deck (carte_t * deck [NBCARTE]){
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


int (* recherche_fonction_verif(carte_t * const carte))(carte_t * const,joueur_t * const){
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


int (*recherche_fonction_parcelle(carte_t * const carte))(carte_t * const, joueur_t * const){

  //printf("------------------ Lancement de la fonction <recherche fonction parcelle> ---------------\n");
  char forme [20];
  char buffer [50];
  sscanf(carte->type,"%[^-]-%[^-]-%s",buffer,buffer,forme);
  //printf("après sscanf :\n buffer = %s \n forme = %s\n",buffer,forme);
  if(!strcmp(forme,"triangle")){
    return verif_parcelle_triangle;
  }
  else if (!strcmp(forme,"losange")){
    return verif_parcelle_losange;
  }
  else if (!strcmp(forme,"ligne")){
    return verif_parcelle_ligne;
  }
  else if (!strcmp(forme,"arc")){
    return verif_parcelle_arc;
  }
  else{
    printf("\n-----------------------\n erreur dans la recherche de fonction parcelle, type non correct \n------------------------\n");
    return NULL;
  }
}


int verif_jardinier(carte_t * const carte,joueur_t * const J){
  //printf("on lance la vérification d'une carte jardinier\n");

  char buff_couleur[10];
  int hauteur ;
  char buff_effet[10];

  couleur_E couleur ;
  int nb_tuile_carte = 1;
  effet_E effet = effet_lac;

  int i;
  int j;

  sscanf(carte->type,"jardinier-%[^-]-%d-%[^-]",buff_couleur,&hauteur,buff_effet);

  //printf("après le sscanf :\n couleur : %s\n hauteur : %d\n effet : %s\n",buff_couleur,hauteur,buff_effet);

  switch (*buff_couleur)
  {
  case 'r' :
    couleur = rose;
    break;
  case 'j' :
    couleur = jaune;
    break;
  case 'v' :
    couleur = vert;
    break;
  default:
    printf("--------------------couleur invalide -------------------------\n");
    return -1;
  }

  switch(*buff_effet){
    case 'b' :
      effet = bassin;
      break;
    case 's' :
      effet = sans_effet;
      break;
    case 'd' :
      nb_tuile_carte = 2;
      break;
    case 't' :
      nb_tuile_carte = 3;
      break;
    case 'q' :
      nb_tuile_carte = 4;
      break;
    case 'e' :
      if(buff_effet [2] == 'c')
        effet = enclos;
      else
        effet = engrais;
      break;
    default :
      printf("--------------erreure, effet non reconnue------------\n");
      return -1;
  }
  //printf("après les switch\n");

  for(i = 0; i<NBTUILES; i++){
    for(j = 0; j<NBTUILES; j++){
      if(plateau[i][j] != NULL)
        if(plateau[i][j]->Coul == couleur && plateau[i][j]->nbBambou == hauteur)
          if((effet == effet_lac || effet == plateau[i][j]->Eff) && plateau[i][j]->Eff != effet_lac)
            nb_tuile_carte--;
    }
  }
  //printf("après le parcoure du tableau\n");
  return (nb_tuile_carte < 1);
}


int verif_panda(carte_t * const carte,joueur_t * const J){
  //printf("on lance la vérification d'une carte panda\n");
  char couleur = carte->type[6];
  switch (couleur)
  {
  case 'j':
    if(J->bambou[0] >= 2)
      return 1;
    break;
  case 'v':
    if(J->bambou[2] >= 2)
      return 1;
    break;
  case 'r':
    if(J->bambou[1] >= 2)
    break;
  case 'm':
    if(J->bambou[0]>=1 && J->bambou[1] >= 1 && J->bambou[2] >= 1)
      return 1;
    break;
  default:
    printf("------------------erreur dans la fonction verif_panda, la couleur ne semble pas bonne----------------------\n");
    return -1;
  }

  return 0;
}


int verif_parcelle_triangle (carte_t * const carte, joueur_t * const J){
  //printf("on lance la vérification d'une carte parcelle triangle\n");
  int i,j;

  char buff_couleur[10];
  couleur_E couleur;

  int ligne_impaire;

  sscanf(carte->type,"parcelle-%[^-]-",buff_couleur);

  /*printf("dans buff_couleur : %s \ndans buff couleur[0] : %c\n",buff_couleur,buff_couleur[0]);*/


  switch (buff_couleur[0])
  {
  case 'r':
    couleur = rose;
    break;
  case 'j':
    couleur = jaune;
    break;
  case 'v':
    couleur = vert;
    break;
  default:
    printf("---------------erreur de vérification de la couleur dans la fonction verif_parcelle triangle ------------------\n");
    return -1;
  }

  for(i=0;i<NBTUILES;i++){
    for(j=0;j<NBTUILES;j++){
        ligne_impaire = i%2;
        if(plateau[i][j] != NULL && plateau[i][j]->iriguer && plateau[i][j]->Coul == couleur){
          if(j < NBTUILES-1  && i < NBTUILES-1 && j>0 &&
            plateau[i+1][j+ligne_impaire] != NULL &&
            plateau[i+1][j-1+ligne_impaire] != NULL &&
            plateau[i+1][j-1+ligne_impaire]->iriguer &&
            plateau[i+1][j-1+ligne_impaire]->Coul == couleur &&
            plateau[i+1][j+ligne_impaire]->iriguer &&
            plateau[i+1][j+ligne_impaire]->Coul == couleur)
            return 1;
          else if( i > 0 && j < NBTUILES-1 && j>0 &&
            plateau[i-1][j-1+ligne_impaire] != NULL &&
            plateau[i-1][j+ligne_impaire] != NULL &&
            plateau[i-1][j-1+ligne_impaire]->iriguer &&
            plateau[i-1][j-1+ligne_impaire]->Coul == couleur &&
            plateau[i-1][j+ligne_impaire]->iriguer &&
            plateau[i-1][j+ligne_impaire]->Coul == couleur)
            return 1;
        }
        /*if(i < 3 && j < 5)
          if(plateau[i][j] != NULL)
            printf("teste avec la case {%i;%i} qui a irriguer = %i\n",i,j,plateau[i][j]->iriguer);*/
    }
  }
  return 0;
}


int verif_parcelle_losange(carte_t * const carte,joueur_t * const J){
  //printf("on lance la vérification d'une carte parcelle losange\n");

  int i,j;

  char buff_couleur1[10];
  char buff_couleur2[10] = "000000000\0";
  couleur_E couleur1;
  couleur_E couleur2;

  int ligne_impaire;

  sscanf(carte->type,"parcelle-%[^/]/%[^-]-",buff_couleur1,buff_couleur2);

  /*printf("dans buff_couleur : %s \ndans buff couleur 1[0] : %c\n",buff_couleur 1,buff_couleur 1[0]);*/


  switch (buff_couleur1[0])
  {
  case 'r':
    couleur1 = rose;
    break;
  case 'j':
    couleur1 = jaune;
    break;
  case 'v':
    couleur1 = vert;
    break;
  default:
    printf("---------------erreur de vérification de la couleur 1 dans la fonction verif_parcelle losange ------------------\n");
    return -1;
  }

  /*printf("dans buff_couleur2 : %s \ndans buff_couleur2[0] : %c\n",buff_couleur2,buff_couleur2[0]);*/

  if(buff_couleur2[1] == '0')
    couleur2 = couleur1;
  
  else{
    switch (buff_couleur2[0])
    {
    case 'r':
      couleur2 = rose;
      break;
    case 'j':
      couleur2 = jaune;
      break;
    case 'v':
      couleur2 = vert;
      break;
    default:
      printf("---------------erreur de vérification de la couleur 2 dans la fonction verif_parcelle losange ------------------\n");
      return -1;
    }
  }


   for(i=0;i<NBTUILES;i++){
    for(j=0;j<NBTUILES;j++){
      ligne_impaire = i%2;
      if(plateau[i][j] != NULL && plateau[i][j]->iriguer){
        if(plateau[i][j]->Coul == couleur1){
          if((j>0-1+ligne_impaire) && (j<(NBTUILES-ligne_impaire)) && i<NBTUILES-2 &&
            plateau[i+1][j+ligne_impaire] != NULL &&
            plateau[i+1][j-1+ligne_impaire] != NULL &&
            plateau[i+2][j] != NULL &&
            plateau[i+1][j+ligne_impaire]->iriguer == 1 &&
            plateau[i+1][j+ligne_impaire]->Coul == couleur1 &&
            plateau[i+1][j-1+ligne_impaire]->iriguer == 1 &&
            plateau[i+1][j-1+ligne_impaire]->Coul == couleur2 &&
            plateau[i+2][j]->iriguer == 1 &&
            plateau[i+2][j]->Coul == couleur2
            )
              return 1;
        }
        if(plateau[i][j]->Coul == couleur2){
          if((j>0-1+ligne_impaire) && (j<(NBTUILES-ligne_impaire)) && i<NBTUILES-2 &&
            plateau[i+1][j+ligne_impaire] != NULL &&
            plateau[i+1][j-1+ligne_impaire] != NULL &&
            plateau[i+2][j] != NULL &&
            plateau[i+1][j+ligne_impaire]->iriguer == 1 &&
            plateau[i+1][j+ligne_impaire]->Coul == couleur2 &&
            plateau[i+1][j-1+ligne_impaire]->iriguer == 1 &&
            plateau[i+1][j-1+ligne_impaire]->Coul == couleur1 &&
            plateau[i+2][j]->iriguer == 1 &&
            plateau[i+2][j]->Coul == couleur1
            )
              return 1;
        }
      }
    }
  }

  return 0;
}


int verif_parcelle_ligne(carte_t * const carte,joueur_t * const J){
  //printf("on lance la vérification d'une carte parcelle ligne\n");

  int i,j;

  char buff_couleur[10];
  couleur_E couleur;

  int ligne_impaire;

  sscanf(carte->type,"parcelle-%[^-]-",buff_couleur);

  /*printf("dans buff_couleur : %s \ndans buff couleur[0] : %c\n",buff_couleur,buff_couleur[0]);*/


  switch (buff_couleur[0])
  {
  case 'r':
    couleur = rose;
    break;
  case 'j':
    couleur = jaune;
    break;
  case 'v':
    couleur = vert;
    break;
  default:
    printf("---------------erreur de vérification de la couleur dans la fonction verif_parcelle ligne ------------------\n");
    return -1;
  }

  for(i=0;i<NBTUILES;i++){
    for(j=0;j<NBTUILES;j++){
      ligne_impaire = i%2;
      if(plateau[i][j] != NULL && plateau[i][j]->iriguer && plateau[i][j]->Coul == couleur){
        /*verticale gauche*/
        if(i < NBTUILES-2 && j>0 &&
          plateau[i+1][j-1+ligne_impaire] != NULL &&
          plateau[i+2][j-1] != NULL &&
          plateau[i+1][j-1+ligne_impaire]->iriguer &&
          plateau[i+1][j-1+ligne_impaire]->Coul == couleur &&
          plateau[i+2][j-1]->iriguer &&
          plateau[i+2][j-1]->Coul == couleur)
            return 1;
        /*verticale droit*/
        else if( i < NBTUILES-2 && j < NBTUILES-1 &&
          plateau[i+1][j+ligne_impaire] != NULL &&
          plateau[i+2][j+1] != NULL &&
          plateau[i+1][j+ligne_impaire]->iriguer &&
          plateau[i+1][j+ligne_impaire]->Coul == couleur &&
          plateau[i+2][j+1]->iriguer &&
          plateau[i+2][j+1]->Coul == couleur)
            return 1;
        /*horizontale*/
        else if(j < NBTUILES-2&&
          plateau[i][j+1] != NULL &&
          plateau[i][j+2] != NULL&&
          plateau[i][j+1]->iriguer&&
          plateau[i][j+2]->iriguer&&
          plateau[i][j+1]->Coul == couleur &&
          plateau[i][j+2]->Coul == couleur)
            return 1;
      }
    }
  }

  return 0;
}


int verif_parcelle_arc(carte_t * const carte,joueur_t * const J){
  //printf("on lance la vérification d'une carte parcelle arc\n");

  int i,j;

  char buff_couleur[10];
  couleur_E couleur;

  int ligne_impaire;

  sscanf(carte->type,"parcelle-%[^-]-",buff_couleur);

  /*printf("dans buff_couleur : %s \ndans buff couleur[0] : %c\n",buff_couleur,buff_couleur[0]);*/


  switch (buff_couleur[0])
  {
  case 'r':
    couleur = rose;
    break;
  case 'j':
    couleur = jaune;
    break;
  case 'v':
    couleur = vert;
    break;
  default:
    printf("---------------erreur de vérification de la couleur dans la fonction verif_parcelle_arc ------------------\n");
    return -1;
  }

  for(i=0;i<NBTUILES;i++){
    for(j=0;j<NBTUILES;j++){
      ligne_impaire = i%2;
      if(plateau[i][j] != NULL && plateau[i][j]->iriguer && plateau[i][j]->Coul == couleur){
        /*verticale gauche*/
        if(i < NBTUILES-2 && j>0 &&
          plateau[i+1][j-1+ligne_impaire] != NULL &&
          plateau[i+2][j] != NULL &&
          plateau[i+1][j-1+ligne_impaire]->iriguer &&
          plateau[i+1][j-1+ligne_impaire]->Coul == couleur &&
          plateau[i+2][j]->iriguer &&
          plateau[i+2][j]->Coul == couleur)
            return 1;
        /*verticale droit*/
        else if( i < NBTUILES-2 && j < NBTUILES-1 &&
          plateau[i+1][j+ligne_impaire] != NULL &&
          plateau[i+2][j] != NULL &&
          plateau[i+1][j+ligne_impaire]->iriguer &&
          plateau[i+1][j+ligne_impaire]->Coul == couleur &&
          plateau[i+2][j]->iriguer &&
          plateau[i+2][j]->Coul == couleur)
            return 1;
      }
    }
  }
  return 0;
}

//carte_t * carte_suivante (){
//  
//}

int nb_point_joueur(joueur_t *J){
  int resultat = 0;
  for(int i = 0; i < MAXNB2J && J->valide[i] != NULL; i++){
    resultat += (J->valide[i])->point;
  }
  return resultat;
}
