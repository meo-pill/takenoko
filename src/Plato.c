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
	srand (time (NULL));


	SDL_Event event;//permet de voir les evenement sur la fenêtre
	SDL_Window* pWindow = NULL; //pointeur sur la fenêtre invisible

	SDL_Renderer *renderer=NULL;

	char fond_Plato[]="image/en_plus/Fond_Plato2.png";
	char contour_tuile[]="image/case/Case.png";
	char bouton_pas_bouge[]="image/bouton/pas_bouge_map.png";
	char bouton_bouge[]="image/bouton/bouge_map.png";

	char image_sol[]="image/meteo/Soleil.png";
	char image_Pluie[]="image/meteo/pluit.png";
	char image_orage[]="image/meteo/Eclaire.png";
	char image_nuage[]="image/meteo/nuage.png";
	char image_vent[]="image/meteo/Vent.png";

	char Select_sol[]="image/meteo/Select_Soleil.png";
	char Select_Pluie[]="image/meteo/Select_pluit.png";
	char Select_orage[]="image/meteo/Select_Eclaire.png";
	char Select_nuage[]="image/meteo/Select_nuage.png";
	char Select_vent[]="image/meteo/Select_Vent.png";
	char Select_choix[]="image/meteo/Select_choix.png";

	char image_Mov_jardinier[]="image/en_plus/Choix/Choix_jardinier.png";
	char image_Mov_pandas[]="image/en_plus/Choix/Choix_pandas.png";
	char image_prd_irrig[]="image/en_plus/Choix/Choix_irrigation.png";
	char image_prd_tuile[]="image/en_plus/Choix/Choix_tuile.png";
	char image_prd_carte[]="image/en_plus/Choix/Choix_carte.png";

	char Select_Mov_jardinier[]="image/en_plus/Choix/Select_Choix_jardinier.png";
	char Select_Mov_pandas[]="image/en_plus/Choix/Select_Choix_pandas.png";
	char Select_prd_irrig[]="image/en_plus/Choix/Select_Choix_irrigation.png";
	char Select_prd_tuile[]="image/en_plus/Choix/Select_Choix_tuile.png";
	char Select_prd_carte[]="image/en_plus/Choix/Select_Choix_carte.png";

	SDL_Color Blanc = {255,255,255};

	text_t* image=NULL;
	text_t* bouton=NULL;
	text_t* Select_Map=NULL;
	text_t* Select_case=NULL;
	text_t* fin_tour=NULL;

	/*bouton Meteo*/
	text_t* Soleil=NULL;
	text_t* Pluie=NULL;
	text_t* Vent= NULL;
	text_t* Orage= NULL;
	text_t* Nuage=NULL;
	text_t* Met_choix=NULL;
	/*--------------------*/

	/*Bouton tour de jeux*/
	text_t* Mov_pandas=NULL;
	text_t* Mov_jardi=NULL;
	text_t* prd_irrig=NULL;
	text_t* prd_tuile=NULL;
	text_t* prd_carte=NULL;
	/*-------------------*/

	text_t** AffJoueur=NULL;
	AffJoueur=malloc(sizeof(text_t*));
	text_t** hexagonal=NULL;
	hexagonal=malloc(sizeof(text_t*));

	
	int TAILTUILE=200;
	int newTail=0;

	int x=0,y=0;
	int fullscreen=0;
	int new_x=0,new_y=0,dif_x,dif_y;
	int victoirJ=0,compteur_tour=0,limit_action=2,choix=0;
	int UtMap=0;
	int nb_action=0;
	effDes_E meteo;

	pWindow = SDL_CreateWindow("Takenoko",SDL_WINDOWPOS_UNDEFINED,
											SDL_WINDOWPOS_UNDEFINED,
											W,
											H,
											SDL_WINDOW_SHOWN |SDL_WINDOW_RESIZABLE);
	renderer = SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_ACCELERATED); // Création d'un SDL_Renderer utilisant l'accélération matérielle

	image=Crea_Tex(1);
	bouton=Crea_Tex(2);
	Select_Map=Crea_Tex(2);
	Select_case=Crea_Tex(1);
	fin_tour=Crea_Tex(2);

	bouton->Table[0]->t=Creation_Text(renderer,lire_Rect(bouton->Table[0],1),"image/police/Takenoko.TTF",60,TTF_STYLE_BOLD,"<-Retour",Blanc,W*1/4,10);
	bouton->Table[1]->t=Creation_Text(renderer,lire_Rect(bouton->Table[1],1),"image/police/Takenoko.TTF",60,TTF_STYLE_BOLD|TTF_STYLE_UNDERLINE,"<-Retour",Blanc,W*1/4,10);

	if ((bouton->Table[0]) == NULL || bouton->Table[1]==NULL){
		exit ( EXIT_FAILURE );
	}
	fin_tour->Table[0]->t=Creation_Text(renderer,lire_Rect(fin_tour->Table[0],1),"image/police/Takenoko.TTF",60,TTF_STYLE_BOLD,"Fin de tour",Blanc,W*1/4,70);
	fin_tour->Table[1]->t=Creation_Text(renderer,lire_Rect(fin_tour->Table[1],1),"image/police/Takenoko.TTF",60,TTF_STYLE_BOLD|TTF_STYLE_UNDERLINE,"Fin de tour",Blanc,W*1/4,70);

	if ((bouton->Table[0]) == NULL || bouton->Table[1]==NULL){
		exit ( EXIT_FAILURE );
	}
	IMG_Init(IMG_INIT_PNG);

	Soleil=Crea_Tex(3);
	Pluie=Crea_Tex(3);
	Vent=Crea_Tex(3);
	Orage=Crea_Tex(3);
	Nuage=Crea_Tex(3);
	Met_choix=Crea_Tex(1);

	Soleil->Table[0]->t=Creation_image(renderer,lire_Rect(Soleil->Table[0],1),image_sol,10,H*3/11,70,50);
	Soleil->Table[1]->t=Creation_image(renderer,lire_Rect(Soleil->Table[1],1),Select_sol,10,H*3/11,70,50);
	Soleil->Table[2]->t=Creation_Text(renderer,lire_Rect(Soleil->Table[2],1),"image/police/Takenoko.TTF",60,TTF_STYLE_BOLD,"O",Blanc,70,H*3/11);


	Pluie->Table[0]->t=Creation_image(renderer,lire_Rect(Pluie->Table[0],1),image_Pluie,10,H*4/11,70,50);
	Pluie->Table[1]->t=Creation_image(renderer,lire_Rect(Pluie->Table[1],1),Select_Pluie,10,H*4/11,70,50);
	Pluie->Table[2]->t=Creation_Text(renderer,lire_Rect(Pluie->Table[2],1),"image/police/Takenoko.TTF",60,TTF_STYLE_BOLD,"O",Blanc,70,H*4/11);

	Vent->Table[0]->t=Creation_image(renderer,lire_Rect(Vent->Table[0],1),image_vent,10,H*5/11,70,50);
	Vent->Table[1]->t=Creation_image(renderer,lire_Rect(Vent->Table[1],1),Select_vent,10,H*5/11,70,50);
	Vent->Table[2]->t=Creation_Text(renderer,lire_Rect(Vent->Table[2],1),"image/police/Takenoko.TTF",60,TTF_STYLE_BOLD,"O",Blanc,70,H*5/11);

	Orage->Table[0]->t=Creation_image(renderer,lire_Rect(Orage->Table[0],1),image_orage,10,H*6/11,70,50);
	Orage->Table[1]->t=Creation_image(renderer,lire_Rect(Orage->Table[1],1),Select_orage,10,H*6/11,70,50);
	Orage->Table[2]->t=Creation_Text(renderer,lire_Rect(Orage->Table[2],1),"image/police/Takenoko.TTF",60,TTF_STYLE_BOLD,"O",Blanc,70,H*6/11);

	Nuage->Table[0]->t=Creation_image(renderer,lire_Rect(Nuage->Table[0],1),image_nuage,10,H*7/11,70,50);
	Nuage->Table[1]->t=Creation_image(renderer,lire_Rect(Nuage->Table[1],1),Select_nuage,10,H*7/11,70,50);
	Nuage->Table[2]->t=Creation_Text(renderer,lire_Rect(Nuage->Table[2],1),"image/police/Takenoko.TTF",60,TTF_STYLE_BOLD,"O",Blanc,70,H*7/11);

	(*Met_choix->Table)->t=Creation_image(renderer,lire_Rect((*Met_choix->Table),1),Select_choix,70,H*3/11,70,50);

	Select_Map->Table[0]->t = Creation_image(renderer,lire_Rect(Select_Map->Table[0],1),bouton_pas_bouge,W*6/8,H*3/11,30,30);
	Select_Map->Table[1]->t = Creation_image(renderer,lire_Rect(Select_Map->Table[1],1),bouton_bouge,W*6/8,H*3/11,30,30);

	Mov_pandas=Crea_Tex(3);
	Mov_jardi=Crea_Tex(3);
	prd_irrig=Crea_Tex(3);
	prd_tuile=Crea_Tex(3);
	prd_carte=Crea_Tex(3);



	Mov_pandas->Table[0]->t=Creation_image(renderer,lire_Rect(Mov_pandas->Table[0],1),image_Mov_pandas,200,H*3/11,70,50);
	Mov_pandas->Table[1]->t=Creation_image(renderer,lire_Rect(Mov_pandas->Table[1],1),Select_Mov_pandas,200,H*3/11,70,50);
	Mov_pandas->Table[2]->t=Creation_Text(renderer,lire_Rect(Mov_pandas->Table[2],1),"image/police/Takenoko.TTF",30,TTF_STYLE_BOLD,"<-",Blanc,270,H*3/11);

	Mov_jardi->Table[0]->t=Creation_image(renderer,lire_Rect(Mov_jardi->Table[0],1),image_Mov_jardinier,200,H*4/11,70,50);
	Mov_jardi->Table[1]->t=Creation_image(renderer,lire_Rect(Mov_jardi->Table[1],1),Select_Mov_jardinier,200,H*4/11,70,50);
	Mov_jardi->Table[2]->t=Creation_Text(renderer,lire_Rect(Mov_jardi->Table[2],1),"image/police/Takenoko.TTF",30,TTF_STYLE_BOLD,"<-",Blanc,270,H*4/11);

	prd_irrig->Table[0]->t=Creation_image(renderer,lire_Rect(prd_irrig->Table[0],1),image_prd_irrig,200,H*5/11,70,50);
	prd_irrig->Table[1]->t=Creation_image(renderer,lire_Rect(prd_irrig->Table[1],1),Select_prd_irrig,200,H*5/11,70,50);
	prd_irrig->Table[2]->t=Creation_Text(renderer,lire_Rect(prd_irrig->Table[2],1),"image/police/Takenoko.TTF",30,TTF_STYLE_BOLD,"<-",Blanc,270,H*5/11);

	prd_tuile->Table[0]->t=Creation_image(renderer,lire_Rect(prd_tuile->Table[0],1),image_prd_tuile,200,H*6/11,70,50);
	prd_tuile->Table[1]->t=Creation_image(renderer,lire_Rect(prd_tuile->Table[1],1),Select_prd_tuile,200,H*6/11,70,50);
	prd_tuile->Table[2]->t=Creation_Text(renderer,lire_Rect(prd_tuile->Table[2],1),"image/police/Takenoko.TTF",30,TTF_STYLE_BOLD,"<-",Blanc,270,H*6/11);

	prd_carte->Table[0]->t=Creation_image(renderer,lire_Rect(prd_carte->Table[0],1),image_prd_carte,200,H*7/11,70,50);
	prd_carte->Table[1]->t=Creation_image(renderer,lire_Rect(prd_carte->Table[1],1),Select_prd_carte,200,H*7/11,70,50);
	prd_carte->Table[2]->t=Creation_Text(renderer,lire_Rect(prd_carte->Table[2],1),"image/police/Takenoko.TTF",30,TTF_STYLE_BOLD,"<-",Blanc,270,H*7/11);


	(*Select_case->Table)->t=IMG_LoadTexture(renderer,"image/case/SelectCase.png");

	(*image->Table)->t = IMG_LoadTexture(renderer, fond_Plato);
	if((*image->Table)->t==NULL){
		fprintf ( stderr , " Erreur au niveau de l'image: %s \n " , TTF_GetError ());
		exit ( EXIT_FAILURE );
	}

	//affichage des joueurs
	for(int i=0;i<nbJoueur;i++){
		AffJoueur[i]=Crea_Tex(4);//normalement 13
		if(i%2!=0){
			if(i==3){
				(AffJoueur[i]->Table[0])->t=Creation_Text(renderer,lire_Rect(AffJoueur[i]->Table[0],1),"image/police/Takenoko.TTF",30,TTF_STYLE_BOLD,J[i]->nom_joueur,Blanc,W*3/4,H*8/11);
				(AffJoueur[i]->Table[1])->t=Creation_image(renderer,lire_Rect(AffJoueur[i]->Table[1],1),"image/en_plus/pionJaune.png",W*3/4,H*8/11+40,50,30);
				(AffJoueur[i]->Table[2])->t=Creation_image(renderer,lire_Rect(AffJoueur[i]->Table[2],1),"image/en_plus/pionRose.png",W*3/4+40,H*8/11+40,50,30);
				(AffJoueur[i]->Table[3])->t=Creation_image(renderer,lire_Rect(AffJoueur[i]->Table[3],1),"image/en_plus/pionVert.png",W*3/4+80,H*8/11+40,50,30);
			}
			else{
				(AffJoueur[i]->Table[0])->t=Creation_Text(renderer,lire_Rect(AffJoueur[i]->Table[0],1),"image/police/Takenoko.TTF",30,TTF_STYLE_BOLD,J[i]->nom_joueur,Blanc,W*3/4,0);
				(AffJoueur[i]->Table[1])->t=Creation_image(renderer,lire_Rect(AffJoueur[i]->Table[1],1),"image/en_plus/pionJaune.png",W*3/4,40,50,30);
				(AffJoueur[i]->Table[2])->t=Creation_image(renderer,lire_Rect(AffJoueur[i]->Table[2],1),"image/en_plus/pionRose.png",W*3/4+40,40,50,30);
				(AffJoueur[i]->Table[3])->t=Creation_image(renderer,lire_Rect(AffJoueur[i]->Table[3],1),"image/en_plus/pionVert.png",W*3/4+80,40,50,30);
			}
		}
		else{
			if(i==2){
				(AffJoueur[i]->Table[0])->t=Creation_Text(renderer,lire_Rect(AffJoueur[i]->Table[0],1),"image/police/Takenoko.TTF",30,TTF_STYLE_BOLD,J[i]->nom_joueur,Blanc,W*(3/4),H*8/11);
				(AffJoueur[i]->Table[1])->t=Creation_image(renderer,lire_Rect(AffJoueur[i]->Table[1],1),"image/en_plus/pionJaune.png",W*(3/4),H*8/11+40,50,30);
				(AffJoueur[i]->Table[2])->t=Creation_image(renderer,lire_Rect(AffJoueur[i]->Table[2],1),"image/en_plus/pionRose.png",W*(3/4)+40,H*8/11+40,50,30);
				(AffJoueur[i]->Table[3])->t=Creation_image(renderer,lire_Rect(AffJoueur[i]->Table[3],1),"image/en_plus/pionVert.png",W*(3/4)+80,H*8/11+40,50,30);
			}
			else{
				(AffJoueur[i]->Table[0])->t=Creation_Text(renderer,lire_Rect(AffJoueur[i]->Table[0],1),"image/police/Takenoko.TTF",30,TTF_STYLE_BOLD,J[i]->nom_joueur,Blanc,W*(3/4),0);
				(AffJoueur[i]->Table[1])->t=Creation_image(renderer,lire_Rect(AffJoueur[i]->Table[1],1),"image/en_plus/pionJaune.png",W*(3/4),40,50,30);
				(AffJoueur[i]->Table[2])->t=Creation_image(renderer,lire_Rect(AffJoueur[i]->Table[2],1),"image/en_plus/pionRose.png",W*(3/4)+40,40,50,30);
				(AffJoueur[i]->Table[3])->t=Creation_image(renderer,lire_Rect(AffJoueur[i]->Table[3],1),"image/en_plus/pionVert.png",W*(3/4)+80,40,50,30);
			}
		}
		if ((AffJoueur[i]->Table[0])->t == NULL){
			if(J[0]->nom_joueur!=NULL)
				printf("\t\tnom: %s\n",J[0]->nom_joueur);
			else
				printf("Il n'y as pas de nom\n");
			fprintf(stderr , " Erreur au niveau du Texte %s\n",TTF_GetError ());
			exit ( EXIT_FAILURE );
		}
	}
	//(AffJoueur->Table[1])->t=Creation_Text(renderer,lire_Rect(AffJoueur->Table[0],1),"image/police/Takenoko.TTF",60,TTF_STYLE_BOLD,"NbBambou = 0",Blanc,W*1/4,H*1/4);

	//initialisation des image du plato
	for(int ligne=0 ; ligne<NBTUILES ; ligne++){
		hexagonal[ligne] = Crea_Tex(NBTUILES);
		int posY;
		posY = H/2 + TAILTUILE* (ligne-LACPOS)*3/4-TAILTUILE*1/2;
		for(int colonne=0 ; colonne<NBTUILES ; colonne++){
			int posX;
			if(ligne%2)
				posX = W/2 + TAILTUILE*(colonne-LACPOS)+TAILTUILE/2;
			else
				posX = W/2 + TAILTUILE*(colonne-LACPOS);

			if(plateau[ligne][colonne]!=NULL){
				(hexagonal[ligne]->Table[colonne])->t= IMG_LoadTexture(renderer, plateau[ligne][colonne]->image);
			}
			else{
				if(!pose_tuile_impossible(ligne,colonne)){
					(hexagonal[ligne]->Table[colonne])->t = IMG_LoadTexture(renderer, contour_tuile);
				}
			}
			if((hexagonal[ligne]->Table[colonne])->t==NULL){
				fprintf ( stderr , " Erreur au niveau de l'image: %s \n " , TTF_GetError ());
				exit ( EXIT_FAILURE );
			}

			positionne_rect(lire_Rect((hexagonal[ligne]->Table[colonne]),1),
					posX,posY,TAILTUILE,TAILTUILE
			);
		}
	}

	Uint32 Clic,relache=0;
	while(1){
		Uint32 souris = SDL_GetMouseState(&x,&y);
		//création de la "fenêtre ou nous verons une partie de l'image
		SDL_RenderCopy(renderer,(*image->Table)->t,NULL,NULL);

		if(souris){
			relache=souris;
		}
		if(relache!=souris){
			relache=souris;
			Clic=1;
		}
		else
			Clic=0;

		if(bout(renderer,bouton,x,y) && Clic){
			image->det(image);
			Select_case->det(Select_case);
			fin_tour->det(fin_tour);
			Select_Map->det(Select_Map);
			Met_choix->det(Met_choix);
			Soleil->det(Soleil);
			Pluie->det(Pluie);
			Vent->det(Vent);
			Orage->det(Orage);
			Nuage->det(Nuage);
			bouton->det(bouton);
			Mov_pandas->det(Mov_pandas);
			Mov_jardi->det(Mov_jardi);
			prd_irrig->det(prd_irrig);
			prd_tuile->det(prd_tuile);
			prd_carte->det(prd_carte);
			for(int ligne=0;ligne<NBTUILES;ligne++){
				hexagonal[ligne]->det(hexagonal[ligne]);
			}
			for(int i=0;i<nbJoueur;i++){
				AffJoueur[i]->det(AffJoueur[i]);
			}
			if(NULL!=renderer)
				SDL_DestroyRenderer(renderer);
			if(NULL!=pWindow)
				SDL_DestroyWindow(pWindow);
			IMG_Quit();
			TTF_Quit();
			SDL_Quit();
			suprimer(nbJoueur);
			selecte_nb_joueur(W,H);
		}
		for(int i=0;i<nbJoueur;i++){
			for(int j=0;j<4;j++){
				SDL_RenderCopy(renderer,lire_Texture(AffJoueur[i]->Table[j]),NULL,lire_Rect(AffJoueur[i]->Table[j],1));
			}
		}

		if(!(victoirJ && compteur_tour==0)){
			if(!choix)
				meteo=rand()%7;
			int modif_Pos=0;
			switch (meteo){
					case soleil :
						SDL_RenderCopy(renderer,lire_Texture(Soleil->Table[1]),NULL,lire_Rect(Soleil->Table[1],1));
						SDL_RenderCopy(renderer,lire_Texture(Soleil->Table[2]),NULL,lire_Rect(Soleil->Table[2],1));
						SDL_RenderCopy(renderer,lire_Texture(Nuage->Table[0]),NULL,lire_Rect(Nuage->Table[0],1));
						SDL_RenderCopy(renderer,lire_Texture(Pluie->Table[0]),NULL,lire_Rect(Pluie->Table[0],1));
						SDL_RenderCopy(renderer,lire_Texture(Vent->Table[0]),NULL,lire_Rect(Vent->Table[0],1));
						SDL_RenderCopy(renderer,lire_Texture(Orage->Table[0]),NULL,lire_Rect(Orage->Table[0],1));
						limit_action ++;
						break;
					case pluie :
						SDL_RenderCopy(renderer,lire_Texture(Pluie->Table[1]),NULL,lire_Rect(Pluie->Table[1],1));
						SDL_RenderCopy(renderer,lire_Texture(Pluie->Table[2]),NULL,lire_Rect(Pluie->Table[2],1));
						SDL_RenderCopy(renderer,lire_Texture(Soleil->Table[0]),NULL,lire_Rect(Soleil->Table[0],1));
						SDL_RenderCopy(renderer,lire_Texture(Nuage->Table[0]),NULL,lire_Rect(Nuage->Table[0],1));
						SDL_RenderCopy(renderer,lire_Texture(Vent->Table[0]),NULL,lire_Rect(Vent->Table[0],1));
						SDL_RenderCopy(renderer,lire_Texture(Orage->Table[0]),NULL,lire_Rect(Orage->Table[0],1));
						//declancher_pluie();
						break;
					case vent :
						SDL_RenderCopy(renderer,lire_Texture(Vent->Table[1]),NULL,lire_Rect(Vent->Table[1],1));
						SDL_RenderCopy(renderer,lire_Texture(Vent->Table[2]),NULL,lire_Rect(Vent->Table[2],1));
						SDL_RenderCopy(renderer,lire_Texture(Soleil->Table[0]),NULL,lire_Rect(Soleil->Table[0],1));
						SDL_RenderCopy(renderer,lire_Texture(Nuage->Table[0]),NULL,lire_Rect(Nuage->Table[0],1));
						SDL_RenderCopy(renderer,lire_Texture(Pluie->Table[0]),NULL,lire_Rect(Pluie->Table[0],1));
						SDL_RenderCopy(renderer,lire_Texture(Orage->Table[0]),NULL,lire_Rect(Orage->Table[0],1));
						break;
					case orage :
						SDL_RenderCopy(renderer,lire_Texture(Orage->Table[1]),NULL,lire_Rect(Orage->Table[1],1));
						SDL_RenderCopy(renderer,lire_Texture(Orage->Table[2]),NULL,lire_Rect(Orage->Table[2],1));
						SDL_RenderCopy(renderer,lire_Texture(Soleil->Table[0]),NULL,lire_Rect(Soleil->Table[0],1));
						SDL_RenderCopy(renderer,lire_Texture(Nuage->Table[0]),NULL,lire_Rect(Nuage->Table[0],1));
						SDL_RenderCopy(renderer,lire_Texture(Pluie->Table[0]),NULL,lire_Rect(Pluie->Table[0],1));
						SDL_RenderCopy(renderer,lire_Texture(Vent->Table[0]),NULL,lire_Rect(Vent->Table[0],1));
						//orage_panda();
						break;
					case nuage :
						SDL_RenderCopy(renderer,lire_Texture(Nuage->Table[1]),NULL,lire_Rect(Nuage->Table[1],1));
						SDL_RenderCopy(renderer,lire_Texture(Nuage->Table[2]),NULL,lire_Rect(Nuage->Table[2],1));
						SDL_RenderCopy(renderer,lire_Texture(Soleil->Table[0]),NULL,lire_Rect(Soleil->Table[0],1));
						SDL_RenderCopy(renderer,lire_Texture(Pluie->Table[0]),NULL,lire_Rect(Pluie->Table[0],1));
						SDL_RenderCopy(renderer,lire_Texture(Vent->Table[0]),NULL,lire_Rect(Vent->Table[0],1));
						SDL_RenderCopy(renderer,lire_Texture(Orage->Table[0]),NULL,lire_Rect(Orage->Table[0],1));
						//choix_amenagement(J[i]);
						break;
					default:
						SDL_RenderCopy(renderer,lire_Texture(*Met_choix->Table),NULL,lire_Rect((*Met_choix->Table),1));
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
						break;
			}
			if(nb_action<limit_action)
			{
				if(bout(renderer,Mov_pandas,x,y)&&Clic)
					SDL_RenderCopy(renderer,lire_Texture(Mov_pandas->Table[2]),NULL,lire_Rect(Mov_pandas->Table[2],1));
			
				if(bout(renderer,Mov_jardi,x,y)&&Clic)
					SDL_RenderCopy(renderer,lire_Texture(Mov_jardi->Table[2]),NULL,lire_Rect(Mov_jardi->Table[2],1));
				
				if(bout(renderer,prd_carte,x,y)&&Clic)
					SDL_RenderCopy(renderer,lire_Texture(prd_carte->Table[2]),NULL,lire_Rect(prd_carte->Table[2],1));
				
				if(bout(renderer,prd_irrig,x,y)&&Clic)
					SDL_RenderCopy(renderer,lire_Texture(prd_irrig->Table[2]),NULL,lire_Rect(prd_irrig->Table[2],1));
			
				if(bout(renderer,prd_tuile,x,y)&&Clic)
					SDL_RenderCopy(renderer,lire_Texture(prd_tuile->Table[2]),NULL,lire_Rect(prd_tuile->Table[2],1));
					
			}
			else
			{
				SDL_RenderCopy(renderer,lire_Texture(Mov_pandas->Table[0]),NULL,lire_Rect(Mov_pandas->Table[0],1));
				SDL_RenderCopy(renderer,lire_Texture(Mov_jardi->Table[0]),NULL,lire_Rect(Mov_jardi->Table[0],1));
				SDL_RenderCopy(renderer,lire_Texture(prd_irrig->Table[0]),NULL,lire_Rect(prd_irrig->Table[0],1));
				SDL_RenderCopy(renderer,lire_Texture(prd_tuile->Table[0]),NULL,lire_Rect(prd_tuile->Table[0],1));
				SDL_RenderCopy(renderer,lire_Texture(prd_carte->Table[0]),NULL,lire_Rect(prd_carte->Table[0],1));
			}
			choix=1;
			if(UtMap==0){
				if(bout(renderer,Select_Map,x,y) && Clic){
					UtMap=1;
					positionne_rect(lire_Rect((Select_Map->Table[0]),1),
										lire_Rect(Select_Map->Table[0],1)->x+30,
										lire_Rect(Select_Map->Table[0],1)->y,
										30,30);
					positionne_rect(lire_Rect((Select_Map->Table[1]),1),
										lire_Rect(Select_Map->Table[1],1)->x+30,
										lire_Rect(Select_Map->Table[1],1)->y,
										30,30);
				}
			}
			if(UtMap==1){
				if(inv_bout(renderer,Select_Map,x,y) && Clic){
					UtMap=0;
					positionne_rect(lire_Rect((Select_Map->Table[0]),1),
										lire_Rect(Select_Map->Table[0],1)->x-30,
										lire_Rect(Select_Map->Table[0],1)->y,
										30,30);
					positionne_rect(lire_Rect((Select_Map->Table[1]),1),
										lire_Rect(Select_Map->Table[1],1)->x-30,
										lire_Rect(Select_Map->Table[1],1)->y,
										30,30);
				}
				if(souris){
					if(x!=new_x && y!=new_y){
						dif_x=x-new_x;
						dif_y=y-new_y;
						SDL_GetMouseState(&new_x,&new_y);
						modif_Pos=1;
					}
				}
			}
		//pose du tableau
			for(int ligne=0;ligne<NBTUILES;ligne++){
				for(int colone=0;colone<NBTUILES;colone++){
					if(modif_Pos){
						if(dif_x<0 && dif_y<=0)
							positionne_rect(lire_Rect((hexagonal[ligne]->Table[colone]),1),
									lire_Rect((hexagonal[ligne]->Table[colone]),1)->x-10,
									lire_Rect((hexagonal[ligne]->Table[colone]),1)->y-10,
									TAILTUILE,TAILTUILE);
						else if(dif_x>=0 && dif_y>0 )
							positionne_rect(lire_Rect((hexagonal[ligne]->Table[colone]),1),
									lire_Rect((hexagonal[ligne]->Table[colone]),1)->x+10,
									lire_Rect((hexagonal[ligne]->Table[colone]),1)->y+10,
									TAILTUILE,TAILTUILE);
						else if(dif_x>=0 && dif_y<0 )
							positionne_rect(lire_Rect((hexagonal[ligne]->Table[colone]),1),
									lire_Rect((hexagonal[ligne]->Table[colone]),1)->x+10,
									lire_Rect((hexagonal[ligne]->Table[colone]),1)->y-10,
									TAILTUILE,TAILTUILE);
						else if(dif_x<0 && dif_y>=0 )
							positionne_rect(lire_Rect((hexagonal[ligne]->Table[colone]),1),
									lire_Rect((hexagonal[ligne]->Table[colone]),1)->x-10,
									lire_Rect((hexagonal[ligne]->Table[colone]),1)->y+10,
									TAILTUILE,TAILTUILE);
					}
					if(newTail!=0){
						if(TAILTUILE+(newTail)<0)
							TAILTUILE=H/27;
						else if(TAILTUILE+(newTail)>200)
							TAILTUILE=200;
						else
							TAILTUILE=TAILTUILE+(newTail);
						int posY = H/2 - TAILTUILE * (ligne-LACPOS)*3/4;
						int posX = W/2 + TAILTUILE*(colone-LACPOS) + (ligne-LACPOS)*TAILTUILE*1/2;
						positionne_rect(lire_Rect((hexagonal[ligne]->Table[colone]),1),
								posX,
								posY,
								TAILTUILE,TAILTUILE);
						newTail=0;
					}
					SDL_RenderCopy(renderer,(hexagonal[ligne]->Table[colone])->t,NULL,lire_Rect((hexagonal[ligne]->Table[colone]),1));
					if(Select_hexa(renderer,(hexagonal[ligne]->Table[colone]),(*Select_case->Table),x,y)){
						if(!pose_tuile_impossible(ligne,colone)&& Clic){
						}
					}
				}
			}
		}
		//	if(victoire_joueur(J[compteur_tour],maxpoint))
		//		victoirJ=1;

			if(bout(renderer,fin_tour,x,y) && Clic){
				compteur_tour= (compteur_tour+1)%nbJoueur;
				choix=0;
			}
		//présentation final
		//pose joueur
		SDL_RenderPresent(renderer);
		if(SDL_PollEvent(&event)){
			if(evenment(event,pWindow,&fullscreen)==QUIT){
				if(fullscreen==1){
					SDL_SetWindowFullscreen(pWindow,0);
				}
				bouton->det(bouton);
				image->det(image);
				Select_case->det(Select_case);
				fin_tour->det(fin_tour);
				Select_Map->det(Select_Map);
				Met_choix->det(Met_choix);
				Soleil->det(Soleil);
				Pluie->det(Pluie);
				Vent->det(Vent);
				Orage->det(Orage);
				Nuage->det(Nuage);
				Mov_pandas->det(Mov_pandas);
				Mov_jardi->det(Mov_jardi);
				prd_irrig->det(prd_irrig);
				prd_tuile->det(prd_tuile);
				prd_carte->det(prd_carte);
				for(int ligne=0;ligne<NBTUILES;ligne++){
					hexagonal[ligne]->det(hexagonal[ligne]);
				}
				for(int i=0;i<nbJoueur;i++){
					AffJoueur[i]->det(AffJoueur[i]);
				}
				if(renderer!=NULL)
					SDL_DestroyRenderer(renderer);
				if(pWindow!=NULL)
					SDL_DestroyWindow(pWindow);
				IMG_Quit();
				TTF_Quit();
				SDL_Quit();
				suprimer(nbJoueur);
				exit(EXIT_SUCCESS);
			}
			if(event.type==SDL_MOUSEWHEEL){
				if(event.wheel.y>0)
					newTail--;
				else if (event.wheel.y<0)
					newTail++;
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

	SDL_Color Blanc = {255,255,255};

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


	bouton1->Table[0]->t=Creation_Text(renderer,lire_Rect(bouton1->Table[0],1),"image/police/Takenoko.TTF",60,TTF_STYLE_BOLD,"2 Joueur",Blanc,W*1/3,H*1/5);
	bouton1->Table[1]->t=Creation_Text(renderer,lire_Rect(bouton1->Table[1],1),"image/police/Takenoko.TTF",60,TTF_STYLE_BOLD|TTF_STYLE_UNDERLINE,"Select 2 J",Blanc,W*1/3,H*1/5);
	if ( bouton1->Table[0]->t == NULL||bouton1->Table[1]->t == NULL ){
		printf("\t\tJe n'arrive pas à charger bouton1\n");
		exit ( EXIT_FAILURE );
	}

	bouton2->Table[0]->t=Creation_Text(renderer,lire_Rect(bouton2->Table[0],1),"image/police/Takenoko.TTF",60,TTF_STYLE_BOLD,"3 Jouer",Blanc,W*1/3,H*1/5+H*1/9);
	bouton2->Table[1]->t=Creation_Text(renderer,lire_Rect(bouton2->Table[1],1),"image/police/Takenoko.TTF",60,TTF_STYLE_BOLD|TTF_STYLE_UNDERLINE,"Select 3 J",Blanc,W*1/3,H*1/5+H*1/9);
	if ( bouton2->Table[0]->t == NULL||bouton2->Table[1]->t == NULL ){
		printf("\t\tJe n'arrive pas à charger bouton2\n");
		exit ( EXIT_FAILURE );
	}

	bouton3->Table[0]->t=Creation_Text(renderer,lire_Rect(bouton3->Table[0],1),"image/police/Takenoko.TTF",60,TTF_STYLE_BOLD,"4 Joueur",Blanc,W*1/3,H*1/5+H*2/9);
	bouton3->Table[1]->t=Creation_Text(renderer,lire_Rect(bouton3->Table[1],1),"image/police/Takenoko.TTF",60,TTF_STYLE_BOLD|TTF_STYLE_UNDERLINE,"Select 4 J",Blanc,W*1/3,H*1/5+H*2/9);
	if ( bouton3->Table[0]->t == NULL||bouton3->Table[1]->t == NULL ){
		printf("\t\tJe n'arrive pas à charger bouton3\n");
		exit ( EXIT_FAILURE );
	}

	bouton4->Table[0]->t=Creation_Text(renderer,lire_Rect(bouton4->Table[0],1),"image/police/Takenoko.TTF",60,TTF_STYLE_BOLD,"<-Retour",Blanc,W*1/3,H*1/5+H*3/9);
	bouton4->Table[1]->t=Creation_Text(renderer,lire_Rect(bouton4->Table[1],1),"image/police/Takenoko.TTF",60,TTF_STYLE_BOLD|TTF_STYLE_UNDERLINE,"~Retour vers Le Menu~",Blanc,W*1/9,H*1/5+H*3/9);
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

