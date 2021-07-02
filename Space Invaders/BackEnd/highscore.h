#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include "constantes.h"

typedef struct {
    char name[NAMELENGHT]; //Nombre del jugador.
    unsigned long points; //Puntaje del jugador
}player_t;


int scoreboardInit(player_t highscores[MAXSCORES]);
int testNewScore(player_t* player, player_t highscores[MAXSCORES]);
int enterNewHighscore(player_t* player, player_t highscores[MAXSCORES]);
void clearArr(char* arr, int countChar);


#endif // HIGHSCORE_H
