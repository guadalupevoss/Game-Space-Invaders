#ifndef ALIENS_H
#define ALIENS_H

typedef struct {
	int x;
	int y;
	int alive;
	int score;
	int bullet;
}alien_t;

void updateAliens(void);
void moveAliens(void);  //no
void alienIsShot(void); //no
void lastAlien(void);	//no
void initAlien(int level); //POSICION + LIVE

#endif // ALIENS_H
