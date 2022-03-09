CC=gcc
FLAGS=-Wall -g
SDL_DIR=lib/SDL2
EXECU_DIR=bin
SDL_LIB_DIR=${SDL_DIR}/lib
SDL_INC_DIR=${SDL_DIR}/include
LIBS=-L${SDL_LIB_DIR} -lSDL2 -lSDL2_image -lSDL2_ttf
INCS=-I${SDL_INC_DIR}
PROG=Takenoko
GESTION=src/Creation.c src/menu.c src/Option.c src/main.c src/texture.c
LIB=lib/Creation.h lib/menu.h lib/Option.h lib/texture.h

cache:all
all:clean ${PROG} laugth

${PROG}: ${GESTION} ${LIB}
	${CC} -o ${PROG} ${GESTION} ${LIBS} ${INCS} ${FLAGS}
clean:
	clear
	rm -f ${PROG}
	rm -f *.o
PATH:
	export LD_LIBRARY_PATH="${PWD}/lib/SDL2/lib"
PULL:
	git pull
COM:
	git commit -m 'mise à jour'
PUSH:
	git push origin fortuna
ADD:
	git add .
laugth:
	./${PROG}
