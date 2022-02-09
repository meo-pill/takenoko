#include "../../lib/index.h"
/**
 * fichier avec les fonction d'initialisation et de supression du jeu
 * Mewen / Leo
 */


/**
 * @brief mélange le tableau
 * Mewen
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
    for (i = 0; i < (NBTUILE * 4); i++){
        while (k == j){
            j = rand() % (NBTUILE);
            k = rand() % (NBTUILE);
        }
        t = piece[j];
        piece[j] = piece[k];
        piece[k] = t;
    }
}

/**
 * @brief sert a extraire le contenue du fichier de memoire des tuile
 * Mewen
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
    while (fscanf(ficTuile,"%d,%d,%d,%d,%s\n",&couleur,&iriguer,&bambou,&effet,&valeur) != EOF){
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
        strcpy(piece[compteur]->image, valeur);

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

/**
 * @brief fonction de mise en file des tuile de terrains
 * Mewen
 * 
 */
static void mise_en_file(void){
    for(int i=0; i<NBTUILE; i++){
        ajouter(piece[i]);
    }
}

/**
 * @brief création des structur de joueur
 * Mewen
 * @param nb_joueur 
 */
static void creation_joueur(int const nb_joueur){
    for (int i = 0; i < nb_joueur; i++){
        J[i] = malloc(sizeof(joueur_t));
    }
}

int extraction_fichier_carte(){

}

static void creation_plateau(void){
    for(int i=0; i<27; i++){
        for(int j=0; j<NBTUILE; j++){
            plateau[i][j] = NULL;
        }
    }
    lac.Coul="lac";
    lac.Eff="lac";
    lac.iriguer="-1";

    plateau[LACPOS][LACPOS]= &lac;
}

/**
 * @brief mise a nul des poiteur pour éviter les poiteur fous
 * Mewen
 */
static void videe_plateau(void){
    creation_plateau();
    plateau[LACPOS][LACPOS]= NULL;
}

/**
 * @brief free des tuile en alocation dinamque
 * Mewen
 */

static void suppression_tuile(void){
    for(int i=0; i<NBTUILE; i++){
        free(piece[i]);
        piece[i] = NULL;
    }
}

/**
 * @brief fonction d'apelle pour l'initialisation de la partie
 * Mewen / Leo
 */
extern void initaliser(int const nb_joueur){
    initfile();
    if (!extraction_fichier_tuile()){
        printf("ereur d'ouverture fichier tuile");
    }
    shuffleTuile();
    mise_en_file();
    creation_plateau();
    creation_joueur(nb_joueur);
}

/**
 * @brief fonction d'appelle pour la libération de fin de partie
 * Mewen / Leo
 */
extern void suprimer(void){
    videe_plateau();
    suppression_tuile();
}
