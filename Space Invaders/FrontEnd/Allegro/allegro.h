#ifndef ALLEGRO_H
#define ALLEGRO_H

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

//En caso de error las funciones devuelven ERROR_GRAPHICS, si todo está bien devuelven un OK_GRSPHICS.
#define ERROR_GRAPHICS -1
#define OK_GRAPHICS		0

#define FPS             60.0

#define MOVE_RATE       5.0 //Para el movimiento

//Tamaño del display
#define SCREEN_W 800
#define SCREEN_H 800

#define UNIDAD SCREEN_W/16

//Defines de la nave
#define NAVE_SIZE_X     40  //TAMAnO DE LA NAVE
#define NAVE_SIZE_Y     40
#define SPACESHIP_POS_Y SCREEN_H
#define INITIAL_SPASESHIP_POS_X SCREEN_W/2 
#define SPACESHIP_LIVES 3

//Defines de los aliens
#define ALIEN_SIZE_X    32  //TAMAnO DEL ALIEN
#define ALIEN_SIZE_Y    32
#define DISTANCIA_TECHO_Y   60  //DISTANCIA INICIAL ENTRE ALIEN Y BORDE SUPERIOR DE LA PANTALLA.
#define NUM_ALIENS		55
#define INITIAL_ALIEN_SPEED 50
#define CANT_TIPOS_ALIEN    6   //TIPOS DE ALIENS (CONTANDO LA IMAGEN DEL ALIEN MUERTO)
#define INITIAL_ALIEN_BULLET_SPEED	1.5
#define COLUMNAS        7   //COLUMNAS Y FILAS (DE ALIENS)MAXIMAS
#define FILAS           5

//Defines de las barreras
#define BARRERA_SIZE_X  52
#define BARRERA_SIZE_Y  42
#define NUM_BARRIERS   4
#define CANT_TIPOS_BARRERAS     5   //TIPOS DE BARRERAS (CONTANDO LA IMAGEN DE LA BARRERA MUERTA)


//Defines del alien random
#define RANDOM_ALIEN_POS_Y 5
#define RANDOM_ALIEN_SIZE_X 40  //Establece el tamaNo del alien random.
#define RANDOM_ALIEN_SIZE_Y 35
#define RANDOM_ALIEN_POSICION_Y  30 //PosiciOn en el eje y que mantendrA el alien random
#define RANDOM_ALIEN_SPEED  2

//Defines de las balas
#define BALA_SIZE_X     5   //TAMANO DE LA BALA (DEPENDE DE LA IMAGEN QUE TENGA)
#define BALA_SIZE_Y     14

//Defines de las imagenes
#define SCORE_SIZE_X    67  //TAMANO DE LA IMAGEN "SCORE"
#define SCORE_SIZE_Y    20
#define HEART_SIZE_X    33  //TAMANO DE IMAGEN DE CORAZON (VIVO Y MUERTO)
#define HEART_SIZE_Y    30
#define ESP_SCORE_NUM   15	//ESPACIO ENTRE LA PALABRA "SCORE" Y LOS NUMEROS
#define CARACTER_SCORE  11  //NUMERO DEL ARREGLO DONDE ESTA SCORE (y esto??????????????)
#define CIFRAS_SCORE    9
#define CANT_BTM_MENU	4	//Numero de bitmaps para el menú.
#define CANT_SAMPL_MENU	4	//Establece la cantidad de audios que se utilizan en el menú.
#define CANT_LIVES_BTM	2
#define CANT_FONDOS_EXTRA 3

//Defines para el highscore
#define FUENTE_SIZE			30
#define ENTER_PLAYER_NAME_X 200
#define ENTER_PLAYER_NAME_Y 190
#define PLAYER_NAME_X       200
#define PLAYER_NAME_Y       230
#define MESSAGE_X           200
#define MESSAGE_Y           290
#define MAXSCORES			10
#define NAMELENGHT			10
#define MAX_ARR_CARACTER	40 
#define DISTANCE_POINTS_PLAYER 250

typedef struct {
	ALLEGRO_DISPLAY*		display;
	ALLEGRO_TIMER*			timer;
	ALLEGRO_EVENT_QUEUE*	eventQueue;
	ALLEGRO_FONT*			font;

	//Para el menu(Podría ser un struct para el menú).
	ALLEGRO_BITMAP* menuBitmaps[CANT_BTM_MENU];
	ALLEGRO_SAMPLE* menuSamples[CANT_SAMPL_MENU];

	//Para los aliens
	ALLEGRO_BITMAP* aliensBitmaps[NUM_ALIENS];

	//Para las barreras
	ALLEGRO_BITMAP* barriersBitmaps[NUM_BARRIERS];

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

enum{FONDO=0, PLAY, HIGHSCORE, EXIT};
enum{ALIEN0=0, ALIEN1, ALIEN2, ALIEN3, ALIEN4, DEADALIEN};
enum{BARRIER0=0, BARRIER1, BARRIER2, BARRIER3, DEADBARRIER};
enum{DEAD=0, ALIVE};
enum{GAMEOVER=0, HIGHSCORES, MENUPAUSE};

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


#endif //ALLEGRO_H

