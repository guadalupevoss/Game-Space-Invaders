#include "position.h"


void initPosition (position_t* pos, int x, int y){
	pos->x = x;
	pos->y = y;
}

void changePosition (position_t* pos, int x, int y){
	pos->x += x;
	pos->y += y;
}

//Devuelve 1 si es igual y 0 si no.
int comparePosition (position_t pos1, position_t pos2){
	int isEqual = 0;
	
	if(pos1.x == pos2.x){
		if(pos1.y == pos2.y){
			isEqual = 1;
		}
	}
	return isEqual;
}