#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "../fichier_h/Board.h"
//#include "../fichier_h/struct.h"


int main(){
	SDL_Event event;
	int fullscreen=0;
	//SDL_Rect imgDestRect;
	/*int flags=IMG_INIT_JPG|IMG_INIT_PNG;
	int initted=IMG_Init(flags);
	if((initted & flags) != flags) {
	    	printf("IMG_Init: Failed to init required jpg and png support!\n");
		printf("IMG_Init: %s\n", IMG_GetError());
		// handle error
	}*/
	if (SDL_Init(SDL_INIT_TIMER |SDL_INIT_VIDEO)== 0 ){
		SDL_Window* pWindow = NULL; //pointeur sur la fenêtre
		SDL_Surface *image2=NULL;
		SDL_Texture *image=NULL;
		SDL_Renderer *renderer=NULL;
		SDL_CreateWindowAndRenderer(
				 600, 569,
				 0, &pWindow, &renderer
		);
		IMG_Init(IMG_INIT_PNG);
		image = IMG_LoadTexture(renderer, "../image/Fond_menu.png");
		while (1) {
			SDL_RenderCopy(renderer, image, NULL, NULL);
			SDL_RenderPresent(renderer);
			if (SDL_PollEvent(&event)){
				 switch(event.type){
					case SDL_QUIT:
						exit(EXIT_FAILURE );
						break;
					case SDL_KEYUP:
						      switch(event.key.keysym.sym){
							      case SDLK_q:
							      /**si touche q la fenêtre ce ferme*/
								      exit(EXIT_FAILURE );
							      	break;
							      case SDLK_F11:
								/**si touche F11 la fenêtre grande ou rétrici*/ 
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
		 
		SDL_DestroyTexture(image);
		IMG_Quit();
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(pWindow);
	}
	else{
		fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
		return -1;
	}
	SDL_Quit();
	return(0);
}
