#ifndef BULLET_H
#define BULLET_H

#define ALIEN_BULLET 1
#define SPACESHIP_BULLET 2

typedef struct {
	int x;
	int y;
	int type;
	int on;
}bullet_t;

//Inicializa la posicion, el tipo y el on o off de la bala. Que arranque en off. Recibe un numero que indica si es de alien (ALIEN_BULLET) o de nave (SPACESHIP_BULLET).
void initBullet(bullet_t bullet)
//Función lógica de la bala.
void updateBullet(bullet_t bullet);
//Mueve la bala.
void moveBullet(bullet_t bullet);
//Se fija si la bala sigue en on. Si choca con algo o sale de la pantalla pasa a off.
void updateState(bullet_t bullet);

#endif // BULLET_H