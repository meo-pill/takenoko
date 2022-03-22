#include "../lib/commande.h"

extern qui_t evenment(SDL_Event event,SDL_Window* pWindow){
	int fullscreen=0;
	 switch(event.type){
		case SDL_QUIT:
			if(fullscreen==1){
				SDL_SetWindowFullscreen(pWindow,0);
			}
			return QUIT;
		case SDL_KEYUP:
			switch(event.key.keysym.sym){
				case SDLK_q:
					if(fullscreen==1){
						SDL_SetWindowFullscreen(pWindow,0);
					}
					return QUIT;
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
	 return CONT;
}
