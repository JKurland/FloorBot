#include "Tracking.h"
using namespace std;


void Update(Robot* Hasard){
	float oldang = Hasard->pos.ang;
	float Ldist = Hasard->tach[0].reading;
	float Rdist = Hasard->tach[1].reading;
	if (Hasard->tach[0].side){ //0 is left 1 is right (wrt tach.side)
		swap(Ldist, Rdist);
	}
	Hasard->pos.ang = oldang + (Rdist - Ldist) / Hasard->width; //width is measured from the centre of each wheel

};