#include <unistd.h>
static void palt_test(int *nb_tuile){
	initialiser(1);
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
    *nb_tuile=9;
}

static text_t* enregistre_table(int *nb_tuile,SDL_Renderer *renderer,int W,int H){
	text_t* Tuile=NULL;
	int i=0;
	SDL_Rect * position
	palt_test(nb_tuile);
	Tuile=Crea_Tex(*nb_tuile);
	for(int x=0;x<NBTUILE && i<*nb_tuile; x++){
		for(int y=0;y<NBTUILES && i<*nb_tuile;y++){
			if(plateau[x][y]!=NULL ){
				(image->Table[i])->t = IMG_LoadTexture(renderer, plateau[x][y]->image);
				position=lire_Rect(image->Table[i],1);
				position->x=(W/2)+(W/(x+1));
				position->y=(H/2)+(y+1);
				i++;
			}
		}
	}
	return Tuile;

}

extern void aff_table(int *nb_tuile,SDL_Renderer *renderer,int W,int H){
	text_t* Tuile=enregistre_table(nb_tuile,renderer, W,H);
	for(int i=0;i<Tuile->Taille;i++){
		SDL_Rect * rect=lire_Rect((image->Table[i]),1);
		SDL_RenderCopy(renderer,(Tuile->Table[i])->t,NULL,rect);
	}
}
