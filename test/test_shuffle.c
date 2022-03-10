#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NBTUILES 27

void shuffleTuile(int test[NBTUILES]){
    /** 
     * mise en place des variable de la fonction
     * une pour servir de tampon pour les donée
     * une de compteur
     * et deux d'indice pour les échange de place
     */
    int t;
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
        t = test[j];
        test[j] = test[k];
        test[k] = t;
        k = j;
    }
    printf("%d \n",i);
}

int main(){
    int i;
    srand(time(NULL));
    int test[NBTUILES] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27};
    for(i = 0; i < NBTUILES; i++){
        printf("%d ",test[i]);
    }
    printf("\n");
    shuffleTuile(test);
    for(i = 0; i < NBTUILES; i++){
        printf("%d ",test[i]);
    }
    printf("\n");
    return(1);
}