#include "randomalien.h"
#include <stdlib.h>
#include <time.h>
/**********************************************************************************
 * Función: moveRandomAlien                                                       *
 * Esta función se encarga de mover el alien para la derecha o la izquierda segun *
 * corresponda.                                                                   *
 **********************************************************************************/
void moveRandomAlien(alienRandom_t* alien);

/**********************************************************************************
 * Función: randomAlienIsShot                                                     *
 * Esta función se encarga de fijarse si le dispararon al alien.	              *
 **********************************************************************************/
int randomAlienIsShot(alienRandom_t* alien, bullet_t* bullet);

void initRandomAlien(alienRandom_t* alien) {
	alien->alive = DEAD;
}

void randomAlienIsBorn(alienRandom_t* alien, int ciclosRandom) {
	srand(time(NULL));
	alien->alive = ALIVE;
	int x = 0;
	if ((ciclosRandom % 2) == 0) {
		x = 0;
		alien->direction = DERECHA;
	}
	else if ((ciclosRandom % 2) == 0) {
		x = WIDTH - 1;
		alien->direction = IZQUIERDA;
	}
	initPosition(&alien->pos, x, RANDOM_ALIEN_POS_Y);
	alien->puntaje = rand() % (MAX_POINTS);
}

void updateRandomAlien(alienRandom_t * alien, bullet_t* bullet, int frames, player_t* player){
	if (alien->alive){
		if (bullet->state == ON) {
			if (randomAlienIsShot(alien, bullet)) {
				player->points += alien->puntaje;
			}
		}
		if ((frames % RANDOM_ALIEN_SPEED) == 0) {
			moveRandomAlien(alien);
		}
	}   
}

void moveRandomAlien(alienRandom_t* alien) {
	switch(alien->direction){
		case DERECHA:
			if (alien->pos.x == (WIDTH - 1)){
				alien->alive = DEAD;
			}
			else{
				changePosition (&alien->pos, 1 , 0);
			}
			break;
		case IZQUIERDA:
			if (alien->pos.x == 0){
				alien->alive = DEAD;
			}
			else{
				changePosition (&alien->pos, -1 , 0);
			}
			break;
	}
}

int randomAlienIsShot(alienRandom_t* alien, bullet_t* bullet){
	int result = 0;
	if ((comparePosition(alien->pos, bullet->pos))&&(bullet->type == SPACESHIP_BULLET)){
		alien->alive = DEAD;
		bullet->state = OFF;
		result = 1;
	}
	return result;
}

