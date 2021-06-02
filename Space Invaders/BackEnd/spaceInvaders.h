#ifndef SPACEINVADERS_H
#define SPACEINVADERS_H

#include "menu.h"

#define OK_SPACE_INCADERS		0
#define ERROR_SPACE_INCADERS	-1
#define NAME_LENGHT				20			//Número máximo de caracteres de un nombre

struct player {
	char[NAME_LENGHT]	name;	//Nombre del jugador.
	int					score;			//Puntaje del jugador.				
};

#endif // SPACEINVADERS_H
