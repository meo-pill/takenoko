/**
 * @file pose.h
 * @author MEWEN et LEO NAIL
 * @brief fonction pour les pose des case et des irigation
 * @version 0.1
 * @date 2022-03-02
 * 
 */
#ifndef DEPLACEMENT_H_INCLUDED
#define DEPLACEMENT_H_INCLUDED
#include "index.h"

/**
 * @brief verificaiton de validité des coordoner
 * 
 * @param x 
 * @param y coordoner des la case
 * @return int 
 * retour d'un booléen de validation
 * 0 les coordoné sont en dehors de la matrice
 * 1 les coordoné sont dans la matrice
 */
extern int coordoner_posible(int const x, int const y);

/**
 * @brief verfication de la contiguité entre deux case
 * 
 * @param xa 
 * @param ya coordonné de la premier case
 * @param xb 
 * @param yb coordonné de la seconde case
 * @return int 
 * O = les case ne sont pas contigue
 * 1 = les case sont contigue
 */
extern int contigue(int const xa, int const ya, int const xb, int const yb);

/**
 * @brief verfication qu'il y a une tuile au coordoné
 * 
 * @param x position x a vérifier
 * @param y position y a vérifier
 * @return int 
 *  retour d'un booléen de validation
 *  0 case n'existe pas
 *  1 case existe
 */
extern int case_existe(int const x, int const y);

extern int pose_tuile_impossible(int const x, int const y);

extern int pose_canal_impossible(int const xa, int const ya, int const xb, int const yb);

/**
 * @brief verifaction si deux casse sont différent
 * 
 * @param xa position x actuel
 * @param ya position y actuel
 * @param xn nouvelle position x voulue
 * @param yn nouvelle position y voulue
 * @return int
 * retour d'un booléen de validaiton
 * 0 les case sont a la même positon
 * 1 les case sont bien différente
 */
extern int case_differente(int const xa, int const ya, int const xn, int const yn);

/**
 * @brief verification de validité des coordonée
 * 
 * @param xa position x actuel
 * @param ya position y actuel
 * @param xn nouvelle position x voulue
 * @param yn nouvelle position y voulue
 * @return int 
 *  retour d'un int de validation
 *  0= tout c'est bien passer le déplacement est possible
 *  1= la case selectioner n'existe pas;
 *  2= les case sont identique
 *  3= la case selectioner n'est pas une coordoné de déplacement valide
 *  4= la ligne entre les deux case n'est pas continue
 */
extern int deplacement_imposible(int const xa, int const ya, int const xn, int const yn);

/**
 * @brief verifiaction des la posibllité de posser une tuile
 *
 * @param x coordoné x de la tuile
 * @param y coordoné y de la tuile
 * @return int
 * retour d'un int de validation/erreur
 * 0= la posse de la tuile est possible
 * 1= une tuile se trouve deja a l'emplacement
 * 2= l'emmplacement a moin de 2 voisin
 */
extern int pose_tuile_impossible(int const x, int const y);

/**
 * @brief fonction permettant de savoir sur quelles cases on peut poser une tuile
 * 
 * @param tab un tableau de coordonne qui reçoit le résultat
 */
extern void pose_tuiles_possible(coordonne_t * tab);

/**
 * @brief fonction de verfication d'access au lac
 * 
 * @param xa 
 * @param ya 
 * @param xb 
 * @param yb
 * la case (xa,ya) est la plus en haut à gauche : 
 *  - (xa <= xb)
 *  - si (xa == ab), (ya <= yb)
 * @return int 
 * 0 = la case n'a pas acces au lac
 * 1 = la case a acces au lac
 */
extern int access_lac(int const xa, int const ya, int const xb, int const yb);

/**
 * @brief fonction de pose de tuile
 *
 * @param case_choix poiteur sur la case a ajouter
 * @param x coordoné pour la dite case
 * @param y 
 * @return int 
 * booléen de validation
 * 1 tout c'est bien passer
 * 0 il y a eu un problème
 */
int ajout_tuile(case_plato_t * case_choix, int const x, int const y);

/**
 * @brief fonction de rangement des coordonner
 * la plus en haut a gauche en premier
 * 
 * @param xa coordoner x de la premier case  a ordoner
 * @param ya coordoner y de la premier case  a ordoner
 * @param xb coordoner x de la seconde case a ordoner
 * @param yb coordoner y de la seconde case a ordoner
 */
extern void ranger(int * xa, int * ya, int * xb, int * yb);

/**
 * @brief fonction d'actualisaiton de l'irigatino d'une tuile
 * 
 * @param x coordoner x de la tuile
 * @param y coodroner y de la tuile
 */
extern void actual_irig(int const x, int const y);

#endif