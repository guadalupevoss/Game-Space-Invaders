#ifndef HIGHSCORE_H
#define HIGHSCORE_H

//en raspi es 3 enrealidad
#define NAME_LENGHT				20			//Número máximo de caracteres de un nombre
#define SCORES_NUM 10

typedef struct {
    char name[NAME_LENGHT]; //Nombre del jugador.
    unsigned long points; //Puntaje del jugador
}player_t;


int scoreboardInit(player_t highscores[SCORES_NUM]);
int testNewScore(player_t* player, player_t highscores[SCORES_NUM]);
int enterNewHighscore(player_t* player, player_t highscores[SCORES_NUM]);


#endif // HIGHSCORE_H
