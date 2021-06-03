#include "menu.h"
#include "../FrontEnd/graphics.h"


int menu(graphics_t graphics) {

    int doExitMenu = 0, menuState = MENU;

    while (!doExitMenu) {

        //Se fija si apretaron algo y cambia el estado
        menuState = stateMenu(&graphics);

        if (menuState != MENU) {
            doExitMenu = 1;
        }
        else {
            //Imprime el menú.
            printMenu(&graphics); //Adentro de esta tiene que haber un static state, que diga que opcion se esta "mostrando"
            updateGraphics();
        }
    }
    //Devuelve el estado
    return menuState;
}