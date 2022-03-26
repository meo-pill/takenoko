include Makefile.compilation
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
OBJ=object/Plato.o object/menu.o object/aff_table.o object/CREA.o object/texture.o object/carte.o object/file.o object/init_fin.o object/commande.o
LIB=lib/menu.h lib/texture2.h lib/Creation.h  lib/Plato.h #lib/Option.hi

LIEN= ${PWD}/lib/SDL2/lib
DATE=$(shell date +%Y-%m-%d)

cache:all
all:clean ${PROG} laugth

#Compilation du programme final
${PROG}: ${OBJ} ${LIB}
	${CC} -o $@ ${OBJ} src/main.c ${LIBS} ${INCS} ${FLAGS}

#compilation des objets
object/menu.o: src/menu.c lib/menu.h
	${CCOBJ} ${CFLAGS} ${LIBS} ${INCS} src/menu.c -o $@
object/Plato.o: src/Plato.c lib/Plato.h
	${CCOBJ} ${CFLAGS} ${LIBS} ${INCS} src/Plato.c -o $@
object/aff_table.o: src/aff_table.c lib/aff_table.h
	${CCOBJ} ${CFLAGS} ${LIBS} ${INCS} src/aff_table.c -o $@
object/CREA.o: src/Creation.c lib/Creation.h
	${CCOBJ} ${CFLAGS} ${LIBS} ${INCS} src/Creation.c -o $@
object/texture.o: src/texture.c lib/texture2.h
	${CCOBJ} ${CFLAGS} ${LIBS} ${INCS} src/texture.c -o $@
object/commande.o: src/commande.c lib/commande.h
	${CCOBJ} ${CFLAGS} ${LIBS} ${INCS} src/commande.c -o $@
object/carte.o:src/carte.c lib/carte.h
	${CCOBJ} ${CFLAGS} src/carte.c -o $@
object/file.o: src/gestion_jeux/file.c lib/file.h
	${CCOBJ} ${CFLAGS}  src/gestion_jeux/file.c -o $@
object/fonction.o: src/gestion_jeux/fonction.c lib/fonction.h
	${CCOBJ} ${CFLAGS} src/gestion_jeux/fonction.c -o $@
object/pose.o: src/gestion_jeux/pose.c lib/pose.h
	${CCOBJ} ${CFLAGS} src/gestion_jeux/pose.c -o $@
object/init_fin.o:src/derouler_partie/init_fin.c lib/init_fin.h
	${CCOBJ} ${CFLAGS} src/derouler_partie/init_fin.c -o $@
object/tour.o: src/derouler_partie/tour.c 
	${CCOBJ} ${CFLAGS} src/derouler_partie/tour.c -o $@

#test des fonction du jeux
test_Maxime: test/test_fonc.c object/fonction.o 
	${CC} -o bin/test_Maxime test/test_fonc.c object/fonction.o ${FLAGS}
test_creation_carte:object/carte.o test/test_cration_carte.o object/init_fin.o object/file.o
	${CC} -o bin/test_creation_carte object/carte.o test/test_cration_carte.o object/init_fin.o object/file.o ${FLAGS}

test_carte: object/carte.o test/carte_test.o object/init_fin.o object/file.o
	${CC} -o bin/test_carte object/carte.o test/carte_test.o object/init_fin.o object/file.o ${FLAGS}

object/carte_test.o: test/carte_test.c
	${CCOBJ} ${CFLAGS} test/carte_test.c -o $@
carte_test:object/carte.o object/carte_test.o object/init_fin.o object/file.o
	${CC} -o bin/carte_test object/carte.o object/carte_test.o object/init_fin.o object/file.o ${FLAGS}

object/test_cration_carte.o: test/test_cration_carte.c
	 ${CCOBJ} ${CFLAGS} test/test_cration_carte.c  -o object/test_cration_carte.o
test_aff:test/test_affichage_Plato.c object/aff_table.o object/CREA.o object/texture.o  object/file.o object/carte.o object/init_fin.o object/commande.o
	${CC} -o bin/$@ test/test_affichage_Plato.c object/aff_table.o object/CREA.o object/texture.o  object/file.o object/carte.o object/init_fin.o object/commande.o ${LIBS} ${INCS} ${FLAGS}
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
	git push origin meo
LE:
	git push origin leopolde
MA:
	git push origin max
MO:
	make clean
	make ADD
	make COM
	git push origin Morgane
TEST:
	echo > $@
