/**
 * @file init_fin.h
 * @authors MEWEN PUREN / NAIL LEO
 * @brief fonction d'inisatilsation de la partie / fonction de supression
 * @version 0.1
 * @date 2022-03-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef INIT_FIN_H_INCLUDED
#define INIT_FIN_H_INCLUDED

#include "index.h"

/**
 * @brief premier fonction d'inisialisaiton pour donner une valeur au varible
 * et faire appelle a la fonction d'inisialisation des tuile et carte
 * 
 * @param nb_joueur atribution du nombre de joueur
 * @param maxpoint atribution du nombre de carte a valider en conséquence
 * @return int pour le retour d'erreur
 */
extern int debut_partie(int const  nb_joueur, int * maxpoint);

/**
 * @brief fonction d'appelle pour la libération de fin de partie
 * @authors Mewen  Leo
 */
extern void suprimer(int const nbJoueur);

/**
 * @brief 
 * Cette fonction sert à extraire les données des cartes objectif du fichier "carte_objectif.txt"
 * et d'en faire des cartes
 * @return int 0 si tout va bien 1 si la fonction n'a pas bien marché
 */
extern int extraction_fichier_carte(void);

/**
 * @brief sert a extraire le contenue du fichier de memoire des tuile
 * Mewen
 *
 * @return int pour la gestion d'érreur
 */
extern int extraction_fichier_tuile(void);

/**
 * @brief fonction de mise en file des tuile de terrains
 * Mewen
 * 
 */
extern void mise_en_file(void);

/**
 * @brief suprrime UNE tuile ;_;
 * @author MORGANE
 */
extern void suppression_ONE_tuile(case_plato_t ** T);

#endif
