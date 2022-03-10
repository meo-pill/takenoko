#include "../lib/texture.h"
/** detruit un pointeur de texture*/
void detruire_Texture(text_t *tab){
	for(int i=0; i<tab->Taille;i++){
		if(tab->Table[i] !=NULL)
			tab->quit(tab->Table[i]->t);
		free(tab->Table[i]->place);
		free(tab->Table[i]->place2);
		tab->Table[i]->place=NULL;
		tab->Table[i]->place2=NULL;
	}
	tab->Taille=0;
	//tab->quit
	free(tab);
}

/**Permet d'afficher la table de  texture*/
void aff_Texture(text_t *tab,SDL_Renderer *renderer){
	for(int i=0;i<tab->Taille;i++){
		SDL_RenderCopy(renderer,(tab->Table[i])->t,(tab->Table[i])->place,(tab->Table[i])->place2);
	}
}


/**Creer une table de texture*/
text_t* Crea_table_Tex(int nb_text){
	text_t* tab=malloc(sizeof(text_t));
	tab->Table=(SDL_Texture**) malloc(nb_text*sizeof(SDL_Texture*));
	printf("Ok\n");
	for(int i=0;i<nb_text;i++){
		(tab->Table[i])->t=NULL;
		(tab->Table[i])->Place=NULL;
		(tab->Table[i])->Place2=NULL;
	}
	tab->Taille=nb_text;
	tab->quit=SDL_DestroyTexture;
	tab->det=detruire_Texture;
	tab->aff=aff_Texture;
	return tab;
}
