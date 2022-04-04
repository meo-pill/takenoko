#include "../lib/index.h"
#include "../lib/bibl_SDL.h"
 

void  fonction (void * user_data, Uint8 * stream, int len){

	int samples = len / sizeof(float); // 4096

   	for (int i = 0; i < samples; i++)
        	stream[i] = 0.5 * SDL_sinf(2 * M_PI * i / 1000);
}


int main(){
    SDL_Init(SDL_INIT_AUDIO);

    SDL_AudioSpec aud,have;
    SDL_AudioDeviceID carte_son ;

    SDL_memset(&aud, 0, sizeof(aud));

    aud.freq = 44100;
    aud.format = AUDIO_F32SYS;
    aud.channels = 1;
    aud.samples = 4096;
    aud.userdata = NULL;
    aud.callback = fonction;

    carte_son = SDL_OpenAudioDevice(NULL, 0, &aud, &have, SDL_AUDIO_ALLOW_FORMAT_CHANGE);

    SDL_PauseAudioDevice(carte_son,0);

    while(1);
    
    return 0;
    
}
