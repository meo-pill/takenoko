#ifndef file_H_INCLUDED
#define file_H_INCLUDED

#include "index.h"

struct file_s{
	case_plato_t * tuile; 
	struct file_s * suivant;
};

extern void initfile(void);
extern void ajouter(case_plato_t * tuile);
extern case_plato_t * retirer(void);
extern int filevide(void);

#endif
