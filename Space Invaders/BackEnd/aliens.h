#ifndef ALIENS_H
#define ALIENS_H

#include "position.h"
#include "bullet.h"

/*
#ifndef RASPI
#include "allegro.h"
#endif

#ifdef RASPI
#include "raspi.h"
#endif
*/
//ESTO TIENE QUE ESTAR DEFINIDO EN ALLEGRO O EN RASPI pero lo defino para q no tire error
#define NUM_ALIENS 2
#define SPACESHIP_POS_Y 0
#define INITIAL_SPASESHIP_POS_X 8 
#define SPACESHIP_LIVES 3
#define UNIDAD 1

#define ALIVE	1
#define DEAD	0

typedef struct {
	position_t pos;
	int alive;
	int score;
	bullet_t bullet;
}alien_t;


void initAliens(alien_t* aliens, int numAliens); //POSICION + LIVE
//Se encarga de fijarse si le dispararon a algun alien y luego de mover los aliens que esten vivos.
void updateAliens(alien_t* aliens, bullet_t* spaceshipBullet);
//Devuelve la cantidad de aliens vivos, si es cero gano.
int lastAlien(alien_t* aliens);	//no

#endif // ALIENS_H
