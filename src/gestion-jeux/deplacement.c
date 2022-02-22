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
extern int case_existe(int const x, int const y){
    return(plateau[x][y]!=NULL);
}

/**
 * @brief verifaction si deux casse sont différent
 * MEWEN
 * @param xa position x actuel
 * @param ya position y actuel
 * @param xn nouvelle position x voulue
 * @param yn nouvelle position y voulue
 * @return int
 * retour d'un booléen de validaiton
 * 0 les case sont a la même positon
 * 1 les case sont bien différente
 */
extern int case_differente(int const xa, int const ya, int const xn, int const yn){
    return(xa!=xn && ya!=yn);
}

/**
 * @brief verification que la case pointer est sur la ligne
 * MEWEN
 * @param xa position x actuel
 * @param ya position y actuel
 * @param xn nouvelle position x voulue
 * @param yn nouvelle position y voulue
 * @return int 
 * retour d'un booléen de validation
 * 0 la case n'est pas sur la ligne
 * 1 la case se trouve sur la ligne
 */
static int sur_la_ligne(int const xa, int const ya, int const xn, int const yn){
    return (xa == xn || ya == yn || xa-ya == xn-yn);
}

/**
 * @brief verification du fait que la ligne entre les deux tuile soit continue
 * MEWEN
 * @param xa position x actuel
 * @param ya position y actuel
 * @param xn nouvelle position x voulue
 * @param yn nouvelle position y voulue
 * @return int 
 * retour d'un booléen de validation
 * 0 la ligne n'est pas continue
 * 1 la ligne est continue
 */
static int ligne_existe(int const xa, int const ya, int const xn, int const yn){
    int nb_rep;
    int xTmp, yTmp;
    if (!(xa-xn)){
        if (ya < yn){
            for(yTmp = ya+1; yTmp<yn; yTmp++){
                if (plateau[xa][yTmp]==NULL){
                    retun(0);
                }
            }
        }
        if (ya > yn){
            for(yTmp = yn+1; yTmp<ya; yTmp++){
                if (plateau[xa][yTmp]==NULL){
                    retun(0);
                }
            }
        }
    }
    else if (!(ya-yn)){
        if (xa < xn){
            for(xTmp = xa+1; xTmp<yn; xTmp++){
                if (plateau[xTmp][ya]==NULL){
                    retun(0);
                }
            }
        }
        if (xa > xn){
            for(xTmp = xn+1; xTmp<ya; xTmp++){
                if (plateau[xTmp][ya]==NULL){
                    retun(0);
                }
            }
        }
    }
    else{
        if (xa < xn){
            xTmp = xa+1;
            yTmp = ya+1;
            while(nb_rep < xn){
                if (plateau[xTmp][yTmp]==NULL){
                    retun(0);
                }
                xTmp ++;
                yTmp ++;
            }
        }
        if (xa > xn){
            xTmp = xn+1;
            yTmp = yn+1;
            while(nb_rep < xa){
                if (plateau[xTmp][yTmp]==NULL){
                    retun(0);
                }
                xTmp ++;
                yTmp ++;
            }
        }
    }

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
 *  0= tout c'est bien passer le déplacement est possible
 *  1= la case selectioner n'existe pas;
 *  2= les case sont identique
 *  3= la case selectioner n'est pas une coordoné de déplacement valide
 *  4= la ligne entre les deux case n'est pas continue
 */
extern int deplacement_posible(int const xa, int const ya, int const xn, int const yn){
    if(!case_existe(xn,yn)){
        return(1);
    }
    if(!case_differente(xa,ya,xn,yn)){
        return(2);
    }
    if(!sur_la_ligne(xa,ya,xn,yn)){
        return(3);
    }
    if(!ligne_existe(xa,ya,xn,yn)){
        return(4);
    }
    return(0);
}

extern int deplacement_personage(){
    
}
