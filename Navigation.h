#ifndef NAVIGATION_H
#define NAVIGATION_H


#include <math.h>
#include "Robot.h"
using namespace std;

class Command{
public:
	int left;
	int right;
	bool complete;
	Command(float, float);
	Command();
};



Command Navigate(Position* Target, Robot* Hasard, float margin);
float Pos2Ang(Position* Target, Position* Origin);
float Distance(Position* point1, Position* point2);
#endif
