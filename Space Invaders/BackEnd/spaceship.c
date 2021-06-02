#include "spaceship.h"

void initSpaceship(spaceship_t* spaceship) {
	initPosition(&spaceship->pos, INITIAL_SPASESHIP_POS_X, SPACESHIP_POS_Y);
	initBullet(&spaceship->bullet, spaceship->pos.x, spaceship->pos.y, SPACESHIP_BULLET);
	spaceship->lives = SPACESHIP_LIVES;
}

void updateSpaceship(void){

}

void moveSpaceship(void) {

}

void isSpaceshipShot(void) {

}
void throwBullet(void) {

}