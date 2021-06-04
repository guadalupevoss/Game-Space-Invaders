#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "bullet.h"

typedef struct {
	position_t pos;
	bullet_t bullet;
	int lives;
}spaceship_t;

//Inicializa la nave.
void initSpaceship(spaceship_t* spaceship);
//Se encarga de actualizar el estado de la nave.
int updateSpaceship(bullet_t* bullet, spaceship_t* spaceship);
//Se envia 1 si se quiere mover a la derecha y 0 si se quiere mover a la izquierda
void moveSpaceship(int moveRight, spaceship_t* spaceship); 
//Se encarga de enceder la bala de la nave.
void throwBullet(spaceship_t* spaceship);    

#endif // SPACESHIP_H
