#include "Fruit.h"
#include "GlobalVar.h"
#include <ctime>
#include <cstdlib>

Fruit::Fruit()
{
	unsigned seed = time(0);

	srand(seed);

	//generates a random location for first fruit
	fxloc = (rand() % MAP_WIDTH) + 1;
	//if fruit is placed at a wall spot or on head then replace it.
	while ((fxloc == MAP_WIDTH) || (fxloc == MAP_WIDTH / 2))
		fxloc = (rand() % MAP_WIDTH) + 1;

	//likewise with y
	fyloc = (rand() % MAP_HEIGHT) + 1;

	while ((fyloc == MAP_HEIGHT) || (fyloc == MAP_HEIGHT / 2))
		fyloc = (rand() % MAP_HEIGHT) + 1;
	
}

int Fruit::getfxloc()
{
	return fxloc;
}

int Fruit::getfyloc()
{
	return fyloc;
}

//Note for improvemnt: consider changing edge detection to one time only
void Fruit::getNewLoc(SnakeLogic snake)
{
	//generates random x location
	fxloc = (rand() % MAP_WIDTH) + 1;
	fyloc = (rand() % MAP_HEIGHT) + 1;

	//checks for collision. 
	for (int seg = 0; seg < snake.getSize(); seg++)
	{
		//checks for collison with each snake segment
		if (fxloc == snake.getXLoc(seg) && fyloc == snake.getYLoc(seg))
		{
			fxloc = (rand() % MAP_WIDTH) + 1;
			fyloc = (rand() % MAP_HEIGHT) + 1;
			seg = 0;
		}
		//checks for collision with edge
		else
		{
			if ((fxloc == MAP_WIDTH) || (fxloc == 0) || (fyloc == MAP_HEIGHT) || (fyloc == 0))
			{
				fxloc = (rand() % MAP_WIDTH) + 1;
				fyloc = (rand() % MAP_HEIGHT) + 1;
				seg = 0;
			}
		}

	}
}