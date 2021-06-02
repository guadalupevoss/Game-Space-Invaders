#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "bullet.h"
#include "position.h"

/*
#ifndef RASPI
#include "allegro.h"
#endif

#ifdef RASPI
#include "raspi.h"
#endif
*/
//ESTO TIENE QUE ESTAR DEFINIDO EN ALLEGRO O EN RASPI pero lo defino para q no tire error
#define SPACESHIP_POS_Y 0
#define INITIAL_SPASESHIP_POS_X 8 
#define SPACESHIP_LIVES 3
#define UNIDAD 1

typedef struct {
	position_t pos;
	bullet_t bullet;
	int lives;
}spaceship_t;

void initSpaceship(spaceship_t* spaceship);
void updateSpaceship(void);
void moveSpaceship(void);  //no
void isSpaceshipShot(void);//no
void throwBullet(void);    //no

#endif // SPACESHIP_H
