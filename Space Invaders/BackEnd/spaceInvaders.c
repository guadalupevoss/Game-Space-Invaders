#include "spaceInvaders.h"


/**********************************************************************************
 * Función: initSpaceInvaders                                                     *
 * Esta función se encarga de inicializar lo que necesita spaceInvaders.		  *
 **********************************************************************************/
int initSpaceInvaders(player_t* player, graphics_t* graphics);

/**********************************************************************************
 * Función: initPlayer                                                            *
 * Esta función se encarga de inicializar las variables del jugador.			  *
 **********************************************************************************/
void initPlayer(player_t* player);

int spaceInvaders(void) {
	//Variable para controlar la salida del while.
	int doExit = 0;
	//Una variable para cambiar el esado del juego. Inicialmente es menú. La función menú será la encargada de cambiarla.
	int estado = MENU;
	//Variable con los datos del jugador.
	player_t player;
	player_t highscores[MAXSCORES];

	//Variable con recursos gráficos.
	graphics_t graphics;

	//Inicializo lo necesario para Space Invaders.
	if (initSpaceInvaders(&player, &graphics) == ERROR_SPACE_INVADERS) {
		doExit = 1;
		estado = ERROR;
	}

	scoreboardInit(highscores);

	while ((!doExit)) {
		switch (estado) {
			//Entra al menú (que es otro while) y devuelve el estado cuando se cambia. 
		case MENU:
			estado = menu(&graphics);
			break;
			//Si el estado es PLAY, entra al juego. 
			//Si se cierra el display devuelve EXIT. Ante un error devuelve ERROR. Si se vuelve al menú o pierde devuelve el puntaje.
		case PLAY:
			estado = playSpaceInvaders(&graphics, &player);
			if (testNewScore(&player, highscores)) {
				//anotar el nombre
				read_keyboard(&player, &graphics);
				if (player.name[0] != '\0') {
					enterNewHighscore(&player, highscores);
				}
			}
			break;
			//Entra a los highsocres. 
			//Si se cierra el display cierra el display devuelve EXIT. En caso contrario devuelve MENU.
		case HIGHSCORE:
			estado = print_scores(&graphics, highscores);
			break;
		//Cierra el programa.
		case EXIT_M:
			doExit = 1;
			break;
			//Cierra el programa y avisa que hubo un error.
		case ERROR:
			doExit = 1;
			break;
			//Cuando se manda el puntaje entra acá.
		default:
			//player.score = estado;
			//player.name= funcion Ingresar nombre. 
			//Cargar Score al txt.
			estado = MENU;
			break;
		}
	}

	destroyGraphics(&graphics);
	//Si hay un error devuelve un ERROR_SPACE_INCADERS.
	if (estado == ERROR) {
		return ERROR_SPACE_INVADERS;
	}
	//Si no hay un error devuelve un OK_SPACE_INCADERS.
	else {
		return OK_SPACE_INVADERS;
	}
}

int initSpaceInvaders(player_t* player, graphics_t* graphics) {
	initPlayer(player);
	if (initGraphics(graphics) == ERROR_GRAPHICS)
	{
		return ERROR_SPACE_INVADERS;
	}
	return OK_SPACE_INVADERS;
}

void initPlayer(player_t* player) {
	player->points = 0;
	clearArr(player->name, NAMELENGHT);
}
