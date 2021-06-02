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

//En caso de error las funciones devuelven ERROR_GRAPHICS, si todo est� bien devuelven un OK_GRSPHICS.
#define ERROR_GRAPHICS -1
#define OK_GRSPHICS		0

typedef struct {
	ALLEGRO_DISPLAY*		display;
	ALLEGRO_TIMER*			timer;
	ALLEGRO_EVENT_QUEUE*	event;
}graphics_t;

//Inicializa Allegro y sus variables.
int initGraphics(graphics_t allegro);
//Destruye Allegro y las variables.
int destroyGraphics(graphics_t allegro);
//Funci�n que imprime el men�.
void printMenu(graphics_t graphics);
//Funci�n que se fija si cambi� el estado (si se presion� alg�n bot�n o salt� error) y devuelve el estado indicado.
int stateMenu(graphics_t graphics);

#endif //ALLEGRO_H
