#include "../lib/Creation.h"

SDL_Texture* Creation_Text(SDL_Renderer *renderer,SDL_Rect *tailText,const char *police,const int tailPolice,const int style,const char *texte,const SDL_Color couleur,const int position_x,const int position_y ){
	TTF_Font* font=NULL;
	SDL_Texture * texte_tex =NULL;
	SDL_Surface * ecrire=NULL;
	font=TTF_OpenFont ( police,tailPolice);
	if ( font == NULL ){
		fprintf ( stderr , " erreur chargement font: %s \n ",TTF_GetError() );
		return texte_tex;
	}
	TTF_SetFontStyle(font,style);
	ecrire =TTF_RenderUTF8_Blended( font , texte ,couleur );
	texte_tex = SDL_CreateTextureFromSurface( renderer , ecrire );
	tailText->x=position_x;
	tailText->y=position_y;
	SDL_QueryTexture( texte_tex , NULL , NULL , &tailText->w , &tailText->h);
	SDL_FreeSurface( ecrire);
	TTF_CloseFont(font);
	return texte_tex;
}


int bout(SDL_Renderer * renderer, text_t * bouton,int x,int y){
	SDL_Rect* rect=lire_Rect(bouton->Table[0],1);
	if((x>=(rect->x) && x<=((rect->w)+(rect->x))) && (y>=rect->y && y<=(rect->h+rect->y))){
		SDL_RenderCopy(renderer, (bouton->Table[1])->t,NULL,(bouton->Table[1])->place2);
		return 1;
	}
	SDL_RenderCopy( renderer, (bouton->Table[0])->t,NULL,(bouton->Table[0])->place2);
	return 0;
}

