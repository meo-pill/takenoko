#include "../lib/Creation.h"
#include "../lib/index.h"

extern SDL_Texture* CreationText(SDL_Renderer *renderer,SDL_Rect *tailText,const char *police,const int tailPolice,const int style,const char *texte,const SDL_Color couleur,const int position_x,const int position_y ){
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

extern int Push(SDL_Renderer *renderer,int x,int y,text_t* bouton){
				if((x>=((bouton->Table->)place2)->x && x<=(((bouton->Table->)place2)->w+((bouton->Table->)place2)->x)) && (y>=((bouton->Table->)place2)->y && y<=(((bouton->Table->)place2)->h+((bouton->Table->)place2)->.y))){
					SDL_RenderCopy(renderer, bouton->Table[1],NULL,&tailBouton1);
					return 1;
				}
				SDL_RenderCopy(renderer, bouton->Table[0],NULL,&tailBouton1);
				return 0;
}
