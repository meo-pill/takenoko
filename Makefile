include Makefile.compilation

SDL_DIR=lib/SDL2
EXECU_DIR=bin

SDL_LIB_DIR=${SDL_DIR}/lib
SDL_INC_DIR=${SDL_DIR}/include

LIBS=-L${SDL_LIB_DIR} -lSDL2 -lSDL2_image -lSDL2_ttf
INCS=-I${SDL_INC_DIR}

PROG=Takenoko
GESTION=src/menu.c src/texture.c src/Creation.c  src/main.c src/Option.c src/Plato.c src/commande.c src/carte.c src/aff_table.c src/gestion_jeux/file.c src/gestion_jeux/fonction.c src/gestion_jeux/pioche.c src/gestion_jeux/pose.c src/derouler_partie/init_fin.c src/derouler_partie/tour.c
OBJ=object/Plato.o object/menu.o object/aff_table.o object/CREA.o object/texture.o object/carte.o object/file.o object/init_fin.o
LIB=lib/menu.h lib/texture2.h lib/Creation.h  lib/Plato.h #lib/Option.hi
TEST= bin/carte_test bin/creation_carte_test bin/plateau_test bin/sdl_test bin/test_affichage_Plato bin/test_fct bin/test_init bin/test_rand bin/test_shuffle bin/test

LIEN= ${PWD}/lib/SDL2/lib
DATE=$(shell date +%Y-%m-%d)

cache:all
all:${PROG} laugth

#Compilation du programme final
${PROG}: ${OBJ} ${LIB}
	${CCLNK} -o $@ ${OBJ} ${LIBS} ${INCS} ${CFLAGS}

#compilation des objets
object/main.o: src/main.c 
	${CCOBJ} ${CFLAGS} ${LIBS} ${INCS} src/main.c -o $@
object/menu.o: src/menu.c
	${CCOBJ} ${CFLAGS} ${LIBS} ${INCS} src/menu.c -o $@
object/Plato.o: src/Plato.c
	${CCOBJ} ${CFLAGS} ${LIBS} ${INCS} src/Plato.c -o $@
object/aff_table.o: src/aff_table.c
	${CCOBJ} ${CFLAGS} ${LIBS} ${INCS} src/aff_table.c -o $@
object/CREA.o: src/Creation.c
	${CCOBJ} ${CFLAGS} ${LIBS} ${INCS} src/Creation.c -o $@
object/texture.o: src/texture.c
	${CCOBJ} ${CFLAGS} ${LIBS} ${INCS} src/texture.c -o $@
object/carte.o:src/carte.c
	${CCOBJ} ${CFLAGS} src/carte.c -o $@
object/file.o: src/gestion_jeux/file.c
	${CCOBJ} ${CFLAGS}  src/gestion_jeux/file.c -o $@
object/fonction.o: src/gestion_jeux/fonction.c
	${CCOBJ} ${CFLAGS} src/gestion_jeux/fonction.c -o $@
object/pose.o: src/gestion_jeux/pose.c
	${CCOBJ} ${CFLAGS} src/gestion_jeux/pose.c -o $@
object/init_fin.o:src/derouler_partie/init_fin.c
	${CCOBJ} ${CFLAGS} src/derouler_partie/init_fin.c -o $@
object/tour.o: src/derouler_partie/tour.c
	${CCOBJ} ${CFLAGS} src/derouler_partie/tour.c -o $@


#test des fonction du jeux

test_creation_carte:object/carte.o test/test_cration_carte.o object/init_fin.o object/file.o
	${CCLNK} -o bin/$@ object/carte.o test/test_cration_carte.o object/init_fin.o object/file.o ${FLAGS}

test_carte: object/carte.o test/carte_test.o object/init_fin.o object/file.o
	${CCLNK} -o bin/$@ object/carte.o test/carte_test.o object/init_fin.o object/file.o ${FLAGS}

object/carte_test.o: test/carte_test.c
	${CCOBJ} ${CFLAGS} test/carte_test.c -o $@
carte_test:object/carte.o object/carte_test.o object/init_fin.o object/file.o
	${CCLNK} -o bin/$@ object/carte.o object/carte_test.o object/init_fin.o object/file.o ${FLAGS}

object/test_cration_carte.o: test/test_cration_carte.c
	 ${CCOBJ} ${CFLAGS} test/test_cration_carte.c  -o $@
test_aff:test/test_affichage_Plato.c object/aff_table.o object/CREA.o object/texture.o  object/file.o object/carte.o object/init_fin.o
	${CCLNK} -o bin/$@ test/test_affichage_Plato.c object/aff_table.o object/CREA.o object/texture.o  object/file.o object/carte.o object/init_fin.o ${LIBS} ${INCS} ${FLAGS}

#supression des fichier obeselette
clean: mr_proper
	clear
	rm -r -f ${PROG}
mr_proper:
	rm -f object/*.o
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
	git push origin meo
LE:
	git push origin leopolde
MA:
	git push origin max
MO:
	git push origin fortuna
TEST:
	echo > $@
