#include "barriers.h"

//Se fija si le dispararon a la barrera que nos estamos fijando.
void barrierIsShot(barriers_t barrier, bullet_t bullet);

void initBarriers (barriers_t* barriers){
	int i;
	for (i = 0; i < NUM_BARRIERS; i++) {
		initPosition(&barriers[i].pos, (UNIDAD*(4*i + 1)), BARRIER_POS_Y);
		barriers[i].lives = BARRIER_LIVES;
	}
}

void updateBarriers(barriers_t* barriers, alien_t* aliens, bullet_t spaceshipBullet) {

}

//Si la bala llega a la barrera, entonces pierde una vida.
void barrierIsShot(barriers_t barrier, bullet_t bullet) {

}