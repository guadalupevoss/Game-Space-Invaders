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

int print_scores(ALLEGRO_FONT* fuente_score, ALLEGRO_EVENT_QUEUE* ev_queue);
void read_keyboard(char arr_char[], ALLEGRO_EVENT_QUEUE* ev_queue, ALLEGRO_FONT* fuente_score, ALLEGRO_BITMAP* fondo_read);
//void clearArr(char* arr, int countChar);

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

	if (!al_reserve_samples(CANT_SAMPL_MENU)) {
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

	allegro->state = MENU;

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
	else if (loadBitmaps(&allegro->fondosExtra, "Resources/Bitmaps/BitmapFondosExtra%d.bmp", 3) == ERROR_GRAPHICS) {
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

void destroyBitmap(ALLEGRO_BITMAP* bitmaps[], int cant){
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
		sprintf(path, "Resources/Sounds/SampleMenu%d.wav", i);
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
		al_convert_mask_to_alpha(bitmaps[i], al_map_rgb(0, 255, 0));
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

void printMenu(graphics_t* graphics){

	al_draw_bitmap(graphics->menuBitmaps[FONDO_GR], 0, 0, 0);
	al_draw_bitmap(graphics->menuBitmaps[SPACEINVADERS_GR], 0, 0, 0);
	al_play_sample(graphics->menuSamples[MENU_GR], 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
	switch (graphics->state)
	{
		case MENU_GR:
			al_draw_bitmap(graphics->menuBitmaps[MENU_GR], 0, 0, 0);
			//al_play_sample(graphics->menuSamples[MENU], 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL); 
			break;
		case PLAY_GR:
			al_draw_bitmap(graphics->menuBitmaps[PLAY_GR], 0, 0, 0);
			//pongo el pan centered nose q es si no funciona poner ALLEGRO_AUDIO_PAN_NONE.
			al_play_sample(graphics->menuSamples[PLAY_GR], 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
			break;
		case HIGHSCORE_GR:
			al_draw_bitmap(graphics->menuBitmaps[HIGHSCORE_GR], 0, 0, 0);
			al_play_sample(graphics->menuSamples[HIGHSCORE_GR], 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
			break;
		case EXIT_GR:
			al_draw_bitmap(graphics->menuBitmaps[EXIT_GR], 0, 0, 0);
			al_play_sample(graphics->menuSamples[EXIT_GR], 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
			break;
	}
}

int stateMenu(graphics_t* graphics) {

	int tempState = MENU;
	int tempCursorState = graphics->state;

	ALLEGRO_EVENT ev;
	if (al_get_next_event(graphics->eventQueue, &ev)) {
		if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
			tempState = EXIT_M;
		}
		else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
			switch(graphics->state){
				case PLAY_GR:
					tempState = PLAY;
					break;
				case HIGHSCORE_GR:
					tempState = HIGHSCORE;
					break;
				case EXIT_GR:
					tempState = EXIT_M;
					break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_TIMER) {
		   // redraw = true;//Podríamos probar para un redraw
		}
		else if (MOUSE_IN_PLAY) {
			tempCursorState = PLAY_GR;
		}
		else if (MOUSE_IN_EXIT) {
			tempCursorState = EXIT_GR;
		}
		else if (MOUSE_IN_HIGH_SCORE) {
			tempCursorState = HIGHSCORE_GR;
		}
		else {
			tempCursorState = MENU_GR;
		}
	}

	graphics->state = tempCursorState;
	return tempState;
}

//enum{NOTHING=0, SS_BULLET, SS_MOVE_R, SS_MOVE_L, PAUSE, EXIT};

int getEvent(graphics_t graphics) {
	int tempEvent = NOTHING;
	ALLEGRO_EVENT ev;
	//Tomo el siguiente evento en la cola de eventos.
	if (al_get_next_event(graphics.eventQueue, &ev)) {

		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			tempEvent = EXIT;
		}

		else if (ev.type == ALLEGRO_EVENT_TIMER) {

		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {

			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_LEFT:
				tempEvent = SS_MOVE_L;
				break;
			case ALLEGRO_KEY_RIGHT:
				tempEvent = SS_MOVE_R;
				break;
			case ALLEGRO_KEY_SPACE:
				tempEvent = SS_BULLET;
				break;
			case ALLEGRO_KEY_ESCAPE:
				tempEvent = PAUSE;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_LEFT:
				break;
			case ALLEGRO_KEY_RIGHT:
				break;
			case ALLEGRO_KEY_SPACE:
				break;
			case ALLEGRO_KEY_ESCAPE:
				break;

			}
		}

	   
	}
	return tempEvent;
}

void printSpaceInvaders(graphics_t* graphics, alien_t* aliens, barriers_t* barriers, spaceship_t* spaceship, alienRandom_t* rAlien, int level, int frames){

	//Defino un contador.
	int i=0;

	//Imprime el fondo del juego.
	al_draw_bitmap(graphics->menuBitmaps[FONDO_GR], 0, 0, 0);

	//Imprime a los aliens en su posición y las balas que tengan.-----Acá falta la parte del alien muerto(explota).
	for(i=0;i<NUM_ALIENS;++i){
		if(aliens[i].alive == ALIVE){
			switch (aliens[i].score) {
					case SCORE_1:
						al_draw_bitmap(graphics->aliensBitmaps[0], (aliens[i].pos.x)*UNIDAD, (aliens[i].pos.y)*UNIDAD, 0);
						break;
					case SCORE_2:
						al_draw_bitmap(graphics->aliensBitmaps[1], (aliens[i].pos.x)*UNIDAD, (aliens[i].pos.y)*UNIDAD, 0);
						break;
					case SCORE_3:
						al_draw_bitmap(graphics->aliensBitmaps[2], (aliens[i].pos.x)*UNIDAD, (aliens[i].pos.y)*UNIDAD, 0);
						break;
					case SCORE_4:
						al_draw_bitmap(graphics->aliensBitmaps[3], (aliens[i].pos.x)*UNIDAD, (aliens[i].pos.y)*UNIDAD, 0);
						break;
					case SCORE_5:
						al_draw_bitmap(graphics->aliensBitmaps[4], (aliens[i].pos.x)*UNIDAD, (aliens[i].pos.y)*UNIDAD, 0);
						break;
					case RECENT_DEAD: //que cuando se mueran le cambien el score a esto y desp aca lo matamos
						al_draw_bitmap(graphics->aliensBitmaps[5], (aliens[i].pos.x)*UNIDAD, (aliens[i].pos.y)*UNIDAD, 0);
						aliens[i].alive = DEAD;
						break;
				}   
		}
		if(aliens[i].bullet.state==ON){
			al_draw_bitmap(graphics->bulletBitmap, (aliens[i].bullet.pos.x)*UNIDAD, (aliens[i].bullet.pos.y)*UNIDAD, 0);
		}
	}


	//Imprime al alien random.-----Acá falta la parte del alien random muerto(explota).
	if(rAlien->alive==ALIVE){
			al_draw_bitmap(graphics->randomAlienBitmap, (rAlien->pos.x)*UNIDAD, (rAlien->pos.y)*UNIDAD, 0);
	}


	//Imprime las barreras.-----Acá falta la parte de la barrera muerta(explota).
	for (i = 0; i < NUM_BARRIERS; i++){
			switch (barriers[i].lives) {
				case BARRIER_LIVES:
					al_draw_bitmap(graphics->barriersBitmaps[0], (barriers[i].pos.x) * UNIDAD, (barriers[i].pos.y) * UNIDAD, 0);
					break;
				case BARRIER_LIVES-1:
					al_draw_bitmap(graphics->barriersBitmaps[1], (barriers[i].pos.x) * UNIDAD, (barriers[i].pos.y) * UNIDAD, 0);
					break;
				case BARRIER_LIVES-2:
					al_draw_bitmap(graphics->barriersBitmaps[2], (barriers[i].pos.x) * UNIDAD, (barriers[i].pos.y) * UNIDAD, 0);
					break;
				case BARRIER_LIVES-3:
					al_draw_bitmap(graphics->barriersBitmaps[3], (barriers[i].pos.x) * UNIDAD, (barriers[i].pos.y) * UNIDAD, 0);
					break;
				case RECENT_SHOT: //que cuando se mueran le cambien el score a esto y desp aca lo matamos
					al_draw_bitmap(graphics->barriersBitmaps[4], (barriers[i].pos.x)*UNIDAD, (barriers[i].pos.y)*UNIDAD, 0);
					barriers[i].lives = 0;
					break;
			}
	}


	//Imprime la nave y su bala.
	al_draw_bitmap(graphics->spaceshipBitmap, (spaceship->pos.x)*UNIDAD, (spaceship->pos.y)*UNIDAD, 0);
	if(spaceship->bullet.state == ON){
		//printf("no se porq no imprime \n");
		al_draw_bitmap(graphics->bulletBitmap, (spaceship->bullet.pos.x)*UNIDAD, (spaceship->bullet.pos.y)*UNIDAD, 0);
	}

	switch (spaceship->lives) {
		case 1:
			al_draw_bitmap(graphics->livesBitmap[DEAD], 13 * UNIDAD, UNIDAD, 0);
			al_draw_bitmap(graphics->livesBitmap[DEAD], 14 * UNIDAD, UNIDAD, 0);
			al_draw_bitmap(graphics->livesBitmap[ALIVE], 15 * UNIDAD, UNIDAD, 0);
			break;
		case 2:
			al_draw_bitmap(graphics->livesBitmap[DEAD], 13 * UNIDAD, UNIDAD, 0);
			al_draw_bitmap(graphics->livesBitmap[ALIVE], 14 * UNIDAD, UNIDAD, 0);
			al_draw_bitmap(graphics->livesBitmap[ALIVE], 15 * UNIDAD, UNIDAD, 0);
			break;
		case 3:
			al_draw_bitmap(graphics->livesBitmap[ALIVE], 13 * UNIDAD, UNIDAD, 0);
			al_draw_bitmap(graphics->livesBitmap[ALIVE], 14 * UNIDAD, UNIDAD, 0);
			al_draw_bitmap(graphics->livesBitmap[ALIVE], 15 * UNIDAD, UNIDAD, 0);
			break;
	}
	
	//print_scores();
	updateGraphics();

}

void clearSpaceInvaders(graphics_t* graphics, alien_t* aliens, barriers_t* barriers, spaceship_t* spaceship, alienRandom_t* rAlien, int level) {

}

//Para highscores

int print_scores(ALLEGRO_FONT* fuente_score, ALLEGRO_EVENT_QUEUE* ev_queue){
	float       text_x, text_y;
	char        str[MAX_ARR_CARACTER];
	bool        do_exit_score = false;
	int error = 0;

	ALLEGRO_BITMAP* fondo_lista_high_score;
	ALLEGRO_BITMAP* fondo_score;

	fondo_lista_high_score = al_load_bitmap("Resources/Bitmaps/high_scores.bmp"); //fondo lista de high scores
	if (!fondo_lista_high_score) {
		fprintf(stderr, "failed to create high score bitmap!\n");
		return 0;
	}
	fondo_score = al_load_bitmap("Resources/Bitmaps/fondo_juego.bmp"); //fondo lista de high scores
	if (!fondo_score) {
		fprintf(stderr, "failed to create fondo score bitmap!\n");
		return 0;
	}

	al_convert_mask_to_alpha(fondo_lista_high_score, al_map_rgb(0, 255, 0));
	al_convert_mask_to_alpha(fondo_score, al_map_rgb(0, 255, 0));

	al_register_event_source(ev_queue, al_get_mouse_event_source());

	al_draw_bitmap(fondo_score, 0, 0, 0);
	al_draw_bitmap(fondo_lista_high_score, 0, 0, 0);
	al_flip_display();


	FILE* fp;
	fp = fopen("Resources/scoreboard.txt", "r");
	if (fp == NULL)
	{
		printf("Error en fp");
	}

	clearArr(str, MAX_ARR_CARACTER);
	text_x = 210;
	text_y = 200;

	//ESCRIBO LA LISTA
	if (fp != NULL) {
		while (!feof(fp))
		{
			error = fscanf(fp, "%s", str);
			if (error == 0) {
				al_draw_text(fuente_score, al_map_rgb(255, 255, 255), text_x - 1, text_y, ALLEGRO_ALIGN_LEFT, str);
				al_draw_text(fuente_score, al_map_rgb(224, 192, 0), text_x, text_y, ALLEGRO_ALIGN_LEFT, str);
				clearArr(str, MAX_ARR_CARACTER);
			}
			error = fscanf(fp, "%s", str);
			if (error == 0) {
				al_draw_text(fuente_score, al_map_rgb(255, 255, 255), text_x + DISTANCE_POINTS_PLAYER - 1, text_y, ALLEGRO_ALIGN_LEFT, str);
				al_draw_text(fuente_score, al_map_rgb(224, 192, 0), text_x + DISTANCE_POINTS_PLAYER, text_y, ALLEGRO_ALIGN_LEFT, str);
				clearArr(str, MAX_ARR_CARACTER);
				text_y += FUENTE_SIZE;
			}
		}
		fclose(fp);
		al_flip_display();
	}

	//ME MANTENGO ADENTRO DE LA LISTA HASTA QUE APRIETO LA FLECHA
	while (!do_exit_score)
	{
		ALLEGRO_EVENT ev;

		if (al_get_next_event(ev_queue, &ev))
		{

			if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			{
				do_exit_score = true;
			}
			else if ((ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) && (MOUSE_IN_EXIT_SCORE))
			{
				do_exit_score = true;
			}

		}
	}

	al_destroy_bitmap(fondo_score);
	al_destroy_bitmap(fondo_lista_high_score);
	return 1;
}
void read_keyboard(char arr_char[], ALLEGRO_EVENT_QUEUE* ev_queue, ALLEGRO_FONT* fuente_score, ALLEGRO_BITMAP* fondo_read)
{
	bool exit_keyboard = false;

	int     character_counter = 0;
	clearArr(arr_char, NAMELENGHT);

	if (!al_install_keyboard()) {
		fprintf(stderr, "failed to initialize the keyboard!\n");
	}


	al_register_event_source(ev_queue, al_get_keyboard_event_source()); //REGISTRAMOS EL TECLADO

	while (!exit_keyboard)
	{
		ALLEGRO_EVENT event;

		//  1° TOMA EL ÚLTIMO EVENTO DE LA COLA DE EVENTOS
		if (al_get_next_event(ev_queue, &event))
		{

			if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			{
				exit_keyboard = true;
			}

			if (character_counter < NAMELENGHT)
			{
				if (event.type == ALLEGRO_EVENT_KEY_DOWN)
				{
					switch (event.keyboard.keycode)
					{
					case ALLEGRO_KEY_A:
						arr_char[character_counter] = 'A';
						++character_counter;
						break;
					case ALLEGRO_KEY_B:
						arr_char[character_counter] = 'B';
						printf("%s", arr_char);
						++character_counter;
						break;
					case ALLEGRO_KEY_C:
						arr_char[character_counter] = 'C';
						++character_counter;
						break;
					case ALLEGRO_KEY_D:
						arr_char[character_counter] = 'D';
						++character_counter;
						break;
					case ALLEGRO_KEY_E:
						arr_char[character_counter] = 'E';
						++character_counter;
						break;
					case ALLEGRO_KEY_F:
						arr_char[character_counter] = 'F';
						++character_counter;
						break;
					case ALLEGRO_KEY_G:
						arr_char[character_counter] = 'G';
						++character_counter;
						break;
					case ALLEGRO_KEY_H:
						arr_char[character_counter] = 'H';
						++character_counter;
						break;
					case ALLEGRO_KEY_I:
						arr_char[character_counter] = 'I';
						++character_counter;
						break;
					case ALLEGRO_KEY_J:
						arr_char[character_counter] = 'J';
						++character_counter;
						break;
					case ALLEGRO_KEY_K:
						arr_char[character_counter] = 'K';
						++character_counter;
						break;
					case ALLEGRO_KEY_L:
						arr_char[character_counter] = 'L';
						++character_counter;
						break;
					case ALLEGRO_KEY_M:
						arr_char[character_counter] = 'M';
						++character_counter;
						break;
					case ALLEGRO_KEY_N:
						arr_char[character_counter] = 'N';
						++character_counter;
						break;
					case ALLEGRO_KEY_P:
						arr_char[character_counter] = 'P';
						++character_counter;
						break;
					case ALLEGRO_KEY_O:
						arr_char[character_counter] = 'O';
						++character_counter;
						break;
					case ALLEGRO_KEY_Q:
						arr_char[character_counter] = 'Q';
						++character_counter;
						break;
					case ALLEGRO_KEY_R:
						arr_char[character_counter] = 'R';
						++character_counter;
						break;
					case ALLEGRO_KEY_S:
						arr_char[character_counter] = 'S';
						++character_counter;
						break;
					case ALLEGRO_KEY_T:
						arr_char[character_counter] = 'T';
						++character_counter;
						break;
					case ALLEGRO_KEY_U:
						arr_char[character_counter] = 'U';
						++character_counter;
						break;
					case ALLEGRO_KEY_V:
						arr_char[character_counter] = 'V';
						++character_counter;
						break;
					case ALLEGRO_KEY_W:
						arr_char[character_counter] = 'W';
						++character_counter;
						break;
					case ALLEGRO_KEY_X:
						arr_char[character_counter] = 'X';
						++character_counter;
						break;
					case ALLEGRO_KEY_Y:
						arr_char[character_counter] = 'Y';
						++character_counter;
						break;
					case ALLEGRO_KEY_Z:
						arr_char[character_counter] = 'Z';
						++character_counter;
						break;
					}

				}
			}

			if (event.type == ALLEGRO_EVENT_KEY_UP)
			{
				switch (event.keyboard.keycode)
				{
				case ALLEGRO_KEY_BACKSPACE:
					if (character_counter > 0)
					{
						--character_counter;
						arr_char[character_counter] = '\0';
					}
					break;
				case ALLEGRO_KEY_ENTER:
					if (character_counter > 0)
					{
						exit_keyboard = true;
					}

					break;

				}
			}

			al_draw_bitmap(fondo_read, 0, 0, 0);

			if (character_counter == NAMELENGHT)
			{
				al_draw_text(fuente_score, al_map_rgb(255, 255, 255), MESSAGE_X - 2, MESSAGE_Y, ALLEGRO_ALIGN_LEFT, "CHARACTER LIMIT REACHED");
				al_draw_text(fuente_score, al_map_rgb(224, 192, 0), MESSAGE_X, MESSAGE_Y, ALLEGRO_ALIGN_LEFT, "CHARACTER LIMIT REACHED");
			}


			al_draw_text(fuente_score, al_map_rgb(255, 255, 255), ENTER_PLAYER_NAME_X - 2, ENTER_PLAYER_NAME_Y, ALLEGRO_ALIGN_LEFT, "ENTER PLAYER NAME:");
			al_draw_text(fuente_score, al_map_rgb(224, 192, 0), ENTER_PLAYER_NAME_X, ENTER_PLAYER_NAME_Y, ALLEGRO_ALIGN_LEFT, "ENTER PLAYER NAME:");
			al_draw_text(fuente_score, al_map_rgb(255, 255, 255), PLAYER_NAME_X - 2, PLAYER_NAME_Y, ALLEGRO_ALIGN_LEFT, arr_char);
			al_draw_text(fuente_score, al_map_rgb(224, 192, 0), PLAYER_NAME_X, PLAYER_NAME_Y, ALLEGRO_ALIGN_LEFT, arr_char);
			al_flip_display();
		}
	}

}

//Para pausa
int statePause(graphics_t* graphics) {
	int tempState = NOTHING;
	static int tempCursorState = NOTHING;

	ALLEGRO_EVENT ev;
	if (al_get_next_event(graphics->eventQueue, &ev)) {
		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			tempState = EXIT_PAUSE;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			switch (tempCursorState) {
			case PLAY_PAUSE:
				tempState = PLAY_PAUSE;
				break;
			case MENU_PAUSE:
				tempState = MENU_PAUSE;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_TIMER) {
			// redraw = true;//Podríamos probar para un redraw
		}
		else if (MOUSE_IN_PAUSE_RESUME) {
			tempCursorState = PLAY_PAUSE;
			printf("esta el mouse en resume\n");
		}
		else if (MOUSE_IN_PAUSE_MENU) {
			tempCursorState = MENU_PAUSE;
			printf("esta el mouse en menu\n");
		}
	}

	graphics->state = tempCursorState;
	return tempState;
}

void printPause(graphics_t* graphics) {
	al_draw_bitmap(graphics->menuBitmaps[FONDO_GR], 0, 0, 0);
	al_draw_bitmap(graphics->menuBitmaps[SPACEINVADERS_GR], 0, 0, 0);
	al_play_sample(graphics->menuSamples[MENU_GR], 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
	al_draw_bitmap(graphics->fondosExtra[2], 0, 0, 0);
}

void printGameOver(graphics_t* graphics) {
	al_draw_bitmap(graphics->menuBitmaps[FONDO_GR], 0, 0, 0);
	al_draw_bitmap(graphics->menuBitmaps[SPACEINVADERS_GR], 0, 0, 0);
	al_play_sample(graphics->menuSamples[MENU_GR], 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
	al_draw_bitmap(graphics->fondosExtra[0], 0, 0, 0);
}


#endif // !RASPI