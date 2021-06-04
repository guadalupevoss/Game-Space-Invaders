#include "play.h"

/*
Idea del juego:
- Init todo: ordenar aliens
- Updates
- Imprimir
*/

enum{NOTHING=0, SS_BULLET, SS_MOVE_R, SS_MOVE_L, PAUSE, EXIT};

int playSpaceInvaders(graphics_t* graphics, int* playerScore) {
	int doExit = 0;
	int eventState;
	int i; 

	//Creamos e inicializamos todos los objetos.
	alien_t aliens[NUM_ALIENS];
	initAliens(&aliens, INIT_NUM_ALIENS);
	barriers_t barriers[NUM_BARRIERS];
	initBarriers(&barriers);
	spaceship_t spaceShip;
	initSpaceship(&spaceShip);
	alienRandom_t alienRandom;
	initRandomAlien(&alienRandom);

	while (!doExit) {
		//eventState = getEvent();
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
				//funcion de pausa
				break;
			case EXIT:
				doExit = 1;
				break;
		}
		//(graphics_t* graphics, alien_t* aliens, barriers_t* barriers, spaceship_t* spaceship, alienRandom_t* rAlien)
		//clearSpaceInvaders(graphics, aliens, barriers, &spaceShip, &alienRandom);

		//Actualizamos todos los objetos
		//playerScore += updateAliens(aliens, &spaceShip.bullet);
		updateBarriers(barriers, aliens, &spaceShip.bullet);
		//playerScore += updateRandomAlien(&alienRandom, &spaceShip.bullet);
		for (i = 0; i < NUM_ALIENS; ++i) {
			if (updateSpaceship(&aliens[i].bullet, &spaceShip)) { 
			}

		}

		//printSpaceInvaders(graphics, aliens, barriers, &spaceShip, &alienRandom);
	}
}


//srand(time(NULL));  //Agregarlo al principio de play QUE SE HAGA UNA SOLA VEZ

//ciclos_random = rand()%(1000);			//Esto me dice cuando se va a crear el alien random

/*
	if(!lastAlien()){
		updateAliens();
	}
	else{
		initAliens;
		etc...
	}
*/
