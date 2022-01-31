// Mise en oeuvre d'une file d'entiers par pointeurs

#include "../fichier_h/file.h"

t_file* tete;
t_file* queue;

void initfile(void){
	tete = NULL;
	queue = NULL;
}

int filevide(void){
	return tete == NULL;
}

void ajouter(int v){
	t_file* nouv;

	nouv = malloc(sizeof(t_file));
	nouv->nombre = v;
	nouv->suivant = NULL;
	if(filevide())
		tete = nouv;
	else
		queue->suivant = nouv;
	queue = nouv;
}

void retirer(int* v){
t_file* premier;

	if(!filevide()){
		premier = tete;
		*v = premier->nombre;
		tete = premier->suivant;
		free(premier);
	}
}


