#include "menu.h"
#include "graphics.h"

int stateMenu(graphics);

int menu(graphics_t graphics) {

    int doExitMenu = 0, menuState = MENU;

    while (!doExitMenu) {
        menuState = stateMenu(graphics); //Se fija si apretaron algo y cambia el estado

        if (menuState != MENU) {
            doExitMenu = 1;
        }
        else {
            //Imprime el menú.
            printMenu(graphics); //Adentro de esta tiene que haber un static state, que diga que opcion se esta "mostrando"
        }
    }
    return menuState;
}