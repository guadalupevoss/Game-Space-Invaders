#ifndef ALIENS_H
#define ALIENS_H

#include "bullet.h"

#define ALIVE	1
#define DEAD	0

#define SCORE_1	1
#define SCORE_2	2
#define SCORE_3	13
#define SCORE_4	20
#define SCORE_5	33

typedef struct {
	position_t pos;
	int alive;
	int score;
	bullet_t bullet;
}alien_t;



/**********************************************************************************
 * Función: initAliens	                                                          *
 * Esta función se encarga de inicializar la posicion de los aliens y ponerlos en *
 * estado de vivos.																  *
 **********************************************************************************/
void initAliens(alien_t* aliens, int numAliens); //POSICION + LIVE

/**********************************************************************************
 * Función: updateAliens														  *
 * Esta función se encarga de fijarse si le dispararon a algun alien y luego de	  *
 * mover los que esten vivos.													  *
 **********************************************************************************/
void updateAliens(alien_t* aliens, bullet_t* spaceshipBullet);

/**********************************************************************************
 * Función: lastAlien	                                                          *
 * Esta función devuelve la cantidad de aliens que estan vivos, si devuelve 0 es  *
 * que el jugador gano el nivel.												  *
 **********************************************************************************/
int lastAlien(alien_t* aliens);	//no

#endif // ALIENS_H
