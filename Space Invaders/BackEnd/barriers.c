#include "barriers.h"

//Se fija si le dispararon a la barrera que nos estamos fijando.
void barrierIsShot(barriers_t* barrier, bullet_t* bullet);

void initBarriers (barriers_t* barriers){
	int i;
	for (i = 0; i < NUM_BARRIERS; i++) {
		//Acordarse de multiplicar por UNIDAD cuando lo queremos imprimir a las posiciones.
		initPosition(&barriers[i].pos, (4*i + 1), BARRIER_POS_Y);
		barriers[i].lives = BARRIER_LIVES;
	}
}

void updateBarriers(barriers_t* barriers, alien_t* aliens, bullet_t* spaceshipBullet) {
	int i, j;
	for (i = 0; i < NUM_BARRIERS; i++) {
		for (j = 0; j < NUM_ALIENS; j++) {
			if (aliens[j].bullet.state == ON) {
				barrierIsShot(&barriers[i], &aliens[j].bullet);
			}
		}
		if (spaceshipBullet->state == ON) {
			barrierIsShot(&barriers[i], spaceshipBullet);
		}
	}
}

//Si la bala llega a la barrera, entonces pierde una vida.
void barrierIsShot(barriers_t* barrier, bullet_t* bullet) {
	if (comparePosition(barrier->pos, bullet->pos)) {
		if (barrier->lives > 1) {
			--barrier->lives;
			bullet->state = OFF;
		}
		else if (barrier->lives == 1) {
			barrier->lives = RECENT_SHOT;
		}
	}
	if (BARRERA_SIZE_X != 1) {
		changePosition(&barrier->pos, 1, 0);
		if (comparePosition(barrier->pos, bullet->pos)) {
			if (barrier->lives > 1) {
				--barrier->lives;
				bullet->state = OFF;
			}
			else if (barrier->lives == 1) {
				barrier->lives = RECENT_SHOT;
			}
		}
		changePosition(&barrier->pos, -1, 0);
	}
}