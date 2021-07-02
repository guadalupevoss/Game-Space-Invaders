#include <stdint.h>
#include "BackEnd/spaceInvaders.h"

int main(void) {

    //Función que va al juego.
    if (spaceInvaders() == OK_SPACE_INVADERS) {
        printf("Ok Space Invaders.\n");
    }
    else{
        printf("ERROR en Space Invaders.\n");
    }

    return 0;
}