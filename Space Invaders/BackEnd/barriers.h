#ifndef BARRIERS_H
#define BARRIERS_H

#include "aliens.h"

#define RECENT_SHOT 5

typedef struct {
	position_t pos;
	int lives;
}barriers_t;

//Inicializa la posicion de todas las barreras y las vidas en el maximo establecido.
void initBarriers (barriers_t* barriers);
//Se fija con todas los aliens y la bala de la nave con cada barrera.
void updateBarriers(barriers_t* barriers, alien_t* aliens, bullet_t* spaceshipBullet);

#endif // BARRIERS_H