CC=gcc
CCOBJ=${CC} -c
CFLAGS=-Wall 
FLAGS=-Wall -g
SDL_DIR=lib/SDL2
EXECU_DIR=bin
SDL_LIB_DIR=${SDL_DIR}/lib
SDL_INC_DIR=${SDL_DIR}/include
LIBS=-L${SDL_LIB_DIR} -lSDL2 -lSDL2_image -lSDL2_ttf
INCS=-I${SDL_INC_DIR}
PROG=Takenoko
GESTION=src/menu.c src/texture.c src/Creation.c  src/main.c #src/Option.c
OBJ=object/Plato.o object/menu.o
LIB=lib/menu.h lib/texture2.h lib/Creation.h  lib/Plato.h #lib/Option.hi

LIEN= ${PWD}/lib/SDL2/lib
DATE=$(shell date +%Y-%m-%d)

cache:all
all:clean ${PROG} laugth

${PROG}: ${OBJ} ${LIB}
	${CC} -o ${PROG} ${OBJ} ${LIBS} ${INCS} ${FLAGS}
object/menu.o:src/menu.c CREA.o
	${CCOBJ} ${CFLAGS} ${LIBS} ${INCS} src/menu.c CREA.o -o object/menu.o
object/Plato.o: src/Plato.c lib/Plato.h object/aff_table.o
	${CCOBJ} ${CFLAGS} ${LIBS} ${INCS} src/Plato.c object/aff_table.o -o object/Plato.o
object/aff_table.o: src/aff_table.c object/CREA.o object/init_fin.o object/file.o
	${CCOBJ} ${CFLAGS} ${LIBS} ${INCS} src/aff_table.c object/CREA.o object/init_fin.o object/file.o -o object/aff_table.o


object/CREA.o: src/Creation.c object/texture.o
	${CCOBJ} ${CFLAGS} ${LIBS} ${INCS} src/Creation.c object/texture.o -o object/CREA.o
object/texture.o: src/texture.c
	${CCOBJ} ${CFLAGS} ${LIBS} ${INCS} src/texture.c -o object/texture.o
object/carte.o:src/carte.c
	${CCOBJ} ${CFLAGS} src/carte.c -o object/carte.o
object/file.o: src/gestion_jeux/file.c
	${CCOBJ} ${CFLAGS} src/gestion_jeux/file.c -o object/file.o
object/fonction.o: src/gestion_jeux/fonction.c
	${CCOBJ} ${CFLAGS} src/gestion_jeux/fonction.c -o object/fonction.o
object/pose.o: src/gestion_jeux/pose.c
	${CCOBJ} ${CFLAGS} src/gestion_jeux/pose.c -o object/pose.o
object/init_fin.o:src/derouler_partie/init_fin.c
	${CCOBJ} ${CFLAGS} src/derouler_partie/init_fin.c -o object/init_fin.o
object/tour.o: src/derouler_partie/tour.c
	${CCOBJ} ${CFLAGS} src/derouler_partie/tour.c -o object/tour.o

#supression des fichier obeselette
clean:
	clear
	rm -r -f ${PROG}
	rm  -f object/*.o

#lancement du programme
laugth:
	./${PROG}
#commande git
PATH:
	export LD_LIBRARY_PATH="${LIEN}"
PULL:
	git pull
ADD:
	git add .
COM:
	git commit -m '${USER} ${DATE}  mise à jour'
ME:
	git push origin mewen
LE:
	git push origin leo
MA:
	git push origin maxime
MO:
	git push origin fortuna
TEST:
	${CC} -o prog_test test.c  src/texture.c src/Creation.c ${LIBS} ${INCS} ${FLAGS}
