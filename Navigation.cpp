
#include "Navigation.h"

const float pi = 3.14159;

Command::Command(float Turn, float Go){
	turn = Turn;
	go = Go;
};

Command::Command(){};

Command Navigate(Position* Target, Robot* Hasard){

	Command com(Pos2Ang(Target, &Hasard->pos) - Hasard->pos.ang, Distance(Target, &Hasard->pos));
	return com;
};

float Pos2Ang(Position* Target, Position* current){
	float x = Target->x - current->x;
	float y = Target->y - current->y;
	if (x == 0 & y > 0) { return (pi/2); }
	else if (x == 0 & y < 0) { return (3*pi/2); }
	float ang = atan(abs(y) / abs(x));
	if (x>0 & y <= 0) { return 2 * pi - ang; } //quad 4
	else if (x < 0 & y <= 0) { return (ang + pi / 2); } //3
	else if (x < 0 & y >= 0) { return (pi / 2 - ang); } //2
	else { return ang; } //1
};

float Distance(Position* point1, Position* point2){
	return sqrt(pow((point1->x - point2->x), 2.0) + pow((point1->y - point2->y), 2.0));
};