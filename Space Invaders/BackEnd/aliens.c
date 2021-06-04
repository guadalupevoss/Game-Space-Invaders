#include "aliens.h"

/**********************************************************************************
 * Funci�n: moveAliens                                                            *
 * Esta funci�n se encarga de mover a los aliens que corresponda.           	  *
 **********************************************************************************/
void moveAliens(alien_t* aliens);

/**********************************************************************************
 * Funci�n: alienIsShot                                                           *
 * Esta funci�n se encarga de chequear si a un alien le dispararon.         	  *
 **********************************************************************************/
void alienIsShot(alien_t* alien, bullet_t* spaceshipBullet); //no

//Inicializa posicion y vidas.
//ACORDARSE DE INICIALIZAR LO DEL SCORE Y EL TIPO DE ALIEN.
void initAliens(alien_t* aliens, int numAliens) {
    int i;
    if (numAliens < NUM_ALIENS) {
        for (i = 0; i < numAliens; i++) {
            //initPosition(&aliens[i].pos, , );
            //initBullet(&aliens[i].bullet, , , ALIEN_BULLET);
            //aliens[i].score = ;
            aliens[i].alive = ALIVE;
        }
        for (; i < NUM_ALIENS; i++) {
            aliens[i].alive = DEAD;
        }
    }
}

void updateAliens(alien_t* aliens, bullet_t* spaceshipBullet) {
    int i;
    if (spaceshipBullet->state == ON) {
        for (i = 0; i < NUM_ALIENS; i++) {
            alienIsShot(&aliens[i], spaceshipBullet);
        }
    }
    moveAliens(aliens);
}

void moveAliens(alien_t* aliens) {

}


void alienIsShot(alien_t* alien, bullet_t* spaceshipBullet) {
    if (comparePosition(alien->pos, spaceshipBullet->pos)) {
        alien->alive = DEAD;
        spaceshipBullet->state = OFF;
    }
}

//Devuelve la cantidad de aliens vivos, si es cero gano.
int lastAlien(alien_t* aliens) {
    int result = 0, i;
    for (i = 0; i < NUM_ALIENS; ++i) {
        if (aliens[i].alive == ALIVE) {
            ++result;
        }
    }
    return result;
}