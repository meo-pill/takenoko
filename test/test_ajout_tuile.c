#include "../lib/index.h"


void test_affichage(void){
    printf("\n affichage du plateau \n");
    for(int x = 0; x < NBTUILES; x++){
        if(x%2){
            printf("  ");
        }
        for(int y = 0; y <NBTUILES; y++){
            if(plateau[x][y]!=NULL){
                printf(" 11 ");
            }
            else{
                if(!pose_tuile_impossible(x,y)){
                    printf(" 22 ");
                }
                else{
                    if(plateau[x][y]==NULL){
                        printf(" 00 ");
                    }
                }
            }
        }
        printf("\n");
    }
}


void main(){
    int maxpoint,x,y;
    debut_partie(2,&maxpoint);
    while (1){
        test_affichage();
        printf("donner coordoner ajout");
        scanf("%d",&x);
        scanf("%d",&y);
        plateau[x][y]= retirer();
    }
}