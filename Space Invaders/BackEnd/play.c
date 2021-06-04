#include "play.h"

/*
Idea del juego:
- Init todo: ordenar aliens
- Updates
- Imprimir
*/

//enum{SS_BULLET = 1, SS_MOVE_R, SS_MOVE_L, PAUSE, EXIT_P}; 

int playSpaceInvaders(graphics_t* graphics, player_t* player) {
	player->points = 0;
	int doExit = 0;
	int eventState = NOTHING;
	int newMenuState = PLAY;
	int i, ciclosTotal = 0, ciclosRandom; 

	//Creamos e inicializamos todos los objetos.
	alien_t aliens[NUM_ALIENS];
	initAliens(aliens, INIT_NUM_ALIENS);
	barriers_t barriers[NUM_BARRIERS];
	initBarriers(barriers);
	spaceship_t spaceShip;
	initSpaceship(&spaceShip);
	alienRandom_t alienRandom;
	initRandomAlien(&alienRandom);


	srand(time(NULL));
	ciclosRandom = rand() % (1000);

	while (!doExit) {
		//eventState = getEvent();
		switch (eventState) {
			case NOTHING:
				break;
			case SS_BULLET:
				printf("TIRA BALA\n");
				throwBullet(&spaceShip);
				break;
			case SS_MOVE_R:
				printf("SE MUEVE DERECHA\n");
				moveSpaceship(DERECHA, &spaceShip);
				break;
			case SS_MOVE_L:
				printf("SE MUEVE IZQUIERDA\n");
				moveSpaceship(IZQUIERDA, &spaceShip);
				break;
			case PAUSE:
				printf("pausa\n");
				//newMenuState = pause(graphics);
				break;
			case EXIT:
				doExit = 1;
				break;
		}

		/*
			//Que si no esta en play se vaya al estado q corresponde, onda si se pasa a menu tiene q salir de play e imprimir el menu otra vez.
			if(newMenuState != PLAY){
				doExit = 1;
			}
		*/

		//clearSpaceInvaders(graphics, aliens, barriers, &spaceShip, &alienRandom);

		//Si llego a la cantidad de ciclos establecida de manera random y el alienRandom esta muerto entonces lo revivo y establezco un nuevo numero de ciclos random.
		if((ciclosTotal == ciclosRandom) && (alienRandom.alive == DEAD)){
			randomAlienIsBorn(&alienRandom, ciclosRandom);
			ciclosRandom = rand() % (1000);
			ciclosTotal = 0;
		}

		//Actualizamos todos los objetos
		//playerScore += updateAliens(aliens, &spaceShip.bullet);
		updateAliens(aliens, &spaceShip.bullet);
		updateBarriers(barriers, aliens, &spaceShip.bullet);
		//playerScore += updateRandomAlien(&alienRandom, &spaceShip.bullet);
		updateRandomAlien(&alienRandom, &spaceShip.bullet);
		for (i = 0; i < NUM_ALIENS; ++i) {
			if (updateSpaceship(&aliens[i].bullet, &spaceShip)) { 
			}

		}

		printSpaceInvaders(graphics, aliens, barriers, &spaceShip, &alienRandom);
		if (ciclosTotal > 1000) {
			ciclosTotal = 0;
		}
		else {
			++ciclosTotal;
		}
	}

	return newMenuState;
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
