/**
 * @file carte.c
 * @author NAIL Léo
 * @brief toute les fonctions lié à la gestion des cartes
 * @version 0.1
 * @date 2022-03-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "../lib/index.h"

/**
 * @brief met tout les deck à NULL
 * 
 */
void a_null_carte(){
  int i;
  for(i = 0; i<NBCARTE; i++){
    carteJardinier[i] = NULL;
    cartePanda[i] = NULL;
    carteParcelle[i] =NULL;
  }
}

/**
 * @brief 
 * prend une carte et l'insère dans le bon tableau
 * @param carte 
 * 
 * @return int 
 *retourne 1 si il y a eu une erreur; 0 sinon
 */
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

/**
 * @brief 
 * permet de créer une carte avec tout ses paramètre
 * 
 * @param type 
 * que mettre dans type
 * @param describ 
 * description (pour clarifier les règles pour les joueurs)
 * @param image 
 * lien du fichier de l'image
 * @param pt 
 * nombre de point que raporte d'accomplir l'objectif
 * @return carte_t* 
 * l'adresse de la carte ainsi créer
 */
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
/**
 * @brief cette fonction affiche une carte sur la sortie standard
 * 
 * @param c 
 * si le paramètre est NULL, la fonction affiche NULL à la place
 */
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
/**
 * @brief 
 * appelle trois fois mélanger deck, pour que tous les decks soient mélanger
 * (n'a du sens que si les decks sont pleins)
 * 
 */
void melanger_carte (){
  melanger_deck(cartePanda);
  melanger_deck(carteParcelle);
  melanger_deck(carteJardinier);
}

/**
 * @brief 
 * fonction de recherche de la bonne fonction de vérification pour un type de carte donnée (jardinier,panda ou parcelle)
 * 
 * @param carte 
 * on cherche la fonction de vérification pour quelle carte (type doit être remplit correctement)
 * @return int(*)(carte_t* const,joueur_t * const) 
 * renvoie un pointeur sur la fonction trouvée (NULL si il ne trouve rien)
 */
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

/**
 * @brief 
 * regarde le type d'une carte parcelle et renvoie la bonne fonction de verification
 * 
 * @param carte 
 * cette carte doit-être de type parcelle
 * 
 * @return int(*)(carte_t* const, joueur_t * const) 
 * renvoie un pointeur sur la fonction trouvée (NULL si il ne trouve rien)
 */
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

/**
 * @brief fonction de vérification pour jardinier 
 * on parcoure tout le tableau pour vérifier si les objectif de la carte sont accomplie
 * 
 * @param carte 
 * quel est la carte objectif (précisément)
 * 
 * @param J
 * joueur dont c'est le tour
 * 
 * @return int 
 * on retourne 1 si la contrainte est vérifié, -1 en cas d'erreur,  0 sinon
 */
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

/**
 * @brief 
 * fonction de verification pour une carte panda
 * pour cela, on prend le joueur courant, et on vérifie s'il a asser de bambou de la bonne couleur
 * 
 * @param carte
 * ce qui nous intéresse ici, c'est la couleur (spécifié dans le type sous forme de "panda-[couleur]")
 * 
 * @param J
 * joueur dont c'est le tour, il est important pour cet objectif
 * 
 * @return int 
 * on retourne 1 si la contrainte est vérifié, -1 en cas d'erreur,  0 sinon
 */
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

/**
 * @brief 
 * fonction de verification pour une carte de parcelle, qui a besoin d'un triangle
 * 
 * @param carte 
 * 
 * @param J
 * joueur dont c'est le tour
 * 
 * @return int 
 * on retourne 1 si la contrainte est vérifié, -1 en cas d'erreur,  0 sinon
 */
int verif_parcelle_triangle (carte_t * const carte, joueur_t * const J){
  /*printf("on lance la vérification d'une carte parcelle triangle\n");*/
  int i,j;

  char buff_couleur[10];
  couleur_E couleur;

  sscanf(carte->type,"parcelle-%[^-]-",buff_couleur);

  switch (buff_couleur[1])
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
        if(plateau[i][j]->iriguer){
          
        }
    }
  }
  return 0;
}

/**
 * @brief 
 * fonction de verification pour une carte de parcelle, qui a besoin d'un losange
 * 
 * @param carte 
 * 
 * @param J
 * joueur dont c'est le tour
 * 
 * @return int 
 * on retourne 1 si la contrainte est vérifié, -1 en cas d'erreur,  0 sinon
 */
int verif_parcelle_losange(carte_t * const carte,joueur_t * const J){
  printf("on lance la vérification d'une carte parcelle losange\n");
  return 0;
}

/**
 * @brief 
 * fonction de verification pour une carte de parcelle, qui a besoin d'une ligne
 * 
 * @param carte 
 * 
 * @param J
 * joueur dont c'est le tour
 * 
 * @return int 
 * on retourne 1 si la contrainte est vérifié, -1 en cas d'erreur,  0 sinon
 */
int verif_parcelle_ligne(carte_t * const carte,joueur_t * const J){
  printf("on lance la vérification d'une carte parcelle ligne\n");
  return 0;
}

/**
 * @brief 
 * fonction de verification pour une carte de parcelle, qui a besoin d'un arc
 * 
 * @param carte 
 * 
 * @param J
 * joueur dont c'est le tour
 * 
 * @return int 
 * on retourne 1 si la contrainte est vérifié, -1 en cas d'erreur,  0 sinon
 */
int verif_parcelle_arc(carte_t * const carte,joueur_t * const J){
  printf("on lance la vérification d'une carte parcelle arc\n");
  return 0;
}
