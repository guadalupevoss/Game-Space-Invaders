#ifndef SPACEINVADERS_H
#define SPACEINVADERS_H

#include "menu.h"
#include "../FrontEnd/graphics.h"

#define OK_SPACE_INVADERS		0
#define ERROR_SPACE_INVADERS	-1
#define NAME_LENGHT				20			//Número máximo de caracteres de un nombre

typedef struct{
	char*	name;	//Nombre del jugador.
	int		score;	//Puntaje del jugador.				
}player_t;

#endif // SPACEINVADERS_H
