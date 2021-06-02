#ifndef BARRIERS_H
#define BARRIERS_H

typedef struct {
	int x;
	int y;
	int lives;
}barriers_t;

void barrierIsShot(barriers_t barrier, bullet_t bullet);

#endif // BARRIERS_H