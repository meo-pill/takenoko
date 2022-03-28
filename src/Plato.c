#include <unistd.h>
#include "../lib/index.h"
#include"../lib/aff_table.h"
#include "../lib/menu.h"
#include "../lib/Plato.h"


static void affiche_Plato(int W,int H,int nbJoueur,int maxpoint){
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
	char contour_tuile[]="image/case/SelectCase.png";

	SDL_Color Bleu = {150,255,234};

	text_t* image=NULL;
	//text_t* bouton=NULL;
	text_t* Soleil=NULL;
	text_t* Pluie=NULL;
	text_t* Vent= NULL;
	text_t* Orage= NULL;
	text_t* Nuage=NULL;
	text_t** hexagonal=NULL;
	hexagonal=malloc(sizeof(text_t*));
//	text_t** AffJoueur=NULL;
//	AffJoueur=malloc(sizeof(text_t*));
//
//	for(int i=0;i<nbJoueur;i++){
//		AffJoueur[i]=Crea_Tex(2);//normalement 13
//		(AffJoueur[i]->Table[0])->t=Creation_Text(renderer,lire_Rect(AffJoueur[i]->Table[0],1),"image/police/Takenoko.TTF",10,TTF_STYLE_BOLD,J[i]->nom_joueur,Bleu,W*1/3*i,H*1/4*i);
//		(AffJoueur[i]->Table[1])->t=Creation_Text(renderer,lire_Rect(AffJoueur[i]->Table[0],1),"image/police/Takenoko.TTF",10,TTF_STYLE_BOLD,"NbBambou =0",Bleu,W*1/3*i,H*1/4*i);
//	}

	
	int TAILTUILE=200;


	int x=0,y=0;
	int fullscreen=0;

	pWindow = SDL_CreateWindow("Takenoko",SDL_WINDOWPOS_UNDEFINED,
											SDL_WINDOWPOS_UNDEFINED,
											W,
											H,
											SDL_WINDOW_SHOWN |SDL_WINDOW_RESIZABLE);
	renderer = SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_ACCELERATED); // Création d'un SDL_Renderer utilisant l'accélération matérielle

	image=Crea_Tex(1);
	//bouton=Crea_Tex(2);

	//bouton->Table[0]->t=Creation_Text(renderer,lire_Rect(bouton->Table[0],1),"image/police/Takenoko.TTF",60,TTF_STYLE_BOLD,"<-Retour",Bleu,W*1/4,H*1/3);
	//bouton->Table[1]->t=Creation_Text(renderer,lire_Rect(bouton->Table[1],1),"image/police/Takenoko.TTF",60,TTF_STYLE_BOLD|TTF_STYLE_UNDERLINE,"<-Retour",Bleu,W*1/4,H*1/3);

	//if ((bouton->Table[0]) == NULL || bouton->Table[1]==NULL){
	//	exit ( EXIT_FAILURE );
	//}
	Soleil=Crea_Tex(2);
	Pluie=Crea_Tex(2);
	Vent=Crea_Tex(2);
	Orage=Crea_Tex(2);
	Nuage=Crea_Tex(2);

	Soleil->Table[0]->t=Creation_Text(renderer,lire_Rect(Soleil->Table[0],1),"image/police/Takenoko.TTF",30,TTF_STYLE_BOLD,"Soleil",Bleu,10,H*3/8);
	Soleil->Table[1]->t=Creation_Text(renderer,lire_Rect(Soleil->Table[1],1),"image/police/Takenoko.TTF",30,TTF_STYLE_BOLD,"Soleil",Bleu,10,H*3/8);

	Pluie->Table[0]->t=Creation_Text(renderer,lire_Rect(Pluie->Table[0],1),"image/police/Takenoko.TTF",30,TTF_STYLE_BOLD,"pluie",Bleu,10,H*4/8);
	Pluie->Table[1]->t=Creation_Text(renderer,lire_Rect(Pluie->Table[1],1),"image/police/Takenoko.TTF",30,TTF_STYLE_BOLD,"pluie",Bleu,10,H*4/8);

	Vent->Table[0]->t=Creation_Text(renderer,lire_Rect(Vent->Table[0],1),"image/police/Takenoko.TTF",30,TTF_STYLE_BOLD,"vent",Bleu,10,H*5/8);
	Vent->Table[1]->t=Creation_Text(renderer,lire_Rect(Vent->Table[1],1),"image/police/Takenoko.TTF",30,TTF_STYLE_BOLD,"vent",Bleu,10,H*5/8);

	Orage->Table[0]->t=Creation_Text(renderer,lire_Rect(Orage->Table[0],1),"image/police/Takenoko.TTF",30,TTF_STYLE_BOLD,"orage",Bleu,10,H*6/8);
	Orage->Table[1]->t=Creation_Text(renderer,lire_Rect(Orage->Table[1],1),"image/police/Takenoko.TTF",30,TTF_STYLE_BOLD,"orage",Bleu,10,H*6/8);

	Nuage->Table[0]->t=Creation_Text(renderer,lire_Rect(Nuage->Table[0],1),"image/police/Takenoko.TTF",30,TTF_STYLE_BOLD,"nuage",Bleu,10,H*7/8);
	Nuage->Table[1]->t=Creation_Text(renderer,lire_Rect(Nuage->Table[1],1),"image/police/Takenoko.TTF",30,TTF_STYLE_BOLD,"nuage",Bleu,10,H*7/8);

	IMG_Init(IMG_INIT_PNG);

	(*image->Table)->t = IMG_LoadTexture(renderer, fond_Plato);
	if((*image->Table)->t==NULL){
		fprintf ( stderr , " Erreur au niveau de l'image: %s \n " , TTF_GetError ());
		exit ( EXIT_FAILURE );
	}
		for(int pos_y=0;pos_y<NBTUILES;pos_y++){
			hexagonal[pos_y]=Crea_Tex(NBTUILES);
			for(int pos_x=0;pos_x<NBTUILES;pos_x++){
				if(plateau[pos_x][pos_y]!=NULL)
					(hexagonal[pos_y]->Table[pos_x])->t= IMG_LoadTexture(renderer, plateau[pos_x][pos_y]->image);
				else{
					if(plateau[pos_x+1][pos_y]!=NULL || 
							plateau[pos_x-1][pos_y]!=NULL || 
							plateau[pos_x+1][pos_y+1]!=NULL||
							plateau[pos_x+1][pos_y-1]!=NULL||
							plateau[pos_x][pos_y-1]!=NULL||
							plateau[pos_x][pos_y-1]!=NULL||
							plateau[pos_x-1][pos_y-1]!=NULL||
							plateau[pos_x-1][pos_y+1]!=NULL){
						(hexagonal[pos_y]->Table[pos_x])->t = IMG_LoadTexture(renderer, contour_tuile);
					}
				}
				if((hexagonal[pos_y]->Table[pos_x])->t==NULL){
					fprintf ( stderr , " Erreur au niveau de l'image: %s \n " , TTF_GetError ());
					exit ( EXIT_FAILURE );
				}
				if(pos_y%2!=0)
					positionne_rect(lire_Rect((hexagonal[pos_y]->Table[pos_x]),1),(TAILTUILE)*pos_x+(TAILTUILE/2),((TAILTUILE)*pos_y)*3/4,TAILTUILE,TAILTUILE);
				else
					positionne_rect(lire_Rect((hexagonal[pos_y]->Table[pos_x]),1),(TAILTUILE)*pos_x,((TAILTUILE)*pos_y)*3/4,TAILTUILE,TAILTUILE);
			}
		}

	int new_x=0,new_y=0,dif_x,dif_y;
	int victoirJ=0,compteur_tour=0,limit_action=2;

	while(1){
		Uint32 Clic = SDL_GetMouseState(&x,&y);
		//création de la "fenêtre ou nous verons une partie de l'image
		SDL_RenderCopy(renderer,(*image->Table)->t,NULL,NULL);
	//	if(bout(renderer,bouton,x,y) && Clic){
	//		bouton->det(bouton);
	//		image->det(image);
	//		for(int pos_y=0;pos_y<NBTUILES;pos_y++){
	//			hexagonal[pos_y]->det(hexagonal[pos_y]);
	//		}
	//		suprimer();
	//		if(NULL!=renderer)
	//			SDL_DestroyRenderer(renderer);
	//		if(NULL!=pWindow)
	//			SDL_DestroyWindow(pWindow);
	//		IMG_Quit();
	//		TTF_Quit();
	//		SDL_Quit();
	//		selecte_nb_joueur(W,H);
	//	}
		//pose du tableau
//		for(int i=0;i<nbJoueur;i++){
//			for(int j=0;j<2;j++){
//				SDL_RenderCopy(renderer,lire_Texture(AffJoueur[i]->Table[j]),NULL,lire_Rect((AffJoueur[i]->Table[j]),1));
//			}
//		}
//		valida

		if(!victoirJ && compteur_tour==0){
			effet_E meteo=lancer_meteo();
			int modif_Pos=0;
			choix : switch (meteo){
					case soleil :
						SDL_RenderCopy(renderer,lire_Texture(Soleil->Table[1]),NULL,lire_Rect(Soleil->Table[1],1));
						limit_action ++;
						break;
					case pluie :
						SDL_RenderCopy(renderer,lire_Texture(Pluie->Table[1]),NULL,lire_Rect(Pluie->Table[1],1));
						//declancher_pluie();
						break;
					case vent :
						SDL_RenderCopy(renderer,lire_Texture(Vent->Table[1]),NULL,lire_Rect(Vent->Table[1],1));
						break;
					case orage :
						SDL_RenderCopy(renderer,lire_Texture(Orage->Table[1]),NULL,lire_Rect(Orage->Table[1],1));
						//orage_panda();
						break;
					case nuage :
						SDL_RenderCopy(renderer,lire_Texture(Nuage->Table[1]),NULL,lire_Rect(Nuage->Table[1],1));
						//choix_amenagement(J[i]);
						break;
					case choixJ :
						if(bout(renderer,Soleil,x,y) && Clic)
							meteo=soleil;
						else if (bout(renderer,Pluie,x,y) && Clic)
							meteo=pluie;
						else if (bout(renderer,Vent,x,y) && Clic)
							meteo=vent;
						else if (bout(renderer,Orage,x,y) && Clic)
							meteo=orage;
						else if(bout(renderer,Nuage,x,y) && Clic)
							meteo=nuage;
						goto choix;
						break;
			}
			if(Clic){
				if(x!=new_x && y!=new_y){
					dif_x=x-new_x;
					dif_y=y-new_y;
					SDL_GetMouseState(&new_x,&new_y);
					modif_Pos=1;
				}
			}
			for(int pos_y=0;pos_y<NBTUILES;pos_y++){
				for(int pos_x=0;pos_x<NBTUILES;pos_x++){
							if(dif_x<0 && dif_y<=0 && modif_Pos)
								positionne_rect(lire_Rect((hexagonal[pos_y]->Table[pos_x]),1),
										lire_Rect((hexagonal[pos_y]->Table[pos_x]),1)->x-10,
										lire_Rect((hexagonal[pos_y]->Table[pos_x]),1)->y-10,
										TAILTUILE,TAILTUILE);
							else if(dif_x>=0 && dif_y>0 && modif_Pos)
								positionne_rect(lire_Rect((hexagonal[pos_y]->Table[pos_x]),1),
										lire_Rect((hexagonal[pos_y]->Table[pos_x]),1)->x+10,
										lire_Rect((hexagonal[pos_y]->Table[pos_x]),1)->y+10,
										TAILTUILE,TAILTUILE);
							else if(dif_x>=0 && dif_y<0 && modif_Pos)
								positionne_rect(lire_Rect((hexagonal[pos_y]->Table[pos_x]),1),
										lire_Rect((hexagonal[pos_y]->Table[pos_x]),1)->x+10,
										lire_Rect((hexagonal[pos_y]->Table[pos_x]),1)->y-10,
										TAILTUILE,TAILTUILE);
							else if(dif_x<0 && dif_y>=0 && modif_Pos)
								positionne_rect(lire_Rect((hexagonal[pos_y]->Table[pos_x]),1),
										lire_Rect((hexagonal[pos_y]->Table[pos_x]),1)->x-10,
										lire_Rect((hexagonal[pos_y]->Table[pos_x]),1)->y+10,
										TAILTUILE,TAILTUILE);
					
					SDL_RenderCopy(renderer,lire_Texture(hexagonal[pos_y]->Table[pos_x]),NULL,lire_Rect((hexagonal[pos_y]->Table[pos_x]),1));
				}
			}
			if(victoire_joueur(J[compteur_tour],maxpoint))
				victoirJ=1;

			compteur_tour= (compteur_tour+1)%nbJoueur;
		}
		//présentation final
		SDL_RenderPresent(renderer);
		if(SDL_PollEvent(&event)){
			if(evenment(event,pWindow,&fullscreen)==QUIT){
				if(fullscreen==1){
					SDL_SetWindowFullscreen(pWindow,0);
				}
				//bouton->det(bouton);
				image->det(image);
				for(int pos_y=0;pos_y<NBTUILES;pos_y++){
					hexagonal[pos_y]->det(hexagonal[pos_y]);
				}
				suprimer();
				if(renderer!=NULL)
					SDL_DestroyRenderer(renderer);
				if(pWindow!=NULL)
					SDL_DestroyWindow(pWindow);
				IMG_Quit();
				TTF_Quit();
				SDL_Quit();
				exit(EXIT_SUCCESS);
			}
		}
	}

}

extern void selecte_nb_joueur(int W,int H){
	if (SDL_Init(SDL_INIT_TIMER |SDL_INIT_VIDEO)== -1 ){
		fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
		exit(EXIT_FAILURE );
	}
	if ( TTF_Init () == -1) {
		fprintf ( stderr , " Erreur d ’ i nitialis ation de TTF_Init : %s \n " , TTF_GetError ());
		exit ( EXIT_FAILURE );
	}
	IMG_Init(IMG_INIT_PNG);
	SDL_Event event;//permet de voir les evenement sur la fenêtre
	SDL_Window* pWindow = NULL; //pointeur sur la fenêtre invisible

	SDL_Renderer *renderer=NULL;

	SDL_Color Bleu = {150,255,234};

	char fond_Plato[]="image/en_plus/Fond_Plato.png";

	text_t* image=NULL;
	text_t* bouton1=NULL;
	text_t* bouton2=NULL;
	text_t* bouton3=NULL;
	text_t* bouton4=NULL;

	int x,y;
	int fullscreen=0;
	int maxpoint=0;

	pWindow = SDL_CreateWindow("Takenoko",SDL_WINDOWPOS_UNDEFINED,
											SDL_WINDOWPOS_UNDEFINED,
											W,
											H,
											SDL_WINDOW_SHOWN |SDL_WINDOW_RESIZABLE);
	renderer = SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_ACCELERATED); // Création d'un SDL_Renderer utilisant l'accélération matérielle

	image=Crea_Tex(1);
	bouton1=Crea_Tex(2);
	bouton2=Crea_Tex(2);
	bouton3=Crea_Tex(2);
	bouton4=Crea_Tex(2);


	bouton1->Table[0]->t=Creation_Text(renderer,lire_Rect(bouton1->Table[0],1),"image/police/Takenoko.TTF",60,TTF_STYLE_BOLD,"2 Joueur",Bleu,W*1/3,H*1/5);
	bouton1->Table[1]->t=Creation_Text(renderer,lire_Rect(bouton1->Table[1],1),"image/police/Takenoko.TTF",60,TTF_STYLE_BOLD|TTF_STYLE_UNDERLINE,"Select 2 J",Bleu,W*1/3,H*1/5);
	if ( bouton1->Table[0]->t == NULL||bouton1->Table[1]->t == NULL ){
		printf("\t\tJe n'arrive pas à charger bouton1\n");
		exit ( EXIT_FAILURE );
	}

	bouton2->Table[0]->t=Creation_Text(renderer,lire_Rect(bouton2->Table[0],1),"image/police/Takenoko.TTF",60,TTF_STYLE_BOLD,"3 Jouer",Bleu,W*1/3,H*1/5+H*1/9);
	bouton2->Table[1]->t=Creation_Text(renderer,lire_Rect(bouton2->Table[1],1),"image/police/Takenoko.TTF",60,TTF_STYLE_BOLD|TTF_STYLE_UNDERLINE,"Select 3 J",Bleu,W*1/3,H*1/5+H*1/9);
	if ( bouton2->Table[0]->t == NULL||bouton2->Table[1]->t == NULL ){
		printf("\t\tJe n'arrive pas à charger bouton2\n");
		exit ( EXIT_FAILURE );
	}

	bouton3->Table[0]->t=Creation_Text(renderer,lire_Rect(bouton3->Table[0],1),"image/police/Takenoko.TTF",60,TTF_STYLE_BOLD,"4 Joueur",Bleu,W*1/3,H*1/5+H*2/9);
	bouton3->Table[1]->t=Creation_Text(renderer,lire_Rect(bouton3->Table[1],1),"image/police/Takenoko.TTF",60,TTF_STYLE_BOLD|TTF_STYLE_UNDERLINE,"Select 4 J",Bleu,W*1/3,H*1/5+H*2/9);
	if ( bouton3->Table[0]->t == NULL||bouton3->Table[1]->t == NULL ){
		printf("\t\tJe n'arrive pas à charger bouton3\n");
		exit ( EXIT_FAILURE );
	}

	bouton4->Table[0]->t=Creation_Text(renderer,lire_Rect(bouton4->Table[0],1),"image/police/Takenoko.TTF",60,TTF_STYLE_BOLD,"<-Retour",Bleu,W*1/3,H*1/5+H*3/9);
	bouton4->Table[1]->t=Creation_Text(renderer,lire_Rect(bouton4->Table[1],1),"image/police/Takenoko.TTF",60,TTF_STYLE_BOLD|TTF_STYLE_UNDERLINE,"~Retour vers Le Menu~",Bleu,W*1/9,H*1/5+H*3/9);
	if ( bouton4->Table[0]->t == NULL||bouton4->Table[1]->t == NULL ){
		printf("\t\tJe n'arrive pas à charger bouton4\n");
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
		if(bout(renderer,bouton1,x,y) && Clic){
			bouton1->det(bouton1);
			bouton2->det(bouton2);
			bouton3->det(bouton3);
			bouton4->det(bouton4);
			image->det(image);
			if(NULL!=renderer)
				SDL_DestroyRenderer(renderer);
			if(NULL!=pWindow)
				SDL_DestroyWindow(pWindow);
			IMG_Quit();
			TTF_Quit();
			SDL_Quit();
			debut_partie(2,&maxpoint);
			affiche_Plato(W,H,2,maxpoint);
		}
		if(bout(renderer,bouton2,x,y) && Clic){
			bouton1->det(bouton1);
			bouton2->det(bouton2);
			bouton3->det(bouton3);
			bouton4->det(bouton4);
			image->det(image);
			if(NULL!=renderer)
				SDL_DestroyRenderer(renderer);
			if(NULL!=pWindow)
				SDL_DestroyWindow(pWindow);
			IMG_Quit();
			TTF_Quit();
			SDL_Quit();
			debut_partie(3,&maxpoint);
			affiche_Plato(W,H,3,maxpoint);
		}
		if(bout(renderer,bouton3,x,y) && Clic){
			bouton1->det(bouton1);
			bouton2->det(bouton2);
			bouton3->det(bouton3);
			bouton4->det(bouton4);
			image->det(image);
			if(NULL!=renderer)
				SDL_DestroyRenderer(renderer);
			if(NULL!=pWindow)
				SDL_DestroyWindow(pWindow);
			IMG_Quit();
			TTF_Quit();
			SDL_Quit();
			debut_partie(4,&maxpoint);
			affiche_Plato(W,H,4,maxpoint);
		}
		if(bout(renderer,bouton4,x,y) && Clic){
			bouton1->det(bouton1);
			bouton2->det(bouton2);
			bouton3->det(bouton3);
			bouton4->det(bouton4);
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
		//présentation final
		SDL_RenderPresent(renderer);
		if(SDL_PollEvent(&event)){
			if(evenment(event,pWindow,&fullscreen)==QUIT){
				if(fullscreen==1){
					SDL_SetWindowFullscreen(pWindow,0);
				}
				bouton1->det(bouton1);
				bouton2->det(bouton2);
				bouton3->det(bouton3);
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

}

