#include "Robot.h"
#include <string>
#include <vector>
using namespace std;
class Packet{
	int LeftMotor;
	int RightMotor;
	int LeftDir;
	int RightDir;
	int LeftBrake;
	int RightBrake;
	vector<string> file;
	vector<string> contents;
	bool update[7];
};

int initialise(void);
Packet tick(Robot*);
