#include "allegro.h"

//Inicializa Allegro y sus variables.
int initGraphics(graphics_t allegro) {

    if (!al_init()) {
        return ERROR_GRAPHICS;
    }

    if (!al_init_image_addon()) {
        return ERROR_GRAPHICS;
    }

    if (!al_init()) {
        return ERROR_GRAPHICS;
    }

    if (!al_init_primitives_addon()) {
        return ERROR_GRAPHICS;
    }

    al_install_keyboard();
    al_install_mouse();

    allegro.display = al_create_display(SCREENWIDTH, SCREENHEIGHT);
    allegro.event = al_create_event_queue();

    al_set_window_title(display, "Space Invaders");

    al_register_event_source(queue, al_get_display_event_source(allegro.display));
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_mouse_event_source());

    return OK_GRSPHICS;
}


int destroyGraphics(graphics_t allegro) {

}