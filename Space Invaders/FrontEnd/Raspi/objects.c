#include "objects.h"
#include "disdrv.h"

//CHEQUEAR LO DEL ARREGLO DE ALIENS, MANTIENEN SU POSICION EN EL ARREGLO??

//Funciones para imprimir aliens
//Para la cantidad de aliens usados usar lastAlien.
void clearAliens(alien_t aliens[], int cantidad_aliens_usados)
{
    //SOFIA CASTRO MURPHY, LEGAJO 61146, DNI 43035705 DESCONFIA FIRMEMENTE DE ESTA FUNCION. ESTA EN CONTRA DE SU UTILIZACION EN LA INTEGRIDAD DE ESTE PROGRAMA.
    int contador;
    //Se encarga de apagar todos los aliens que esten vivos.
    if ((aliens[0].pos.x > 0) && (aliens[cantidad_aliens_usados - 1].pos.x < 15))
    {
        for (contador = 0; contador < cantidad_aliens_usados; ++contador)
        {
            if (aliens[contador].alive == ALIVE) {
                dcoord_t CLEARPOINT(contador) = { aliens[contador].pos.x,aliens[contador].pos.y };
                disp_write(CLEARPOINT(contador), D_OFF);
            }
        }
    }

    disp_update();
}

void printAliens(alien_t aliens[], int cantidad_aliens_usados)
{
    int contador = 0;
    //clear_aliens(arr, cantidad_aliens_usados);

    //Se encarga de imprimir todos los aliens que esten vivos.

    if ((aliens[0].pos.x > 0) && (aliens[cantidad_aliens_usados - 1].pos.x < 15))
    {
        for (contador = 0; contador < CANTIDAD_ALIENS; ++contador)
        {
            if (aliens[contador].alive)
            {
                dcoord_t MYPOINT(contador) = { aliens[contador].pos.x,aliens[contador].pos.y };
                disp_write(MYPOINT(contador), D_ON);
            }
        }
    }

    //disp_update();
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
    dcoord_t myPoint_bala = { x,y };
    disp_write(myPoint_bala, D_ON);
}

//Recibe las coordenadas de la bala.
void clearBala(int x, int y){
    dcoord_t myPoint_bala = { x,y };
    disp_write(myPoint_bala, D_OFF);
}

//Funciones para imprimir nave
//Recibe la coordenada x de la nave
void printNave(int x){
    dcoord_t myPoint_nave = { x,15 };
    disp_write(myPoint_nave, D_ON);
    dcoord_t myPoint_nave1 = { x + 1,15 };
    disp_write(myPoint_nave1, D_ON);
    dcoord_t myPoint_nave2 = { x + 2,15 };
    disp_write(myPoint_nave2, D_ON);
    dcoord_t myPoint_nave3 = { x + 1,14 };
    disp_write(myPoint_nave3, D_ON);
}

//Recibe la coordenada x de la nave.
void clearNave(int x){
    dcoord_t myPoint_nave = { x,15 };
    disp_write(myPoint_nave, D_OFF);
    dcoord_t myPoint_nave1 = { x + 1,15 };
    disp_write(myPoint_nave1, D_OFF);
    dcoord_t myPoint_nave2 = { x + 2,15 };
    disp_write(myPoint_nave2, D_OFF);
    dcoord_t myPoint_nave3 = { x + 1,14 };
    disp_write(myPoint_nave3, D_OFF);
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

