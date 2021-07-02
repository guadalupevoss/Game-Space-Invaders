#ifndef RANDOM_ALIEN_H
#define RANDOM_ALIEN_H

#include "bullet.h"
#include "highscore.h"

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

void updateRandomAlien(alienRandom_t* alien, bullet_t* bullet, int frames, player_t* player);
void initRandomAlien(alienRandom_t* alien); //posicion + alive + puntaje (puntaje es random y posicion es en y siempre la misma y la inicial en x puede variar entre der e izq)
void randomAlienIsBorn(alienRandom_t* alien, int ciclosRandom);

#endif // RANDOM_ALIEN_H