//#include "../lib/index.h"

typedef struct case_plato_s case_plato_t;
extern void retirer(case_plato_t ** tuile);
extern void ajouter(case_plato_t * tuile);

int pioche_une_case(void){
    int choix = -1, nb_choix =2;
    case_plato_t * choix_de_trois[3];
    case_plato_t * case_ajout;
    int x,y;
    if(filevide()){
        printf ("plus de case en file");
        return 0;
    }
    retirer(&choix_de_trois[0]);
    if(!filevide()){
        retirer(&choix_de_trois[1]);
        if(!filevide()){
            retirer(&choix_de_trois[2]);
        }
        
        printf("le joueur pioche une case");
        // a faire sdl
        while (choix < 0 && choix > nb_choix){
            scanf("%d",&choix);
        }
        for(int i = 0; i<nb_choix+1; i++){
            if(i!= choix+1){
                ajouter(choix_de_trois[i]);
            }
        }
    }
    else{
        case_ajout = choix_de_trois[0];
    }
    printf("donner position de case a ajouter");
    scanf("%d", &x);
    scanf("%d", &y);   
    ajout_tuile(case_ajout,x,y);
    return 1;
}