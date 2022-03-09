#include <stdlib.h>
#include <stdio.h>

int main(){
    char tab[10000];
    int i = 0;

    FILE * fich;
    fich = fopen("asset/carte_objectif.txt","r");

    if(fich == NULL)
        printf("\n --------------------- \n erreur lors de l'ouverture du fichier \"carte_objectif.txt \" \n ---------------------\n");
    while(!feof(fich)){
        fscanf(fich,"%c",&tab[i]);
        i++;
    }
    fclose(fich);
    tab[i] = '\0';
    printf("valeur final : %s",tab);
}