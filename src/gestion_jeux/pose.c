#include "../../lib/pose.h"


extern void ranger(int * xa, int * ya, int * xb, int * yb){
    if (*xa < *xb){
        return;
    }
    if(*xa == *xb){
        if(*ya < *yb){
            return;
        }
    }
    int x,y;
    x = *xa;
    y = *ya;
    *xa = *xb;
    *ya = *yb;
    *xb = x;
    *yb = y;
    return;
}


extern int coordoner_posible(int const x, int const y){
    return( x > -1 && x < NBTUILES && y > -1 && y < NBTUILES);
}

extern int case_existe(int const x, int const y){
    if(coordoner_posible(x,y)){
        return(plateau[x][y]!=NULL);
    }
    return(-1);
}

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
static int ligne_existe(int xa, int ya, int xn, int yn) {/*
    ranger(&xa,&ya,&xn,&yn);
    int ligne_impaire = xa%2;
    int nb_rep;
    int xTmp, yTmp;
    if (xa == xn){
        return 1;
    }
    if ((xa-xn)%2){
        if( (ya-yn) == ( (xa-xn)/2 ) ){
            return 1;
        }
    }
 */   
return 1;
}


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


extern int pose_tuile_impossible(int const x, int const y){
    int ligne_impaire = x%2;
    int validation = 0;
    if (case_existe(x,y)){
        return(1);
    }
    if(contigue(x,y,LACPOS,LACPOS)){
	/*if(ligne_impaire)
		printf("impaire Contique x=%d y=%d\n",x,y);
	else
		printf("paire Contique x=%d y=%d\n",x,y);
        return (0);
    */
    }

    // test de toute les position voisine et ajjout dans un compteur
    validation += case_existe(x,y-1);
    validation += case_existe(x,y+1);
    validation += case_existe(x-1,y+1-ligne_impaire);
    validation += case_existe(x-1,y-ligne_impaire);
    validation += case_existe(x+1,y+1-ligne_impaire);
    validation += case_existe(x+1,y-ligne_impaire);
    // pour que la posse soit possible la casse doit avoir minimum 2 voissine donc le compteur doit ètre >= a 2
    if(validation >= 2){
        return(0);
    }
    return(2);
}

extern void pose_tuiles_possible(coordonne_t * tab){
    int i;
    int j;
    int cases_contigue;
    int ligne_impaire;
    int k = 0;

    for(i = 0 ; i < NBTUILES ; i++){
        for(j = 0 ; j< NBTUILES; j++){
            cases_contigue = 0;
            ligne_impaire = i%2;
            if(j>0 && plateau[i][j-1] != NULL){
                cases_contigue ++;
                if(i == LACPOS && j-1 == LACPOS)
                    cases_contigue ++;
            }
            if( j>(0-ligne_impaire) && i>0 && plateau[i-1][j-1+ligne_impaire]!= NULL){
                cases_contigue ++;
                if(i-1 == LACPOS && j-1+ligne_impaire == LACPOS)
                    cases_contigue ++;
            }
                

            if(i>0 && j<NBTUILES-ligne_impaire && plateau[i-1][j+ligne_impaire]!= NULL){
                cases_contigue ++;
                if(i-1 == LACPOS && j+ligne_impaire == LACPOS)
                    cases_contigue ++;
            }

            if(j<NBTUILES-1 && plateau[i][j+1]!= NULL){
                cases_contigue ++;
                if(i == LACPOS && j+1 == LACPOS)
                    cases_contigue ++;
            }
            
            if(i<NBTUILES-1 && j<NBTUILES-ligne_impaire && plateau[i+1][j+ligne_impaire]!= NULL){
                cases_contigue ++;
                if(i+1 == LACPOS && j+ligne_impaire == LACPOS)
                    cases_contigue ++;
            }

            if(i<i<NBTUILES-1 && j>0-ligne_impaire && plateau[i+1][j-1+ligne_impaire]!= NULL){
                cases_contigue ++;
                if(i+1 == LACPOS && j-1+ligne_existe == LACPOS)
                    cases_contigue ++;
            }
            

            
            if(cases_contigue >= 2){
                tab[k].x = i;
                tab[k].y = j;
                k++;
            }
        }
    }
}


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



extern int contigue(int const xa, int const ya, int const xb, int const yb){
    int ligne_impaire = xa%2;
    return( (xa==xb && ya==yb-1)||
            (xa==xb && ya==yb+1)||
            (xa==xb-1 && ya==yb+1-ligne_impaire)||
            (xa==xb-1 && ya==yb-ligne_impaire)||
            (xa==xb+1 && ya==yb+1-ligne_impaire)||
            (xa==xb+1 && ya==yb-ligne_impaire) );

}


extern int access_lac(int const xa, int const ya, int const xb, int const yb){
    int i;
    if (!case_existe(xa,ya) && !case_existe(xa,yb)){
        return(0);
    }
    if ((xa == LACPOS && ya == LACPOS) || (xb == LACPOS && yb == LACPOS)){
        return(0);
    }
    if (!contigue(xa,ya,xb,yb)){
        return(0);
    }
    if (contigue(xa,ya,LACPOS,LACPOS)&&contigue(xb,yb,LACPOS,LACPOS)){
        return (1);
    }

    int ligne_impaire = xa %2;

    /*si les deux cases sont sur la même ligne*/
    if(xa == xb){
        /*pour toutes les irrigations*/
        for(i=0; i<NBIRIG && irig[i]!=NULL; i++){
            /*si elle contient en haut à gauche la tuile au dessus*/
            if(irig[i]->x_haut_gauche == xa-1 && irig[i]->y_haut_gauche == ya+ligne_impaire){
                /*et que ses deux tuiles ne sont pas sur la même ligne*/
                if(irig[i]->x_bas_droit != irig[i]->x_haut_gauche)
                    return 1;
            }
            /*si elle contient en bas à droite la tuile en dessous*/
            if(irig[i]->x_bas_droit == xa -1 && irig[i]->y_bas_droit == ya+ligne_impaire){
                /*et que ses deux tuiles ne sont pas sur la même ligne*/
                if(irig[i]->x_bas_droit != irig[i]->x_haut_gauche)
                    return 1;
            }
        }
    }
    /*si la case haute est en haut à gauche de l'autre*/
    else if (ya == yb+ligne_impaire && xa +1 == xb){
        /*pour toutes les irrigations*/
        for(i=0; i<NBIRIG && irig[i]!=NULL; i++){
            /*si la partie haute gauche est sur la même ligne que (xa,ya)*/
            if(irig[i]->x_haut_gauche == xa){
                /*irrigation ->  haute gauche == (xa,ya)*/
                if(irig[i]->y_haut_gauche == ya){
                    /*si l'irrigation est verticale*/
                    if(irig[i]->x_bas_droit == xa)
                        return 1;
                    else if(irig[i]->y_bas_droit == yb-1)
                        return 1;
                }
            }
            /*si irrigation->bas_droit == (xb,yb)*/
            if(irig[i]->y_bas_droit == yb && irig[i]->x_bas_droit == xb){
                if(irig[i]->x_haut_gauche == xb)
                    return 1;
                else if (irig[i]->x_haut_gauche == xa && irig[i]->y_haut_gauche == ya+1)
                    return 1;
            }
        }
    }
    /*si la case haute est en haut à droite de l'autre*/
    else if (xa +1 == xb && ya == yb-1+ligne_impaire){
        for(i=0; i<NBIRIG && irig[i]!=NULL; i++){
            if(irig[i]->x_haut_gauche == xa && irig[i]->y_haut_gauche == ya-1){
                if(irig[i]->x_bas_droit == xa)
                    return 1;
                if(irig[i]->x_bas_droit == xb && irig[i]->y_bas_droit == yb-1)
                    return 1;
            }
            if(irig[i]->y_bas_droit == yb+1 && irig[i]->x_bas_droit == xb){
                if(irig[i]->x_haut_gauche == xa && irig[i]->y_haut_gauche == ya)
                    return 1;
                if(irig[i]->x_haut_gauche == xb)
                    return 1;
            }
        }
    }
    else{
        printf("\n-------------------erreur dans la fonction acces_lac, vérifier les if-----------------\n");
    }
    return(0);
}


extern void actual_irig(int const x, int const y){
    if (contigue(x,y,LACPOS,LACPOS)){
        if(plateau[x][y]->iriguer == 0){
           plateau[x][y]->nbBambou ++;
        }
        plateau[x][y]->iriguer=1;
        return;
    }
    for(int i=0; i < NBIRIG && irig[i]!=NULL; i++){
        if((irig[i]->x_haut_gauche == x && irig[i]->y_haut_gauche==y) ||
        (irig[i]->x_bas_droit == x && irig[i]->y_bas_droit == y)){
            if(plateau[x][y]->iriguer == 0){
                plateau[x][y]->nbBambou ++;
            }
            plateau[x][y]->iriguer=1;
            return;
        }
    }
}