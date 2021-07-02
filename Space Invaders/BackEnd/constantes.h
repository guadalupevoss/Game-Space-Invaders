#ifndef CONSTANTS_H
#define CONSTANTS_H

#define WIDTH 16
#define HEIGHT 16

#define ERROR_GRAPHICS -1
#define OK_GRAPHICS		0

#define MOVE_RATE       5.0 //Para el movimiento

#ifndef RASPI
//En caso de error las funciones devuelven ERROR_GRAPHICS, si todo está bien devuelven un OK_GRSPHICS.
#define FPS             60.0

//Tamaño del display
#define SCREEN_W 800
#define SCREEN_H 800

#define UNIDAD SCREEN_W/16

//Defines para mouse
#define MOUSE_IN_PLAY ((ev.mouse.x>210)&(ev.mouse.x<550)&(ev.mouse.y>334)&(ev.mouse.y<407)) //COORDENADAS DE LOS BOTONES DEL MENÚ
#define MOUSE_IN_EXIT ((ev.mouse.x>208)&(ev.mouse.x<548)&(ev.mouse.y>620)&(ev.mouse.y<747))
#define MOUSE_IN_HIGH_SCORE ((ev.mouse.x>130)&(ev.mouse.x<650)&(ev.mouse.y>500)&(ev.mouse.y<538))
#define MOUSE_IN_EXIT_SCORE 1
#define MOUSE_IN_PAUSE_RESUME     ((ev.mouse.x>199)&(ev.mouse.x<611)&(ev.mouse.y>351)&(ev.mouse.y<421))
#define MOUSE_IN_PAUSE_MENU   ((ev.mouse.x>199)&(ev.mouse.x<611)&(ev.mouse.y>435)&(ev.mouse.y<506))

//Defines de la nave
#define NAVE_SIZE_X     40  //TAMAnO DE LA NAVE
#define NAVE_SIZE_Y     40
#define SPACESHIP_POS_Y 15
#define INITIAL_SPASESHIP_POS_X 8 
#define SPACESHIP_LIVES 3
#define SPACESHIP_BULLET_SPEED	30
#define POS_CENTRO 0

//Defines de los aliens
#define ALIEN_SIZE_X    32  //TAMAnO DEL ALIEN
#define ALIEN_SIZE_Y    32
#define DISTANCIA_ALIENS_X 1
#define DISTANCIA_ALIENS_Y 1
#define DISTANCIA_TECHO_Y   3  //DISTANCIA INICIAL ENTRE ALIEN Y BORDE SUPERIOR DE LA PANTALLA.
#define NUM_ALIENS		55
#define INIT_NUM_ALIENS 6
#define INITIAL_ALIEN_SPEED 100
#define CANT_TIPOS_ALIEN    6   //TIPOS DE ALIENS (CONTANDO LA IMAGEN DEL ALIEN MUERTO)
#define INITIAL_ALIEN_BULLET_SPEED	100
#define COLUMNAS        7   //COLUMNAS Y FILAS (DE ALIENS)MAXIMAS
#define FILAS           5
#define BULLET_FRAMES	100

//Defines de las barreras
#define BARRERA_SIZE_X  1//52
#define BARRERA_SIZE_Y  0//42
#define NUM_BARRIERS   4
#define CANT_TIPOS_BARRERAS     5   //TIPOS DE BARRERAS (CONTANDO LA IMAGEN DE LA BARRERA MUERTA)
#define BARRIER_POS_Y 14
#define BARRIER_LIVES 4

//Defines del alien random
#define RANDOM_ALIEN_POS_Y 2
#define RANDOM_ALIEN_SIZE_X 40  //Establece el tamaNo del alien random.
#define RANDOM_ALIEN_SIZE_Y 35
#define RANDOM_ALIEN_POSICION_Y  1 //PosiciOn en el eje y que mantendrA el alien random
#define RANDOM_ALIEN_SPEED  40

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
#define CANT_BTM_MENU	6	//Numero de bitmaps para el menú.
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
#define NAMELENGHT			20
#define MAX_ARR_CARACTER	40 
#define DISTANCE_POINTS_PLAYER 250
#define NUMBERLENGHT 10


#endif

#ifdef RASPI

//Tamano del display
#define SCREEN_W 16
#define SCREEN_H 16

//Defines de la nave
#define NAVE_SIZE_X 3
#define NAVE_SIZE_Y 2
#define SPACESHIP_POS_Y 15
#define INITIAL_SPASESHIP_POS_X 8
#define SPACESHIP_LIVES 3
#define SPACESHIP_BULLET_SPEED	2
#define POS_CENTRO 1


//Defines de los aliens
#define ALIEN_SIZE_X 1
#define ALIEN_SIZE_Y 1
#define DISTANCIA_ALIENS_X  2  //DISTANCIA ENTRE ALIEN Y ALIEN EN X.
#define DISTANCIA_ALIENS_Y  2  //DISTANCIA ENTRE ALIEN Y ALIEN EN Y.
#define DISTANCIA_TECHO_Y   4  //DISTANCIA INICIAL ENTRE ALIEN Y BORDE SUPERIOR DE LA PANTALLA.
#define COLUMNAS        6   //COLUMNAS Y FILAS (DE ALIENS)MÁXIMAS
#define FILAS           3
#define INITIAL_ALIEN_SPEED 10
#define RANGO_X         15
#define RANGO_Y         60
#define NUM_ALIENS		18
#define INIT_NUM_ALIENS	4
#define INIT_SCORE		20
#define BULLET_FRAMES	20
#define INITIAL_ALIEN_BULLET_SPEED	5


//Defines de las balas
#define BALA_SIZE_X     1   //TAMAÑO DE LA BALA (DEPENDE DE LA IMÁGEN QUE TENGA)
#define BALA_SIZE_Y     1

//Defines de highscore
#define NUM_SIZE_X      4  //TAMAÑO DE LOS NÚMEROS
#define NUM_SIZE_Y      5
#define CANTIDAD_NUM    10
#define CIFRAS_SCORE    9
#define MAXSCORES       10
#define NAMELENGHT      3
#define NUMBERLENGHT 10
#define NUMBER_OF_SCREENS 9

//Defines de las barreras
#define BARRERA_SIZE_X  2
#define BARRERA_SIZE_Y  1
#define NUM_BARRIERS   4
#define CANT_TIPOS_BARRERAS     5   //TIPOS DE BARRERAS (CONTANDO LA IMAGEN DE LA BARRERA MUERTA)
#define BARRIER_POS_Y 12
#define BARRIER_LIVES 4

//Defines del alien random
#define RANDOM_ALIEN_SIZE_X 2  //Establece el tamaño del alien random.
#define RANDOM_ALIEN_SIZE_Y 1
#define RANDOM_ALIEN_POS_Y  1 //Posición en el eje y que mantendrá el alien random
#define RANDOM_ALIEN_SPEED  2


#endif

#endif //CONSTANTS_H