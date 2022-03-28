//#include "../lib/Option.h"
#include "../lib/Plato.h"

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

	//SDL_Color maron ={95,67,36};
	SDL_Color Noir = {0 , 0 , 0};
	SDL_Color Bleu = {4,41,46};
	SDL_Color Orange={240,58,0};

	SDL_Window* pWindow = NULL; //pointeur sur la fenêtre

	SDL_RWops *rwop=NULL;//permet d'incruster l'image sur la fenètre

	char fond[]="image/en_plus/Fond_menu.png";//chemin vers l'image de fond
	char animation[]="image/animation/oiseau.bmp";//chemin vers l'animation

	//permet de prendre la taille de l'écran
	SDL_DisplayMode DM;
	SDL_GetCurrentDisplayMode(0, &DM);
	auto int Width = DM.w;
	auto int Height = DM.h;

	int fullscreen=0;
	//création d'une fênetre
	pWindow = SDL_CreateWindow("takenoko",SDL_WINDOWPOS_UNDEFINED,
											SDL_WINDOWPOS_UNDEFINED,
											Width,
											Height,
											SDL_WINDOW_SHOWN |SDL_WINDOW_RESIZABLE);
	renderer = SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_ACCELERATED); // Création d'un SDL_Renderer utilisant l'accélération matérielle
	/**Creation de la table de texture*/
	image=Crea_Tex(2);
	titre=Crea_Tex(1);
	bouton1=Crea_Tex(2);
	bouton2=Crea_Tex(2);
	bouton3=Crea_Tex(2);


	if(image== NULL && bouton1==NULL && bouton2==NULL && bouton3==NULL && titre==NULL){
		printf("la table ne c'est pas creer\n");
		exit ( EXIT_FAILURE );
	}
	//création du titre
	//chargement de la police
	titre->Table[0]->t=Creation_Text(renderer,lire_Rect(titre->Table[0],1),"image/police/Takenoko.TTF",Width/25,TTF_STYLE_BOLD,"Takenoko", Noir,Width/4,10);
	if ( titre->Table[0]->t==NULL){
		exit ( EXIT_FAILURE );
	}
	bouton1->Table[0]->t =Creation_Text(renderer,lire_Rect(bouton1->Table[0],1),"image/police/Takenoko.TTF",Width/48,TTF_STYLE_BOLD,"Jouer",Bleu,(Width/4)+(Height*2/18),(Height*5/8));
	bouton1->Table[1]->t =Creation_Text(renderer,lire_Rect(bouton1->Table[1],1),"image/police/Takenoko.TTF",Width/48,TTF_STYLE_BOLD|TTF_STYLE_UNDERLINE,"Jouer",Orange,(Width/4)+(Height*2/18),(Height*5/8));
	if ( bouton1->Table[0]->t == NULL||bouton1->Table[1]->t == NULL ){
		exit ( EXIT_FAILURE );
	}

	bouton2->Table[0]->t =Creation_Text(renderer,lire_Rect(bouton2->Table[0],1),"image/police/Takenoko.TTF",Width/48,TTF_STYLE_BOLD,"Option",Bleu,(Width/4)+(Height*2/18),(Height*5/8)+(Height*1/18));
	bouton2->Table[1]->t =Creation_Text(renderer,lire_Rect(bouton2->Table[1],1),"image/police/Takenoko.TTF",Width/48,TTF_STYLE_BOLD|TTF_STYLE_UNDERLINE,"Option",Orange,(Width/4)+(Height*2/18),(Height*5/8)+(Height*1/18));
	if ( bouton2->Table[0]->t == NULL||bouton2->Table[1]->t == NULL ){
		exit ( EXIT_FAILURE );
	}

	bouton3->Table[0]->t =Creation_Text(renderer,lire_Rect(bouton3->Table[0],1),"image/police/Takenoko.TTF",Width/48,TTF_STYLE_BOLD,"Quiter",Bleu,(Width/4)+(Height*2/18),(Height*5/8)+(Height*2/18));
	bouton3->Table[1]->t =Creation_Text(renderer,lire_Rect(bouton3->Table[1],1),"image/police/Takenoko.TTF",Width/48,TTF_STYLE_BOLD|TTF_STYLE_UNDERLINE,"Quiter",Orange,(Width/4)+(Height*2/18),(Height*5/8)+(Height*2/18));
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
	image->Table[0]->t = IMG_LoadTexture(renderer, fond);
	image->Table[1]->t = SDL_CreateTextureFromSurface(renderer,pSprite);
	if(image->Table[0]->t==NULL||image->Table[1]->t==NULL){
		printf("ERR chargement image\n");
		if(renderer==NULL)
			printf("ERR au nv du renderer\n");
		exit ( EXIT_FAILURE );
	}
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
		positionne_rect(lire_Rect(image->Table[1],0),sprite*120,0,100,120);
		//crop
		positionne_rect(lire_Rect(image->Table[1],1),Width/10,Height/100,100,120);
		/** on affiche les image*/
		SDL_RenderCopy(renderer,(image->Table[0])->t,NULL,NULL);
		SDL_RenderCopy(renderer,(image->Table[1])->t,lire_Rect(image->Table[1],0),lire_Rect(image->Table[1],1));
		/** titre*/
		SDL_RenderCopy(renderer,(*titre->Table)->t,NULL,(*titre->Table)->place2);
		/**on gère les boutons*/
		if(bout(renderer,bouton1,x,y) && Clic){
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
			image->det(image);
			IMG_Quit();
			TTF_Quit();
			SDL_Quit();
			selecte_nb_joueur(Width,Height);
		}
		if(bout(renderer,bouton2,x,y)==1 && Clic==1){
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
			image->det(image);
			IMG_Quit();
			TTF_Quit();
			SDL_Quit();
			//affiche_option(Width,Height);
		}

		
		if(bout(renderer,bouton3,x,y) && Clic){
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
			image->det(image);
			IMG_Quit();
			TTF_Quit();
			SDL_Quit();
			exit(EXIT_SUCCESS);
		}

		//présentation final
		SDL_RenderPresent(renderer);
		//affiche la position de l'endroit ou la sourie à cliquer
		if(Clic ==1){
			fprintf(stdout, "\t\tavec clic Position de la souris : %d;%d\n",x,y);
		}
		if(SDL_PollEvent(&event)){
			if(evenment(event,pWindow,&fullscreen)==QUIT){
				if(fullscreen==1){
					SDL_SetWindowFullscreen(pWindow,0);
				}
				printf("adieu\n");
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
				image->det(image);
				IMG_Quit();
				TTF_Quit();
				SDL_Quit();
				exit(EXIT_SUCCESS);
			}
		}
	}
}
