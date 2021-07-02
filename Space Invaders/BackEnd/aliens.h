#ifndef ALIENS_H
#define ALIENS_H

#include "highscore.h"
#include "bullet.h"

#define ALIVE	1
#define DEAD	0
#define RECENT_DEAD 2

#define SCORE_1	10
#define SCORE_2	20
#define SCORE_3	30
#define SCORE_4	40
#define SCORE_5	50

typedef struct {
	position_t pos;
	int alive;
	int score;
	bullet_t bullet;
}alien_t;



/**********************************************************************************
 * Funci�n: initAliens	                                                          *
 * Esta funci�n se encarga de inicializar la posicion de los aliens y ponerlos en *
 * estado de vivos.																  *
 **********************************************************************************/
void initAliens(alien_t* aliens, int level); //POSICION + LIVE

/**********************************************************************************
 * Funci�n: updateAliens														  *
 * Esta funci�n se encarga de fijarse si le dispararon a algun alien y luego de	  *
 * mover los que esten vivos.													  *
 **********************************************************************************/
void updateAliens(alien_t* aliens, bullet_t* spaceshipBullet, int frames, player_t* player, int level);

/**********************************************************************************
 * Funci�n: lastAlien	                                                          *
 * Esta funci�n devuelve la cantidad de aliens que estan vivos, si devuelve 0 es  *
 * que el jugador gano el nivel.												  *
 **********************************************************************************/
int lastAlien(alien_t* aliens);	


/**********************************************************************************
 * Funci�n: throwAlienBulle                                                       *
 * Esta funci�n se encarga de cambiar la posicion de la bala del alien y de poner *
 * su estado en encendido.														  *
 **********************************************************************************/
void throwAlienBullet(alien_t* alien);

int getFilas(int level);
int getColumnas(int level);

#endif // ALIENS_H
