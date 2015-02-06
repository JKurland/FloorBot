#ifndef ROBOT_H
#define ROBOT_H


#include<vector>
#include<string>
using namespace std;


class Position{
public:
	float x; 
	float y;
	float ang;
	Position(float, float, float);
	Position(float, float);
	Position();
};

class Tach{
public:
	float reading;
	bool side;
	int pin;
	Tach(bool, int);
	Tach();
};

class USD{
public:
	float reading;
	Position offset;
	int pin;
	USD(Position, int);
	USD();
};

class Trib{
public:
	float reading;
	int pin;
	Trib(int);
	Trib();
};

class Robot{
public:
	float length;
	float width; 
	float rot; //meters
	Position pos;
	Trib trib;
	vector<Tach> tach;
	vector<USD> usd;
	Robot();
};

bool stob(string);
#endif