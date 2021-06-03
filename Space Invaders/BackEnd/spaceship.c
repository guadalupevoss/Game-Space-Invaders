#include "spaceship.h"

//Devuelve 1 si le dispararon a la nave o 0 si no.
int isSpaceshipShot(bullet_t* bullet, spaceship_t* spaceship);

void initSpaceship(spaceship_t* spaceship) {
	initPosition(&spaceship->pos, INITIAL_SPASESHIP_POS_X, SPACESHIP_POS_Y);
	initBullet(&spaceship->bullet, spaceship->pos.x, spaceship->pos.y, SPACESHIP_BULLET);
	spaceship->lives = SPACESHIP_LIVES;
}

int updateSpaceship(bullet_t* bullet, spaceship_t* spaceship){
	int lost = 0;
	if (isSpaceshipShot(bullet, spaceship)){
		if(spaceship->lives){
			(spaceship->lives)--;
		}
		else{
			lost = 1;
		}
	}
	return lost;
}

void moveSpaceship(int moveRight, spaceship_t* spaceship) {
	if ((moveRight)&&(spaceship->pos.x != (WIDTH - 1))){
		changePosition(&spaceship->pos, 1, 0);
	}
	else if((!moveRight)&&(spaceship->pos.x != 0)){
		changePosition(&spaceship->pos, -1, 0);
	}
}

int isSpaceshipShot(bullet_t* bullet, spaceship_t* spaceship) {
	int shot = 0;
	if (bullet->type == ALIEN_BULLET){
		if (comparePosition(spaceship->pos, bullet->pos)){
			shot = 1;
		}
	}
	return shot;
}

void throwBullet(spaceship_t* spaceship) {
	changePosition(&spaceship->bullet.pos, spaceship->pos.x, spaceship->pos.y);
	spaceship->bullet.state = ON;
}
