#include "play.h"
#include <stdlib.h>
#include <time.h>

//enum{SS_BULLET = 1, SS_MOVE_R, SS_MOVE_L, PAUSE, EXIT_P}; 

int playSpaceInvaders(graphics_t* graphics, player_t* player) {
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
		eventState = getEvent(*graphics);
		switch (eventState) {
			case NOTHING:
				break;
			case SS_BULLET:
				throwBullet(&spaceShip);
				break;
			case SS_MOVE_R:
				moveSpaceship(DERECHA, &spaceShip);
				break;
			case SS_MOVE_L:
				moveSpaceship(IZQUIERDA, &spaceShip);
				break;
			case PAUSE:
				newMenuState = pause(graphics);
				break;
			case EXIT:
				doExit = 1;
				break;
		}

		
		//Que si no esta en play se vaya al estado q corresponde, onda si se pasa a menu tiene q salir de play e imprimir el menu otra vez.
		if(newMenuState != PLAY){
			doExit = 1;
		}

		//Si llego a la cantidad de ciclos establecida de manera random y el alienRandom esta muerto entonces lo revivo y establezco un nuevo numero de ciclos random.
		if((ciclosTotal == ciclosRandom) && (alienRandom.alive == DEAD)){
			randomAlienIsBorn(&alienRandom, ciclosRandom);
			ciclosRandom = rand() % (1000);
			ciclosTotal = 0;
		}

		if (lastAlien(aliens)) {
			updateAliens(aliens, &spaceShip.bullet, frames, player, level);
			updateBarriers(barriers, aliens, &spaceShip.bullet);
			updateRandomAlien(&alienRandom, &spaceShip.bullet, frames, player);
			for (i = (NUM_ALIENS - 1); i >=0; --i) {
				if (updateSpaceship(&aliens[i].bullet, &spaceShip) == 1){
					printGameOver(graphics);
					updateGraphics();
					doExit = 1;
					newMenuState = MENU;
				}
				else if (aliens[i].bullet.state == ON) {

					updateBullet(&aliens[i].bullet, frames);
				}
				else if((aliens[i].alive==ALIVE)&&(aliens[i].pos.y == BARRIER_POS_Y)){
					printGameOver(graphics);
					updateGraphics();
					doExit = 1;
					newMenuState = MENU;
					i = 0; //Para que salga del for.

				}
			}
			if (spaceShip.bullet.state == ON) {
				updateBullet(&spaceShip.bullet, frames);
			}
			if ((frames % BULLET_FRAMES) == 0) {
				randomNumber = rand() % (NUM_ALIENS);
				if ((aliens[randomNumber].alive == ALIVE) && (aliens[randomNumber].bullet.state == OFF)) {
					throwAlienBullet(&aliens[randomNumber]);
				}
			}
		}
		else{
			++level;
			clearSpaceInvaders();
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


