#ifndef file_H_INCLUDED
#define file_H_INCLUDED

#include "index.h"

typedef struct file {
	int nombre; 
	struct file* suivant;
} t_file;

void initfile(void);
void ajouter(int v);
void retirer(int* v);
int filevide(void);

#endif