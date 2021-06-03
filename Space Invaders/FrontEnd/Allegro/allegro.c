#pragma warning (disable: 4996)

#ifndef RASPI

#include "allegro.h"

//Carga los bitmaps necesarios. Si está todo bien devuelve OK_GRAPHICS. En caso contrario devuelve ERROR_GRAPHICS.
int loadAllBitmaps(graphics_t* allegro);
//Recibe un arreglo de bitmaps a cargar, con su path y su cantidad y los carga. Si esta todo bien devuelve OK_GRAPHICS. En caso contrario devuelve ERROR_GRAPHICS.
int loadBitmaps(ALLEGRO_BITMAP* bitmaps[], char* pathTemplate, int cantBitmaps);
//Carga los samples para el menu. Si está todo bien devuelve OK_GRSPHICS. En caso contrario devuelve ERROR_GRAPHICS.
int loadMenuSamples(ALLEGRO_SAMPLE* menuSamples[]);
void destroyBitmaps(graphics_t* allegro);
void destroyBitmap(ALLEGRO_BITMAP* bitmaps[], int cant);

////Carga los bitmaps para el menu. Si está todo bien devuelve OK_GRAPHICS. En caso contrario devuelve ERROR_GRAPHICS.
//int loadMenuBitmaps(ALLEGRO_BITMAP* menuBitmaps[]);
////Carga los bitmaps para las barreras. Si esta todo bien devuelve OK_GRAPHICS. En caso contrario devuelve ERROR_GRAPHICS.
//int loadBarrierBitmaps(ALLEGRO_BITMAP* barriersBitmaps[]);
////Carga los bitmaps para los aliens. Si está todo bien devuelve OK_GRAPHICS. En caso contrario devuelve ERROR_GRAPHICS.
//int loadAliensBitmaps(ALLEGRO_BITMAP* aliensBitmaps[]);
////Carga el bitmap para el random alien. Si está todo bien devuelve OK_GRAPHICS. En caso contrario devuelve ERROR_GRAPHICS.
//int loadRandomAlienBitmap(ALLEGRO_BITMAP* randomAlienBitmap)
////Carga el bitmap para la bala. Si está todo bien devuelve OK_GRAPHICS. En caso contrario devuelve ERROR_GRAPHICS.
//int loadBulletBitmap(ALLEGRO_BITMAP* bulletBitmap)
////Carga el bitmap para la nave. Si está todo bien devuelve OK_GRAPHICS. En caso contrario devuelve ERROR_GRAPHICS.
//int loadSpaceshipBitmap(ALLEGRO_BITMAP* spaceshipBitmap)
////Carga los bitmaps para las vidas. Si está todo bien devuelve OK_GRAPHICS. En caso contrario devuelve ERROR_GRAPHICS.
//int loadLivesBitmaps(ALLEGRO_BITMAP* livesBitmaps[])

//Inicializa Allegro y sus variables.
int initGraphics(graphics_t* allegro) {

    allegro->display = NULL;
    allegro->timer = NULL;
    allegro->eventQueue = NULL;
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

    al_install_keyboard();
    al_init_font_addon();
    al_init_ttf_addon();
    al_install_audio();
    
    if (!al_init_acodec_addon()) {
        return ERROR_GRAPHICS;
    }

    if (!al_reserve_samples(3)) {
        return ERROR_GRAPHICS;
    }

    allegro->display = al_create_display(SCREEN_W, SCREEN_H);
    if (allegro->display == NULL) {
        printf("Failed to create the display !\n");
        return ERROR_GRAPHICS;
    }
    allegro->eventQueue = al_create_event_queue();
    if (allegro->eventQueue == NULL) {
        return ERROR_GRAPHICS;
    }
    allegro->timer = al_create_timer(1.0 / FPS);
    if (allegro->timer == NULL) {
        return ERROR_GRAPHICS;
    }
    allegro->font = al_load_ttf_font("Resources/space_invaders.ttf", FUENTE_SIZE, 0);
    if (allegro->font == NULL) {
        printf("Failed to load the font !\n");
        return ERROR_GRAPHICS;
    }
    //Cargo los bitmaps.
    if (loadAllBitmaps(allegro) == ERROR_GRAPHICS) {
        printf("Failed to load the bitmaps !\n");
        return ERROR_GRAPHICS;
    }

    if (loadMenuSamples(allegro->menuSamples) == ERROR_GRAPHICS) {
        printf("Failed to load menu Samples !\n");
        return ERROR_GRAPHICS;
    }

    al_set_window_title(allegro->display, "Space Invaders");
    al_register_event_source(allegro->eventQueue, al_get_display_event_source(allegro->display));
    al_register_event_source(allegro->eventQueue, al_get_keyboard_event_source());
    al_register_event_source(allegro->eventQueue, al_get_mouse_event_source());
    al_register_event_source(allegro->eventQueue, al_get_timer_event_source(allegro->timer));
    al_start_timer(allegro->timer);

    return OK_GRAPHICS;
}

void destroyGraphics(graphics_t* allegro) {

    al_destroy_timer(allegro->timer);
    al_destroy_display(allegro->display);
    al_destroy_event_queue(allegro->eventQueue);
    al_destroy_font(allegro->font);

    al_uninstall_audio();
}

void updateGraphics(void) {
    al_flip_display();
}

int loadAllBitmaps(graphics_t* allegro) {
    if (loadBitmaps(allegro->menuBitmaps, "Resources/Bitmaps/BitmapMenu%d.png", CANT_BTM_MENU) == ERROR_GRAPHICS) {
        printf("error 1\n");
        return ERROR_GRAPHICS;
    }
    if (loadBitmaps(allegro->aliensBitmaps, "Resources/Bitmaps/BitmapAlien%d.bmp", CANT_TIPOS_ALIEN) == ERROR_GRAPHICS) {
        printf("error 2\n");
        return ERROR_GRAPHICS;
    }
    else if (loadBitmaps(&allegro->randomAlienBitmap, "Resources/Bitmaps/BitmapRandomAlien%d.bmp", 1) == ERROR_GRAPHICS) {
        printf("error 3\n");
        return ERROR_GRAPHICS;
    }
    else if (loadBitmaps(allegro->barriersBitmaps, "Resources/Bitmaps/BitmapBarriers%d.bmp", CANT_TIPOS_BARRERAS) == ERROR_GRAPHICS) {
        printf("error 4\n");
        return ERROR_GRAPHICS;
    }
    else if (loadBitmaps(allegro->livesBitmap, "Resources/Bitmaps/BitmapLives%d.bmp", CANT_LIVES_BTM) == ERROR_GRAPHICS) {
        printf("error 5\n");
        return ERROR_GRAPHICS;
    }
    else if (loadBitmaps(&allegro->spaceshipBitmap, "Resources/Bitmaps/BitmapSpaceship%d.bmp", 1) == ERROR_GRAPHICS) {
        printf("error 6\n");
        return ERROR_GRAPHICS;
    }
    else if (loadBitmaps(&allegro->bulletBitmap, "Resources/Bitmaps/BitmapBullet%d.bmp", 1) == ERROR_GRAPHICS) {
        printf("error 7\n");
        return ERROR_GRAPHICS;
    }

    /*if(loadMenuBitmaps(allegro->menuBitmaps)==ERROR_GRAPHICS){
        return ERROR_GRAPHICS;
    }*/

    return OK_GRAPHICS;
}

void destroyBitmaps(graphics_t* allegro) {
    //Destruyo los bitmaps del menu.
    destroyBitmap(allegro->menuBitmaps, CANT_BTM_MENU);
}

void destroyBitmap(ALLEGRO_BITMAP* bitmaps[], int cant)
{
    int i;
    for (i = 0; i < cant; ++i)
    {
        al_destroy_bitmap(bitmaps[i]);
    }

}

int loadMenuSamples(ALLEGRO_SAMPLE* menuSamples[]) {
    int i, err = 0;
    char path[100];
    for (i = 0; (err == 0) && (i < CANT_SAMPL_MENU); ++i) {
        sprintf(path, "Resources/Sounds/SampleMenu%d.bmp", i);
        menuSamples[i] = al_load_sample(path);
        if (menuSamples[i] == NULL) {
            err = 1;
        }
    }
    //Si todo está bien devuelvo OK. En caso contrario devuelvo ERROR.
    if (err == 0) {
        return OK_GRAPHICS;
    }
    else {
        return ERROR_GRAPHICS;
    }
}

int loadBitmaps(ALLEGRO_BITMAP* bitmaps[], char* pathTemplate, int cantBitmaps) {
    int i = 0, err = 0;
    char path[100];

    for (i = 0; (err == 0) && (i < cantBitmaps); ++i) {
        sprintf(path, pathTemplate, i);
        bitmaps[i] = al_load_bitmap(path);
        if (bitmaps[i] == NULL) {
            err = 1;
        }
    }
    //Si todo está bien devuelvo OK. En caso contrario devuelvo ERROR.
    if (err == 0) {
        return OK_GRAPHICS;
    }
    else {
        return ERROR_GRAPHICS;
    }
}

void printMenu(graphics_t* graphics) {
    al_draw_bitmap(graphics->menuBitmaps[0], 0, 0, 0);
    al_draw_bitmap(graphics->menuBitmaps[1], 0, 0, 0);
    al_draw_bitmap(graphics->menuBitmaps[2], 0, 0, 0);

    //updateGraphics();
}

//int loadMenuBitmaps(ALLEGRO_BITMAP* menuBitmaps[]){
//    int i=0, err=0;
//    char* path;
//
//    for(i=0; (err==0)&&(i<CANT_BTM_MENU); ++i){
//        sprintf(path, "Resources/Bitmaps/BitmapMenu%d.bmp",i);
//        menuBitmaps[i] = al_load_bitmap(path);
//        if(menuBitmaps[i]==NULL){
//            err=1;            
//        }
//    }
//    //Si todo está bien devuelvo OK. En caso contrario devuelvo ERROR.
//    if(err==0){
//        return OK_GRAPHICS;
//    }
//    else{
//        return ERROR_GRAPHICS;
//    }
//}
//
//int loadAliensBitmaps(ALLEGRO_BITMAP* aliensBitmaps[]) {
//    int i = 0, err = 0;
//    char* path;
//
//    for (i = 0; (err == 0) && (i < CANT_TIPOS_ALIEN); ++i) {
//        sprintf(path, "Resources/Bitmaps/BitmapAlien%d.bmp", i);
//        aliensBitmaps[i] = al_load_bitmap(path);
//        if (aliensBitmaps[i] == NULL) {
//            err = 1;
//        }
//    }
//    //Si todo está bien devuelvo OK. En caso contrario devuelvo ERROR.
//    if (err == 0) {
//        return OK_GRAPHICS;
//    }
//    else {
//        return ERROR_GRAPHICS;
//    }
//}
//
//int loadBarrierBitmaps(ALLEGRO_BITMAP* barriersBitmaps[]) {
//    int i = 0, err = 0;
//    char* path;
//
//    for (i = 0; (err == 0) && (i < CANT_TIPOS_BARRERAS); ++i) {
//        sprintf(path, "Resources/Bitmaps/BitmapBarriers%d.bmp", i); //CAMBIAR
//        barriersBitmaps[i] = al_load_bitmap(path);
//        if (barriersBitmaps[i] == NULL) {
//            err = 1;
//        }
//    }
//    //Si todo está bien devuelvo OK. En caso contrario devuelvo ERROR.
//    if (err == 0) {
//        return OK_GRAPHICS;
//    }
//    else {
//        return ERROR_GRAPHICS;
//    }
//}
//
//int loadRandomAlienBitmap(ALLEGRO_BITMAP* randomAlienBitmap) {
//    int i = 0, err = 0;
//    char* path;
//    path = "Resources/Bitmaps/BitmapRandomAlien.bmp";
//    randomAlienBitmap = al_load_bitmap(path);
//    if (randomAlienBitmap == NULL) {
//        err = 1;
//    }
//    //Si todo está bien devuelvo OK. En caso contrario devuelvo ERROR.
//    if (err == 0) {
//        return OK_GRAPHICS;
//    }
//    else {
//        return ERROR_GRAPHICS;
//    }
//}
//
//int loadBulletBitmap(ALLEGRO_BITMAP* bulletBitmap) {
//    int i = 0, err = 0;
//    char* path;
//    path = "Resources/Bitmaps/BitmapBullet.bmp";
//    bulletBitmap = al_load_bitmap(path);
//    if (bulletBitmap == NULL) {
//        err = 1;
//    }
//    //Si todo está bien devuelvo OK. En caso contrario devuelvo ERROR.
//    if (err == 0) {
//        return OK_GRAPHICS;
//    }
//    else {
//        return ERROR_GRAPHICS;
//    }
//}
//
//int loadSpaceshipBitmap(ALLEGRO_BITMAP* spaceshipBitmap) {
//    int i = 0, err = 0;
//    char* path;
//    path = "Resources/Bitmaps/BitmapSpaceship.bmp";
//    spaceshipBitmap = al_load_bitmap(path);
//    if (spaceshipBitmap == NULL) {
//        err = 1;
//    }
//    //Si todo está bien devuelvo OK. En caso contrario devuelvo ERROR.
//    if (err == 0) {
//        return OK_GRAPHICS;
//    }
//    else {
//        return ERROR_GRAPHICS;
//    }
//}
//
//int loadLivesBitmaps(ALLEGRO_BITMAP* livesBitmaps[]) {
//    int i = 0, err = 0;
//    char* path;
//
//    for (i = 0; (err == 0) && (i < CANT_LIVES_BTM); ++i) {
//        sprintf(path, "Resources/Bitmaps/BitmapLives%d.bmp", i); 
//        livesBitmaps[i] = al_load_bitmap(path);
//        if (livesBitmaps[i] == NULL) {
//            err = 1;
//        }
//    }
//    //Si todo está bien devuelvo OK. En caso contrario devuelvo ERROR.
//    if (err == 0) {
//        return OK_GRAPHICS;
//    }
//    else {
//        return ERROR_GRAPHICS;
//    }
//}
//
//int loadFondosExtraBitmap(ALLEGRO_BITMAP* fondosExtraBitmaps[]) {
//
//    int i = 0, err = 0;
//    char* path;
//    for (i = 0; (err == 0) && (i < CANT_FONDOS_EXTRA); ++i) {
//        sprintf(path, "Resources/Bitmaps/BitmapFondosExtra%d.bmp", i);
//        fondosExtraBitmaps[i] = al_load_bitmap(path);
//        if (fondosExtraBitmaps[i] == NULL) {
//            err = 1;
//        }
//    }
//    //Si todo está bien devuelvo OK. En caso contrario devuelvo ERROR.
//    if (err == 0) {
//        return OK_GRAPHICS;
//    }
//    else {
//        return ERROR_GRAPHICS;
//    }
//}

#endif // !RASPI