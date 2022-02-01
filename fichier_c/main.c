#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "../fichier_h/Board.h"
//#include "../fichier_h/struct.h"


int main(){
	SDL_Event event;
	int fullscreen=0,quit=0;
	if (SDL_Init(SDL_INIT_VIDEO) != 0 ){
		fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
		return -1;
	}
	else{
		SDL_Window* pWindow = NULL; //pointeur sur la fenêtre
		SDL_Surface *image=NULL;
		SDL_Renderer *renderer=NULL;
		pWindow = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED,
				700,
				600,
				SDL_WINDOW_MOUSE_FOCUS);//création de la fenêtre
		 if( pWindow ){
			 if((renderer = SDL_CreateRenderer(pWindow , -1, SDL_RENDERER_ACCELERATED))==NULL ){
					 fprintf(stderr , "Erreur a la creation du renderer\n");
					 exit(EXIT_FAILURE );
			}

			 SDL_RWops *rwop=SDL_RWFromFile("../image/Fond_menu.jpg", "rb");
			 image=IMG_LoadPNG_RW(rwop);
			 if(!image) {
				 printf("IMG_LoadPNG_RW: %s\n", IMG_GetError ());
			 }
			 SDL_Texture *image_tex = SDL_CreateTextureFromSurface(renderer , image);
			 if(! image_tex ){
				 fprintf(stderr , "Erreur a la creation du rendu de l’image : %s\n", SDL_GetError ());
				 exit(EXIT_FAILURE );
			 }
			 SDL_FreeSurface(image );
			 while (quit==0){
				 SDL_PollEvent(&event);//récupération des action de l'utilisateur
				 switch(event.type){
					case SDL_QUIT:quit=1;break;
					case SDL_KEYUP:
						      switch(event.key.keysym.sym){
							      case SDLK_q:
							      /**si touche q la fenètre ce ferme*/
							      	quit=1;
							      	break;
							      case SDLK_F11:
								/**si touche F11 la fêtre grande ou rétrici*/ 
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
				 }
			 }
		 }
		 SDL_DestroyWindow(pWindow);
			  //attendre 3 seconde que l'utilisateur voie la fenêtre
			  //avent de la détruire
	}
	
	SDL_Quit();


    return(0);
}