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
	ecrire =TTF_RenderUTF8_Blended( font ,texte ,couleur );
	texte_tex = SDL_CreateTextureFromSurface( renderer , ecrire );
	if(texte_tex==NULL){
		printf("Il y a un problème au chargement du texte %s\n",texte);
		exit(EXIT_FAILURE);
	}
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

typedef struct
{
int x;
int y;
}t_point;

extern int Select_hexa(SDL_Renderer * renderer,
		Texture_t * evaluation,
		Texture_t * source,
		int const curseur_x,
		int const curseur_y)
{

	SDL_Rect* rect=evaluation->place2;
	
	t_point Haut_G;
	Haut_G.x=rect->x;
	Haut_G.y=rect->y+rect->h*1/4;
	
	t_point Bas_D;
	Bas_D.x=rect->w+rect->x;
	Bas_D.y=rect->h+rect->y-rect->h*1/4;
	if((curseur_x>=(Haut_G.x) && curseur_x<=Bas_D.x) && (curseur_y>=Haut_G.y && curseur_y<=Bas_D.y))
	{
		SDL_RenderCopy(renderer,source->t,NULL,rect);
		return 1;
	}
	SDL_RenderCopy(renderer,evaluation->t,NULL,rect);
	return 0;
}
