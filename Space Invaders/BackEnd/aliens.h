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
void updateAliens(void);
void moveAliens(void);  //no
void alienIsShot(void); //no
void lastAlien(void);	//no

#endif // ALIENS_H
