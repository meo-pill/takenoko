CC=gcc
FLAGS=-Wall -g
SDL_DIR=lib/SDL2
SDL_LIB_DIR=${SDL_DIR}/lib
SDL_INC_DIR=${SDL_DIR}/include
LIBS=-L${SDL_LIB_DIR} -lSDL2 -lSDL2_image -lSDL2_ttf
INCS=-I${SDL_INC_DIR}
PROG=bin/Takenoko
FENETRE=bin/fenetre.o
CREATION:=bin/Creation.o
MENU=bin/menu.o
cache:all
all:clean ${PROG} laugth
${PROG}: src/main.c  ${CREATION} ${FENETRE} ${MENU}
	${CC} -o ${PROG} src/main.c ${CREATION} ${FENETRE} ${MENU} ${LIBS} ${INCS} ${FLAGS}
${FENETRE}:src/fenetre.c lib/fenetre.h 
	${CC} -c src/fenetre.c ${LIBS} ${INCS} ${FLAGS}
${CREATION}:src/Creation.c lib/Creation.h
	${CC} -c src/Creation.c ${LIBS} ${INCS} ${FLAGS}
${MENU}:src/menu.c lib/menu.h
	${CC} -c src/menu.c ${LIBS} ${INCS} ${FLAGS}
clean:
	clear
	rm -f ${PROG}
	rm -f *.o
PATH:
	export LD_LIBRARY_PATH="/media/USER/Cours/université/L2/2/projet/takenoko/lib/SDL2/lib"
PUSH:
	git push origin master
USER:
	echo $USER
laugth:
	git add .
	./${PROG}
