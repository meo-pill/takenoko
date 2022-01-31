#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED
/**
 *
 *
 *
 *
 */

/**Definition des constante*/
#define MAXNB2J 9
#define MAXNB3J 8
#define MAXNB4J 7
/**definition des structurs*/
typedef struct  personnage personnage_t;
typedef struct case_plato case_plato_t;
typedef struct carte carte_t;
typedef struct joueur joueur_t;

/**definition des type enumérer*/
typedef enum couleur {jaune,rose,vert};
typedef enum effet{rien,eau,stop,plus};
typedef enum effDes{soleil,pluie,vent,orage,nuage,choixJ};
typedef enum couleurJ{bleu,rouge,noir,vert};

/**variable globale*/
joueur_t J[4];
case_plato_t piece[27];
carte_t typeCartePanda[4];
carte_t *cartePanda[15];
carte_t carteParcelle[15];
carte_t carteJardinier[15];
case_plato_t * plateau[27][27];


/** des structurs*/
struct personnage{
        int x,y; //coordonnée
        char image; //l'images du personne
        char Type[10]; //nom du personnage
        void (*deplacement)(case_plato_t * plateau[27][27]); // poiteur sur fonction de déplacement
};

struct case_plato{
        couleur C;
        int iriguer;
        int nbBambou;
        effet E;
};
struct carte{
 	char desc;
 	int nbRep;
 	int point;
};
 
struct joueur{
        char nom_joueur[20];
        carte * carte_panda[15];
        carte * carte_jardinier[15];
        carte * carte_parcelle[15];
	int bambou [3];
	int effSpe [3];
	int nbIrigation;
        int nbObjectif;
};

#endif