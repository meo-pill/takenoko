CC=gcc
FLAGS=-Wall -g

SDL_DIR=./lib/SDL2

LIBS=-L${SDL_LIB_DIR} -lSDL2
INCS=-I${SDL_INC_DIR}
PROG=affichage_SDL

all: clean tuto_SDL laungth
tuto_SDL: tuto_SDL.c
	${CC} -o ${PROG} tuto_SDL.c ${LIBS} ${INCS} ${FLAGS}
clean:
	rm -f ${PROG}
	rm -f *.o
laungth:
	./${PROG}
