#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#define MAXSCORES 10
#define NAMELENGHT 10

//sino pasarle directamente la struct del player que habiamos hehco
typedef struct{
    char name[NAMELENGHT];
    unsigned long points;
}score_t;

// score_t tabla[MAXSCORES] le paso a la funcion





#endif // HIGHSCORE_H
