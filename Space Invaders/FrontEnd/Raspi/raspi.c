/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   raspi.c
 * Author: mpaget
 * 
 * Created on February 21, 2021, 11:21 AM
 */

#ifdef RASPI

#include "raspi.h"

////Estados del juego
//enum { NOTHING = 0, SS_BULLET, SS_MOVE_R, SS_MOVE_L, PAUSE, EXIT };

void printLetter(char letter, int x);
void selectNumber(int number[NUMBERLENGHT], int cifra);
void printName(player_t highscores[MAXSCORES], int contNames);
void readNumber(unsigned long num, int number[NUMBERLENGHT]);
int letterSize(char letter);


//Inicializa Raspi y sus variables.
int initGraphics(graphics_t* allegro) {
    disp_init();
    joy_init();
    //init_sound();
    draw_play();
	return OK_GRAPHICS;
}
//Destruye Raspi y las variables.
void destroyGraphics(graphics_t* allegro) {
    disp_clear();
}
//Función que imprime el menú.
void printMenu(graphics_t* graphics) {
	switch (graphics->state)
	{
		case PLAY_GR:
			draw_play();
			//play_highscore();
			break;
		case HIGHSCORE_GR:
			draw_highscore();
			//play_exit();
			break;
		case EXIT_GR:
			draw_exit();
			//play_play();
			break;
	}
}

//Función que se fija si cambió el estado (si se presionó algún botón o saltó error) y devuelve el estado indicado.
int stateMenu(graphics_t* graphics) {
	int newState = MENU;
	joy_update();

	jcoord_t myCoords;
	myCoords = joy_get_coord();
	jswitch_t mySwitch;
	mySwitch = joy_get_switch();

	if ((graphics->state != HIGHSCORE_GR) && (graphics->state != EXIT_GR)) {
		graphics->state = PLAY_GR;
	}

	//Se fija si se mueve el joystick para la izquierda o la derecha. En caso de que si pasa a la pantalla correspondiente siguiente. Si se aprieta el botón del joystick se selecciona esa opción.
	if (mySwitch != J_PRESS){
		joy_update();
		myCoords = joy_get_coord();
		mySwitch = joy_get_switch();

		if (myCoords.x > 50){
			switch (graphics->state)
			{
				case PLAY_GR:
					graphics->state = HIGHSCORE_GR;
					disp_clear();
					break;
				case HIGHSCORE_GR:
					graphics->state = EXIT_GR;
					disp_clear();
					break;
				case EXIT_GR:
					graphics->state = PLAY_GR;
					disp_clear();
					break;
			}
		}

		else if (myCoords.x < (-50))
		{
			switch (graphics->state)
			{
				case PLAY_GR:
					graphics->state = EXIT_GR;
					disp_clear();
					break;
				case HIGHSCORE_GR:
					graphics->state = PLAY_GR;
					disp_clear();
					break;
				case EXIT_GR:
					graphics->state = HIGHSCORE_GR;
					disp_clear();
					break;
			}
		}

		while (myCoords.x < -50)
		{
			joy_update();
			myCoords = joy_get_coord();
			mySwitch = joy_get_switch();
		}
		while (myCoords.x > 50)
		{
			joy_update();
			myCoords = joy_get_coord();
			mySwitch = joy_get_switch();
		}
	}

	else if (mySwitch == J_PRESS)
	{
		while (mySwitch == J_PRESS)
		{
			joy_update();
			mySwitch = joy_get_switch();
		}
		switch (graphics->state)
		{
			case PLAY_GR:
				newState = PLAY;
				disp_clear();
				break;
			case HIGHSCORE_GR:
				newState = HIGHSCORE;
				disp_clear();
				break;
			case EXIT_GR:
				newState = EXIT_M;
				disp_clear();
				break;
		}
	}
	return newState;
}

//Se encarga de hacer el flip display.
void updateGraphics(void) {
	disp_update();
}

int getEvent(graphics_t graphics) {
	int newState = NOTHING;
	joy_update();

	jcoord_t myCoords;
	myCoords = joy_get_coord();
	jswitch_t mySwitch;
	mySwitch = joy_get_switch();

	if (myCoords.x > 10)
	{
		newState = SS_MOVE_R;
	}
	while ((myCoords.x > 10) && (myCoords.x < 100))
	{
		joy_update();
		myCoords = joy_get_coord();
	}

	if (myCoords.x < -10)
	{
		newState = SS_MOVE_L;
	}
	while ((myCoords.x < -10) && (myCoords.x > -100))
	{
		joy_update();
		myCoords = joy_get_coord();
	}

	//Si se movio para abajo, es pausa.
	if (myCoords.y < -100)
	{
		newState = PAUSE;
	}
	while (myCoords.y < -100)
	{
		joy_update();
		myCoords = joy_get_coord();
	}

	//Si se aprieta el botón del joystick se prende la bala.
	if (mySwitch == J_PRESS)//&&(!shot_reset))
	{
		newState = SS_BULLET;
	}
	while (mySwitch == J_PRESS)
	{
		joy_update();
		mySwitch = joy_get_switch();
	}
	return newState;
}

void printSpaceInvaders(graphics_t* graphics, player_t* player, alien_t* aliens, barriers_t* barriers, spaceship_t* spaceship, alienRandom_t* rAlien, int level, int frames) {
	static int prevSSX = INITIAL_SPASESHIP_POS_X;
	int numberAliens = getFilas(level) * getColumnas(level);
	int i;
	if ((spaceship->pos.x != prevSSX) && spaceship->lives) {
		if (prevSSX <= 13) {
			clearNave(prevSSX);
		}
		printNave(spaceship->pos.x);
		prevSSX = spaceship->pos.x;
	}
	clearAliens(aliens, numberAliens);
	printAliens(aliens, numberAliens);
	if (rAlien->alive) {
		if (rAlien->direction == DERECHA) {
			clearAlienRandom(rAlien->pos.x - 1, rAlien->pos.y);
		}
		else {
			clearAlienRandom(rAlien->pos.x + 1, rAlien->pos.y);
		}
		printAlienRandom(rAlien->pos.x, rAlien->pos.y);
	}
	printLives(spaceship->lives);
	for (i = 0; i < numberAliens; ++i) {
		if (aliens[i].bullet.state == ON) {
			clearBala(aliens[i].bullet.pos.x, aliens[i].bullet.pos.y - 1);
			printBala(aliens[i].bullet.pos.x, aliens[i].bullet.pos.y);
		}
	}

	if (spaceship->bullet.state == ON) {
		clearBala(spaceship->bullet.pos.x, spaceship->bullet.pos.y + 1);
		printBala(spaceship->bullet.pos.x, spaceship->bullet.pos.y);
	}
	printBarriers(barriers);
	updateGraphics();
}

void clearSpaceInvaders(void) {
	disp_clear();
}

//Función que imprime el menú de pausa.
void printPause(graphics_t* graphics) {
	switch (graphics->state)
	{
		case PLAY_PAUSE:
			draw_pause_play();
			break;
		case EXIT_PAUSE:
			draw_pause_exit();
			break;
		case MENU_PAUSE:
			draw_pause_menu();
			break;
	}
}

//Función que se fija si cambió el estado (si se presionó algún botón o saltó error) y devuelve el estado indicado.
int statePause(graphics_t* graphics) {
	static int numb = 0;
	int newState = NOTHING;
	joy_update();

	//Para que se imprima correctamente el menu de pausa, sin basura.
	if (numb == 0) {
		disp_clear();
		numb = 1;
	}

	jcoord_t myCoords;
	myCoords = joy_get_coord();
	jswitch_t mySwitch;
	mySwitch = joy_get_switch();

	if ((graphics->state != MENU_PAUSE) && (graphics->state != EXIT_PAUSE)) {
		graphics->state = PLAY_PAUSE;
	}

	//Se fija si se mueve el joystick para la izquierda o la derecha. En caso de que si pasa a la pantalla correspondiente siguiente. Si se aprieta el botón del joystick se selecciona esa opción.
	if (mySwitch != J_PRESS){
		joy_update();
		myCoords = joy_get_coord();
		mySwitch = joy_get_switch();

		if (myCoords.x > 50){
			switch (graphics->state)
			{
				case PLAY_PAUSE:
					graphics->state = MENU_PAUSE;
					disp_clear();
					break;
				case MENU_PAUSE:
					graphics->state = EXIT_PAUSE;
					disp_clear();
					break;
				case EXIT_PAUSE:
					graphics->state = PLAY_PAUSE;
					disp_clear();
					break;
			}
		}

		else if (myCoords.x < (-50))
		{
			switch (graphics->state)
			{
				case PLAY_PAUSE:
					graphics->state = EXIT_PAUSE;
					disp_clear();
					break;
				case MENU_PAUSE:
					graphics->state = PLAY_PAUSE;
					disp_clear();
					break;
				case EXIT_PAUSE:
					graphics->state = MENU_PAUSE;
					disp_clear();
					break;
			}
		}

		while (myCoords.x < -50)
		{
			joy_update();
			myCoords = joy_get_coord();
			mySwitch = joy_get_switch();
		}
		while (myCoords.x > 50)
		{
			joy_update();
			myCoords = joy_get_coord();
			mySwitch = joy_get_switch();
		}
	}

	if (mySwitch == J_PRESS)
	{
		while (mySwitch == J_PRESS)
		{
			joy_update();
			mySwitch = joy_get_switch();
		}
		switch (graphics->state)
		{
			case PLAY_PAUSE:
				newState = PLAY_PAUSE;
				disp_clear();
				break;
			case MENU_PAUSE:
				newState = MENU_PAUSE;
				disp_clear();
				break;
			case EXIT_PAUSE:
				newState = EXIT_PAUSE;
				disp_clear();
				break;
		}
	}

	return newState;
}

//Funciones para ingresar y mostrar un nuevo highscore

//	Esta funcion recibe un unsigned long y llena un arreglo con sus cifras	   
void readNumber(unsigned long num, int number[NUMBERLENGHT]){
	int contador;
	for (contador = (NUMBERLENGHT - 1); contador >= 0; contador--){
		number[contador] = num % 10;		//guardo en el arreglo cifra por cifra
		num = num / 10;
	}
}

/*Esta funcion recibe la lista con las estructuras de los highscores y el 
numero de la lista que quieras imprimir, e imprime el nombre que le corresponde 
(si le envia 1 imprime el nombre del mejor highscore)	*/
void printName(player_t highscores[MAXSCORES], int contNames){ //decia +1 puse -1 
	int contLetters;
	int nameSizeX = 0;
	for (contLetters = 0; contLetters < NAMELENGHT; contLetters++){  //calculo el tamano de la palabra
		char letter = highscores[contNames-1].name[contLetters];
		nameSizeX += letterSize(letter);
	}
	if (nameSizeX < 15){
		nameSizeX = 0;
		for (contLetters = 0; contLetters < NAMELENGHT; contLetters++){
			char letter = highscores[contNames-1].name[contLetters];
			printLetter(letter, contLetters + nameSizeX);
			nameSizeX += letterSize(letter);
		}
	}
	else if (nameSizeX == 15){ //si el nombre tiene tres letras de 5x5
		for (contLetters = 0; contLetters < NAMELENGHT; contLetters++){
			char letter = highscores[contNames-1].name[contLetters];
			printLetter(letter, contLetters * 5);   //imprime las tres letras pegadas (sino no entran de otra forma) 
			nameSizeX += letterSize(letter);
		}
	}
}

// Esta funcion recibe una letra y la imprime en el lugar indicado para el highscore.
void printLetter(char letter, int x){
	switch (letter){
		case 'A':
			draw_a(x, 6);
			break;
		case 'B':
			draw_b(x, 6);
			break;
		case 'C':
			draw_c(x, 6);
			break;
		case 'D':
			draw_d(x, 6);
			break;
		case 'E':
			draw_e(x, 6);
			break;
		case 'F':
			draw_f(x, 6);
			break;
		case 'G':
			draw_g(x, 6);
			break;
		case 'H':
			draw_h(x, 6);
			break;
		case 'I':
			draw_i(x, 6);
			break;
		case 'J':
			draw_j(x, 6);
			break;
		case 'K':
			draw_k(x, 6);
			break;
		case 'L':
			draw_l(x, 6);
			break;
		case 'M':
			draw_m(x, 6);
			break;
		case 'N':
			draw_n(x, 6);
			break;
		case 'O':
			draw_o(x, 6);
			break;
		case 'P':
			draw_p(x, 6);
			break;
		case 'Q':
			draw_q(x, 6);
			break;
		case 'R':
			draw_r(x, 6);
			break;
		case 'S':
			draw_s(x, 6);
			break;
		case 'T':
			draw_t(x, 6);
			break;
		case 'U':
			draw_u(x, 6);
			break;
		case 'V':
			draw_v(x, 6);
			break;
		case 'W':
			draw_w(x, 6);
			break;
		case 'X':
			draw_x(x, 6);
			break;
		case 'Y':
			draw_y(x, 6);
			break;
		case 'Z':
			draw_z(x, 6);
			break;

	}
}

//Recibe un numero y sus coordenadas y lo imprime
void printNumber(int num, int x, int y){
	switch (num) {
	case 0:
		draw_0(x, y);
		break;
	case 1:
		draw_1(x, y);
		break;
	case 2:
		draw_2(x, y);
		break;
	case 3:
		draw_3(x, y);
		break;
	case 4:
		draw_4(x, y);
		break;
	case 5:
		draw_5(x, y);
		break;
	case 6:
		draw_6(x, y);
		break;
	case 7:
		draw_7(x, y);
		break;
	case 8:
		draw_8(x, y);
		break;
	case 9:
		draw_9(x, y);
		break;
	}
}

//Esta funcion recibe una letra y devuelve el tamano de su coordenada x	
int letterSize(char letter){
	int size_x = 0;
	switch(letter){
		case 'A':
		case 'B':
		case 'C':
		case 'D':
		case 'E':
		case 'F':
		case 'G':
		case 'H':
		case 'J':
		case 'K':
		case 'L':
		case 'N':
		case 'O':
		case 'P':
		case 'Q':
		case 'R':
		case 'S':
		case 'U':
		case 'Z':
			size_x = 4;
			break;
		case 'I':
		case 'M':
		case 'T':
		case 'V':
		case 'W':
		case 'X':
		case 'Y':
			size_x = 5;
			break;
	}
	return size_x;
}

//Esta funcion recibe un arreglo y imprime 3 numeros correspondientes
void selectNumber(int number[NUMBERLENGHT], int cifra){
	int contador;
	for (contador = 0; (contador < 3)&&((cifra + contador) < 20); contador++){ 
		//imprimo el numero en su lugar respectivo
		printNumber(number[cifra + contador], (5 * contador) + 1, 13); 
		//5*contador+1 es una cuenta que calcula la coordenada x dependiendo si hablamos del primer numero el segundo o el tercero que se muestra
	}
}

void printGameOver(graphics_t* graphics) {
	disp_clear();
	draw_gameover();
}

void read_keyboard(player_t* player, graphics_t* graphics) {
	char letter_keyboard[NUMBER_OF_SCREENS][NAMELENGHT]; //matriz de todas las letras, cada pantalla es un arreglo de 3 letras
	init_keyboard(letter_keyboard);
	int contador;
	for (contador = 0; contador < NAMELENGHT; contador++){
		(player->name)[contador] = get_letter(letter_keyboard);
	}
	disp_clear();
}

int print_scores (graphics_t * graphics, player_t lista_scores[MAXSCORES]){ //enrealidad buscar cuando se define lista_scores
	int i;
	printf("\n\t\t\tNAME:\t\t\tSCORE\n\n");
	for (i = 0; i < MAXSCORES; ++i) {
		printf("\t\t\t%s\t\t\t%lu\n", lista_scores[i].name, lista_scores[i].points);
	}
	graphics->state = MENU;
	return MENU;
}




#endif