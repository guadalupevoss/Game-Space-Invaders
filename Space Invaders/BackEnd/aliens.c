#include "aliens.h"
#include <stdlib.h>

/**********************************************************************************
 * Función: moveAliens                                                            *
 * Esta función se encarga de mover a los aliens que corresponda.           	  *
 **********************************************************************************/
void moveAliens(alien_t* aliens, int frames, int level);

/**********************************************************************************
 * Función: alienIsShot                                                           *
 * Esta función se encarga de chequear si a un alien le dispararon.         	  *
 **********************************************************************************/
int alienIsShot(alien_t* alien, bullet_t* spaceshipBullet); //no

int getInitX(int columnas);


//Inicializa posicion y vidas.
//ACORDARSE DE INICIALIZAR LO DEL SCORE Y EL TIPO DE ALIEN.
void initAliens(alien_t* aliens, int level) {
	int i = 0, j = 0, cont = 0;
	int initX, initY;
	//Existe un numero maximo de columnas, si lo supero lo pongo de este valor.
	int columnas, filas; //Me fijo un valor para la cantidad de filas (max divisor)
	filas = getFilas(level);
	//Existe un numero maximo de filas, si lo supera lo pongo de este valor.
	columnas = getColumnas(level);
	initX = getInitX(columnas);
	initY = DISTANCIA_TECHO_Y;
	for (j = 0; j < filas; j++)
	{
			for (i = 0; i < columnas; ++i)
			{
				initPosition(&aliens[cont].pos, initX + i * DISTANCIA_ALIENS_X, initY + j * DISTANCIA_ALIENS_Y);
				//Aca invente un toque, onda no se si esta bien este valor.
				aliens[cont].score = SCORE_1 + 10 * j;
				aliens[cont].alive = ALIVE;
				initBullet(&aliens[cont].bullet, aliens[cont].pos.x, aliens[cont].pos.y, ALIEN_BULLET, INITIAL_ALIEN_BULLET_SPEED);
				++cont;
			}
		}
		for (; cont < NUM_ALIENS; cont++) {
			aliens[cont].alive = DEAD;
		}
}

void updateAliens(alien_t* aliens, bullet_t* spaceshipBullet, int frames, player_t* player, int level) {
	int i;
	if (spaceshipBullet->state == ON) {
		for (i = 0; i < NUM_ALIENS; i++) {
			if (alienIsShot(&aliens[i], spaceshipBullet)) {
				player->points += aliens[i].score;
			}
		}
	}
	moveAliens(aliens, frames, level);
}

//FALTA LO DE CHEQUEAR QUE PASA SI LLEGAN AL FINAL :(
void moveAliens(alien_t* aliens, int frames, int level) {
	static int side = 0; //side en 1 significa que van a la derecha, side en 0 significa izquierda.
	int i;
	if ((frames % INITIAL_ALIEN_SPEED) == 0) {
		if (aliens[0].pos.x == 0) {
			side = 1;
			for (i = 0; i < NUM_ALIENS; i++) {
				changePosition(&aliens[i].pos, 0, 1);
			}
		}
		if (aliens[getColumnas(level)-1].pos.x == 15) { 
			side = 0;
			for (i = 0; i < NUM_ALIENS; i++) {
				changePosition(&aliens[i].pos, 0, 1);
			}
		}
		for (i = 0; i < NUM_ALIENS; i++) {
			if (side) {
				changePosition(&aliens[i].pos, 1, 0);
			}
			else if (!side) {
				changePosition(&aliens[i].pos, -1, 0);
			}
		}
	}
}

int alienIsShot(alien_t* alien, bullet_t* spaceshipBullet) {
	int result = 0;
	if (comparePosition(alien->pos, spaceshipBullet->pos)) {
		if (alien->alive == ALIVE) {
			alien->alive = RECENT_DEAD;
			spaceshipBullet->state = OFF;
			result = 1;
		}
	}
	return result;
}

//Devuelve la cantidad de aliens vivos, si es cero gano.
int lastAlien(alien_t* aliens) {
	int result = 0, i;
	for (i = 0; i < NUM_ALIENS; ++i) {
		if (aliens[i].alive == ALIVE) {
			++result;
		}
	}
	return result;
}

#ifdef RASPI
int getInitX(int columnas) {
	int x = 7;
	switch (columnas)
	{
	case 2:
		x = 7;
		break;
	case 3:
		x = 5;
		break;
	case 4:
		x = 5;
		break;
	case 5:
		x = 3;
		break;
	case 6:
		x = 3;
		break;
	}
	return x;
}

int getFilas(int level) {
	int filas = 0;
	switch (level)
	{
		case 1: 
			filas = 2;
			break;
		case 2:
		case 3:
		case 4:
		case 5:
			filas = 2;
			break;
		default:
			filas = 3;
			break;
	}
	return filas;
}

int getColumnas(int level) {
	int columnas = 0;
	switch (level)
	{
		case 1: 
			columnas = 2;
			break;
		case 2:
			columnas = 3;
			break;
		case 3:
			columnas = 4;
			break;
		case 4:
			columnas = 5;
			break;
		default:
			columnas = 6;
			break;
	}
	return columnas;
}


#endif	

#ifndef RASPI
int getInitX(int columnas) {
	int x = 7;
	switch (columnas)
	{
	case 2:
		x = 7;
		break;
	case 3:
		x = 5;
		break;
	case 4:
		x = 5;
		break;
	case 5:
		x = 3;
		break;
	case 6:
		x = 3;
		break;
	}
	return x;
}

int getFilas(int level) {
	int filas = 0;
	switch (level)
	{
	case 1:
		filas = 1;
		break;
	case 2:
	case 3:
		filas = 2;
		break;
	case 4:
		filas = 3;
		break;
	case 5:
		filas = 4;
		break;
	case 6:
		filas = 5;
		break;
	default:
		if ((rand() % 2) && (rand() % 3))
		{
			filas = 4;
		}
		else if (rand() % 2)
		{
			filas = 6;
		}
		else
		{
			filas = 5;
		}
		break;
	}
	return filas;
}

int getColumnas(int level) {
	int columnas = 0;
	switch (level)
	{
		case 1:
			columnas = 3;
			break;
		case 2:
		case 3:
			columnas = 5;
			break;
		case 4:
			columnas = 7;
			break;
		case 5:
			columnas = 9;
			break;
		case 6:	
			columnas = 9;
			break;
		default:
			if ((rand() % 2) && (rand() % 3)){
				columnas = 9;
			}
			else if (rand() % 2){
				columnas = 7;
			}
			else{
				columnas = 8;
			}
			break;
	} 
	return columnas;
}
#endif

void throwAlienBullet(alien_t* alien) {
	if (alien->bullet.state == OFF) {
		changePosition(&alien->bullet.pos, (-1) * (alien->bullet.pos.x), (-1) * (alien->bullet.pos.y));
		changePosition(&alien->bullet.pos, alien->pos.x, alien->pos.y);
		alien->bullet.state = ON;
	}
}