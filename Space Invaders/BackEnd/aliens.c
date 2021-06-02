#include "aliens.h"

//Inicializa posicion y vidas.
void initAliens(alien_t* aliens, int numAliens) {
    int i;
    if (numAliens < NUM_ALIENS) {
        for (i = 0; i < numAliens; i++) {
            //initPosition(&aliens[i].pos, , );
            //initBullet(&aliens[i].bullet, , , ALIEN_BULLET);
            //aliens[i].score = ;
            aliens[i].alive = ALIVE;
        }
    }
}

void updateAliens(void) {

}

void moveAliens(void) {

}

void alienIsShot(void) {

}

void lastAlien(void) {

}