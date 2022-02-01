#include "../lib/index.h"
/** 
 * fichier avec les fonction d'initialisation et de supression du jeu
 * 
 */


/**
 * @brief mélange le tableau
 * 
 *  
 */
static void shuffleTuile(){
    /** 
     * mise en place des variable de la fonction
     * une pour servir de tampon pour les donée
     * une de compteur
     * et deux d'indice pour les échange de place
     */
    case_plato_t * t;
    int i;
    int j;
    int k;

    /**
     * @brief boucle servant a donnée 100 répétion
     * bon rapport entre un homgénéité du mélange et temp de calcul
     * 
     * 
     */
    for (i = 0; i < 100; i++){
        while (k == j){
            j = rand() % (27);
            k = rand() % (27);
        }
        t = piece[j];
        piece[j] = piece[k];
        piece[k] = t;
    }
}



/**
 * @brief sert a extraire le contenue du fichier de memoire des tuile
 * 
 * 
 * @return int pour la gestion d'érreur
 */
static int extraction_fichier_tuile(void){
    /** création des variable */
    int couleur,iriguer,bambou,effet;
    int compteur = 0;
    char valeur[30];

    /** création et ouverture des fichier contenant les tuile */
    FILE * ficTuile = NULL;

    ficTuile = fopen("../asset/carte_objectif.txt","r");

    if(ficTuile == NULL){
        return(1);
    }

    /** boucle de remplisage du tableaux des tuile */
    while (fscanf(ficTuile,"%d,%d,%d,%d,%s\n",&couleur,&iriguer,&bambou,&effet) != EOF){
        /* création de la structure en allocation dinamque */
        piece[compteur] = malloc(sizeof(case_plato_t));

        /** 
         * attribution des valeur dans la structure
         * 
         * 
        */
        piece[compteur]->Coul = couleur;
        piece[compteur]->iriguer = iriguer;
        piece[compteur]->nbBambou = bambou;
        piece[compteur]->Eff = effet;
        piece[compteur]->image = valeur;

        compteur ++;
    }
    if(compteur != 26){
        return(1);
    }
    /** mise en aléatoire du tableaux */

    fclose(ficTuile);
    if(ficTuile != NULL){
        return (1);
    }
    return (0);
}

static int mise_en_pile(void){
    
}

extern void initaliser(void){
    initfile();
    if (!extraction_fichier_tuile()){
        printf("ereur d'ouverture fichier tuile");
    }
    shuffleTuile();
}

extern void suprimer(void){

}

