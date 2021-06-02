#include "spaceInvaders.h"

int spaceInvaders(void) {

	int doExit = 0;
	int error = 0;
	int score = 0;
	int estado = MENU;

while((!doExit)&&(!error))

	switch (estado) {
	
	//Entra al menú (que es otro while) y devuelve el estado. 
	case MENU:
		estado = menu();
		break;
	//Entra al juego. 
	case PLAY:
		estado = playSpaceInvaders();
		break;
	//Entra a los highsocres.
	case HIGHSCORE:
		estado = showHighscore();
		break;
	//Cierra el programa.
	case EXIT:
		doExit = 1;
		break;
	//Cierra el programa y avisa que hubo un error.
	case ERROR:
		error = 1;
		break;
	default:
		score = estado;
		break;
	}
}