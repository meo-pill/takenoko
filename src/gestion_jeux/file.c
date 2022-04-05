#include "../../lib/file.h"

extern void initfile(void){
	file_tuile_tete = NULL;
	file_tuile_queue = NULL;
}

extern int filevide(void){
	return file_tuile_tete == NULL;
}

extern void ajouter(case_plato_t * tuile){
	file_t* nouv=malloc(sizeof(file_t));
	
	nouv->tuile = tuile;
	nouv->suivant = NULL;
	if(filevide())
		file_tuile_tete = nouv;
	else
		file_tuile_queue->suivant = nouv;
	file_tuile_queue = nouv;
}

extern case_plato_t * retirer(void){
	case_plato_t *tuile;
file_t* premier=NULL;

	if(!filevide()){
		premier = file_tuile_tete;
		tuile = premier->tuile;
		file_tuile_tete = premier->suivant;
		free(premier);
	}
	return tuile;
}

