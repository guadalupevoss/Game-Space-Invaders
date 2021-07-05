#include "play.h"
#include <stdlib.h>
#include <time.h> 

//Esta funcion se encarga de todo el funcionamiento del juego.
int playSpaceInvaders(graphics_t* graphics, player_t* player) {
	//Ponemos los valores iniciales de los estados y los puntos del jugador.
	player->points = 0;
	int doExit = 0;
	int eventState = NOTHING;
	int newMenuState = PLAY;
	int i, ciclosTotal = 0, ciclosRandom;
	int frames = 0;
	int randomNumber;
	int level = 1;

	//Creamos e inicializamos todos los objetos.
	alien_t aliens[NUM_ALIENS];
	initAliens(aliens, level);
	barriers_t barriers[NUM_BARRIERS];
	initBarriers(barriers);
	spaceship_t spaceShip;
	initSpaceship(&spaceShip);
	alienRandom_t alienRandom;
	initRandomAlien(&alienRandom);


	srand(time(NULL));
	ciclosRandom = rand() % (1000);

	while (!doExit) {
		//Agarramos un nuevo evento dentro de la cola.
		eventState = getEvent(*graphics);
		switch (eventState) {
			//Si el estado es NOTHING entonces no hubo ningun evento nuevo en la cola.
			case NOTHING:
				break;
			//Si el estado es SS_BULLET entonces se disparo una bala de la nave.
			case SS_BULLET:
				throwBullet(&spaceShip);
				break;
			//Si el estado es SS_MOVE_R entonces se movio la nave para la derecha.
			case SS_MOVE_R:
				moveSpaceship(DERECHA, &spaceShip);
				break;
			//Si el estado es SS_MOVE_L entonces se movio la nave para la izquierda.
			case SS_MOVE_L:
				moveSpaceship(IZQUIERDA, &spaceShip);
				break;
			//Si el estado es PAUSE entonces se puso en pausa el juego. 
			case PAUSE:
				newMenuState = pause(graphics);
				break;
			//Si el estado es EXIT se quiere salir de la partida.
			case EXIT:
				doExit = 1;
				break;
		}
		
		//Si el estado no es PLAY, debemos ir a ese estado y salir del juego.
		if(newMenuState != PLAY){
			doExit = 1;
		}

		//Si llego a la cantidad de ciclos establecida de manera random y el alienRandom esta muerto entonces lo revivo y establezco un nuevo numero de ciclos random.
		if((ciclosTotal == ciclosRandom) && (alienRandom.alive == DEAD)){
			randomAlienIsBorn(&alienRandom, ciclosRandom);
			ciclosRandom = rand() % (1000);
			ciclosTotal = 0;
		}

		//Mientras haya aliens vivos hago todas las actualizaiones, de los aliens, de las barreras, del random alien, de la nave y de todas las balas.
		if (lastAlien(aliens)) {
			updateAliens(aliens, &spaceShip.bullet, frames, player, level);
			updateBarriers(barriers, aliens, &spaceShip.bullet);
			updateRandomAlien(&alienRandom, &spaceShip.bullet, frames, player);
			for (i = (NUM_ALIENS - 1); i >=0; --i) {
				//Si la nave se quedo sin vidas entonces se termina el juego y pierde. Cambio el estado a menu y salgo.
				if (updateSpaceship(&aliens[i].bullet, &spaceShip) == 1){
					printGameOver(graphics);
					updateGraphics();
					doExit = 1;
					newMenuState = MENU;
				}
				
				else if (aliens[i].bullet.state == ON) {
					updateBullet(&aliens[i].bullet, frames);
				}
				
				//Si los aliens llegan a la posicion de las barreras entonces el jugador no fue capaz de dispararles y pierde.
				else if((aliens[i].alive==ALIVE)&&(aliens[i].pos.y == BARRIER_POS_Y)){
					printGameOver(graphics);
					updateGraphics();
					doExit = 1;
					newMenuState = MENU;
					i = 0; 

				}
			}
			if (spaceShip.bullet.state == ON) {
				updateBullet(&spaceShip.bullet, frames);
			}
			//Si llego a la cantidad de fraes necesarios tiro una bala nueva de aliens.
			if ((frames % BULLET_FRAMES) == 0) {
				randomNumber = rand() % (NUM_ALIENS);
				if ((aliens[randomNumber].alive == ALIVE) && (aliens[randomNumber].bullet.state == OFF)) {
					throwAlienBullet(&aliens[randomNumber]);
				}
			}
		}

		//Si no quedan aliens vivos entonces reinicio todo.
		else{
			++level;
			//Para que no queden leds prendidos cuando se usa con la RASPI.
			clearSpaceInvaders();
			//Volvemos a inicializar los objetos.
			initAliens(aliens, level);
			initBarriers(barriers);
			initSpaceship(&spaceShip);
			initRandomAlien(&alienRandom);
		}
		if (doExit != 1) {
			printSpaceInvaders(graphics, player, aliens, barriers, &spaceShip, &alienRandom, level, frames);
		}

		if (ciclosTotal > 1000) {
			ciclosTotal = 0;
		}
		else {
			++ciclosTotal;
		}
		++frames;
	}
	graphics->state = newMenuState;
	return newMenuState;
}


