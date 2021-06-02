#include "randomalien.h"

void initRandomAlien(alienRandom_t* alien) {
    alien->alive = DEAD;
}

void randomAlienIsBorn(alienRandom_t* alien, int ciclos_random) {
    //srand(time(NULL));
    alien->alive = ALIVE;
    int x;
    if ((ciclos_random % 2) == 0) {
        x = 0;
        alien->direction = DERECHA;
    }
    else if ((ciclos_random % 2) == 0) {
        x = WIDTH;
        alien->direction = IZQUIERDA;
    }
    initPosition(&alien->pos, x, RANDOM_ALIEN_POS_Y);
    alien->puntaje = rand() % (MAX_POINTS);
}

void updateRandomAlien(alienRandom_t * alien, bullet_t* bullet){
    if (alien->alive){
        randomAlienIsShot(alien, bullet);
        moveRandomAlien(alien);
    }   
}

void moveRandomAlien(alienRandom_t* alien) {
    switch(alien->direction){
        case DERECHA:
            if (alien->pos.x == WIDTH){
                alien->alive = DEAD;
            }
            else{
                changePosition (alien->pos, 1 , 0);
            }
            break;
        case IZQUIERDA:
            if (alien->pos.x == 0){
                alien->alive = DEAD;
            }
            else{
                changePosition (alien->pos, -1 , 0);
            }
            break;
    }
}

void randomAlienIsShot(alienRandom_t* alien, bullet_t* bullet){
    if ((comparePosition(alien->pos, bullet->pos))&&(bullet->type == SPACESHIP_BULLET)){
        alien->alive = DEAD;
    }
}


/*
int move_random_alien (mysteryalien_t alien_random, int lado)
#ifdef ALLEGRO
{
    int x= alien_random.x;
    /*FUNCION MOVER_ALIEN_RANDOM QUE RECIBA LADO_RANDOM Y MYSTERY_ALIEN misma funcion */
    //Si apareció por la derecha debo moverlo hacia la izquierda y viceversa.
/*if (lado == DERECHA)
{
    x -= SCREEN_W / 200;
}
if (lado == IZQUIERDA)
{
    x += SCREEN_W / 200;

}
return x;
}
#endif
#ifdef RASPI
{
clear_alien_random(alien_random.x, alien_random.y);
int x = alien_random.x;
if (lado == DERECHA)
{
    x -= 1;
}
if (lado == IZQUIERDA)
{
    x += 1;
}
return x;
}
#endif
*/

/*
#ifdef ALLEGRO
int update_random_alien (int bullet_x, int bullet_y, int *nave_shot, mysteryalien_t alien_random, ALLEGRO_BITMAP* image_alien[], ALLEGRO_BITMAP* image_alien_random, unsigned long *puntaje, int ciclos_random)
#endif
#ifdef RASPI
int update_random_alien (int bullet_x, int bullet_y, int *nave_shot, mysteryalien_t alien_random, unsigned long *puntaje, int ciclos_random)
#endif
{
    int devuelvo;
    //Si el alien estaba vivo y le dispararon ingresa al if.
    if( alien_random.alive && RANDOM_ALIEN_NOT_SHOT)
    {
        //Me fijo si existia una bala de la nave.
        if(*nave_shot==1)
        {
            //Si le pegaron al alien cambio su estado a muerto, elimino el disparo de la nave e imprimo la imagen del alien muerto.
            alien_random.alive=0;
            *nave_shot=0;
            #ifdef ALLEGRO
        al_draw_bitmap(image_alien[0], alien_random.x, alien_random.y, 0);
        #endif

            //Establezco un puntaje random que depende tambien del valor random establecido para los ciclos.
            if(ciclos_random>=100)
            {
                if ((ciclos_random/100)<=30)
                {
                    *puntaje = *puntaje + (ciclos_random/10) +10;
                }
                else
                {
                    *puntaje = *puntaje + (ciclos_random/10);
                }
            }
            else
            {
                *puntaje=*puntaje + ciclos_random;
            }

        }
    }

   //Si no le dispararon al alien entonces imprimo la imagen.
    if(alien_random.alive)
    {
        #ifdef ALLEGRO
    al_draw_bitmap(image_alien_random, alien_random.x, alien_random.y, 0);
    #endif

    #ifdef RASPI
    print_alien_random (alien_random.x, alien_random.y);
    #endif
        devuelvo=1;
    }
    else                    //Si el alien murio entonces hago flip display para mostrar la imagen del alien muerto y pongo un rest para que se pueda observar
    {
        #ifdef ALLEGRO
        al_flip_display();
        al_rest(0.05);//ESPERA UN RATO PARA QUE SE VEA CUANDO EXPLOTA
    #endif
    #ifdef RASPI
    dcoord_t myPoint_random = {alien_random.x,alien_random.y};
    disp_write (myPoint_random, D_OFF);
    dcoord_t myPoint_random1 = {alien_random.x+1,alien_random.y};
    disp_write (myPoint_random1, D_OFF);
    #endif
        devuelvo=0;
    }
    return devuelvo;
}
*/