#include "spaceInvaders.h"

//Inicializa lo que necesita spaceInvaders.
void initSpaceInvaders(void);
//Inicializa la variables del jugador.
void initPlayer(void);


//Limpia un arreglo de char de cantidad de caracteres countChar.
clearArr(char arr[], int countChar);


int spaceInvaders(void) {
	//Variable para controlar la salida del while.
	int doExit = 0;
	//Una variable para cambiar el esado del juego. Inicialmente es menú. La función menú será la encargada de cambiarla.
	int estado = MENU;
	char playerName[]
		//Inicializo lo necesario para Space Invaders.
		initSpaceInvaders();

	while ((!doExit))

		switch (estado) {
			//Entra al menú (que es otro while) y devuelve el estado cuando se cambia. 
		case MENU:
			estado = menu();
			break;
			//Si el estado es PLAY, entra al juego. 
			//Si se cierra el display devuelve EXIT. Ante un error devuelve ERROR. Si se vuelve al menú o pierde devuelve el puntaje.
		case PLAY:
			estado = playSpaceInvaders();
			break;
			//Entra a los highsocres. 
			//Si se cierra el display cierra el display devuelve EXIT. En caso contrario devuelve MENU.
		case HIGHSCORE:
			estado = showHighscore();
			break;
			//Cierra el programa.
		case EXIT:
			doExit = 1;
			break;
			//Cierra el programa y avisa que hubo un error.
		case ERROR:
			doExit = 1;
			break;
			//Cuando se manda el puntaje entra acá.
		default:
			player.score = estado;
			//player.name= funcion Ingresar nombre. 
			//Cargar Score
			estado = MENU;
			break;
		}

	//Si hay un error devuelve un ERROR_SPACE_INCADERS
	if (estado == ERROR) {
		return ERROR_SPACE_INCADERS;
	}
	//Si no hay un error devuelve un OK_SPACE_INCADERS
	else {
		return OK_SPACE_INCADERS;
	}
}


void initSpaceInvaders(void) {
	initPlayer();
	initGraphics();
}
void initPlayer(*) {
	player.score = 0;
	clearArr(&player.name, NAME_LENGHT);
}

clearArr(char* arr, int countChar) {

	int i = 0;
	for (i = 0; i < countChar; ++i) {
		arr[i] = ' ';
	}
}