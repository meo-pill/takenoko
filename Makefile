CC=gcc
FLAGS=-Wall -g

POS=./bin
LIB=./lib

SDL_DIR=${LIB}/SDL2
SDL_LIB_DIR=${SDL_DIR}/lib
SDL_INC_DIR=${SDL_DIR}/include

LIBS=-L${SDL_LIB_DIR} -lSDL2 -lSDL2_image -lSDL2_ttf
INCS=-I${SDL_INC_DIR}
PROG=${POS}/affichage_SDL

all: clean tuto_SDL laungth
tuto_SDL: tuto_SDL.c
	${CC} -o ${PROG} tuto_SDL.c ${LIBS} ${INCS} ${FLAGS}
clean:
	rm -f ${PROG}
	rm -f *.o
laungth:
	./${PROG}
