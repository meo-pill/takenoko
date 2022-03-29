/**
 * @file init_fin.c
 * @author MEWEN PUREN / NAIL LEO
 * @brief fonction d'inisatilsation de la partie / fonction de supression
 * @version 0.1
 * @date 2022-03-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "../../lib/init_fin.h"

/*
 ****************************************************************************************
 * partie initialitation
 ****************************************************************************************
 */

/**
 * @brief mélange le tableau
 * Mewen
 *
 */
static void shuffleTuile(coid){
    /** 
     * mise en place des variable de la fonction
     * une pour servir de tampon pour les donée
     * une de compteur
     * et deux d'indice pour les échange de place
     */
    case_plato_t * t;
    int i;
    int j = 0;
    int k = 0;

    /**
     * @brief boucle servant a donnée 100 répétion
     * bon rapport entre un homgénéité du mélange et temp de calcul
     * 
     * 
     */
    for (i = 0; i < (NBTUILES * 6); i++){
        while (k == j){
            j = rand() % (NBTUILES);
            k = rand() % (NBTUILES);
        }
        t = piece[j];
        piece[j] = piece[k];
        piece[k] = t;
        k = j;
    }
}

/**
 * @brief sert a extraire le contenue du fichier de memoire des tuile
 * Mewen
 *
 * @return int pour la gestion d'érreur
 */
extern int extraction_fichier_tuile(void){
    /** création des variable */
    int couleur,iriguer,bambou,effet;
    int compteur = 0;
    char valeur[30];

    printf("Extraction lancé\n");

    /** création et ouverture des fichier contenant les tuile */
    FILE * ficTuile = NULL;

    ficTuile = fopen("asset/tuile.txt","r");

    if(ficTuile == NULL){
	printf("le fichier ne c'est pas ouvert\n");
        return(1);
    }
    /** boucle de remplisage du tableaux des tuile */
    printf("Enregistrement en cour\n");
    while (fscanf(ficTuile,"%d,%d,%d,%d,%s\n",&couleur,&iriguer,&bambou,&effet,valeur) != EOF){
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
    if(compteur != 27){
	printf("Mauvais nombre de tuile %d\n",compteur);
        return(1);
    }
    /** mise en aléatoire du tableaux */

    
    if(fclose(ficTuile)==EOF){
	printf("Le fichier c'est mal fermet\n");
        return (1);
    }
    printf("Fin de l'extraction\n");
    return (0);
}

/**
 * @brief fonction de mise en file des tuile de terrains
 * Mewen
 * 
 */
extern void mise_en_file(void){
    for(int i=0; i<NBTUILES; i++){
        ajouter(piece[i]);
    }
}

/**
 * @brief retoutne le nom d'un joueur
 * @author Morgane
 */
static char* NomJ (int numJ){
	switch(numJ){
		case 1:
			return "Joueur1";
			break;
		case 2:
			return "Joueur2";
			break;
		case 3:
			return "Joueur3";
			break;
		case 4:
			return "Joueur4";
			break;
	}
	return NULL;
}

/**
 * @brief création des structur de joueur
 * Mewen
 * @param nb_joueur 
 */
static void creation_joueur(int const nb_joueur){
    int j;
    for (int i = 0; i < nb_joueur; i++){
        J[i] = malloc(sizeof(joueur_t));
	J[i]->nom_joueur= malloc(sizeof(char));
        J[i]->nom_joueur=NomJ(i+1);
        for(j=0;j<3;j++){
            joueur_pioche_carte(J[i],j);
        	J[i]->bambou[j]=0;
        	J[i]->effSpe[j]=0;
        }
        for(j=0;j<MAXNB2J;j++){
        	J[i]->valide[j]=NULL;
        }
        J[i]->nbIrigation=0;
        J[i]->nbObjectif=i;
    }
    for(int i=4-nb_joueur;i!=0;i--){
	    J[i] =NULL;
    }
}




/**
 * @brief mise en place de la case lac et inisialisaiton des poiteur
 * MEWEN
 */
static void creation_plateau(void){
    for(int i=0; i<27; i++){
        for(int j=0; j<NBTUILES; j++){
            plateau[i][j] = NULL;
        }
    }
    lac.Coul= water;
    lac.Eff= effet_lac;
    lac.iriguer= -1;
    strcpy(lac.image,"image/en_plus/Depart.png");

    plateau[LACPOS][LACPOS]= &lac;
}

/**
 * @brief initalisation du tableau des irigation
 * MEWEN
 */
static void init_irigation(void){
    for(int i=0; i < NBIRIG; i++){
        irig[i]= NULL;
    }
}

extern int extraction_fichier_carte(){
    int nb_panda = 0;
    int nb_parc = 0;
    int nb_jard = 0;

    int i;

    char type [LONGTYPE];
    char image [LONGPATH];
    char desc [DESCRIPTION];
    int pt;

    FILE * fich;
    fpos_t position;

    fich = fopen("asset/carte_objectif.txt","r");
    if(fich == NULL)
        printf("\n --------------------- \n erreur lors de l'ouverture du fichier \"carte_objectif.txt \" \n ---------------------\n");
    
    //fgetpos(fich,&position);
    //fread(desc,36,200,fich);
    fscanf(fich,"%s\n",desc);

    while(!feof(fich)){
        fgetpos(fich,&position);
        //printf("on avance dans le fichier : on est à %li\n",position.__pos);
        for(i=0; type[i-1] !=';';i++){
            fscanf(fich,"%c",&type[i]);
        }
        type[i-1] = '\0';
        
        //printf("type : %s \n",type);

        for(i=0;image[i-1]!=';';i++){
            fscanf(fich,"%c",&image[i]);
        }
        image[i-1] = '\0';
        //printf("image : %s\n",image);


        for(i=0;desc[i-1]!=';';i++)
            fscanf(fich,"%c",&desc[i]);

        desc[i-1] = '\0';

        fscanf(fich,"%d\n",&pt);
        if(type[5] == '-'){
            cartePanda[nb_panda] = creer_carte(type,desc,image,pt);
            nb_panda ++;
        }
        else if (type[8] == '-'){
            carteParcelle[nb_parc] = creer_carte(type,desc,image,pt);
            nb_parc ++;
        }
        else if (type[9] == '-'){
            carteJardinier[nb_jard] = creer_carte(type,desc,image,pt);
            nb_jard ++;
        }
        else{
            printf("\n --------------------- \n erreur de recuperation des cartes (type mal informé)\n type contient : \"%s\"\n -------------- \n",type);
            return 1;
        }
        if(nb_panda > 15 || nb_parc > 15 || nb_jard > 15){
            printf("\n --------------------- \n erreur de recuperation des types de cartes (trop d'un type) \n panda : %d \n parcelles : %d \n jardinier : %d \n  --------------------- \n",nb_panda,nb_parc,nb_jard);
            return 1;
        }
    }
    fclose(fich);
    return 0;

}

/**
 * @brief fonction d'apelle pour l'initialisation de la partie
 * Mewen / Leo
 */
static void initialiser(int const nb_joueur){
    initfile();
    if (extraction_fichier_tuile()){
        printf("ereur d'ouverture fichier tuile\n");
    }
    if(extraction_fichier_carte()){
        printf("erreur dans l'ouvertur des cartes");
    }
    srand(time(NULL));
    melanger_carte();
    shuffleTuile();
    mise_en_file();
    creation_plateau();
    creation_joueur(nb_joueur);
    init_irigation();
    indique_carte[0] = 0;
    indique_carte[1] = 0;
    indique_carte[2] = 0;
}

/**
 * @brief premier fonction d'inisialisaiton pour donner une valeur au varible
 * et faire appelle a la fonction d'inisialisation des tuile et carte
 * 
 * @param nb_joueur atribution du nombre de joueur
 * @param maxpoint atribution du nombre de carte a valider en conséquence
 * @return int pour le retour d'erreur
 */
extern int debut_partie(int const  nb_joueur, int * maxpoint){
    initialiser(nb_joueur);
    /**
     * @brief établisement la variable du maxpoint en fonciton du nb de joueur
     * 
     */
    switch (nb_joueur){
    case 2:
        *maxpoint = MAXNB2J;
        break;
    case 3:
        *maxpoint = MAXNB3J;
        break;
    case 4:
        *maxpoint = MAXNB4J;
        break;
    default:
        return(0);
    }
    return(1);
}


/*
 ****************************************************************************************
 * partie destruction
 ****************************************************************************************
 */

/**
 * @brief detruit un joueur
 * @author Morgane
 */
static void det_Joueur(joueur_t** Joueur){
	free((*Joueur)->nom_joueur);
	(*Joueur)->nom_joueur=NULL;
	for(int i=0;i<5;i++){
		if((*J)->main_J[i]!=NULL)
			detruire_one_carte(&((*Joueur)->main_J[i]));
	}
	for(int i=0;i<MAXNB2J;i++){
		if((*Joueur)->valide[i]!=NULL)
			detruire_one_carte(&((*Joueur)->valide[i]));
	}
	free((*J));
	*J=NULL;
}
/**
 * @briefdetruit les joueurs 
 * @author Morgane
 */
static void detruir_Table_J(int const nbJoueur){
	for(int i=0;i<nbJoueur;i++){
		det_Joueur(&J[i]);
	}
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
    for(int i=0; i<NBTUILES; i++){
        free(piece[i]);
        piece[i] = NULL;
    }
}

static void suppression_irig(void){
    for(int i=0; i < NBIRIG; i++){
	if(irig[i]!=NULL)
		free(irig[i]);
    }
    init_irigation();
}

/**
 * @brief fonction d'appelle pour la libération de fin de partie
 * Mewen / Leo
 */
extern void suprimer(int const nbJoueur){
	printf("Je débug\n");
	if(plateau!=NULL)
		videe_plateau();
    detruire_carte();
    suppression_tuile();
    suppression_irig();
    detruir_Table_J(nbJoueur);
}
