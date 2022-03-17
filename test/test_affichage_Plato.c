#include "../lib/aff_table.h"
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
	SDL_Window* pWindow = NULL; //pointeur sur la fenêtre invisible

	SDL_Renderer *renderer=NULL;
	char fond_Plato[]="image/en_plus/Fond_Plato.png";

	text_t* image=NULL;
	text_t* bouton=NULL;

	SDL_Color Noir = {0 , 0 , 0};

	int W=1000,H=1000;

	int x=0,y=0;

	pWindow = SDL_CreateWindow("Takenoko",SDL_WINDOWPOS_UNDEFINED,
											SDL_WINDOWPOS_UNDEFINED,
											W,
											H,
											SDL_WINDOW_SHOWN |SDL_WINDOW_RESIZABLE);
	renderer = SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_ACCELERATED); // Création d'un SDL_Renderer utilisant l'accélération matérielle

	image=Crea_Tex(1);
	//Tuile=Crea_table_tex(13);il 13 image de tuille
	bouton=Crea_Tex(2);
	bouton->Table[0]->t=Creation_Text(renderer,lire_Rect(bouton->Table[0],1),"image/police/Takenoko.TTF",30,TTF_STYLE_BOLD,"<-Retour",Noir,W*1/3,10);
	bouton->Table[1]->t=Creation_Text(renderer,lire_Rect(bouton->Table[1],1),"image/police/Takenoko.TTF",30,TTF_STYLE_BOLD|TTF_STYLE_UNDERLINE,"<-Retour",Noir,W*1/3,10);

	if ((bouton->Table[0]) == NULL || bouton->Table[1]==NULL){
		exit ( EXIT_FAILURE );
	}

	(*image->Table)->t = IMG_LoadTexture(renderer, fond_Plato);
	if((*image->Table)->t==NULL){
		fprintf ( stderr , " Erreur au niveau de l'image: %s \n " , TTF_GetError ());
		exit ( EXIT_FAILURE );
	}
	while(1){
		Uint32 Clic = SDL_GetMouseState(&x,&y);
		//création de la "fenêtre ou nous verons une partie de l'image
		SDL_RenderCopy(renderer,(*image->Table)->t,NULL,NULL);
		if(bout(renderer,bouton,x,y) && Clic){
			bouton->det(bouton);
			image->det(image);
			if(NULL!=renderer)
				SDL_DestroyRenderer(renderer);
			if(NULL!=pWindow)
				SDL_DestroyWindow(pWindow);
			IMG_Quit();
			TTF_Quit();
			SDL_Quit();
			break;
		}
		text_t* Tuile=enregistre_table(renderer, W,H);
		for(int i=0;i<Tuile->Taille;i++){
			SDL_RenderCopy(renderer,(Tuile->Table[i])->t,NULL,(Tuile->Table[i])->place2);
		}
		Tuile->det(Tuile);
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
							bouton->det(bouton);
							image->det(image);
							if(NULL!=renderer)
								SDL_DestroyRenderer(renderer);
							if(NULL!=pWindow)
								SDL_DestroyWindow(pWindow);
							IMG_Quit();
							TTF_Quit();
							SDL_Quit();
							break;
					}
					break;
			 }
		}
	}
	return 0;
}
