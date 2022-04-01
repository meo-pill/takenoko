#include "../lib/Creation.h"
#include "../lib/index.h"

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

extern text_t* Creation_Joueur(SDL_Renderer * renderer,int x,int y,int i){
	/*! \brief couleur du texte*/
	SDL_Color Blanc = {255,255,255};
	text_t* Joueur;
	Joueur=Crea_Tex(13);
	(Joueur->Table[0])->t=Creation_Text(renderer,lire_Rect(Joueur->Table[0],1),"image/police/Takenoko.TTF",30,TTF_STYLE_BOLD,J[i]->nom_joueur,Blanc,x,y);
	//affichage du  nombre de bambou pour le joueur
	//Nb de bambou Jaune
	(Joueur->Table[1])->t=Creation_image(renderer,lire_Rect(Joueur->Table[1],1),"image/en_plus/pionJaune.png",x,y+40,50,30);
	(Joueur->Table[2])->t=Creation_Text(renderer,lire_Rect(Joueur->Table[2],1),"image/police/Takenoko.TTF",30,TTF_STYLE_BOLD,retourne_itoa(J[i]->bambou[0]),Blanc,x,y+90);

	//nb de bambou rose
	(Joueur->Table[3])->t=Creation_image(renderer,lire_Rect(Joueur->Table[3],1),"image/en_plus/pionRose.png",x+40,y+40,50,30);
	(Joueur->Table[4])->t=Creation_Text(renderer,lire_Rect(Joueur->Table[4],1),"image/police/Takenoko.TTF",30,TTF_STYLE_BOLD,retourne_itoa(J[i]->bambou[1]),Blanc,x+40,y+90);

	//Nb de bambou Vert
	(Joueur->Table[5])->t=Creation_image(renderer,lire_Rect(Joueur->Table[5],1),"image/en_plus/pionVert.png",x+80,y+40,50,30);
	(Joueur->Table[6])->t=Creation_Text(renderer,lire_Rect(Joueur->Table[6],1),"image/police/Takenoko.TTF",30,TTF_STYLE_BOLD,retourne_itoa(J[i]->bambou[2]),Blanc,x+80,y+90);

	//affichage du nombre d'effet en la posertion d'un joueur
	//Nb d'effet non au panda
	(Joueur->Table[7])->t=Creation_image(renderer,lire_Rect(Joueur->Table[7],1),"image/en_plus/nonPanda.png",x,y+130,30,30);
	(Joueur->Table[8])->t=Creation_Text(renderer,lire_Rect(Joueur->Table[8],1),"image/police/Takenoko.TTF",30,TTF_STYLE_BOLD,retourne_itoa(J[i]-> effSpe[2]),Blanc,x,y+160);

	//Nb d'effet tuile iriger
	(Joueur->Table[9])->t=Creation_image(renderer,lire_Rect(Joueur->Table[9],1),"image/en_plus/irige.png",x+40,y+130,30,30);
	(Joueur->Table[10])->t=Creation_Text(renderer,lire_Rect(Joueur->Table[10],1),"image/police/Takenoko.TTF",30,TTF_STYLE_BOLD,retourne_itoa(J[i]-> effSpe[2]),Blanc,x+40,y+160);

	//Nb d'effet tuile avec engret
	(Joueur->Table[11])->t=Creation_image(renderer,lire_Rect(Joueur->Table[11],1),"image/en_plus/engret.png",x+80,y+130,30,30);
	(Joueur->Table[12])->t=Creation_Text(renderer,lire_Rect(Joueur->Table[12],1),"image/police/Takenoko.TTF",30,TTF_STYLE_BOLD,retourne_itoa(J[i]-> effSpe[2]),Blanc,x+80,y+160);

	return Joueur;

}
