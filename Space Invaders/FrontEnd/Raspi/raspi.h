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
#include "../../BackEnd/aliens.h"

//ver si esta bien esto
#include "../../BackEnd/highscore.h"

//Estados del juego
enum { NOTHING = 0, SS_BULLET, SS_MOVE_R, SS_MOVE_L, PAUSE, EXIT };
enum { MENU_GR = 0, PLAY_GR, HIGHSCORE_GR, EXIT_GR, FONDO_GR, SPACEINVADERS_GR };
//Estados del MENU
enum { MENU = 0, PLAY, HIGHSCORE, EXIT_M, ERROR };
//Estados del MENU DE PAUSA
enum { MENU_PAUSE = 1, PLAY_PAUSE, EXIT_PAUSE, ERROR_PAUSE };

#ifdef RASPI
typedef struct {
	int state;
}graphics_t;

/**********************************************************************************
 * Función: initGraphics                                                          *
 * Esta función se encarga de inicializar a la RPi y sus variables.				  *
 **********************************************************************************/
int initGraphics(graphics_t* allegro);

/**********************************************************************************
 * Función: destroyGraphics                                                       *
 * Esta función se encarga de destruir todo lo necesario relacionado con la RPi	  *
 **********************************************************************************/
 void destroyGraphics(graphics_t* allegro);

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
void printSpaceInvaders(graphics_t* graphics, player_t* player, alien_t* aliens, barriers_t* barriers, spaceship_t* spaceship, alienRandom_t* rAlien, int level, int frames);
//Se fija si apretaron algo nuevo o si movieron la nave. 

/**********************************************************************************
 * Función: getEvent                                                              *
 * Esta función se encarga de chequear si ocurrio algun evento nuevo.			  *
 * Devuelve un int con el tipo de evento ocurrido.								  *
 **********************************************************************************/
int getEvent(graphics_t graphics);

/**********************************************************************************
 * Función: printHighscore														  *
 * Esta función se encarga de imprimir la tabla de highscore					  *
 **********************************************************************************/
int printHighscore(player_t highscores[MAXSCORES]);

void printGameOver(graphics_t* graphics);
void printPause(graphics_t* graphics);
int statePause(graphics_t* graphics);

void read_keyboard(player_t* player, graphics_t* graphics);
int print_scores(graphics_t* graphics, player_t lista_scores[MAXSCORES]);
void clearSpaceInvaders(void);

#endif

#endif /* RASPI_H */

