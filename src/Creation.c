#include "../lib/Creation.h"
#include "../lib/index.h"

/*int creabouton(int position_x, int position_y, int w, int h, SDL_Surface* ecran, int couleura, int couleurb, int couleurc)
{
	int i = 0, resultat = 0, j = 0, resultat2 = 0, j2 = 0;
	SDL_Event event;
	SDL_Surface *bouton = NULL, *degrader = NULL;
	SDL_Rect position, position2;
	position.x = position_x;
	position.y = position_y;
	position2.x = position_x;
	position2.y = position_y;
	
	bouton = ;
	SDL_FillRect(bouton, NULL,  SDL_MapRGB(ecran->format, couleura, couleurb, couleurc));
	SDL_BlitSurface(bouton, NULL, ecran, &position);
	resultat2 = (4*h)/100;
	resultat = (4*w)/100;
	for(i = 0; i < resultat || i < resultat2; i++){
		if(i < resultat){
			degrader = SDL_CreateRGBSurface(SDL_SWSURFACE, 1, h, 32, 0, 0, 0,0);
			SDL_FillRect(degrader, NULL, SDL_MapRGB(bouton->format, j, j, j));
			SDL_BlitSurface(degrader, NULL, ecran, &position);
			position.x++;
			j += 255/resultat;
		}
		if(i < resultat2){
			degrader = SDL_CreateRGBSurface(SDL_SWSURFACE, w, 1, 32, 0, 0, 0,0);
			SDL_FillRect(degrader, NULL, SDL_MapRGB(bouton->format, j2, j2, j2));
			SDL_BlitSurface(degrader, NULL, ecran, &position2);
			position2.y++;
			j2 += 255/resultat2;
		}
	}
	
	//SDL_Flip(ecran);
		SDL_WaitEvent(&event);
		if( event.button.x >= position_x && event.button.x <= (position_x + w) && event.button.y >= position_y && event.button.y <= (position_y + h))
			return 1;
		return 0;
}*/
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
