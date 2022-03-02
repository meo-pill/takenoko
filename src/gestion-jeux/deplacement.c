/**
 * @file deplacement.c
 * @author MEWEN
 * @brief fonction de calcul pour le delacement est la gestion de pose sur le plateau
 * @version 0.1
 * @date 2022-03-02
 * 
 */
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
                    return(0);
                }
            }
        }
        if (ya > yn){
            for(yTmp = yn+1; yTmp<ya; yTmp++){
                if (plateau[xa][yTmp]==NULL){
                    return(0);
                }
            }
        }
    }
    else if (!(ya-yn)){
        if (xa < xn){
            for(xTmp = xa+1; xTmp<yn; xTmp++){
                if (plateau[xTmp][ya]==NULL){
                    return(0);
                }
            }
        }
        if (xa > xn){
            for(xTmp = xn+1; xTmp<ya; xTmp++){
                if (plateau[xTmp][ya]==NULL){
                    return(0);
                }
            }
        }
    }
    else{
        if (xa < xn){
            xTmp = xa+1;
            yTmp = ya+1;
            while(xTmp < xn){
                if (plateau[xTmp][yTmp]==NULL){
                    return(0);
                }
                xTmp ++;
                yTmp ++;
                nb_rep ++;
            }
        }
        if (xa > xn){
            xTmp = xn+1;
            yTmp = yn+1;
            while(xTmp < xa){
                if (plateau[xTmp][yTmp]==NULL){
                    return(0);
                }
                xTmp ++;
                yTmp ++;
            }
        }
    }
    return(1);
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
extern int deplacement_imposible(int const xa, int const ya, int const xn, int const yn){
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

/**
 * @brief verifiaction des la posibllité de posser une tuile
 * MEWEN
 * @param x coordoné x de la tuile
 * @param y coordoné y de la tuile
 * @return int 
 * retour d'un int de validation/erreur
 * 0= la posse de la tuile est possible
 * 1= une tuile se trouve deja a l'emplacement
 * 2= l'emmplacement a moin de 2 voisin
 */
extern int pose_tuile_impossible(int const x, int const y){
    int validation = 0;
    if (!case_existe(x,y)){
        return(1);    
    }
    // test de toute les position voisine et ajjout dans un compteur
    validation += case_existe(x-1,y-1);
    validation += case_existe(x-1,y);
    validation += case_existe(x,y-1);
    validation += case_existe(x,y+1);
    validation += case_existe(x+1,y);
    validation += case_existe(x+1,y+1);
    // pour que la posse soit possible la casse doit avoir minimum 2 voissine donc le compteur doit ètre >= a 2
    if(validation >= 2){
        return(0);
    }
    return(2);
}

/**
 * @brief verfication de la contiguité entre deux case
 * MEWEN
 * @param xa 
 * @param ya coordonné de la premier case
 * @param xb 
 * @param yb coordonné de la seconde case
 * @return int 
 * O = les case ne sont pas contigue
 * 1 = les case sont contigue
 */
extern int contigue(int const xa, int const ya, int const xb, int const yb){
    return( (xa == xb-1 && ya == yb) || (xa == xb+1 && ya == yb) || 
    (xa == xb && ya == yb-1) || (xa == xb && ya == yb+1) ||
    (xa == xb-1 && ya == yb-1) || (xa == xb+1 && ya == yb+1) );
}

/**
 * @brief fonction de verfication d'access au lac
 * MEWEN
 * @param xa 
 * @param ya 
 * @param xb 
 * @param yb coordoné des casse la plus en haut a gauche dabord
 * @return int 
 * 0 = la case n'a pas acces au lac
 * 1 = la case a acces au lac
 */
extern int access_lac(int const xa, int const ya, int const xb, int const yb){
    int i;
    if (!case_existe(xa,ya) && !case_existe(xa,yb)){
        return(0);
    }
    if (!contigue(xa,ya,xb,yb)){
        return(0);
    }
    if (contigue(xa,ya,LACPOS,LACPOS)&&contigue(xb,yb,LACPOS,LACPOS)){
        return (1);
    }
    
    if(xa == xb){
        for(i=0; i<NBIRIG && irig[i]!=NULL; i++){
            if(irig[i]->xa==xa-1 && irig[i]->ya==ya &&
            irig[i]->xb == xa && irig[i]->yb == yb){
                return (1);
            }
            
        }
    }
    else if (ya == yb){

    }
    else if (xa-xb == ya-yb){

    }
    
    return(0);
}

extern int deplacement_personage(){
    return(0);
}
