CC=gcc
FLAGS=-Wall -g
SDL_DIR=lib/SDL2
EXECU_DIR=bin
SDL_LIB_DIR=${SDL_DIR}/lib
SDL_INC_DIR=${SDL_DIR}/include
LIBS=-L${SDL_LIB_DIR} -lSDL2 -lSDL2_image -lSDL2_ttf
INCS=-I${SDL_INC_DIR}
PROG=Takenoko
GESTION=src/Creation.c src/menu.c src/fenetre.c src/main.c
LIB_OBJET=lib/Creation.h lib/menu.h lib/fenetre.h
OBJET_O=Creation.o menu.o fenetre.o

cache:all
all:clean ${PROG} laugth

${PROG}: ${GESTION}
	${CC} -o ${PROG} ${GESTION} ${LIBS} ${INCS} ${FLAGS}
clean:
	clear
	rm -f ${PROG}
	rm -f *.o
PATH:
	export LD_LIBRARY_PATH="/media/${USER}/Cours/université/L2/2/projet/takenoko/lib/SDL2/lib"
PUSH:
	git push origin master
laugth:
	git add .
	./${PROG}
