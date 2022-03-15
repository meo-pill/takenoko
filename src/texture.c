#include "../lib/texture2.h"
/*! detruit un pointeur de texture*/
static void detruire_Texture(text_t *tab){
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

/*!Permet d'afficher la table de  texture*/

extern SDL_Rect* lire_Rect(Texture_t* texture,int type_rect){
	if(type_rect)
		return  texture->place2;
	else if(!type_rect)
		return texture->place;
	return NULL;
}

/*! defini à null la structure Texture*/
static Texture_t* Crea_Texture(){
	Texture_t* Texture=malloc(sizeof(Texture_t));
	Texture->t=malloc(sizeof(SDL_Texture*));
	Texture->place=malloc(sizeof(SDL_Rect));
	Texture->place2=malloc(sizeof(SDL_Rect));
	return Texture;
}

/*!Creer une table de texture*/
text_t* Crea_Tex(int nb_text){
	text_t* tab=malloc(sizeof(text_t));
	tab->Table=(Texture_t **) malloc(nb_text*sizeof(Texture_t*));
	for(int i=0;i<nb_text;i++){
		(tab->Table[i])=Crea_Texture();
	}
	tab->Taille=nb_text;
	tab->quit=SDL_DestroyTexture;
	tab->det=detruire_Texture;
	return tab;
}
