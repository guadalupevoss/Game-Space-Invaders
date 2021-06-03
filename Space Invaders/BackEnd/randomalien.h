#ifndef RANDOM_ALIEN_H
#define RANDOM_ALIEN_H

#include "position.h"
#include "bullet.h"
#include "../FrontEnd/graphics.h"

#define DERECHA 1
#define IZQUIERDA 0

#define ALIVE 1
#define DEAD 0

#define MAX_POINTS 100

typedef struct {
	position_t pos;
	int alive;
	int puntaje;
	int direction;
}alienRandom_t;

void updateRandomAlien(alienRandom_t* alien, bullet_t* bullet);
void initRandomAlien(alienRandom_t* alien); //posicion + alive + puntaje (puntaje es random y posicion es en y siempre la misma y la inicial en x puede variar entre der e izq)
void randomAlienIsBorn(alienRandom_t* alien, int ciclos_random)

#endif // RANDOM_ALIEN_H