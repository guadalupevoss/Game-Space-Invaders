#include "spaceship.h"
#pragma warning(disable : 4996)
#pragma warning(disable : 6387)


//Devuelve 1 si le dispararon a la nave o 0 si no.
int isSpaceshipShot(bullet_t* bullet, spaceship_t* spaceship);

void initSpaceship(spaceship_t* spaceship) {
	initPosition(&spaceship->pos, INITIAL_SPASESHIP_POS_X, SPACESHIP_POS_Y);
	initBullet(&spaceship->bullet, spaceship->pos.x, spaceship->pos.y, SPACESHIP_BULLET, SPACESHIP_BULLET_SPEED);
	spaceship->lives = SPACESHIP_LIVES;
}

int updateSpaceship(bullet_t* bullet, spaceship_t* spaceship){
	int lost = 0;
	char hola[100];
	if (isSpaceshipShot(bullet, spaceship)){
		bullet->state = OFF;
		--spaceship->lives;
		if (spaceship->lives == 0) {
			lost = 1;
		}
	}
	return lost;
}

void moveSpaceship(int moveRight, spaceship_t* spaceship) {
	if ((moveRight)&&(spaceship->pos.x != 15)){
		changePosition(&spaceship->pos, 1, 0);
	}
	else if((!moveRight)&&(spaceship->pos.x != 0)){
		changePosition(&spaceship->pos, -1, 0);
	}
}

int isSpaceshipShot(bullet_t* bullet, spaceship_t* spaceship) {
	int shot = 0;
	if (bullet->type == ALIEN_BULLET && bullet->state == ON){
		if (comparePosition(spaceship->pos, bullet->pos)){
			shot = 1;
		}
	}
	return shot;
}

void throwBullet(spaceship_t* spaceship) {
	if (spaceship->bullet.state == OFF) {
		changePosition(&spaceship->bullet.pos, (-1) * (spaceship->bullet.pos.x), (-1) * (spaceship->bullet.pos.y));
		changePosition(&spaceship->bullet.pos, spaceship->pos.x, spaceship->pos.y - 1);
		spaceship->bullet.state = ON;
	}
}

