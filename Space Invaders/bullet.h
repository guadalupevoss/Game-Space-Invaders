#ifndef BULLET_H
#define BULLET_H

typedef struct {
	int x;
	int y;
	int type;
	int on;
}bullet_t;

//Función lógica de la bala.
void updateBullet(bullet_t bullet);
//Mueve la bala.
void moveBullet(bullet_t bullet);
//Se fija si la bala sigue en on. Si choca con algo o sale de la pantalla pasa a off.
void updateState(bullet_t bullet);

#endif // BULLET_H