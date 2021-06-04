#include "randomalien.h"

/**********************************************************************************
 * Función: moveRandomAlien                                                       *
 * Esta función se encarga de mover el alien para la derecha o la izquierda segun *
 * corresponda.                                                                   *
 **********************************************************************************/
void moveRandomAlien(alienRandom_t* alien);

/**********************************************************************************
 * Función: randomAlienIsShot                                                     *
 * Esta función se encarga de fijarse si le dispararon al alien.	              *
 **********************************************************************************/
void randomAlienIsShot(alienRandom_t* alien, bullet_t* bullet);

void initRandomAlien(alienRandom_t* alien) {
    alien->alive = DEAD;
}

void randomAlienIsBorn(alienRandom_t* alien, int ciclosRandom) {
    //srand(time(NULL));
    alien->alive = ALIVE;
    int x;
    if ((ciclosRandom % 2) == 0) {
        x = 0;
        alien->direction = DERECHA;
    }
    else if ((ciclosRandom % 2) == 0) {
        x = WIDTH - 1;
        alien->direction = IZQUIERDA;
    }
    initPosition(&alien->pos, x, RANDOM_ALIEN_POS_Y);
    alien->puntaje = rand() % (MAX_POINTS);
}

void updateRandomAlien(alienRandom_t * alien, bullet_t* bullet){
    if (alien->alive){
        if (bullet->state == ON) {
            randomAlienIsShot(alien, bullet);
        }
        moveRandomAlien(alien);
    }   
}

void moveRandomAlien(alienRandom_t* alien) {
    switch(alien->direction){
        case DERECHA:
            if (alien->pos.x == (WIDTH - 1)){
                alien->alive = DEAD;
            }
            else{
                changePosition (&alien->pos, 1 , 0);
            }
            break;
        case IZQUIERDA:
            if (alien->pos.x == 0){
                alien->alive = DEAD;
            }
            else{
                changePosition (&alien->pos, -1 , 0);
            }
            break;
    }
}

void randomAlienIsShot(alienRandom_t* alien, bullet_t* bullet){
    if ((comparePosition(alien->pos, bullet->pos))&&(bullet->type == SPACESHIP_BULLET)){
        alien->alive = DEAD;
        bullet->state = OFF;
    }
}

