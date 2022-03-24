/**
 * @file tour.c
 * @author MEWEN
 * @brief gestion principale des tour du jeux
 * @version 0.1
 * @date 2022-03-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "../../lib/index.h"

/**
 * @brief premier fonction d'inisialisaiton pour donner une valeur au varible
 * et faire appelle a la fonction d'inisialisation des tuile et carte
 * 
 * @param nb_joueur atribution du nombre de joueur
 * @param maxpoint atribution du nombre de carte a valider en conséquence
 * @return int pour le retour d'erreur
 */
static int debut_partie(int const * nb_joueur, int * maxpoint){
    initaliser(*nb_joueur);
    /**
     * @brief établisement la variable du maxpoint en fonciton du nb de joueur
     * 
     */
    switch (*nb_joueur){
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



static int victoire_joueur(joueur_t const * J, int const maxpoint){
    return (J->nbObjectif >= maxpoint);
}



extern void tour_jeux(int const nb_joueur){
    int maxpoint, victoire_j=0, i, j, limite_action;
    effDes_E meteo;
    /**
     * @brief souvenir des dernière acction effectuer par le joueur
     * action numéroté de 1 a 5
     * 0 égal action nul
     */
    choixJ_E mem_action[2];

    /**
     * @brief if pour verifier la bonne initialisation de la partie
     * 
     */
    if (!debut_partie(&nb_joueur, &maxpoint)){
        printf("problème de selection du nb joueur");
        return;
    }


    while(!victoire_j){

        for(i=0; i<nb_joueur; i++){

            limite_action = 2;
            mem_action[0] = 0;
            mem_action[1] = 0;


            printf("tour du j%d",i+1);

            printf("lancer du dée");
            meteo = lancer_meteo();
            choix : switch (meteo){
            case soleil :
                printf("Un grand soleil rayonne sur la bambouseraie\n");
                printf("une action suplémentaire pour le joueur\n");
                limite_action ++;
                break;
            case pluie :
                printf("Une fine pluie vient nourrir les jeunes pousses de bambou\n");
                printf("monter de bamboo sur une partelle irigiée\n");
                declancher_pluie();
                break;
            case vent :
                printf("Une brise rafraîchissante souffle sur la bambouseraie\n");
                printf("peut effectuer 2 foi la même action\n");
                break;
            case orage :
                printf("Le ciel gronde et la foudre frappe, effrayant le panda\n");
                printf("positioner le panda ou on veut\n");
                orage_panda();
                break;
            case nuage :
                printf("De gris nuages voilent le ciel. Qu’à cela ne tienne, autant en profiter pour effectuer quelques travaux!");
                printf("choisir un aménagement");
                choix_amenagement(J[i]);
                break;
            case choixJ :
                printf("choisir la météo que l'on veut");
                choix_meteo(&meteo);
                goto choix;
                break;
            }

            for(j=0; j<limite_action;j++){
                choixactionduJ(J[i],meteo,mem_action);
            }

            validation_objectif(&J[i]);
            if(victoire_joueur(J[i],maxpoint)){
                victoire_j = 1;
                printf("J%d a valider %d objectif dernier tour",i+1,maxpoint);
            }
        }
    }
    
}