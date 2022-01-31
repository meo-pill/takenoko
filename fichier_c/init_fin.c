#include "../fichier_h/index.h"
/** 
 * fichier avec les fonction d'initialisation et de supression du jeu
 * 
 */


/**
 * @brief mélange le tableau
 * 
 *  
 */
void shuffleTuile(){
    if (27 > 1) 
    {
        case_plato_t * t;
        size_t i;
        for (i = 0; i < 27 - 1; i++) 
        {
          size_t j = i + rand() / (RAND_MAX / (27 - i) + 1);
          t = piece[j];
          piece[j] = piece[i];
          piece[i] = t;
        }
    }
}



/**
 * @brief sert a extraire le contenue du fichier de memoire des tuile
 * 
 * 
 * @return int 
 */
static int extraction_fichier_tuile(void){
    /** création des variable */
    char temp_tuile[7];
    char temp_val;
    int compteur = 0;

    /** création et ouverture des fichier contenant les tuile */
    FILE * ficTuile = NULL;

    ficTuile = fopen("../asset/carte_objectif.txt","r");

    /** boucle de remplisage du tableaux des tuile */
    while (fscanf(ficTuile,"%[^\n]",temp_tuile) != EOF){
        /* création de la structure en allocation dinamque */
        piece[compteur] = malloc(sizeof(case_plato_t));

        /** 
         * attribution des valeur dans la structure
         * 
         * int atoi ( const char * str );
         *  transforme un char en son int corespondant (normalement)
         * 
        */
        temp_val = strtok(temp_tuile,",");
        piece[compteur]->Coul = atoi(temp_val);
        temp_val = strtok(temp_tuile,",");
        piece[compteur]->iriguer = atoi(temp_val);
        temp_val = strtok(temp_tuile,",");
        piece[compteur]->nbBambou = atoi(temp_val);
        temp_val = strtok(temp_tuile,",");
        piece[compteur]->Eff = atoi(temp_val);
        compteur ++;
    }
    if(compteur != 26){
        return(1);
    }
    /** mise en aléatoire du tableaux */
    shuffleTuile(&piece);


    fclose(ficTuile);
}



extern void initaliser(void){
    initfile();

    if (!extraction_fichier()){
        printf("ereur d'ouverture fichier");
    }
}

extern void suprimer(void){

}

