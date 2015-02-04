#include"Robot.h"
using namespace std;

Position::Position(float X, float Y, float Ang){
	x = X;
	y = Y;
	ang = Ang;
};

Position::Position(float X, float Y){
	x = X;
	y = Y;
};

Position::Position(){

};

Tach::Tach(bool Side, int Pin){
	side = Side;
	pin = Pin;
};

Tach::Tach(){};

USD::USD(Position* Offset, int Pin){
	pin = Pin;
	offset = *Offset;
};

USD::USD(){}

Trib::Trib(int Pin){
	pin = Pin;
}

Trib::Trib(){}


Robot::Robot(float Length, float Width, float ROT, Trib* tr, vector<Tach>* ta, vector<USD>* Usd){
	length = Length;
	width = Width;
	rot = ROT;
	Position pos(0, 0, 0);
	trib = *tr;
	tach = *ta;
};

Robot::Robot(){
};