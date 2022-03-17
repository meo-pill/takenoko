#include "../lib/aff_table.h"
static int palt_test(){
    case_plato_t * tuile;
    retirer(&tuile);
    plateau[LACPOS+1][LACPOS+1] = tuile;
    retirer(&tuile);
    plateau[LACPOS+1][LACPOS] = tuile;
    retirer(&tuile);
    plateau[LACPOS+1][LACPOS-1] = tuile;
    retirer(&tuile);
    plateau[LACPOS][LACPOS-1] = tuile;
    retirer(&tuile);
    plateau[LACPOS][LACPOS] = tuile;
    retirer(&tuile);
    plateau[LACPOS][LACPOS+1] = tuile;
    retirer(&tuile);
    plateau[LACPOS-1][LACPOS-1] = tuile;
    retirer(&tuile);
    plateau[LACPOS-1][LACPOS] = tuile;
    retirer(&tuile);
    plateau[LACPOS-1][LACPOS+1] = tuile;
    return 9;

}

extern text_t* enregistre_table(SDL_Renderer *renderer,int W,int H){
	text_t* Tuile=NULL;
	int i=0;
	SDL_Rect * position;
	Tuile=Crea_Tex(palt_test());
	for(int x=0;x<NBTUILES && i<Tuile->Taille; x++){
		for(int y=0;y<NBTUILES && i<Tuile->Taille;y++){
			if(plateau[x][y]!=NULL ){
				(Tuile->Table[i])->t = IMG_LoadTexture(renderer, plateau[x][y]->image);
				position=lire_Rect(Tuile->Table[i],1);
				position->x=(W/2)+(W/(x+1));
				position->y=(H/2)+(y+1);
				(Tuile->Table[i])->place2=position;
				i++;
			}
		}
	}
	return Tuile;

}

