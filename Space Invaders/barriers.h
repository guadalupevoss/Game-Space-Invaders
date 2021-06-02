#ifndef BARRIERS_H
#define BARRIERS_H

typedef struct {
	int x;
	int y;
	int lives;
}barriers_t;

//Inicializa la posicion de todas las barreras y las vidas en el maximo establecido.
void initBarriers (barriers_t* barriers);

//Se fija si le dispararon a la barrera que nos estamos fijando.
void barrierIsShot(barriers_t barrier, bullet_t bullet);

#endif // BARRIERS_H