#include "../lib/texture.h"
/** detruit un pointeur de texture*/
void detruire_Texture(text_t *tab){
	for(int i=0; i<tab->Taille;i++){
		if(tab->Table[i] !=NULL)
			tab->quit(tab->Table[i]);
	}
	tab->Taille=0;
	//tab->quit
	free(tab);
}

/**Permet d'afficher la table de  texture*/
void aff_Texture(text_t *tab,SDL_Renderer *renderer,const SDL_Rect * srcrect,const SDL_Rect * dstrect){
	for(int i=0;i<tab->Taille;i++){
		SDL_RenderCopy(renderer,tab->Table[i],srcrect,dstrect);
	}
}

/**Creer une texture à null*/
SDL_Texture* Crea_Texture(){
	SDL_Texture* texture=NULL;
	return texture;
}

/**Creer une table de texture*/
text_t* Crea_table_Tex(int nb_text){
	text_t* tab=malloc(sizeof(text_t));
	tab->Table=(SDL_Texture**) malloc(nb_text*sizeof(SDL_Texture*));
	printf("Ok\n");
	for(int i=0;i<nb_text;i++){
		tab->Table[i]=Crea_Texture();
	}
	tab->Taille=nb_text;
	tab->quit=SDL_DestroyTexture;
	tab->det=detruire_Texture;
	tab->aff=aff_Texture;
	return tab;
}
