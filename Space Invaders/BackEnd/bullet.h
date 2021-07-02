#ifndef BULLET_H
#define BULLET_H

#include "position.h"
#include "constantes.h"


#define ALIEN_BULLET 1
#define SPACESHIP_BULLET 2

#define ON 1
#define OFF 0

typedef struct {
	position_t pos;
	int type;     
	int state;
	int speed;	//PIXELES POR FRAME
}bullet_t;

//Inicializa la posicion, el tipo y el on o off de la bala. Que arranque en off. Recibe un numero que indica si es de alien (ALIEN_BULLET) o de nave (SPACESHIP_BULLET).
void initBullet(bullet_t* bullet, int x, int y, int type, int speed);
//Función lógica de la bala.
void updateBullet(bullet_t* bullet, int frames);

#endif // BULLET_H