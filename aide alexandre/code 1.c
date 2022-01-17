#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED
#endif // BOARD_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct terrain{
    int latitude;
    int longitude;
    int irriguee;
    int bambou;
}terrain;

terrain rentree(terrain a){
    printf("entrée latitude");
    scanf("%d",a.latitude);
    printf("entrée longitude");
    scanf("%d",a.longitude);
    return a ;
}

terrain panda(terrain a){
    if (a.irriguee==1){
        a.bambou -= 1;
        printf("Le panda est arrivé, il mange un bambou.");
    }
    return(a);
}

terrain jardinier(terrain a){
    if (a.irriguee==1){
        a.bambou += 1;
        printf("Le jardinier fait pousser un bambou");
    }
    return(a);
}

terrain irriguer(terrain a){
    a.irriguee = 1;
    printf("Le terrain est maintenant irrigué");
    return(a);
}

void main(){
    int mem = 1;
    int irrigation;
    int posjardinier;
    int pospanda;
    int action;
    terrain takenoko[100];
    do {
        printf("Vous mettez un terrain(1) ou déplacer le panda(2) / jardinier(3) / irriguer(4) / arréter(0) ?");
        scanf("%d",action);
        if (action==1){
            takenoko[mem] = rentree(takenoko[mem]);
            mem = mem+1;
        }
        if (action==2){
            printf("Sur quel terrain va le panda ?");
            scanf("%d",pospanda);
            takenoko[pospanda] = panda(takenoko[pospanda]);
        }
        if (action==3){
            printf("Sur quel terrain va le jardinier ?");
            scanf("%d",posjardinier);
            takenoko[posjardinier] = jardinier(takenoko[posjardinier]);
        }
        if (action==4){
            printf("Sur quel terrain creusez-vous ?");
            scanf("%d",irrigation);
            takenoko[irrigation] = irriguer(takenoko[irrigation]);
        }
    }while (action != 0);
}