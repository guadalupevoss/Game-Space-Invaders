#ifndef BARRIERS_H
#define BARRIERS_H

#include "aliens.h"
#include "bullet.h"
#include "position.h"

/*
#ifndef RASPI
#include "allegro.h"
#endif

#ifdef RASPI
#include "raspi.h"
#endif

ESTO EN REALIDAD ES 
#include "graphics.h"
*/
//ESTO TIENE QUE ESTAR DEFINIDO EN ALLEGRO O EN RASPI pero lo defino para q no tire error
#define BARRIER_POS_Y 1
#define BARRIER_LIVES 4
#define UNIDAD 1



#define NUM_BARRIERS 4


typedef struct {
	position_t pos;
	int lives;
}barriers_t;

//Inicializa la posicion de todas las barreras y las vidas en el maximo establecido.
void initBarriers (barriers_t* barriers);
//Se fija con todas los aliens y la bala de la nave con cada barrera.
void updateBarriers(barriers_t* barriers, alien_t* aliens, bullet_t* spaceshipBullet);

#endif // BARRIERS_H