#include "bullet.h"

//Mueve la bala.
void moveBullet(bullet_t* bullet);

void initBullet(bullet_t* bullet, int x, int y, int type, int speed) {
	initPosition(&bullet->pos, x, y);
	bullet->type = type;
	bullet->speed = speed;
	bullet->state = OFF;
}

void updateBullet(bullet_t* bullet){
	moveBullet(bullet);
}

void moveBullet(bullet_t* bullet) {
	if (bullet->pos.y != 0 || bullet->pos.y != (HEIGHT-1)) {
		if (bullet->type == ALIEN_BULLET) {
			changePosition(&bullet->pos, 0, bullet->speed);
		}
		if (bullet->type == SPACESHIP_BULLET) {
			changePosition(&bullet->pos, 0, (-1) * bullet->speed);
		}
	}
	else {
		bullet->state = OFF;
	}
}
