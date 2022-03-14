#include <unistd.h>
#include "../lib/Creation.h"
#include "../lib/menu.h"
#include "../lib/texture.h"
void palt_test(int *nb_tuile){
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

void aff_table(int *nb_tuile,SDL_Renderer *renderer,int W,int H){
	text_t* Tuile=NULL;
	int i=0;
	SDL_Rect position
	palt_test(nb_tuile);
	Tuile=Crea_table_tex(*nb_tuile);
	for(int x=0;x<NBTUILE && i<*nb_tuile; x++){
		for(int y=0;y<NBTUILE && i<*nb_tuile;y++){
			if(plateau[x][y]!=NULL ){
				image->Table[i] = IMG_LoadTexture(renderer, plateau[x][y]);
				i++;
			}
		}
	}

}
