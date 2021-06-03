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

#include "raspi.h"

//Inicializa Raspi y sus variables.
int initGraphics(graphics_t* allegro) {
    disp_init();
    joy_init();
    //init_sound();
    draw_play();
}
//Destruye Raspi y las variables.
int destroyGraphics(graphics_t* allegro) {
    disp_clear();
}
//Función que imprime el menú.
void printMenu(graphics_t* graphics) {
	switch (graphics->state)
	{
		case PLAY:
			draw_play();
			//play_highscore();
			break;
		case HIGHSCORE:
			draw_highscore();
			//play_exit();
			break;
		case EXIT:
			draw_exit();
			//play_play();
			break;
	}
}
//Función que se fija si cambió el estado (si se presionó algún botón o saltó error) y devuelve el estado indicado.
int stateMenu(graphics_t* graphics) {
	int newState;
	joy_update();

	jcoord_t myCoords;
	myCoords = joy_get_coord();
	jswitch_t mySwitch;
	mySwitch = joy_get_switch();

	//Se fija si se mueve el joystick para la izquierda o la derecha. En caso de que si pasa a la pantalla correspondiente siguiente. Si se aprieta el botón del joystick se selecciona esa opción.
	while (mySwitch != J_PRESS){
		joy_update();
		myCoords = joy_get_coord();
		mySwitch = joy_get_switch();

		if (myCoords.x > 50){
			switch (graphics->state)
			{
				case PLAY:
					graphics->state = HIGHSCORE;
					break;
				case HIGHSCORE:
					graphics->state = EXIT;
					break;
				case EXIT:
					graphics->state = PLAY;
					break;
			}
		}

		else if (myCoords.x < (-50))
		{
			switch (graphics->state)
			{
				case PLAY:
					graphics->state = EXIT;
					break;
				case HIGHSCORE:
					graphics->state = PLAY;
					break;
				case EXIT:
					graphics->state = HIGHSCORE;
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
			case PLAY:
				newState = PLAY;
				break;
			case HIGHSCORE:
				newState = HIGHSCORE;
				break;
			case EXIT:
				newState = EXIT;
				break;
		}
	}

	disp_update();
}
//Se encarga de hacer el flip display.
void updateGraphics(void) {
	disp_update();
}