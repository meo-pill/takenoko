#ifndef _COMMANDE_H_
#define _COMMANDE_H_
#include "bibl_SDL.h"
#define QUIT -1
#define CONT 1
/*!
 * \author Morgane Pechon
 * \file commande.h
 * \brief gère les differentes commande
*/
/*! \brief permet de convertir le type int en quit_t et savoir s'il faut quitter ou non
 * \typedef quit_t
 */
typedef int quit_t;

/*! \brief permet de gérer les evenement du clavier
 * \param event : permet de lire les evenements
 * \param pWindow : permet de gerer l'écrant
 * \param fullscreen : permet de mettre en plienne écrant
 */
extern quit_t evenment( SDL_Event event,SDL_Window* pWindow,int * fullscreen);
#endif
