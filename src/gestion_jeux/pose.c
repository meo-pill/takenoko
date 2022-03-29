/**
 * @file back_pose.c
 * @author MEWEN
 * @brief fonction pour les pose des case et des irigation
 * @version 0.1
 * @date 2022-03-02
 * 
 */
#include "../../lib/pose.h"

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
extern int coordoner_posible(int const x, int const y){
    return( x > 0 && x < NBTUILES && y > 0 && y < NBTUILES);
}

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
extern int case_existe(int const x, int const y){
    if(coordoner_posible(x,y)){
        return(plateau[x][y]!=NULL);
    }
    return(-1);
}

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
extern int case_differente(int const xa, int const ya, int const xn, int const yn){
    if(coordoner_posible(xa,ya) && coordoner_posible(xn,yn)){
        return(xa!=xn && ya!=yn);
    }
    return(0);
}

/**
 * @brief verification que la case pointer est sur la ligne
 * 
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
    if(coordoner_posible(xa,ya) && coordoner_posible(xn,yn)){
        return (xa == xn || ya == yn || xa-ya == xn-yn);
    }
    return(0);
}

/**
 * @brief verification du fait que la ligne entre les deux tuile soit continue
 * 
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

extern int a_coter_irigation(int const x, int const y){
    if(coordoner_posible(x,y)){
        for(int i=0; irig[i]!=NULL;i++){
            if((irig[i]->x_bas_droit == x && irig[i]->y_bas_droit == y )||(irig[i]->x_haut_gauche == x && irig[i]->y_haut_gauche == y )){
                return 1;
            }
        }
    }
    return(0);
}

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
extern int pose_tuile_impossible(int const x, int const y){
    int validation = 0;
    if(contigue(x,y,LACPOS,LACPOS)){
        return (0);
    }
    if (case_existe(x,y)){
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
int ajout_tuile(case_plato_t  * case_choix, int const x, int const y){

    if(!pose_tuile_impossible(x,y)){
        plateau[x][y] = case_choix;
        if(contigue(x,y,LACPOS,LACPOS)){
            plateau[x][y]->iriguer = 1;
        }
        else{
            if(a_coter_irigation(x,y)){
                plateau[x][y]->iriguer = 1;
            }
        }
        return 1;
    }
    return 0;
}


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
extern int contigue(int const xa, int const ya, int const xb, int const yb){
    return( (xa == xb-1 && ya == yb) || (xa == xb+1 && ya == yb) || 
    (xa == xb && ya == yb-1) || (xa == xb && ya == yb+1) ||
    (xa == xb-1 && ya == yb-1) || (xa == xb+1 && ya == yb+1) );
}

/**
 * @brief fonction de verfication d'access au lac
 * 
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
    if ((xa == LACPOS && ya == LACPOS) || xb == (LACPOS && yb == LACPOS)){
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
            if(irig[i]->x_haut_gauche == xa-1 && irig[i]->y_haut_gauche == ya &&
            irig[i]->x_bas_droit == xb && irig[i]->y_bas_droit == yb-1){
                return (1);
            }
            if(irig[i]->x_haut_gauche == xa-1 && irig[i]->y_haut_gauche == ya &&
            irig[i]->x_bas_droit == xb && irig[i]->y_bas_droit == yb){
                return (1);
            }
            if(irig[i]->x_haut_gauche == xa && irig[i]->y_haut_gauche == ya &&
            irig[i]->x_bas_droit == xb+1 && irig[i]->y_bas_droit == yb){
                return (1);
            }
            if(irig[i]->x_haut_gauche == xa && irig[i]->y_haut_gauche == ya+1 &&
            irig[i]->x_bas_droit == xb+1 && irig[i]->y_bas_droit == yb){
                return (1);
            }
        }
    }
    else if (ya == yb){
        for(i=0; i<NBIRIG && irig[i]!=NULL; i++){
            if(irig[i]->x_haut_gauche == xa && irig[i]->y_haut_gauche == ya-1 &&
            irig[i]->x_bas_droit == xb-1 && irig[i]->y_bas_droit == yb){
                return (1);
            }
            if(irig[i]->x_haut_gauche == xa && irig[i]->y_haut_gauche == ya-1 &&
            irig[i]->x_bas_droit == xb && irig[i]->y_bas_droit == yb){
                return (1);
            }
            if(irig[i]->x_haut_gauche == xa && irig[i]->y_haut_gauche == ya &&
            irig[i]->x_bas_droit == xb && irig[i]->y_bas_droit == yb+1){
                return (1);
            }
            if(irig[i]->x_haut_gauche == xa+1 && irig[i]->y_haut_gauche == ya &&
            irig[i]->x_bas_droit == xb && irig[i]->y_bas_droit == yb+1){
                return (1);
            }
        }
    }
    else if (xa-xb == ya-yb){
        for(i=0; i<NBIRIG && irig[i]!=NULL; i++){
            if(irig[i]->x_haut_gauche == xa && irig[i]->y_haut_gauche == ya &&
            irig[i]->x_bas_droit == xb-1 && irig[i]->y_bas_droit == yb){
                return (1);
            }
            if(irig[i]->x_haut_gauche == xa && irig[i]->y_haut_gauche == ya+1 &&
            irig[i]->x_bas_droit == xb && irig[i]->y_bas_droit == yb){
                return (1);
            }
            if(irig[i]->x_haut_gauche == xa+1 && irig[i]->y_haut_gauche == ya &&
            irig[i]->x_bas_droit == xb && irig[i]->y_bas_droit == yb){
                return (1);
            }
            if(irig[i]->x_haut_gauche == xa && irig[i]->y_haut_gauche == ya &&
            irig[i]->x_bas_droit == xb && irig[i]->y_bas_droit == yb-1){
                return (1);
            }
        }
    }
    
    return(0);
}
