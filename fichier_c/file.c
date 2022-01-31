// Mise en oeuvre d'une file d'entiers par pointeurs

#include "index.h"

extern void initfile(void){
	tete = NULL;
	queue = NULL;
}

extern int filevide(void){
	return tete == NULL;
}

extern void ajouter(case_plato_t * tuile){
	file_t* nouv;

	nouv = malloc(sizeof(file_t));
	nouv->tuile = tuile;
	nouv->suivant = NULL;
	if(filevide())
		tete = nouv;
	else
		queue->suivant = nouv;
	queue = nouv;
}

extern void retirer(case_plato_t ** tuile){
file_t* premier;

	if(!filevide()){
		premier = tete;
		*tuile = premier->tuile;
		tete = premier->suivant;
		free(premier);
	}
}


