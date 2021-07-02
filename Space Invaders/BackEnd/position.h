#ifndef POSITION_H
#define POSITION_H

#include <stdio.h>

typedef struct {
	int x;
	int y;
}position_t;

//Inicializa la posicion con los valores que le mandan.
void initPosition (position_t* pos, int x, int y);
//Le suma la cantidad x e y que le mandan.
void changePosition (position_t* pos, int x, int y);
//Compara dos posiciones y se fija si son iguales. Devuelve 1 si si o 0 si no.
int comparePosition (position_t pos1, position_t pos2);
#endif //POSITION_H
