
#ifdef RASPI

#include "objects.h"
#include "disdrv.h"


//Se encarga de limpiar los aliens que estaban encendidos previamente.
void clearAliens(alien_t aliens[], int cantidad_aliens_usados) {
	static int side = 0; //side en 1 es va a la derecha y side en 0 es izq.
	int contador;


	//Para cada variable alien dentro del rango permitido.
	if ((aliens[0].pos.x >= 0) && (aliens[cantidad_aliens_usados - 1].pos.x <= 15)) {

		for (contador = 0; contador < cantidad_aliens_usados; ++contador) {
			//[0], Se mueve para la derecha [0]-->>[15] y acaba de bajar.
			if (side && (aliens[0].pos.x == 0)) {
				dcoord_t CLEARPOINT(contador) = { aliens[contador].pos.x, aliens[contador].pos.y - 1};
				disp_write(CLEARPOINT(contador), D_OFF);
			}

			//Se mueve para la izquierda [0]<<--[15] y acaba de bajar.
			else if (!side && (aliens[cantidad_aliens_usados - 1].pos.x == 15)) {
				dcoord_t CLEARPOINT(contador) = { aliens[contador].pos.x, aliens[contador].pos.y - 1 };
				disp_write(CLEARPOINT(contador), D_OFF);
			}
			//Se mueve para la izquierda [0]<<--[15] .
			else if (!side) {
				dcoord_t CLEARPOINT(contador) = { aliens[contador].pos.x + 1, aliens[contador].pos.y };
				disp_write(CLEARPOINT(contador), D_OFF);
			}
			//Se mueve para la derecha [0]-->>[15].
			else if (side) {
				dcoord_t CLEARPOINT(contador) = { aliens[contador].pos.x - 1, aliens[contador].pos.y };
				disp_write(CLEARPOINT(contador), D_OFF);
			}
			else if ((aliens[cantidad_aliens_usados - 1].pos.x == 15) && side) {
				dcoord_t CLEARPOINT(contador) = { aliens[contador].pos.x, aliens[contador].pos.y };
				disp_write(CLEARPOINT(contador), D_OFF);
			}
			else if ((aliens[0].pos.x == 0) && !side) {
				dcoord_t CLEARPOINT(contador) = { aliens[contador].pos.x, aliens[contador].pos.y };
				disp_write(CLEARPOINT(contador), D_OFF);
			}
		}
	}

	//Cambia side
	if (side && (aliens[cantidad_aliens_usados - 1].pos.x == 15)) {
		//Tiene que ir a la izquierda.
		side = 0;
	}
	else if (!side && (aliens[0].pos.x == 0)) {
		//Tiene que ir a la derecha.
		side = 1;
	}

}

//Se encarga de encender los aliens q estan vivos.
void printAliens(alien_t aliens[], int cantidad_aliens_usados){
	int contador = 0;

	//Se encarga de imprimir todos los aliens que esten vivos.
	if ((aliens[0].pos.x >= 0) && (aliens[cantidad_aliens_usados - 1].pos.x <= 15)){
		for (contador = 0; contador < NUM_ALIENS; ++contador){
			if (aliens[contador].alive == ALIVE){
				dcoord_t MYPOINT(contador) = { aliens[contador].pos.x, aliens[contador].pos.y };
				disp_write(MYPOINT(contador), D_ON);
			}
		}
	}
}

//Funciones para imprimir alien random
//Recibe las coordenadas del alien random.
void printAlienRandom(int x, int y)
{
	if ((x >= 0) && (x <= 14))
	{
		dcoord_t myPoint_random = { x,y };
		disp_write(myPoint_random, D_ON);
		dcoord_t myPoint_random1 = { x + 1,y };
		disp_write(myPoint_random1, D_ON);
	}
}
//Recibe las coordenadas del alien random.
void clearAlienRandom(int x, int y)
{
	if ((x >= 0) && (x <= 14))
	{
		dcoord_t myPoint_random = { x,y };
		disp_write(myPoint_random, D_OFF);
		dcoord_t myPoint_random1 = { x + 1,y };
		disp_write(myPoint_random1, D_OFF);
	}
}

//Funciones para imprimir la bala
//Recibe las coordenadas de la bala.
void printBala(int x, int y){
	if ((y != 0) && (y != 15)) {
		dcoord_t myPoint_bala = { x,y };
		disp_write(myPoint_bala, D_ON);
	}
}

//Recibe las coordenadas de la bala.
void clearBala(int x, int y){
	dcoord_t myPoint_bala = { x,y };
	disp_write(myPoint_bala, D_OFF);
}

//Funciones para imprimir nave
//Recibe la coordenada x de la nave
void printNave(int x){
	if (x <= 13) {
		dcoord_t myPoint_nave = { x,15 };
		disp_write(myPoint_nave, D_ON);
		dcoord_t myPoint_nave1 = { x + 1,15 };
		disp_write(myPoint_nave1, D_ON);
		dcoord_t myPoint_nave2 = { x + 2,15 };
		disp_write(myPoint_nave2, D_ON);
		dcoord_t myPoint_nave3 = { x + 1,14 };
		disp_write(myPoint_nave3, D_ON);
	}
}

//Recibe la coordenada x de la nave.
void clearNave(int x){
	if (x <= 13) {
		dcoord_t myPoint_nave = { x ,15 };
		disp_write(myPoint_nave, D_OFF);
		dcoord_t myPoint_nave1 = { x + 1,15 };
		disp_write(myPoint_nave1, D_OFF);
		dcoord_t myPoint_nave2 = { x + 2,15 };
		disp_write(myPoint_nave2, D_OFF);
		dcoord_t myPoint_nave3 = { x + 1,14 };
		disp_write(myPoint_nave3, D_OFF);
	}
}

//Imprimo las vidas. Recibe la cantidad de vidas de la nave.
void printLives(int cantidad_vidas){
	int contador_vidas, contador;

	//Imprimo las vidas (prendidas o apagadas, como corresponda).
	for (contador_vidas = 0, contador = 0; contador_vidas < SPACESHIP_LIVES; ++contador_vidas){
		if (cantidad_vidas > 0){
			dcoord_t LIVES(contador) = { contador,0 };
			disp_write(LIVES(contador), D_ON);
		}
		else{
			dcoord_t LIVES(contador) = { contador,0 };
			disp_write(LIVES(contador), D_OFF);
		}
		--cantidad_vidas;
		++contador;
	}
}

//Se encarga de imprimir las barreras que estan vivas.
void printBarriers(barriers_t* barriers){
	if ((barriers[0].lives == RECENT_SHOT) || (barriers[0].lives == 0)){
		barriers[0].lives = 0;
		dcoord_t myPoint_apago_barrera = { 1, BARRIER_POS_Y };
		disp_write(myPoint_apago_barrera, D_OFF);
		dcoord_t myPoint_apago_barrera1 = { 2, BARRIER_POS_Y };
		disp_write(myPoint_apago_barrera1, D_OFF);
	}
	else {
		dcoord_t myPoint_barrera = { 1, BARRIER_POS_Y };
		disp_write(myPoint_barrera, D_ON);
		dcoord_t myPoint_barrera1 = { 2, BARRIER_POS_Y };
		disp_write(myPoint_barrera1, D_ON);
	}

	if ((barriers[1].lives == RECENT_SHOT) || (barriers[1].lives == 0)) {
		barriers[1].lives = 0;
		dcoord_t myPoint_apago_barrera2 = { 5, BARRIER_POS_Y };
		disp_write(myPoint_apago_barrera2, D_OFF);
		dcoord_t myPoint_apago_barrera3 = { 6, BARRIER_POS_Y };
		disp_write(myPoint_apago_barrera3, D_OFF);
	}
	else {
		dcoord_t myPoint_barrera2 = { 5, BARRIER_POS_Y };
		disp_write(myPoint_barrera2, D_ON);
		dcoord_t myPoint_barrera3 = { 6, BARRIER_POS_Y };
		disp_write(myPoint_barrera3, D_ON);
	}

	if ((barriers[2].lives == RECENT_SHOT) || (barriers[2].lives == 0)) {
		barriers[2].lives = 0;
		dcoord_t myPoint_apago_barrera4 = { 9, BARRIER_POS_Y };
		disp_write(myPoint_apago_barrera4, D_OFF);
		dcoord_t myPoint_apago_barrera5 = { 10, BARRIER_POS_Y };
		disp_write(myPoint_apago_barrera5, D_OFF);
	}
	else {
		dcoord_t myPoint_barrera4 = { 9, BARRIER_POS_Y };
		disp_write(myPoint_barrera4, D_ON);
		dcoord_t myPoint_barrera5 = { 10, BARRIER_POS_Y };
		disp_write(myPoint_barrera5, D_ON);
	}

	if ((barriers[3].lives == RECENT_SHOT) || (barriers[3].lives == 0)) {
		barriers[3].lives = 0;
		dcoord_t myPoint_apago_barrera6 = { 13, BARRIER_POS_Y };
		disp_write(myPoint_apago_barrera6, D_OFF);
		dcoord_t myPoint_apago_barrera7 = { 14, BARRIER_POS_Y };
		disp_write(myPoint_apago_barrera7, D_OFF);
	}
	else {
		dcoord_t myPoint_barrera6 = { 13, BARRIER_POS_Y };
		disp_write(myPoint_barrera6, D_ON);
		dcoord_t myPoint_barrera7 = { 14, BARRIER_POS_Y };
		disp_write(myPoint_barrera7, D_ON);
	}
}

#endif