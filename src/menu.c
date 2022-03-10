#include "../lib/index.h"
#include "../lib/Creation.h"
#include "../lib/Option.h"
#include "../lib/Plato.h"
#include "../lib/texture.h"
void menu(){
	if (SDL_Init(SDL_INIT_TIMER |SDL_INIT_VIDEO)== -1 ){
		fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
		exit(EXIT_FAILURE );
	}

	if ( TTF_Init () == -1) {
		fprintf ( stderr , " Erreur d ’ i nitialis ation de TTF_Init : %s \n " , TTF_GetError ());
		exit ( EXIT_FAILURE );
	}
	SDL_Event event;//permet de voir les evenement sur la fenêtre

	SDL_Renderer *renderer=NULL;//pour créer une fennêtre 


	text_t* image=NULL;
	text_t* bouton=NULL;


	SDL_Surface* pSprite =NULL;//ajout d'une image par dessus le fond

	SDL_Rect tailText;
	SDL_Rect tailBouton1;
	SDL_Rect tailBouton2;
	SDL_Rect tailBouton3;
	SDL_Rect tailBouton4;
	SDL_Rect tailBouton5;
	SDL_Rect tailBouton6;

	//SDL_Color maron ={95,67,36};
	SDL_Color Noir = {0 , 0 , 0};
	SDL_Color Bleu = {4,41,46};
	SDL_Color Orange={240,58,0};

	SDL_Window* pWindow = NULL; //pointeur sur la fenêtre

	SDL_RWops *rwop=NULL;//permet d'incruster l'image sur la fenètre

	char fond[]="image/en_plus/Fond_menu.png";//chemin vers l'image de fond
	char animation[]="image/animation/oiseau.bmp";//chemin vers l'animation
	int fullscreen=0;

	//permet de prendre la taille de l'écran
	SDL_DisplayMode DM;
	SDL_GetCurrentDisplayMode(0, &DM);
	auto int Width = DM.w;
	auto int Height = DM.h;

	//création d'une fênetre
	pWindow = SDL_CreateWindow("takenoko",SDL_WINDOWPOS_UNDEFINED,
											SDL_WINDOWPOS_UNDEFINED,
											Width,
											Height,
											SDL_WINDOW_SHOWN |SDL_WINDOW_RESIZABLE);
	renderer = SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_ACCELERATED); // Création d'un SDL_Renderer utilisant l'accélération matérielle
	/**Creation de la table de texture*/
	image=Crea_table_Tex(2);
	bouton=Crea_table_Tex(6);
	if(image== NULL && bouton==NULL){
		printf("la table ne c'est pas creer\n");
		exit ( EXIT_FAILURE );
	}
	//création du titre
	//chargement de la police
	bouton->Table[0]=CreationText(renderer,&tailText,"image/police/Takenoko.TTF",80,TTF_STYLE_BOLD,"Takenoko", Noir,Width/4,10);
	if(bouton->Table[0]==NULL)
		exit(EXIT_FAILURE );

	bouton->Table[1] =CreationText(renderer,&tailBouton1,"image/police/Takenoko.TTF",40,TTF_STYLE_BOLD,"Jouer",Bleu,569,700);
	if ( bouton->Table[1] == NULL ){
		exit ( EXIT_FAILURE );
	}

	bouton->Table[2] =CreationText(renderer,&tailBouton2,"image/police/Takenoko.TTF",40,TTF_STYLE_BOLD,"Option",Bleu,569,650);
	if ( bouton->Table[2] == NULL ){
		exit ( EXIT_FAILURE );
	}

	bouton->Table[3] =CreationText(renderer,&tailBouton3,"image/police/Takenoko.TTF",40,TTF_STYLE_BOLD,"Quiter",Bleu,569,750);
	if ( bouton->Table[3] == NULL ){
		exit ( EXIT_FAILURE );
	}

	bouton->Table[4] =CreationText(renderer,&tailBouton4,"image/police/Takenoko.TTF",40,TTF_STYLE_BOLD|TTF_STYLE_UNDERLINE,"Jouer",Orange,569,700);
	if ( bouton->Table[4] == NULL ){
		exit ( EXIT_FAILURE );
	}
	bouton->Table[5] =CreationText(renderer,&tailBouton5,"image/police/Takenoko.TTF",40,TTF_STYLE_BOLD|TTF_STYLE_UNDERLINE,"Option",Orange,569,650);
	if ( bouton->Table[5] == NULL ){
		exit ( EXIT_FAILURE );
	}

	bouton->Table[6] =CreationText(renderer,&tailBouton6,"image/police/Takenoko.TTF",40,TTF_STYLE_BOLD|TTF_STYLE_UNDERLINE,"Quiter",Orange,569,750);
	if ( bouton->Table[6] == NULL ){
		exit ( EXIT_FAILURE );
	}

	IMG_Init(IMG_INIT_PNG);

	//création d'une animation
	rwop=SDL_RWFromFile(animation,"rb");
	pSprite = IMG_LoadBMP_RW(rwop);

	if(pSprite==NULL){
		printf("ERR pour le chargement de l'animation\n");
		exit(EXIT_FAILURE );
	}
		//suppretion de l'image animation
		rwop->close(rwop);
		rwop=NULL;

		//chargement de la nouvelle image
		rwop=SDL_RWFromFile(fond, "rb");
		image->Table[0] = IMG_LoadTexture(renderer, fond);
		image->Table[1] = SDL_CreateTextureFromSurface(renderer,pSprite);
		if(image->Table[0]==NULL||image->Table[1]==NULL){
			printf("ERR chargement image\n");
			if(renderer==NULL)
				printf("ERR au nv du renderer\n");
		}
		else{
			int x=0,y=0;
			//boucle des evenments permet defaire diférente action sur la fenêtre
			while (1) {
				//permet de savoir où et si on clique avec la souri
				Uint32 boutons = SDL_GetMouseState(&x,&y);

				//permet de faire bouger l'animation
				Uint32 ticks = SDL_GetTicks();
				Uint32 seconds = ticks / 230;
				Uint32 sprite = seconds % 4;
				//création de la "fenêtre ou nous verons une partie de l'image
				SDL_Rect annimation = { sprite*120,0,120,100};
				SDL_Rect crop={Width/10, Height/100, 120, 100 };
				//on pose le fond sur la fenêtre
				SDL_RenderCopy(renderer, image->Table[0], NULL, NULL);
				SDL_RenderCopy(renderer, bouton->Table[0], NULL,&tailText);
				if((x>=tailBouton1.x && x<=(tailBouton1.w+tailBouton1.x)) && (y>=tailBouton1.y && y<=(tailBouton1.h+tailBouton1.y))){
					if(boutons==1)
						affiche_Plato(Width,Height);
					else
						SDL_RenderCopy(renderer, bouton->Table[4],NULL,&tailBouton4);
				}
				else
					SDL_RenderCopy(renderer, bouton->Table[1],NULL,&tailBouton1);

				if((x>=tailBouton2.x && x<=(tailBouton2.w+tailBouton2.x)) && (y>=tailBouton2.y && y<=(tailBouton2.h+tailBouton2.y))){
					if(boutons==1){
						if(NULL!=renderer)
							SDL_DestroyRenderer(renderer);
						if(NULL!=pWindow)
							SDL_DestroyWindow(pWindow);
						if(NULL!=pSprite)
							SDL_FreeSurface(pSprite);
						bouton->det(bouton);
						image->det(image);
						IMG_Quit();
						TTF_Quit();
						SDL_Quit();
						affiche_option(fond,Width,Height);
					}
					else
						SDL_RenderCopy(renderer,bouton->Table[5],NULL,&tailBouton5);
				}
				else
					SDL_RenderCopy(renderer, bouton->Table[2],NULL,&tailBouton2);

				if((x>=tailBouton3.x && x<=(tailBouton3.w+tailBouton3.x)) && (y>=tailBouton3.y && y<=(tailBouton3.h+tailBouton3.y))){
					if(boutons==1)
						exit(EXIT_SUCCESS);
					else
						SDL_RenderCopy(renderer, bouton->Table[6],NULL,&tailBouton6);
				}
				else
					SDL_RenderCopy(renderer, bouton->Table[3],NULL,&tailBouton3);
				//on pose l'animation sur la fenêtre
				SDL_RenderCopy(renderer,image->Table[1],&annimation,&crop);// Copie du sprite grâce au SDL_Renderer
				//présentation final
				SDL_RenderPresent(renderer);
				//affiche la position de l'endroit ou la sourie à cliquer
				if(boutons ==1){
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
							bouton->det(bouton);
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
									bouton->det(bouton);
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
}
