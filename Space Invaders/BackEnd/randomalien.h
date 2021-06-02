#ifndef RANDOM_ALIEN_H
#define RANDOM_ALIEN_H

typedef struct {
	int x;
	int y;
	int alive;
	int puntaje;
}alienRandom_t;

void updateRandomAlien(void);
void moveRandomAlien(void);  //no
void randomAlienIsShot(void); //no
void initRandomAlien(void); //posicion + alive + puntaje (puntaje es random y posicion es en y siempre la misma y la inicial en x puede variar entre der e izq)

#endif //RANDOM_ALIEN_H