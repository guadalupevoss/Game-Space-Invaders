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

//Se encarga del movimiento y de fijarse que sigan vivos.
void updateAliens(alien_t* aliens, bullet_t* spaceshipBullet, int frames, player_t* player, int level) {
	int i;
	//Solo si la bala de la nave esta encendida me fijo si le disparo a algun alien.
	if (spaceshipBullet->state == ON) {
		for (i = 0; i < NUM_ALIENS; i++) {
			if (alienIsShot(&aliens[i], spaceshipBullet)) {
				player->points += aliens[i].score;
			}
		}
	}
	//Muevo a todos los aliens.
	moveAliens(aliens, frames, level);
}

//Se encarga del movimiento de los aliens.
void moveAliens(alien_t* aliens, int frames, int level) {
	static int side = 0, down = 0, levelCount = 1; //side en 1 significa que van a la derecha, side en 0 significa van a la izquierda.
	int i;
	if (down && !frames) {
		down = 0;
	}
	if (level != levelCount) {
		down = 0;
		levelCount = level;
	}

	//Si los frames que pasaron son multiplo de la velocidad de los aliens hay que moverlos (se aumenta la velocidad depende el nivel)
	if ((frames % (INITIAL_ALIEN_SPEED - 2*level)) == 0) {
		//Se fija si hay que cambiar la direccion de los aliens (izquierda o derecha)
		if (aliens[0].pos.x == 0) {
			side = 1;
			if (!down) {
				for (i = 0; i < NUM_ALIENS; i++) {
					//Baja.
					changePosition(&aliens[i].pos, 0, 1);
				}
				down = 1;
			}
			else {
				down = 0;
			}
		}
		if (aliens[getColumnas(level)-1].pos.x == 15) { 
			side = 0;
			if (!down) {
				for (i = 0; i < NUM_ALIENS; i++) {
					//Baja.
					changePosition(&aliens[i].pos, 0, 1);
				}
				down = 1;
			}
			else {
				down = 0;
			}
		}

		if (!down) {
			//Mueve a los aliens, dependiendo para que lado se esten moviendo
			for (i = 0; i < NUM_ALIENS; i++) {
				//En caso de que vayan para la derecha, hay que sumarles un valor
				if (side) {
					changePosition(&aliens[i].pos, 1, 0);
				}
				//En caso de que vayan para la izquierda, hay que restarles un valor
				else if (!side) {
					changePosition(&aliens[i].pos, -1, 0);
				}
			}
		}
	}
}

//Se fija si la posicion de la bala de la nave y la de un alien son iguales.
//Devuelve un 1 si le dispararon o un 0 si no.
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

//Para las siguientes funciones, son distintas para la raspi y para allegro, ya que el espacio con el que contamos
//en cada caso es distinto, por ende la cantidad de aliens que podemos incluir en cada nivel cambia.

#ifdef RASPI
//Devuelve la posicion en x del primer alien, dependiendo la cantidad de columnas que tiene el nivel.
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

//Devuelve la cantidad de filas de aliens, dependiendo del nivel en el que esta.
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

//Devuelve la cantidad de columnas de aliens, dependiendo del nivel en el que esta.
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
//Establece la posicion inicial del primer alien.
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

//Devuelve la cantidad de filas de aliens, dependiendo del nivel en el que esta.
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

//Devuelve la cantidad de columnas de aliens, dependiendo del nivel en el que esta.
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

//Se encarga de encender la bala del alien.
void throwAlienBullet(alien_t* alien) {
	if (alien->bullet.state == OFF) {
		changePosition(&alien->bullet.pos, (-1) * (alien->bullet.pos.x), (-1) * (alien->bullet.pos.y));
		changePosition(&alien->bullet.pos, alien->pos.x, alien->pos.y);
		alien->bullet.state = ON;
	}
}