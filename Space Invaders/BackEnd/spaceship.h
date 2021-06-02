#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "bullet.h"
#include "position.h"

/*
#ifndef RASPI
#include "allegro.h"
#endif

#ifdef RASPI
#include "raspi.h"
#endif
*/
//ESTO TIENE QUE ESTAR DEFINIDO EN ALLEGRO O EN RASPI pero lo defino para q no tire error
#define SPACESHIP_POS_Y 0
#define INITIAL_SPASESHIP_POS_X 8 
#define SPACESHIP_LIVES 3
#define UNIDAD 1
#define WIDTH 15    //esto sirve pa todo
#define HEIGHT 15	

typedef struct {
	position_t pos;
	bullet_t bullet;
	int lives;
}spaceship_t;

void initSpaceship(spaceship_t* spaceship);
int updateSpaceship(spaceship_t* spaceship);

//Se envia 1 si se quiere mover a la derecha y 0 si se quiere mover a la izquierda
void moveSpaceship(int moveRight, spaceship_t* spaceship); 

//devuelve 1 si la spaceship esta shot
int isSpaceshipShot(void);//no


void throwBullet(spaceship_t* spaceship);    

#endif // SPACESHIP_H
