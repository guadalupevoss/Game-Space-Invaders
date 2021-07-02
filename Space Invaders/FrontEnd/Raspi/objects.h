#ifndef OBJECTS_H
#define OBJECTS_H

#include "../../BackEnd/aliens.h"
#include "../../BackEnd/barriers.h"

#define CLEARPOINT(f) myPoint_##f##_clear
#define MYPOINT(s) myPoint_##s##_level
#define LIVES(s) myPoint_##s##_lives

//Funciones que imprimen los objetos segun la posicion que se desee.

void clearAliens(alien_t aliens[], int cantidad_aliens_usados);
void printAliens(alien_t aliens[], int cantidad_aliens_usados);
void printAlienRandom(int x, int y);
void clearAlienRandom(int x, int y);
void printBala(int x, int y);
void clearBala(int x, int y);
void printNave(int x);
void clearNave(int x);
void printLives(int cantidad_vidas);
void printBarriers(barriers_t* barriers);

#endif // OBJECTS_H
