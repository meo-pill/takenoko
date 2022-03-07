#include <unistd.h>
#include "../lib/Creation.h"
#include "../lib/menu.h"
#include "../lib/texture.h"

void affiche_option(char *fond,int W,int H){
	if (SDL_Init(SDL_INIT_TIMER |SDL_INIT_VIDEO)== -1 ){
		fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
		exit(EXIT_FAILURE );
	}

	if ( TTF_Init () == -1) {
		fprintf ( stderr , " Erreur d ’ i nitialis ation de TTF_Init : %s \n " , TTF_GetError ());
		exit ( EXIT_FAILURE );
	}
	SDL_Event event;//permet de voir les evenement sur la fenêtre
	SDL_Window* pWindowInv = NULL; //pointeur sur la fenêtre invisible

	SDL_Renderer *rendererInv=NULL;
	char fond_option[]="image/en_plus/Fond_option.png";

	text_t* image;
	text_t* bouton;
//	SDL_Texture* Texture=NULL;//pour avoir un fond
//	SDL_Texture* pTexture =NULL;//pour ajouter une animation
//	SDL_Texture *  bouton =NULL;
//	SDL_Texture *  bouton2 =NULL;

	SDL_Color Noir = {0 , 0 , 0};

	SDL_Rect tailBouton;
	SDL_Rect tailBouton2;

	int h=0,x=0,y=0;

	pWindowInv = SDL_CreateWindow("Option",SDL_WINDOWPOS_UNDEFINED,
											SDL_WINDOWPOS_UNDEFINED,
											W,
											H,
											SDL_WINDOW_SHOWN |SDL_WINDOW_RESIZABLE);
	rendererInv = SDL_CreateRenderer(pWindowInv,-1,SDL_RENDERER_ACCELERATED); // Création d'un SDL_Renderer utilisant l'accélération matérielle

	Crea_table_Tex(image,2);
	Crea_table_Tex(bouton,2);
	(1+bouton->Table) =CreationText(rendererInv,&tailBouton,"image/police/Takenoko.TTF",30,TTF_STYLE_BOLD,"<-Retour",Noir,580,750);
	if ((1+bouton->Table) == NULL ){
		exit ( EXIT_FAILURE );
	}

	(2+bouton->Table) =CreationText(rendererInv,&tailBouton2,"image/police/Takenoko.TTF",30,TTF_STYLE_BOLD|TTF_STYLE_UNDERLINE,"<-Retour",Noir,580,750);
	if ((2+ bouton->Table) == NULL ){
		exit ( EXIT_FAILURE );
	}

	(2+(image->Table)) = IMG_LoadTexture(rendererInv, fond_option);
	(1+image->Table) = IMG_LoadTexture(rendererInv, fond);
	if((1+image->Table)==NULL||(2+image.Table)==NULL){
		fprintf ( stderr , " Erreur au niveau de l'image: %s \n " , TTF_GetError ());
		exit ( EXIT_FAILURE );
	}

	int fullscreen=0;
	while(1){
	if(h!=H){
		//permet de faire bouger l'animation
		h+=10;
		SDL_Rect annimation = { 0,0,W,h};
		SDL_Rect crop={0, H, W, H };
		//on pose l'animation sur la fenêtre
		SDL_RenderCopy(rendererInv,(1+image->Table),NULL,NULL);
		SDL_RenderCopy(rendererInv,(2+image->Table),&crop,&annimation);// Copie du sprite grâce au SDL_Renderer
		//sleep(1);
	}
	else{
		Uint32 Clic = SDL_GetMouseState(&x,&y);
		//création de la "fenêtre ou nous verons une partie de l'image
		//SDL_RenderCopy(rendererInv,Texture,NULL,NULL);
		//SDL_RenderCopy(rendererInv, pTexture, NULL, NULL);
		image->aff(image,rendererInv,NULL,NULL);
		if((x>=tailBouton.x && x<=(tailBouton.w+tailBouton.x)) && (y>=tailBouton.y && y<=(tailBouton.h+tailBouton.y))){
			if(Clic==1){
				/*while(h>=0){
					h=10;
					SDL_Rect annimation = { 0,0,W,h};
					SDL_Rect crop={0, H, W, H };
					SDL_RenderCopy(rendererInv,Texture,NULL,NULL);
					SDL_RenderCopy(rendererInv,pTexture,&crop,&annimation);
				}*/
				bouton->det(bouton);
				image->det(image);
				/*if(NULL!=bouton) 
					SDL_DestroyTexture(bouton);
				if(NULL!=bouton2) 
					SDL_DestroyTexture(bouton2);
				if(NULL!=pTexture)
					SDL_DestroyTexture(pTexture);
				if(NULL!=Texture) 
					SDL_DestroyTexture(Texture);
					*/
				if(NULL!=rendererInv)
					SDL_DestroyRenderer(rendererInv);
				if(NULL!=pWindowInv)
					SDL_DestroyWindow(pWindowInv);
				IMG_Quit();
				TTF_Quit();
				SDL_Quit();
				menu();
			}
			else
				SDL_RenderCopy(rendererInv, bouton->Table[2],NULL,&tailBouton2);
		}
		else
			SDL_RenderCopy(rendererInv, bouton->Table[1],NULL,&tailBouton);
	
	}
		//présentation final
		SDL_RenderPresent(rendererInv);
		if (SDL_PollEvent(&event)){
			 switch(event.type){
				case SDL_QUIT:
					bouton->det(bouton);
					image->det(image);
					/*if(NULL!=bouton) 
						SDL_DestroyTexture(bouton);
					if(NULL!=bouton2) 
						SDL_DestroyTexture(bouton2);
					if(NULL!=pTexture)
						SDL_DestroyTexture(pTexture);
					if(NULL!=Texture) 
						SDL_DestroyTexture(Texture);
						*/
					if(NULL!=rendererInv)
						SDL_DestroyRenderer(rendererInv);
					if(NULL!=pWindowInv)
						SDL_DestroyWindow(pWindowInv);
					IMG_Quit();
					TTF_Quit();
					SDL_Quit();
					exit(EXIT_SUCCESS);
					break;
				case SDL_KEYUP:
					switch(event.key.keysym.sym){
						case SDLK_q:
							if(fullscreen==1)
								SDL_SetWindowFullscreen(pWindowInv,0);
							bouton->det(bouton);
							image->det(image);
							/*if(NULL!=bouton) 
								SDL_DestroyTexture(bouton);
							if(NULL!=bouton2) 
								SDL_DestroyTexture(bouton2);
							if(NULL!=pTexture)
								SDL_DestroyTexture(pTexture);
							if(NULL!=Texture) 
								SDL_DestroyTexture(Texture);
								*/
							if(NULL!=rendererInv)
								SDL_DestroyRenderer(rendererInv);
							if(NULL!=pWindowInv)
								SDL_DestroyWindow(pWindowInv);
							IMG_Quit();
							TTF_Quit();
							SDL_Quit();
							menu();
						case SDLK_F11:
						 	if(fullscreen==0){
								SDL_SetWindowFullscreen(pWindowInv,SDL_WINDOW_FULLSCREEN);
								fullscreen++;
							 }
							else{
								SDL_SetWindowFullscreen(pWindowInv,0);
								fullscreen--;
							}
						     	break;
					}
					break;
			 }
		}
	}
}
