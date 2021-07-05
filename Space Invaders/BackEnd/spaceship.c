#include "spaceship.h"

//Esta funcion se encarga de fijarse si le dispararon a la nave. Devuelve 1 si le dispararon a la nave o 0 si no.
int isSpaceshipShot(bullet_t* bullet, spaceship_t* spaceship);

//Se encarga de inicializar la nave con la posicion inicial, las vidas y su bala.
void initSpaceship(spaceship_t* spaceship) {
	initPosition(&spaceship->pos, INITIAL_SPASESHIP_POS_X, SPACESHIP_POS_Y);
	initBullet(&spaceship->bullet, spaceship->pos.x, spaceship->pos.y, SPACESHIP_BULLET, SPACESHIP_BULLET_SPEED);
	spaceship->lives = SPACESHIP_LIVES;
}

//Se encarga de actualizar la nave, fijandose si le dispararon.
int updateSpaceship(bullet_t* bullet, spaceship_t* spaceship){
	int lost = 0;
	if (isSpaceshipShot(bullet, spaceship)){
		bullet->state = OFF;
		if (spaceship->lives == 0) {
			lost = 1;
		}
	}
	return lost;
}

//Se encarga de mover la nave para el lado que corresponde.
void moveSpaceship(int moveRight, spaceship_t* spaceship) {
	if ((moveRight)&&(spaceship->pos.x != 15)){
		changePosition(&spaceship->pos, 1, 0);
	}
	else if((!moveRight)&&(spaceship->pos.x != 0)){
		changePosition(&spaceship->pos, -1, 0);
	}
}

//Se encarga de fijarse si le dispararon a la nave.
int isSpaceshipShot(bullet_t* bullet, spaceship_t* spaceship) {
	int shot = 0;
	if (bullet->type == ALIEN_BULLET && bullet->state == ON){
		if (comparePosition(spaceship->pos, bullet->pos)){
			shot = 1;
			--spaceship->lives;
		}
	}
	if (NAVE_SIZE_X == 3) {
		changePosition(&spaceship->pos, 1, 0);
		if (bullet->type == ALIEN_BULLET && bullet->state == ON) {
			if (comparePosition(spaceship->pos, bullet->pos)) {
				shot = 1;
				--spaceship->lives;
			}
		}
		changePosition(&spaceship->pos, 1, 0);
		if (bullet->type == ALIEN_BULLET && bullet->state == ON) {
			if(comparePosition(spaceship->pos, bullet->pos)) {
				shot = 1;
				--spaceship->lives;
			}
		}
		changePosition(&spaceship->pos, -2, 0);
	}
	return shot;
}

//Se encarga de encender la bala de la nave cuando es necesario, estableciendo las posiciones correspondientes.
void throwBullet(spaceship_t* spaceship) {
	if (spaceship->bullet.state == OFF) {
		changePosition(&spaceship->bullet.pos, (-1) * (spaceship->bullet.pos.x), (-1) * (spaceship->bullet.pos.y));
		changePosition(&spaceship->bullet.pos, spaceship->pos.x + POS_CENTRO, spaceship->pos.y - 1 - POS_CENTRO);
		spaceship->bullet.state = ON;
	}
}

