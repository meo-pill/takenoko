#include "../lib/Creation.h"

extern SDL_Texture* Creation_Text(SDL_Renderer *renderer,
		SDL_Rect *tailText,
		const char *police,
		const int tailPolice,
		const int style,
		const char *texte,
		const SDL_Color couleur,
		const int position_x,
		const int position_y ){
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

extern SDL_Texture* Creation_image(SDL_Renderer *renderer,
		SDL_Rect *tailImage,
		const char *nom_image,
		const int position_x,
		const int position_y,
		const int Hauteur,
		const int largeur){
	SDL_Texture* image;
	image = IMG_LoadTexture(renderer,nom_image);
	if(image==NULL){
		fprintf ( stderr , " Erreur au niveau de l'image: %s \n " , TTF_GetError ());
		exit ( EXIT_FAILURE );
	}
	positionne_rect(tailImage,position_x,position_y,Hauteur,largeur);
	return image;
}

extern int bout(SDL_Renderer * renderer, 
		text_t * bouton,
		int x,int y){
	SDL_Rect* rect=lire_Rect(bouton->Table[0],1);
	if((x>=(rect->x) && x<=((rect->w)+(rect->x))) && (y>=rect->y && y<=(rect->h+rect->y))){
		SDL_RenderCopy(renderer, (bouton->Table[1])->t,NULL,(bouton->Table[1])->place2);
		return 1;
	}
	SDL_RenderCopy( renderer, (bouton->Table[0])->t,NULL,(bouton->Table[0])->place2);
	return 0;
}
extern int inv_bout(SDL_Renderer * renderer, 
		text_t * bouton,
		int x,int y){
	SDL_Rect* rect=lire_Rect(bouton->Table[1],1);
	if((x>=(rect->x) && x<=((rect->w)+(rect->x))) && (y>=rect->y && y<=(rect->h+rect->y))){
		SDL_RenderCopy(renderer, (bouton->Table[0])->t,NULL,(bouton->Table[0])->place2);
		return 1;
	}
	SDL_RenderCopy( renderer, (bouton->Table[1])->t,NULL,(bouton->Table[1])->place2);
	return 0;
}

extern int Select_hexa(SDL_Renderer * renderer,Texture_t * evaluation, Texture_t * source, int const x, int const y){
	SDL_Rect * rectangle =  evaluation->place2;
	if (y < (rectangle->y +(rectangle->h/4) ) ){
		if ( x <= (rectangle->x + (rectangle->w /2) ) ){
			if ( (y - rectangle->y) <= ( ( (rectangle->w/2) - (x - rectangle->x) )/2) ){
				SDL_RenderCopy(renderer, evaluation->t,NULL,rectangle);
				return 0;
			}
		}
		else if ( x<= (rectangle->x + (rectangle->w /2) ) ){
			if( (y - rectangle->y) <= ( ( (x - rectangle->x) + (rectangle->w /2) ) /2 ) ){
				SDL_RenderCopy(renderer, evaluation->t,NULL,rectangle);
				return 0;
			}
		}
	}
	else if ( y > (rectangle->y + (rectangle->h - (rectangle->h/4) ) ) ){
		if (  x <= (rectangle->x + (rectangle->w /2) ) ){
			if ( (y - rectangle->y) >= ( ( (x - rectangle->x) + (rectangle->w /2) ) /2 ) ){
				SDL_RenderCopy(renderer, evaluation->t,NULL,rectangle);
				return 0;
			}
		}
		else if ( x<= (rectangle->x + (rectangle->w /2) ) ){
			if( (y - rectangle->y) >= ( ( (x - rectangle->x) + (rectangle->w /2) ) /2 ) ){
				SDL_RenderCopy(renderer, evaluation->t,NULL,rectangle);
				return 0;
			}
		}
	}
	else{
		SDL_RenderCopy(renderer, source->t,NULL,rectangle);
		return 1;
	}
}
