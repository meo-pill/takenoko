#include <unistd.h>
#include"../lib/aff_table.h"
#include "../lib/Creation.h"
#include "../lib/menu.h"
#include "../lib/commande.h"


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
	text_t* Tex_Tuile=NULL;

	SDL_Color Noir = {0 , 0 , 0};


	int x=0,y=0;
	int fullscreen=0;

	pWindow = SDL_CreateWindow("Takenoko",SDL_WINDOWPOS_UNDEFINED,
											SDL_WINDOWPOS_UNDEFINED,
											W,
											H,
											SDL_WINDOW_SHOWN |SDL_WINDOW_RESIZABLE);
	renderer = SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_ACCELERATED); // Création d'un SDL_Renderer utilisant l'accélération matérielle

	image=Crea_Tex(1);
	bouton=Crea_Tex(2);
	bouton->Table[0]->t=Creation_Text(renderer,lire_Rect(bouton->Table[0],1),"image/police/Takenoko.TTF",30,TTF_STYLE_BOLD,"<-Retour",Noir,W*1/3,10);
	bouton->Table[1]->t=Creation_Text(renderer,lire_Rect(bouton->Table[1],1),"image/police/Takenoko.TTF",30,TTF_STYLE_BOLD|TTF_STYLE_UNDERLINE,"<-Retour",Noir,W*1/3,10);

	if ((bouton->Table[0]) == NULL || bouton->Table[1]==NULL){
		exit ( EXIT_FAILURE );
	}
	IMG_Init(IMG_INIT_PNG);

	(*image->Table)->t = IMG_LoadTexture(renderer, fond_Plato);
	if((*image->Table)->t==NULL){
		fprintf ( stderr , " Erreur au niveau de l'image: %s \n " , TTF_GetError ());
		exit ( EXIT_FAILURE );
	}
//	unsigned int tempdeb= SDL_GetTicks();
//	unsigned int tempfin= SDL_GetTicks();
//	double delta =0;
	int i=0;
	SDL_Rect * position;
//	SDL_Rect * Pre_position=NULL;
	palt_test();
//	Pre_position->x=0;
//	Pre_position->y=0;
	Tex_Tuile=Crea_Tex(NBTUILES);

	for(int pos_x=1;pos_x<NBTUILES;pos_x++){
		for(int pos_y =0;pos_y<NBTUILES ;pos_y++){
			if(plateau[pos_x][pos_y] != NULL){
	printf("Coucou\n");
				(Tex_Tuile->Table[i])->t = IMG_LoadTexture(renderer, plateau[pos_x][pos_y]->image);
//				printf (" Erreur au niveau de l'image: %s \n ",plateau[x][y]->image);
				if((Tex_Tuile->Table[i])->t==NULL){
					fprintf ( stderr , " Erreur au niveau de l'image: %s \n " , TTF_GetError ());
					exit ( EXIT_FAILURE );
				}
				position=lire_Rect(Tex_Tuile->Table[i],1);
//				if(i>0){
//					Pre_position=lire_Rect(Tex_Tuile->Table[i-1],1);
//					position->x=Pre_position->x+W/9;
//					position->y=Pre_position->x+H/9;
//				}
//				else{
					position->x=W/2;
					position->y=H/2;
//				}
				(Tex_Tuile->Table[i])->place2=position;
				i++;
			}
		}
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
			menu();
		}
		//pose du tableau
		for(int i=1;i<Tex_Tuile->Taille;i++){
			SDL_Rect * rect=lire_Rect(Tex_Tuile->Table[i],1);
			SDL_RenderCopy(renderer,Tex_Tuile->Table[i]->t,NULL,rect);
		}
		//présentation final
		SDL_RenderPresent(renderer);
		if(evenment(event,pWindow,&fullscreen)==QUIT){
			Tex_Tuile->det(Tex_Tuile);
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
		}
	}

}
