#include "spaceship.h"

void initSpaceship(spaceship_t* spaceship) {
	initPosition(&spaceship->pos, INITIAL_SPASESHIP_POS_X, SPACESHIP_POS_Y);
	initBullet(&spaceship->bullet, spaceship->pos.x, spaceship->pos.y, SPACESHIP_BULLET);
	spaceship->lives = SPACESHIP_LIVES;
}

int updateSpaceship(spaceship_t* spaceship){
	int lost = 0;
	if (isSpaceshipShot(spaceship)){
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
	if ((moveRight)&&(spaceship->pos.x =! WIDTH)){
		(spaceship->pos.x)++;
	}
	else ((!moveRight)&&(spaceship->pos.x =! 0)){
		(spaceship->pos.x)--;
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
