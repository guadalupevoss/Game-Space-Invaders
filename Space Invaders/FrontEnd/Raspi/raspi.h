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
#include "../../BackEnd/bullet.h"
#include "../../BackEnd/barriers.h"
#include "../../BackEnd/spaceship.h"
#include "../../BackEnd/randomalien.h"


//Tamano del display
#define SCREEN_W 16
#define SCREEN_H 16

#define MOVE_RATE       5.0 //Para el movimiento

//Defines de la nave
#define NAVE_SIZE_X 3
#define NAVE_SIZE_Y 2
#define SPACESHIP_POS_Y SCREEN_H-1
#define INITIAL_SPASESHIP_POS_X SCREEN_W/2 
#define SPACESHIP_LIVES 3

//Defines de los aliens
#define CANTIDAD_ALIENS 18 //Cantidad maxima de aliens
#define ALIEN_SIZE_X 1
#define ALIEN_SIZE_Y 1
#define DISTANCIA_ALIENS_X  2  //DISTANCIA ENTRE ALIEN Y ALIEN EN X.
#define DISTANCIA_ALIENS_Y  2  //DISTANCIA ENTRE ALIEN Y ALIEN EN Y.
#define DISTANCIA_TECHO_Y   4  //DISTANCIA INICIAL ENTRE ALIEN Y BORDE SUPERIOR DE LA PANTALLA.
#define COLUMNAS        6   //COLUMNAS Y FILAS (DE ALIENS)MÁXIMAS
#define FILAS           3
#define INITIAL_ALIEN_SPEED 50
#define RANGO_X         15
#define RANGO_Y         60
#define VELOCIDAD_BALA_ALIEN    1.5
#define NUM_ALIENS		18
#define INIT_NUM_ALIENS	4

//Defines de las balas
#define BALA_SIZE_X     1   //TAMAÑO DE LA BALA (DEPENDE DE LA IMÁGEN QUE TENGA)
#define BALA_SIZE_Y     1

//Defines de highscore
#define NUM_SIZE_X      4  //TAMAÑO DE LOS NÚMEROS
#define NUM_SIZE_Y      5
#define CANTIDAD_NUM    10
#define CIFRAS_SCORE    9
#define MAXSCORES       3
#define NAMELENGHT      3

//Defines de las barreras
#define BARRERA_SIZE_X  2
#define BARRERA_SIZE_Y  1
#define BARRERA_POSICION_Y 12
#define CANT_BARRERAS   4

//Defines del alien random
#define RANDOM_ALIEN_SIZE_X 2  //Establece el tamaño del alien random.
#define RANDOM_ALIEN_SIZE_Y 1
#define RANDOM_ALIEN_POS_Y  1 //Posición en el eje y que mantendrá el alien random
#define RANDOM_ALIEN_SPEED  2

//Estados del MENU
enum { MENU = 0, PLAY, HIGHSCORE, EXIT, ERROR };

//Estados del MENU DE PAUSA
enum {MENU_PAUSE = 0, PLAY_PAUSE, EXIT_PAUSE, ERROR_PAUSE};

#ifdef RASPI
	typedef struct {
		int state;
	}graphics_t

//Inicializa Raspi y sus variables.
int initGraphics(graphics_t* allegro);
//Destruye Raspi y las variables.
int destroyGraphics(graphics_t* allegro);
//Función que imprime el menú.
void printMenu(graphics_t* graphics);
//Función que se fija si cambió el estado (si se presionó algún botón o saltó error) y devuelve el estado indicado.
int stateMenu(graphics_t* graphics);
//Se encarga de realizar el update del Front End.
void updateGraphics();
//Realiza todos los prints necesarios
void printSpaceInvaders(graphics_t* graphics, alien_t* aliens, barriers_t* barriers, spaceship_t* spaceship, alienRandom_t* rAlien);
//Realiza todos los clears necesarios.
void clearSpaceInvaders(graphics_t* graphics, alien_t* aliens, barriers_t* barriers, spaceship_t* spaceship, alienRandom_t* rAlien);

#endif

#endif /* RASPI_H */

