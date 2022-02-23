#include <unistd.h>
#include "../lib/Creation.h"
#include "../lib/menu.h"

void affiche_option(SDL_Window* pWindow,SDL_Renderer *renderer,int W,int H){
	char fond_option[]="image/en_plus/Fond_option.png";

	SDL_Texture* pTexture =NULL;//pour ajouter une animation
	SDL_Texture *  bouton =NULL;
	SDL_Texture *  bouton2 =NULL;

	SDL_Color Noir = {0 , 0 , 0};

	SDL_Rect tailBouton;
	SDL_Rect tailBouton2;

	int h=1,x=0,y=0;

	printf("Ok1\n");

	bouton =CreationText(renderer,&tailBouton,"image/police/Takenoko.TTF",30,TTF_STYLE_BOLD,"Quiter",Noir,580,750);
	if ( bouton == NULL ){
		exit ( EXIT_FAILURE );
	}

	bouton2 =CreationText(renderer,&tailBouton2,"image/police/Takenoko.TTF",30,TTF_STYLE_BOLD|TTF_STYLE_UNDERLINE,"Quiter",Noir,580,750);
	if ( bouton == NULL ){
		exit ( EXIT_FAILURE );
	}

	printf("Ok2\n");
	pTexture = IMG_LoadTexture(renderer, fond_option);
	if(pTexture==NULL){
		fprintf ( stderr , " Erreur au niveau de l'image: %s \n " , TTF_GetError ());
		exit ( EXIT_FAILURE );
	}

	printf("Ok3\n");
	while(h<H){
		//permet de faire bouger l'animation
		h+=100;
		printf("ok4 h=%d\n",h);
		SDL_Rect annimation = { 1,h,W-138,H};
		SDL_Rect crop={138,H,W-138, H };
		//on pose l'animation sur la fenêtre
		SDL_RenderCopy(renderer,pTexture,&annimation,&crop);// Copie du sprite grâce au SDL_Renderer
		SDL_RenderPresent(renderer);
		sleep(5);
	}
	
	while(1){
		Uint32 Clic = SDL_GetMouseState(&x,&y);
		//création de la "fenêtre ou nous verons une partie de l'image
	
		SDL_RenderCopy(renderer, pTexture, NULL, NULL);
		if((x>=tailBouton.x && x<=(tailBouton.w+tailBouton.x)) && (y>=tailBouton.y && y<=(tailBouton.h+tailBouton.y))){
			if(Clic==1){
				if(NULL!=bouton) 
					SDL_DestroyTexture(bouton);
				if(NULL!=bouton2) 
					SDL_DestroyTexture(bouton2);
				if(NULL!=pTexture)
					SDL_DestroyTexture(pTexture);
				menu();

			}
			else
				SDL_RenderCopy(renderer, bouton2,NULL,&tailBouton2);
		}
		else
			SDL_RenderCopy(renderer, bouton,NULL,&tailBouton);
	
		//présentation final
		SDL_RenderPresent(renderer);
		printf("option: %d %d\n",x,y);
	}
}
