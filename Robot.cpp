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

USD::USD(Position Offset, int Pin){
	pin = Pin;
	offset = Offset;
};

USD::USD(){}

Trib::Trib(int Pin){
	pin = Pin;
}

Trib::Trib(){}

bool stob(string str){
	return str != "0";
}

Robot::Robot(void){
	int tachs = 2;
	int tribs = 1;
	int usds = 2;
	float data[]= { 0.8, 0.2, 0.01, 0, 26, 1, 27, 0.4, 0.1, 0, 50, 0.4, -0.1, 0, 51, 1 };
	length = data[0];
	width = data[1];
	rot = data[2];
	int off = 3;
	//tachometers
	for (int i = 0; i < tachs * 2; i += 2){
		tach.push_back(Tach(data[i + off], data[i + off + 1]));
	}
	off += tachs * 2;
	//usds
	for (int i = 0; i < usds * 4; i += 4){
		usd.push_back(USD(Position(data[i + off], data[i + off + 1], data[i + off + 2]), data[i + off + 3]));
	}
	off += usds * 4;
	trib = Trib(data[off]);
	Position pos(0, 0, 0);
};
