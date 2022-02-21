#include "../../lib/index.h"

/**
 * @brief verfication qu'il y a une tuile au coordoné
 * MEWEN
 * @param x position x a vérifier
 * @param y position y a vérifier
 * @return int 
 *  retour d'un booléen de validation
 *  0 case n'existe pas
 *  1 case existe
 */
int case_existe(int x, int y){
    return(plateau[x][y]!=NULL);
}

/**
 * @brief verification d'exitence de la 
 * MEWEN
 * @param xa position x actuel
 * @param ya position y actuel
 * @param xn nouvelle position x voulue
 * @param yn nouvelle position y voulue
 * @return int 
 * retour d'un booléen de validation
 * 0 la case n'est pas sur la ligne
 * 1 la case l'es
 */
int sur_la_ligne(int xa, int ya, int xn, int yn){
    return (xa == xn || ya == yn || xa-ya == xn-yn);
}

/**
 * @brief verification de validité des coordonée
 * MEWEN
 * @param xa position x actuel
 * @param ya position y actuel
 * @param xn nouvelle position x voulue
 * @param yn nouvelle position y voulue
 * @return int 
 *  retour d'un int de validation
 *  1= la case selectioner n'existe pas;
 *  2= la case selectioner n'est pas une coordoné de déplacement valide
 */
int deplacement_posible(int xa, int ya, int xn, int yn){
    if(!a_case(xn,yn)){
        return(1);
    }
    if(!sur_la_ligne(xa,ya,xn,yn)){
        return(2);
    }
}