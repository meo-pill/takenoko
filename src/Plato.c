#include <unistd.h>
#include "../lib/Creation.h"
#include "../lib/menu.h"
#include "../lib/texture.h"


void affiche_Plato(int W,int H){
	if (SDL_Init(SDL_INIT_TIMER |SDL_INIT_VIDEO)== -1 ){
		fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
		exit(EXIT_FAILURE );
	}
	if ( TTF_Init () == -1) {
		fprintf ( stderr , " Erreur d ’ i nitialis ation de TTF_Init : %s \n " , TTF_GetError ());
		exit ( EXIT_FAILURE );
	}
	SDL_Event event;//permet de voir les evenement sur la fenêtre
	SDL_Window* pWindow = NULL; //pointeur sur la fenêtre invisible

	SDL_Renderer *renderer=NULL;
	char fond_Plato[]="image/en_plus/Fond_Plato.png";

	text_t* image=NULL;
	text_t* bouton=NULL;

	SDL_Color Noir = {0 , 0 , 0};

	SDL_Rect tailBouton;
	SDL_Rect tailBouton2;

	int x=0,y=0;

	pWindow = SDL_CreateWindow("Takenoko",SDL_WINDOWPOS_UNDEFINED,
											SDL_WINDOWPOS_UNDEFINED,
											W,
											H,
											SDL_WINDOW_SHOWN |SDL_WINDOW_RESIZABLE);
	renderer = SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_ACCELERATED); // Création d'un SDL_Renderer utilisant l'accélération matérielle

	image=Crea_table_Tex(1);
	//Tuile=Crea_table_tex(13);il 13 image de tuille
	bouton=Crea_table_Tex(2);
	bouton->Table[0]=CreationText(renderer,&tailBouton2,"image/police/Takenoko.TTF",30,TTF_STYLE_BOLD,"<-Retour",Noir,109,71);
	bouton->Table[1]=CreationText(renderer,&tailBouton2,"image/police/Takenoko.TTF",30,TTF_STYLE_BOLD|TTF_STYLE_UNDERLINE,"<-Retour",Noir,109,71);

	if ((bouton->Table[0]) == NULL || bouton->Table[1]==NULL){
		exit ( EXIT_FAILURE );
	}

	(image->Table[0]) = IMG_LoadTexture(renderer, fond_Plato);
	if((image->Table[0])==NULL){
		fprintf ( stderr , " Erreur au niveau de l'image: %s \n " , TTF_GetError ());
		exit ( EXIT_FAILURE );
	}
	int fullscreen=0;
	while(1){
		Uint32 Clic = SDL_GetMouseState(&x,&y);
		//création de la "fenêtre ou nous verons une partie de l'image
		image->aff(image,renderer,NULL,NULL);
		if((x>=tailBouton.x && x<=(tailBouton.w+tailBouton.x)) && (y>=tailBouton.y && y<=(tailBouton.h+tailBouton.y))){
			if(Clic==1){
				bouton->det(bouton);
				image->det(image);
				if(NULL!=renderer)
					SDL_DestroyRenderer(renderer);
				if(NULL!=pWindow)
					SDL_DestroyWindow(pWindow);
				IMG_Quit();
				TTF_Quit();
				SDL_Quit();
				menu();
			}
			else
				SDL_RenderCopy(renderer, bouton->Table[1],NULL,&tailBouton2);
		}
		else
			SDL_RenderCopy(renderer, bouton->Table[0],NULL,&tailBouton);
	
		//présentation final
		SDL_RenderPresent(renderer);
		if (SDL_PollEvent(&event)){
			 switch(event.type){
				case SDL_QUIT:
					bouton->det(bouton);
					image->det(image);
					if(NULL!=renderer)
						SDL_DestroyRenderer(renderer);
					if(NULL!=pWindow)
						SDL_DestroyWindow(pWindow);
					IMG_Quit();
					TTF_Quit();
					SDL_Quit();
					exit(EXIT_SUCCESS);
					break;
				case SDL_KEYUP:
					switch(event.key.keysym.sym){
						case SDLK_q:
							if(fullscreen==1)
								SDL_SetWindowFullscreen(pWindow,0);
							bouton->det(bouton);
							image->det(image);
							if(NULL!=renderer)
								SDL_DestroyRenderer(renderer);
							if(NULL!=pWindow)
								SDL_DestroyWindow(pWindow);
							IMG_Quit();
							TTF_Quit();
							SDL_Quit();
							menu();
						case SDLK_F11:
						 	if(fullscreen==0){
								SDL_SetWindowFullscreen(pWindow,SDL_WINDOW_FULLSCREEN);
								fullscreen++;
							 }
							else{
								SDL_SetWindowFullscreen(pWindow,0);
								fullscreen--;
							}
						     	break;
					}
					break;
			 }
		}
	}

}
