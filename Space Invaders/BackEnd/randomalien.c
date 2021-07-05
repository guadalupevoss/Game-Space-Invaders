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

//Inicializamos al alien random como muerto.
void initRandomAlien(alienRandom_t* alien) {
	alien->alive = DEAD;
}

//Cuando se llama esta funcion hacemos que el alien este vivo.
void randomAlienIsBorn(alienRandom_t* alien, int ciclosRandom) {
	srand(time(NULL));
	alien->alive = ALIVE;
	int x = 0;
	//Si la cantidad de ciclos son pares entonces hacemos que salga por la derecha.
	if ((ciclosRandom % 2) == 0) {
		x = 0;
		alien->direction = DERECHA;
	}
	//Si la cantidad de ciclos son impares entonces hacemos que salga por la izquierda.
	else {
		x = WIDTH - 1;
		alien->direction = IZQUIERDA;
	}
	initPosition(&alien->pos, x, RANDOM_ALIEN_POS_Y);
	//Establecemos un puntaje random para el alien.
	alien->puntaje = rand() % (MAX_POINTS);
}

//Se encarga del movimiento del alien random y de fijarse que este vivo.
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

//Se encarga de moverlo.
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

//Se encarga de fijarse si le dispararon al alien random.
int randomAlienIsShot(alienRandom_t* alien, bullet_t* bullet){
	int result = 0;
	//Me fijo si la posicion de la bala coincide con la del alien random. En caso de que sea asi, apago la bala y lo mato.
	if ((comparePosition(alien->pos, bullet->pos))&&(bullet->type == SPACESHIP_BULLET)){
		alien->alive = DEAD;
		bullet->state = OFF;
		result = 1;
	}
	//Hago que tenga en cuenta todas las posiciones del alien teniendo en cuenta su tamano.
	if (RANDOM_ALIEN_SIZE_X == 2) {
		changePosition(&alien->pos, 1, 0);
		if ((comparePosition(alien->pos, bullet->pos)) && (bullet->type == SPACESHIP_BULLET)) {
			alien->alive = DEAD;
			bullet->state = OFF;
			result = 1;
		}
		changePosition(&alien->pos, -1, 0);
	}
	return result;
}

