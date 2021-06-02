#include <stdint.h>
#include "../Space Invaders/BackEnd/spaceInvaders.h"

int main(void) {

    //Función que va al juego.
    if (spaceInvaders() == OK_SPACE_INCADERS) {
        printf("Ok Space Invaders.\n");
    }
    else if (spaceInvaders() == ERROR_SPACE_INCADERS) {
        printf("ERROR en Space Invaders.\n");
    }

    return 0;
}