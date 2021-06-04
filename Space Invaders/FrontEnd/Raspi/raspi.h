/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   raspi.h
 * Author: mpaget
 *
 * Created on February 21, 2021, 11:21 AM
 */

#ifndef RASPI_H
#define RASPI_H

#include "joydrv.h"
#include "disdrv.h"
//#include "libaudio.h"
#include "fondos.h"
#include "objects.h"
#include "caracteres.h"
#include "../../BackEnd/barriers.h"
#include "../../BackEnd/spaceship.h"
#include "../../BackEnd/randomalien.h"

//ver si esta bien esto
#include "../../BackEnd/highscore.h"


//Estados del MENU
enum { MENU = 0, PLAY, HIGHSCORE, EXIT, ERROR };

//Estados del MENU DE PAUSA
enum {NOTHING = 0, MENU_PAUSE, PLAY_PAUSE, EXIT_PAUSE, ERROR_PAUSE};

#ifdef RASPI
	typedef struct {
		int state;
	}graphics_t

/**********************************************************************************
 * Función: initGraphics                                                          *
 * Esta función se encarga de inicializar a la RPi y sus variables.				  *
 **********************************************************************************/
int initGraphics(graphics_t* allegro);

/**********************************************************************************
 * Función: destroyGraphics                                                       *
 * Esta función se encarga de destruir todo lo necesario relacionado con la RPi	  *
 **********************************************************************************/
 int destroyGraphics(graphics_t* allegro);

/**********************************************************************************
 * Función: printMenu                                                             *
 * Esta función se encarga de imprimir el menu en el display de la Raspberry Pi.  *
 **********************************************************************************/
void printMenu(graphics_t* graphics);

/**********************************************************************************
 * Función: stateMenu                                                             *
 * Esta función se encarga de fijarse si cambio el estado del menu.				  *
 * Devuelve un int con el nuevo estado.											  *
 **********************************************************************************/
int stateMenu(graphics_t* graphics);

/**********************************************************************************
 * Función: updateGraphics                                                        *
 * Esta función se encarga de realizar un update del front end.					  *
 **********************************************************************************/
void updateGraphics();

/**********************************************************************************
 * Función: printSpaceInvaders                                                    *
 * Esta función se encarga de imprimir todos los objetos del juego en caso de ser *
 * necesarios.																	  *
 **********************************************************************************/
void printSpaceInvaders(graphics_t* graphics, alien_t* aliens, barriers_t* barriers, spaceship_t* spaceship, alienRandom_t* rAlien);

/**********************************************************************************
 * Función: clearSpaceInvaders                                                    *
 * Esta función se encarga de hacer los clears de todos los objetos que lo		  *
 * necesiten.																	  *
 **********************************************************************************/
void clearSpaceInvaders(graphics_t* graphics, alien_t* aliens, barriers_t* barriers, spaceship_t* spaceship, alienRandom_t* rAlien);
//Se fija si apretaron algo nuevo o si movieron la nave. 

/**********************************************************************************
 * Función: getEvent                                                              *
 * Esta función se encarga de chequear si ocurrio algun evento nuevo.			  *
 * Devuelve un int con el tipo de evento ocurrido.								  *
 **********************************************************************************/
int getEvent(graphics_t* graphics);

/**********************************************************************************
 * Función: printHighscore														  *
 * Esta función se encarga de imprimir la tabla de highscore					  *
 **********************************************************************************/
int printHighscore(player_t highscores[SCORES_NUM])
#endif

#endif /* RASPI_H */

