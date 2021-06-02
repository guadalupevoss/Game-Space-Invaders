#ifndef ALLEGRO_H
#define ALLEGRO_H

//Include de allegro.
#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <stdbool.h>

//En caso de error las funciones devuelven ERROR_GRAPHICS, si todo está bien devuelven un OK_GRSPHICS.
#define ERROR_GRAPHICS -1
#define OK_GRSPHICS		0

typedef struct {
	ALLEGRO_DISPLAY*		display;
	ALLEGRO_TIMER*			timer;
	ALLEGRO_EVENT_QUEUE*	event;
}graphics_t;

//Inicializa Allegro y sus variables.
int initAllegro(graphics_t allegro);
//Destruye Allegro y las variables.
int destroyAllegro(graphics_t allegro);

#endif //ALLEGRO_H
