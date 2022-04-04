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

OBJ=object/Plato.o object/menu.o object/CREA.o object/texture.o object/carte.o object/file.o object/init_fin.o object/commande.o object/pioche.o object/pose.o
LIB=lib/menu.h lib/texture2.h lib/Creation.h  lib/Plato.h #lib/Option.hi
TEST= bin/carte_test bin/creation_carte_test bin/plateau_test bin/sdl_test bin/test_affichage_Plato bin/test_fct bin/test_init bin/test_rand bin/test_shuffle bin/test


LIEN= ${PWD}/lib/SDL2/lib
DATE=$(shell date +%Y-%m-%d)

cache:ProgFinal
all: mr_proper ${PROG} ${TEST}
ProgFinal:clean ${PROG} laugth

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
object/test_rand.o: test/test_rand.c
	${CCOBJ} ${CFLAGS} ${LIBS} ${INCS} test/test_rand.c -o $@
object/carte.o:src/carte.c lib/carte.h
	${CCOBJ} ${CFLAGS} src/carte.c -o $@
object/file.o: src/gestion_jeux/file.c lib/file.h
	${CCOBJ} ${CFLAGS}  src/gestion_jeux/file.c -o $@
object/fonction.o: src/gestion_jeux/fonction.c lib/fonction.h
	${CCOBJ} ${CFLAGS} src/gestion_jeux/fonction.c -o $@Z
object/init_fin.o:src/derouler_partie/init_fin.c lib/init_fin.h 
	${CCOBJ} ${CFLAGS} src/derouler_partie/init_fin.c -o $@
object/tour.o: src/derouler_partie/tour.c 
	${CCOBJ} ${CFLAGS} src/derouler_partie/tour.c -o $@
object/carte_pioche_test.o: test/carte_pioche_test.c
	${CCOBJ} ${CFLAGS}  test/carte_pioche_test.c -o $@
object/pioche.o : src/gestion_jeux/pioche.c
	${CCOBJ} ${CFLAGS}  src/gestion_jeux/pioche.c -o $@
object/pose.o : src/gestion_jeux/pose.c
	${CCOBJ} ${CFLAGS} src/gestion_jeux/pose.c -o $@
object/test_creation_carte.o: test/test_creation_carte.c
	${CCOBJ} ${CFLAGS} test/test_creation_carte.c  -o $@

#test des fonction du jeux
test_Maxime: test/test_fonc.c object/fonction.o 
	${CC} -o bin/test_Maxime test/test_fonc.c object/fonction.o ${FLAGS}
bin/creation_carte_test:object/carte.o object/test_creation_carte.o object/init_fin.o object/file.o object/pioche.o
	${CC} -o bin/test_creation_carte object/carte.o object/test_creation_carte.o object/init_fin.o object/file.o object/pioche.o ${FLAGS}

test_carte: object/carte.o test/carte_test.o object/init_fin.o object/file.o object/pioche.o
	${CC} -o bin/test_carte object/carte.o test/carte_test.o object/init_fin.o object/file.o object/pioche.o ${FLAGS}

carte_pioche_test: object/carte.o object/carte_pioche_test.o object/init_fin.o object/file.o object/pioche.o object/pose.o
	${CC} -o bin/carte_pioche_test object/pose.o object/carte.o object/carte_pioche_test.o object/init_fin.o object/pioche.o object/file.o ${FLAGS}

object/carte_test.o: test/carte_test.c
	${CCOBJ} ${CFLAGS} test/carte_test.c -o $@
bin/carte_test:object/carte.o object/carte_test.o object/init_fin.o object/file.o object/pioche.o
	${CC} -o bin/carte_test object/carte.o object/carte_test.o object/init_fin.o object/file.o object/pioche.o ${FLAGS}

test_aff:test/test_affichage_Plato.c object/aff_table.o object/CREA.o object/texture.o  object/file.o object/carte.o object/init_fin.o object/commande.o
	${CC} -o bin/$@ test/test_affichage_Plato.c object/aff_table.o object/CREA.o object/texture.o  object/file.o object/carte.o object/init_fin.o object/commande.o object/pioche.o ${LIBS} ${INCS} ${FLAGS}
	
test_rand:object/test_rand.o
	${CC} -o bin/$@ object/test_rand.o ${LIBS} ${INCS} ${FLAGS}

#supression des fichier obeselette
clean:
	clear
	rm -r -f ${PROG}
	rm  -f object/*.o
mr_proper:
	make clean
	rm -r -f ${TEST}

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
	make clean
	make ADD
	make COM
	git push origin meo
LE:
	make clean
	make ADD
	make COM
	git push origin leopolde
MA:
	make clean
	make ADD
	make COM
	git push origin max
MO:
	make clean
	make ADD
	make COM
	git push origin Morgane
TEST:
	echo > $@
