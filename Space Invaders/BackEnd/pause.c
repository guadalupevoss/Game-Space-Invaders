#include "pause.h"


//Estados del MENU DE PAUSA
//enum {NOTHING = 0, MENU_PAUSE, PLAY_PAUSE, ERROR_PAUSE};

int pause(graphics_t* graphics) {

	int doExitPause = 0, pauseState = NOTHING;

	while (!doExitPause) {

		//Se fija si apretaron algo y cambia el estado. Además cambia la variable state de graphics (que indica a dónde está apuntando).
		pauseState = statePause(graphics);

		if (pauseState != NOTHING) {
			doExitPause = 1;
		}

		else if (pauseState == NOTHING){
			//Imprime el menú.
			printPause(graphics); //Adentro de esta tiene que haber un static state, que diga que opcion se esta "mostrando"
			updateGraphics();
		}
	}

	//Tengo que cambiar el estado del graphics para q si no esta en play que salga del juego.
	if (pauseState == PLAY_PAUSE){
		graphics->state = PLAY_GR;
		pauseState = PLAY;
	}
	else if (pauseState == EXIT_PAUSE){
		graphics->state = EXIT_M;
		pauseState = EXIT_M;
	}
	else if(pauseState == MENU_PAUSE){
		graphics->state = MENU;
		pauseState = MENU;
	}
	//Devuelve el estado
	return pauseState;
}