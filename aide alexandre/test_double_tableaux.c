#include <stdio.h>
#include <stdlib.h>

void intialisation (int coordonee[100][100]){

    for(int i = 0; i<100; i++){
        for(int j = 0; j<100; j++){
            coordonee[i][j] = j;
        }
    }
}
int main (){
    int coordonee [100][100];
    intialisation(coordonee);
    for(int i = 0; i<100; i++){
        for(int j = 0; j<100; j++){
            printf("%d ",coordonee[i][j]);
        }
        printf("\n");
    }
}