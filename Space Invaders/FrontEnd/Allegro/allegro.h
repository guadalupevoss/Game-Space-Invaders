#ifndef ALLEGRO_H
#define ALLEGRO_H

#ifndef RASPI
//Include de allegro.
#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "../../BackEnd/barriers.h"
#include "../../BackEnd/randomalien.h"
#include "../../BackEnd/spaceship.h"
#include "../../BackEnd/highscore.h"

//ver si esta bien esto
#include "../../BackEnd/highscore.h"

typedef struct {
	int state;

	ALLEGRO_DISPLAY* display;
	ALLEGRO_TIMER* timer;
	ALLEGRO_EVENT_QUEUE* eventQueue;
	ALLEGRO_FONT* font;

	//Para el menu(Podría ser un struct para el menú).
	ALLEGRO_BITMAP* menuBitmaps[CANT_BTM_MENU];
	ALLEGRO_SAMPLE* menuSamples[CANT_SAMPL_MENU];

	//Para los aliens
	ALLEGRO_BITMAP* aliensBitmaps[CANT_TIPOS_ALIEN];

	//Para las barreras
	ALLEGRO_BITMAP* barriersBitmaps[CANT_TIPOS_BARRERAS];

	//Para el random alien
	ALLEGRO_BITMAP* randomAlienBitmap;

	//Para la bala
	ALLEGRO_BITMAP* bulletBitmap;

	//Para la nave
	ALLEGRO_BITMAP* spaceshipBitmap;

	//Para las vidas (2) lives
	ALLEGRO_BITMAP* livesBitmap[CANT_LIVES_BTM];

	//Para fondos extra (game over, high scores, menu pausa)
	ALLEGRO_BITMAP* fondosExtra[CANT_FONDOS_EXTRA];

}graphics_t;

//Estados del juego
enum { NOTHING = 0, SS_BULLET, SS_MOVE_R, SS_MOVE_L, PAUSE, EXIT };
enum { MENU_GR = 0, PLAY_GR, HIGHSCORE_GR, EXIT_GR, FONDO_GR, SPACEINVADERS_GR };

enum{ALIEN0=0, ALIEN1, ALIEN2, ALIEN3, ALIEN4, DEADALIEN};
enum{BARRIER0=0, BARRIER1, BARRIER2, BARRIER3, DEADBARRIER};
//enum{DEAD=0, ALIVE};
enum{GAMEOVER=0, HIGHSCORES, MENUPAUSE};


//Estados del MENU
enum { MENU = 0, PLAY, HIGHSCORE, EXIT_M, ERROR};
//Estados del MENU DE PAUSA
enum { MENU_PAUSE=1, PLAY_PAUSE, EXIT_PAUSE, ERROR_PAUSE };

//Inicializa Allegro y sus variables.
int initGraphics(graphics_t* allegro);
//Destruye Allegro y las variables.
void destroyGraphics(graphics_t* allegro);
//Función que refresca el display.
void updateGraphics(void);
//Función que imprime el menú.
void printMenu(graphics_t* graphics);
//Función que se fija si cambió el estado (si se presionó algún botón o saltó error) y devuelve el estado indicado.
int stateMenu(graphics_t* graphics);
//Imprime ej juego.
void printSpaceInvaders(graphics_t* graphics, player_t* player, alien_t* aliens, barriers_t* barriers, spaceship_t* spaceship, alienRandom_t* rAlien, int level, int frames);

int getEvent(graphics_t graphics);

int statePause(graphics_t* graphics);
void printPause(graphics_t* graphics);
void printGameOver(graphics_t* graphics);
void clearSpaceInvaders(void);
int print_scores(graphics_t* graphics, player_t highscores[MAXSCORES]);
void read_keyboard(player_t* player, graphics_t* graphics);

/**********************************************************************************
 * Función: clearArr                                                              *
 * Esta función se encarga de limpiar un arreglo de char de cantidad de caracteres*
 * countChar.																	  *
 **********************************************************************************/
void clearArr(char* arr, int countChar);


#endif // ! RASPI

#endif //ALLEGRO_H

