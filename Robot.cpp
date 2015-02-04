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

bool stob(string str){
	return str != "0";
}

Robot::Robot(string* data, int tachs, int usds){
	string str = *data;
	bool bo;
	int in;
	float fl1, fl2, fl3;
	Position p;


	size_t pos1 = 0;
	size_t pos2 = str.find(" ");
	length = stof(str.substr(pos1, pos2 - pos1));

	pos1 = pos2;
	pos2 = str.find(" ", pos1 + 1);
	width = stof(str.substr(pos1, pos2 - pos1));

	pos1 = pos2;
	pos2 = str.find(" ", pos1 + 1);
	rot = stof(str.substr(pos1, pos2 - pos1));

	//Tachometers
	for (int i = 0; i < tachs; i++){

		pos1 = pos2;
		pos2 = str.find(" ", pos1 + 1);
		bo = stob(str.substr(pos1, pos2 - pos1));

		pos1 = pos2;
		pos2 = str.find(" ", pos1 + 1);
		in = stoi(str.substr(pos1, pos2 - pos1));

		tach.push_back(Tach(bo, in));
	}

	//Ultra Sonic Distance Sensors
	for (int i = 0; i < usds; i++){

		pos1 = pos2;
		pos2 = str.find(" ", pos1 + 1);
		fl1 = stof(str.substr(pos1, pos2 - pos1));

		pos1 = pos2;
		pos2 = str.find(" ", pos1 + 1);
		fl2 = stof(str.substr(pos1, pos2 - pos1));

		pos1 = pos2;
		pos2 = str.find(" ", pos1 + 1);
		fl3 = stof(str.substr(pos1, pos2 - pos1));

		pos1 = pos2;
		pos2 = str.find(" ", pos1 + 1);
		in = stoi(str.substr(pos1, pos2 - pos1));

		pos = Position(fl1, fl2, fl3);

		usd.push_back(USD(&pos, in));
	}

	//Tribometer

	pos1 = pos2;
	pos2 = str.find(" ", pos1 + 1);
	in = stoi(str.substr(pos1, pos2 - pos1));

	Trib trib(in);
	Position pos(0, 0, 0);
};

Robot::Robot(){
};