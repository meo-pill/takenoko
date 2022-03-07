#include "../lib/texture.h"

void detruire_Texture(text_t *tab){
	for(int i=0; i<tab->Taille;i++){
		if(tab->Table[i] !=NULL)
			tab->quit(tab->Table[i]);
	}
}

void aff_Texture(text_t *tab,SDL_Renderer *renderer,const SDL_Rect * srcrect,const SDL_Rect * dstrect){
	for(int i=0;i<tab->Taille;i++){
		SDL_RenderCopy(renderer,tab->Table[i],srcrect,dstrect);
	}
}
SDL_Texture* Crea_Texture(){
	SDL_Texture* texture=NULL;
	return texture;
}

void Crea_table_Tex(text_t* tab,int nb_text){
	tab->Table= malloc(nb_text*sizeof(SDL_Texture*));
	for(int i=0;i<nb_text;i++){
		tab->Table[i]=Crea_Texture();
	}
	tab->Taille=nb_text;
	tab->quit=SDL_DestroyTexture;
	tab->det=detruire_Texture;
	tab->aff=aff_Texture;
}
