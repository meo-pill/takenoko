// Mise en oeuvre d'une file d'entiers par pointeurs

#include "index.h"

file_t* tete;
file_t* queue;

void initfile(void){
	tete = NULL;
	queue = NULL;
}

int filevide(void){
	return tete == NULL;
}

void ajouter(case_plato_t * tuile){
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

void retirer(case_plato_t ** tuile){
file_t* premier;

	if(!filevide()){
		premier = tete;
		*tuile = premier->tuile;
		tete = premier->suivant;
		free(premier);
	}
}


