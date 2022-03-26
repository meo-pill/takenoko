#include "../lib/commande.h"

extern quit_t evenment(SDL_Event event,SDL_Window* pWindow,int * fullscreen){
	 switch(event.type){
		case SDL_QUIT:
			if(*fullscreen==1)
				SDL_SetWindowFullscreen(pWindow,0);
			return QUIT;
			break;
		case SDL_KEYUP:
			switch(event.key.keysym.sym){
				case SDLK_q:
					if(*fullscreen==1){
						SDL_SetWindowFullscreen(pWindow,0);
					}
					return QUIT;
					break;
				case SDLK_F11:
				 	if(*fullscreen==0){
						SDL_SetWindowFullscreen(pWindow,SDL_WINDOW_FULLSCREEN);
						*fullscreen=1;
					 }
					else{
						SDL_SetWindowFullscreen(pWindow,0);
						*fullscreen=0;
					}
					break;
			}
			break;
		default:
			return CONT;
			break;
	 }
}
