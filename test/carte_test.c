#include "../lib/index.h"
void afficher_plateau(){
    int i,j;
    int balance = 0;
    for(i = 0; i<NBTUILE;i++){
        if(balance == 1){
            printf("    ");
            balance =0;
        }
        else
            balance = 1;
        for(j=0;j<NBTUILE;j++){
            if(plateau[i][j] != NULL)
                printf("  %d  ",plateau[i][j]->Coul);
            else
                printf("  -1  ");
        }
        printf("\n");
    }
}

int test_triangle(){
    return 0;
}

void remplir_plateau(){
    int i,j;
    for(i=0;i<NBTUILE;i++){
        for(j=0;j<NBTUILE;j++){
            plateau[i][j] = NULL;
        }
    }
    plateau[14][14] = malloc(sizeof(case_plato_t));
    plateau[14][14]->Coul = lac;
    plateau[15][13] = piece[0];
    plateau[15][14] = piece[1];
    plateau[16][14] = piece[2];
}


int main(){
    if (!extraction_fichier_tuile()){
        printf("ereur d'ouverture fichier tuile");
    }
    remplir_plateau();
    afficher_plateau();
    if(test_triangle() == 0){
        printf("ça marche !");
    }
    else{
        printf("il doit encore rester un problème quelque part");
    }
}