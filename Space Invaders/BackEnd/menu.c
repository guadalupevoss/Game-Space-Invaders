#include "menu.h"
#include "../FrontEnd/graphics.h"


int menu(graphics_t* graphics) {

	int doExitMenu = 0, menuState = MENU;

	while (!doExitMenu) {

		//Se fija si apretaron algo y cambia el estado. Además cambia la variable state de graphics (que indica a dónde está apuntando).
		menuState = stateMenu(graphics);

		if (menuState != MENU) {
			doExitMenu = 1;
		}

		else if (menuState == MENU){
			//Imprime el menú.
			printMenu(graphics); //Adentro de esta tiene que haber un static state, que diga que opcion se esta "mostrando"
			updateGraphics();
		}
	}
	//Devuelve el estado
	return menuState;
}
