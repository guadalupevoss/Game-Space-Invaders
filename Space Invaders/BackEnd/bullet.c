#include "bullet.h"

//Mueve la bala.
void moveBullet(bullet_t bullet);
//Se fija si la bala sigue en on. Si choca con algo o sale de la pantalla pasa a off.
void updateState(bullet_t bullet);


void initBullet(bullet_t* bullet, int x, int y, int type, int speed) {
	initPosition(&bullet->pos, x, y);
	bullet->type = type;
	bullet->speed = speed;
	bullet->state = OFF;
}

void updateBullet(bullet_t bullet){
	

}

void moveBullet(bullet_t bullet) {

}

void updateState(bullet_t bullet) {

}
