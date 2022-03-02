#include "index.h"

err_t detruire_texture(text_t *tab){
	for(int i, i<tab->Taille;i+){
		if(tab->Table[i] !=NULL)
			(tab->Table[i])->quite(tab->Table[i]);
	}
}

void aff(text_t *tab){
