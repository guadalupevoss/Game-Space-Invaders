#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "bullet.h"

typedef struct {
	int x;
	int y;
	bullet_t bullet;
	int lives;
}spaceship_t;


void updateSpaceship(void);
void moveSpaceship(void);  //no
void isSpaceshipShot(void);//no
void throwBullet(void);    //no

#endif // SPACESHIP_H
