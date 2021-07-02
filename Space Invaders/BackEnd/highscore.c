#include "highscore.h"

#ifndef RASPI
#define PATH "Resources/scoreboard.txt"
#endif

#ifdef RASPI
#define PATH "SpaceInvaders/Resources/scoreboard.txt"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Para usar strcpy()
#pragma warning (disable: 4996)

//asumo q en player_t player esta lo de este jugador

//devuelve 0 si todo ok
int scoreboardInit(player_t highscores[MAXSCORES]) {
    unsigned int counter;
    int error = 0, errorBis = 0;
    FILE* scoreboard_create = fopen(PATH, "a");     //crea el archivo si no esta
    if (scoreboard_create == NULL) {
        error = 1;
        printf("error de archivo 1\n");
    }
    else {
        fclose(scoreboard_create);
    }
    FILE* scoreboard_file = fopen(PATH, "r");     //lee el archivo
    if (scoreboard_file == NULL) {
        error = 1;
        printf("error de archivo 2\n");
    }
    else {
        for (counter = 0; counter < MAXSCORES; counter++) {            //limpio la estructura por si tiene datos basura
            strcpy(highscores[counter].name, "-");
            highscores[counter].points = 0;
        }
        for (counter = 0; counter < MAXSCORES; counter++) {             //lee datos del archivo txt y los guarda en la estructura
            errorBis = fscanf(scoreboard_file, "%s %lu", &highscores[counter].name, &highscores[counter].points);
        }
        if (errorBis == 1) {
            printf("Error en fscanf\n");
            error = 1;
        }
        fclose(scoreboard_file);
    }
    return error;
}
//devuelve 1 si entra en los highscores
int testNewScore(player_t* player, player_t highscores[MAXSCORES])           //testea si un score nuevo entra en los highscores o no. devuelve 1 si entra, 0 si no
{
    int i = 0;
    if ((player->points) >= highscores[MAXSCORES - 1].points)
    {
        i = 1;
    }
    return i;
}
int enterNewHighscore(player_t* player, player_t highscores[MAXSCORES]){
    unsigned int counter, stop = 0, error = 0;
    unsigned long pointsTemp;
    char nameTemp[NAMELENGHT];
    if(highscores[0].points==0){
        highscores[0].points= player->points;
        strcpy(highscores[0].name,player->name);
    }
    else{
        strcpy(highscores[MAXSCORES-1].name,player->name);
        highscores[MAXSCORES-1].points=player->points;
        for(counter=(MAXSCORES-1) ; ((stop==0)&&(counter!=0)) ; counter--){               //ordena el nuevo score en la posicion adecuada
            if(highscores[counter].points >= highscores[counter-1].points){
                    pointsTemp = highscores[counter-1].points;
                    strcpy(nameTemp,highscores[counter-1].name);

                    highscores[counter-1].points=highscores[counter].points;
                    strcpy(highscores[counter-1].name,highscores[counter].name);

                    highscores[counter].points=pointsTemp;
                    strcpy(highscores[counter].name,nameTemp);
            }
            else{
                stop=1;
            }
        }
    }
    FILE *scoreboard_write = fopen("Resources/scoreboard.txt", "w");
    if (scoreboard_write==NULL){
        error = 1;
        printf("Error de apertura de archivo para escritura\n");
    }
    else {
        for (counter = 0; counter < MAXSCORES; counter++) {                        //escribe como quedo la tabla en el txt
            fprintf(scoreboard_write, "%s\t", highscores[counter].name);
            fprintf(scoreboard_write, "%lu\t", highscores[counter].points);
        }
        fclose(scoreboard_write);
    }
    return error;
}

//termina de jugar se llama a test new score, si da 1 se llama a enter new highscore





