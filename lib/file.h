/**
 * @file file.h
 * @author MEWEN
 * @brief mise en oeuvre de la file
 * @version 0.1
 * @date 2022-04-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef file_H_INCLUDED
#define file_H_INCLUDED

#include "index.h"

/**
 * @brief structure de mise de la file
 * 
 */
struct file_s{
	case_plato_t * tuile; 
	struct file_s * suivant;
};

/**
 * @brief fonction d'initialisation de la file
 * 
 */
extern void initfile(void);

/**
 * @brief fonction d'ajout d'une tuile dans la file
 * 
 * @param tuile poiteur sur une tuile a metre en file
 */
extern void ajouter(case_plato_t * tuile);

/**
 * @brief fonction permet de retire une tuile de la file
 * 
 * @return case_plato_t* retourne un poiteur sur tuile
 */
extern case_plato_t * retirer(void);

/**
 * @brief fonction booléne de validation sur la contenance de la file
 * 
 * @return int boolene de validation sur la contenace
 */
extern int filevide(void);

#endif
