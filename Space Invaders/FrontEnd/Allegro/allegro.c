#include "allegro.h"

//Carga los bitmaps necesarios. Si está todo bien devuelve OK_GRSPHICS. En caso contrario devuelve ERROR_GRAPHICS.
int loadBitmaps(graphics_t* allegro);
//Carga los bitmaps para el menu. Si está todo bien devuelve OK_GRSPHICS. En caso contrario devuelve ERROR_GRAPHICS.
int loadMenuBitmaps(ALLEGRO_BITMAP* menuBitmaps[]);

//Inicializa Allegro y sus variables.
int initGraphics(graphics_t* allegro) {

    allegro->display=NULL ; 
    allegro->timer=NULL;
    allegro->eventQueue=NULL;
    allegro->font = NULL;

    if (!al_init()) {
        return ERROR_GRAPHICS;
    }
    if (!al_install_mouse()) {
        return ERROR_GRAPHICS;
    }
    if (!al_init_image_addon()) {
        return ERROR_GRAPHICS;
    }
    if (!al_init_primitives_addon()) {
        return ERROR_GRAPHICS;
    }
    if (!al_reserve_samples(3)) {
        return ERROR_GRAPHICS;

    }
    al_install_keyboard();
    al_init_font_addon();
    al_init_ttf_addon();

    allegro->display = al_create_display(SCREEN_W, SCREEN_H);
    if(allegro->display==NULL){
        return ERROR_GRAPHICS;
    }
    allegro->eventQueue = al_create_event_queue();
    if(allegro->eventQueue==NULL){
        return ERROR_GRAPHICS;
    }
    allegro->timer = al_create_timer(1.0 / FPS);
    if(allegro->timer==NULL){
        return ERROR_GRAPHICS;
    }
    allegro->font=al_load_ttf_font("Resources/space_invaders.ttf",FUENTE_SIZE,0);
    if(allegro->font==NULL){
        return ERROR_GRAPHICS;
    }
    //Cargo los bitmaps.
    if(loadBitmaps(allegro)==ERROR_GRAPHICS){
        return ERROR_GRAPHICS;
    }

    al_set_window_title(allegro->display, "Space Invaders");
    al_register_event_source(allegro->eventQueue, al_get_display_event_source(allegro->display));
    al_register_event_source(allegro->eventQueue, al_get_keyboard_event_source());
    al_register_event_source(allegro->eventQueue, al_get_mouse_event_source());
    al_register_event_source(allegro->eventQueue, al_get_timer_event_source(allegro->timer));
    al_start_timer(allegro->timer);

    return OK_GRSPHICS;
}

void destroyGraphics(graphics_t* allegro) {

    al_destroy_timer(allegro->timer);
    al_destroy_display(allegro->display);
    al_destroy_event_queue(allegro->eventQueue);     
    al_destroy_font(allegro->font);

    al_uninstall_audio();  
}

void updateGraphics(void){
    al_flip_display();
}

int loadBitmaps(graphics_t* allegro){
    
    if(loadMenuBitmaps(allegro->menuBitmaps)==ERROR_GRAPHICS){
        return ERROR_GRAPHICS;
    }

    return OK_GRSPHICS;
}
void destroyBitmaps(graphics_t* allegro){
    //Destruyo los bitmaps del menu.
    destroyBitmap(allegro->menuBitmaps, CANT_BTM_MENU);
}
void destroyBitmap(ALLEGRO_BITMAP* bitmaps[], int cant)
{
    int i;
    for(i=0; i<cant; ++i)
    {
        al_destroy_bitmap(bitmaps[i]);
    }

}

int loadMenuBitmaps(ALLEGRO_BITMAP* menuBitmaps[]){
    int i=0, err=0;
    char path[100];

    for(i=0; (err==0)&&(i<CANT_BTM_MENU); ++i){
        sprintf(path, "Resources/Bitmaps/BitmapMenu%d.bmp",i);
        menuBitmaps[i] = al_load_bitmap(path);
        if(menuBitmaps[i]==NULL){
            err=1;            
        }
    }
    //Si todo está bien devuelvo OK. En caso contrario devuelvo ERROR.
    if(err=0){
        return OK_GRSPHICS;
    }
    else{
        return ERROR_GRAPHICS;
    }
}

void printMenu(graphics_t* graphics){
        
    //imprime el menu

    updateGraphics();
}