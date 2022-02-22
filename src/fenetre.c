#include "../lib/Creation.h"

void affiche_option(SDL_Window* pWindow,SDL_Renderer *renderer,int W,int H){
	char fond_option[]="image/en_plus/Fond_option.png";

	SDL_RWops *rwop=NULL;//permet d'incruster l'image sur la fenètre

	SDL_Surface* pSprite =NULL;//ajout d'une image par dessus le fond

	SDL_Texture* pTexture =NULL;//pour ajouter une animation
	SDL_Texture *  bouton =NULL;
	SDL_Texture *  bouton2 =NULL;

	//SDL_Rect fix={138,0,W-138,H};

	SDL_Color Noir = {0 , 0 , 0};

	SDL_Rect tailBouton;
	SDL_Rect tailBouton2;

	int h=1,x=0,y=0;

	bouton =CreationText(renderer,&tailBouton,"image/police/Takenoko.TTF",30,TTF_STYLE_BOLD,"Quiter",Noir,580,750);
	if ( bouton == NULL ){
		exit ( EXIT_FAILURE );
	}

	bouton2 =CreationText(renderer,&tailBouton2,"image/police/Takenoko.TTF",30,TTF_STYLE_BOLD|TTF_STYLE_UNDERLINE,"Quiter",Noir,580,750);
	if ( bouton == NULL ){
		exit ( EXIT_FAILURE );
	}

	rwop=SDL_RWFromFile(fond_option,"rb");
	pSprite = IMG_LoadBMP_RW(rwop);
	if(pSprite==NULL)
		exit ( EXIT_FAILURE );
	rwop->close(rwop);
	rwop=NULL;
	pTexture = SDL_CreateTextureFromSurface(renderer,pSprite);//X=138;Y=4
	if(pTexture==NULL)
		exit ( EXIT_FAILURE );
	while(1){
		Uint32 Clic = SDL_GetMouseState(&x,&y);
		//création de la "fenêtre ou nous verons une partie de l'image
		if(h<H){
			//permet de faire bouger l'animation
			Uint32 ticks = SDL_GetTicks();
			Uint32 seconds = ticks / 230;
			Uint32 sprite = seconds % 4;
			x=sprite*120;
			SDL_Rect annimation = { 138,h,W-138,h};
			SDL_Rect crop={138,0, 120, h };
			//on pose l'animation sur la fenêtre
			SDL_RenderCopy(renderer,pTexture,&annimation,&crop);// Copie du sprite grâce au SDL_Renderer
		}
		else{
			SDL_RenderCopy(renderer, pTexture, NULL, NULL);
			if((x>=tailBouton.x && x<=(tailBouton.w+tailBouton.x)) && (y>=tailBouton.y && y<=(tailBouton.h+tailBouton.y))){
				if(Clic==1)
					return;
				else
					SDL_RenderCopy(renderer, bouton2,NULL,&tailBouton2);
			}
			else
				SDL_RenderCopy(renderer, bouton,NULL,&tailBouton);
		}
		//présentation final
		SDL_RenderPresent(renderer);
	}
}
