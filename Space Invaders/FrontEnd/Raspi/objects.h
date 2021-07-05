#ifndef OBJECTS_H
#define OBJECTS_H

#include "../../BackEnd/aliens.h"
#include "../../BackEnd/barriers.h"

#define CLEARPOINT(f) myPoint_##f##_clear
#define MYPOINT(s) myPoint_##s##_level
#define LIVES(s) myPoint_##s##_lives

//Funciones que imprimen los objetos segun la posicion que se desee.
//Se encarga de limpiar los leds que fueron apagados
void clearAliens(alien_t aliens[], int cantidad_aliens_usados);
//Se encarga de imprimir los aliens que estan vivos.
void printAliens(alien_t aliens[], int cantidad_aliens_usados);
//Se encarga de imprimir al alien random.
void printAlienRandom(int x, int y);
//Se encarga de eliminar los leds que deben ser apagados del random alien.
void clearAlienRandom(int x, int y);
//Imprime la bala.
void printBala(int x, int y);
//Elimina los leds de la bala.
void clearBala(int x, int y);
//Se encarga de imprimir la nave.
void printNave(int x);
//Se encarga de limpiar los leds de la nave.
void clearNave(int x);
//Imprime las vidas.
void printLives(int cantidad_vidas);
//Imprime las barreras.
void printBarriers(barriers_t* barriers);

#endif // OBJECTS_H
