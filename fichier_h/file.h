#ifndef file_H_INCLUDED
#define file_H_INCLUDED

#include "index.h"

struct file_s{
	case_plato_t * tuile; 
	struct file_s * suivant;
};

void initfile(void);
void ajouter(case_plato_t * tuile);
void retirer(case_plato_t ** tuile);
int filevide(void);

#endif