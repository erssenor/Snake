#pragma once
#include "SnakeLogic.h"
class Fruit
{
private:
	//friut x location
	int fxloc;
	//fruit y location
	int fyloc;
public:

	Fruit();

	//~Fruit() { fxloc = NULL; fyloc = NULL; }

	//returns the locations respectively
	int getfxloc();
	int getfyloc();


	//generates new fruit
	void getNewLoc(SnakeLogic snake);

};

