#include "../../lib/index.h"

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

carte_t * creer_carte(char * type, char * descrip, char * image, int pt ){
  carte_t * carte = malloc(sizeof(carte_t));

  strcpy(carte->type,type);
  strcpy(carte->image,image);
  strcpy(carte->desc,describ);
  carte->point = pt;


}
