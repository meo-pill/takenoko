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
	text_t* titre=NULL;
	text_t* bouton1=NULL;
	text_t* bouton2=NULL;
	text_t* bouton3=NULL;


	SDL_Surface* pSprite =NULL;//ajout d'une image par dessus le fond

	SDL_Rect tailText;

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
	titre=Crea_table_Tex(1);
	bouton1=Crea_table_Tex(2);
	bouton2=Crea_table_Tex(2);
	bouton3=Crea_table_Tex(2);

	if(image== NULL && bouton==NULL){
		printf("la table ne c'est pas creer\n");
		exit ( EXIT_FAILURE );
	}
	//création du titre
	//chargement de la police
	tirte->Table[0]->texture=CreationText(renderer,(titre->Table[0])->Place2,"image/police/Takenoko.TTF",80,TTF_STYLE_BOLD,"Takenoko", Noir,Width/4,10);
	if ( tirte->Table[0]->texture){
		exit ( EXIT_FAILURE );
	}

	bouton1->Table[1]->t =CreationText(renderer,bouton1->Table[1]->place2,"image/police/Takenoko.TTF",40,TTF_STYLE_BOLD,"Option",Bleu,569,650);¶
	bouton1->Table[1]->t =CreationText(renderer,(bouton1->Table[1])->Place2,"image/police/Takenoko.TTF",40,TTF_STYLE_BOLD|TTF_STYLE_UNDERLINE,"Option",Orange,569,650);
	if ( bouton1->Table[0]->t == NULL||bouton1->Table[1]->t == NULL ){
		exit ( EXIT_FAILURE );
	}

	bouton2->Table[0]->t =CreationText(renderer,bouton2->Table[0]->place2,"image/police/Takenoko.TTF",40,TTF_STYLE_BOLD,"Jouer",Bleu,569,700);
	bouton2->Table[1]->t =CreationText(renderer,bouton2->Table[1]->place2,"image/police/Takenoko.TTF",40,TTF_STYLE_BOLD|TTF_STYLE_UNDERLINE,"Jouer",Bleu,569,700);
	if ( bouton2->Table[0]->t == NULL||bouton2->Table[1]->t == NULL ){
		exit ( EXIT_FAILURE );
	}

	bouton3->Table[0]->t =CreationText(renderer,bouton3->Table[0]->place2,"image/police/Takenoko.TTF",40,TTF_STYLE_BOLD,"Quiter",Bleu,569,750);
	bouton3->Table[1]->t =CreationText(renderer,bouton3->Table[1]->place2,"image/police/Takenoko.TTF",40,TTF_STYLE_BOLD|TTF_STYLE_UNDERLINE,"Quiter",Orange,569,750);
	if ( bouton3->Table[0]->t == NULL||bouton3->Table[1]->t == NULL ){
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
		image->Table[0]->t = IMG_LoadTexture(renderer, fond);
		image->Table[1]->t = SDL_CreateTextureFromSurface(renderer,pSprite);
		if(image->Table[0]->t==NULL||image->Table[1]->t==NULL){
			printf("ERR chargement image\n");
			if(renderer==NULL)
				printf("ERR au nv du renderer\n");
		}
		else{
			int x=0,y=0;
			//boucle des evenments permet defaire diférente action sur la fenêtre
			while (1) {
				//permet de savoir où et si on clique avec la souri
				Uint32 Clic = SDL_GetMouseState(&x,&y);

				//permet de faire bouger l'animation
				Uint32 ticks = SDL_GetTicks();
				Uint32 seconds = ticks / 230;
				Uint32 sprite = seconds % 4;
				//création de la "fenêtre ou nous verons une partie de l'image
				//animation
				((image->Table[1])->Place)->x=sprite*120;
				((image->Table[1])->Place)->y=0;
				((image->Table[1])->Place)->w=120;
				((image->Table[1])->Place)->h=100;
				//crop
				((image->Table[1])->Place2)->x=Width/10;
				((image->Table[1])->Place2)->y=Height/100;
				((image->Table[1])->Place2)->w=120;
				((image->Table[1])->Place2)->h=100;
				/** on affiche les image*/
				image->aff(tab,render);
				/**on gère les boutons*/
				SDL_RenderCopy(renderer, bouton->Table[0], NULL,&tailText);
				if(Push(renderer,x,y,bouton1)==1 && Clic==1){
					if(NULL!=renderer)
						SDL_DestroyRenderer(renderer);
					if(NULL!=pWindow)
						SDL_DestroyWindow(pWindow);
					if(NULL!=pSprite)
						SDL_FreeSurface(pSprite);
					titre->det(titre);
					bouton1->det(bouton1);
					bouton2->det(bouton2);
					bouton3->det(bouton3);
					affiche_option(Width,Height);
				}

				if(Push(renderer,x,y,bouton2)==1 && Clic==1){
					if(NULL!=renderer)
						SDL_DestroyRenderer(renderer);
					if(NULL!=pWindow)
						SDL_DestroyWindow(pWindow);
					if(NULL!=pSprite)
						SDL_FreeSurface(pSprite);
					titre->det(titre);
					bouton1->det(bouton1);
					bouton2->det(bouton2);
					bouton3->det(bouton3);
					affiche_option(Width,Height);
				}
				
				
				if(Push(renderer,x,y,bouton3)==1 && Clic==1){
					if(NULL!=renderer)
						SDL_DestroyRenderer(renderer);
					if(NULL!=pWindow)
						SDL_DestroyWindow(pWindow);
					if(NULL!=pSprite)
						SDL_FreeSurface(pSprite);
					titre->det(titre);
					bouton1->det(bouton1);
					bouton2->det(bouton2);
					bouton3->det(bouton3);
					affiche_option(Width,Height);
				}

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
