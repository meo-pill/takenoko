#include "lib/Creation.h"
int main(){
	if (SDL_Init(SDL_INIT_TIMER |SDL_INIT_VIDEO)== -1 ){
		fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
		exit(EXIT_FAILURE );
	}

	if ( TTF_Init () == -1) {
		fprintf ( stderr , " Erreur d ’ i nitialis ation de TTF_Init : %s \n " , TTF_GetError ());
		exit ( EXIT_FAILURE );
	}
	SDL_Event event;//permet de voir les evenement sur la fenêtre

	SDL_Window* pWindow = NULL; //pointeur sur la fenêtre

	SDL_Renderer *renderer=NULL;//pour créer une fennêtre 

	SDL_Surface* pSprite =NULL;//ajout d'une image par dessus le fond

	text_t* image=NULL;

	char fond[]="image/en_plus/Fond_menu.png";//chemin vers l'image de fond
	int fullscreen=0;

	//permet de prendre la taille de l'écran
	SDL_DisplayMode DM;
	SDL_GetCurrentDisplayMode(0, &DM);
	auto int Width = DM.w;
	auto int Height = DM.h;

	image=Crea_Tex(1);

	pWindow = SDL_CreateWindow("takenoko",SDL_WINDOWPOS_UNDEFINED,
											SDL_WINDOWPOS_UNDEFINED,
											Width,
											Height,
											SDL_WINDOW_SHOWN |SDL_WINDOW_RESIZABLE);
	renderer = SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_ACCELERATED); // Création d'un SDL_Renderer utilisant l'accélération matérielle

	(*image->Table)->t = IMG_LoadTexture(renderer, fond);
	if((*image->Table)->t==NULL){
		printf("ERR chargement image\n");
		if(renderer==NULL)
			printf("ERR au nv du renderer\n");
		exit ( EXIT_FAILURE );
	}
	int x=0,y=0;
	while (1) {
		//permet de savoir où et si on clique avec la souri
		Uint32 Clic = SDL_GetMouseState(&x,&y);
//		if(bout(renderer,bouton3,x,y) && Clic){
//			//affiche_option(Width,Height);
//		}

		SDL_RenderCopy(renderer,(image->Table[0])->t,NULL,NULL);
		//présentation final
		SDL_RenderPresent(renderer);
		//affiche la position de l'endroit ou la sourie à cliquer
		if(Clic ==1){
			fprintf(stdout, "Position de la souris : %d;%d\n",x,y);
		}
		if (SDL_PollEvent(&event)){
			 switch(event.type){
				case SDL_QUIT:
					if(NULL!=renderer)
						SDL_DestroyRenderer(renderer);
					if(NULL!=pWindow)
						SDL_DestroyWindow(pWindow);
					if(NULL!=pSprite)
						SDL_FreeSurface(pSprite);
					image->det(image);
					IMG_Quit();
					TTF_Quit();
					SDL_Quit();
					exit(EXIT_SUCCESS);
				case SDL_KEYUP:
					switch(event.key.keysym.sym){
						case SDLK_q:
							 if(fullscreen==1)
								SDL_SetWindowFullscreen(pWindow,0);
							if(NULL!=renderer)
								SDL_DestroyRenderer(renderer);
							if(NULL!=pWindow)
								SDL_DestroyWindow(pWindow);
							if(NULL!=pSprite)
								SDL_FreeSurface(pSprite);
							image->det(image);
							IMG_Quit();
							TTF_Quit();
							SDL_Quit();
							exit(EXIT_SUCCESS);
							break;
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
