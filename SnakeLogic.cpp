//Created by Ethan Senor

#include "SnakeLogic.h"
#include <list>
#include <Windows.h>
#include <iostream>
#include "GlobalVar.h"
#include "snakeSegment.h"
//#include <iostream>

SnakeLogic::SnakeLogic()
{
	snakeSegment head;
	head.xLoc = MAP_HEIGHT / 2;
	head.yLoc = MAP_WIDTH / 2;

	snake[0] = head;

	tail = 1;

	oldDir = 'd';
}

void SnakeLogic::saveLoc(int i)
{
	snake[i].xTemp = snake[i].xLoc;
	snake[i].yTemp = snake[i].yLoc;
	snake[i].tempDirection = snake[i].direction;
}

void SnakeLogic::update(int i) //add segemnt funtion?
{
	snake[i].xLoc = snake[i - 1].xTemp;
	snake[i].yLoc = snake[i - 1].yTemp;
	snake[i].direction = snake[i - 1].tempDirection;
}


//eventually add checks for the snakes body.
void SnakeLogic::addSegment(int seg)
{
	//checking for possible locations to put the new segment
	if (snake[seg - 1].direction == '>')
	{
		if ((snake[seg - 1].xLoc - 1) != 0)
		{
			snake[seg].xLoc = snake[seg - 1].xLoc - 1;
			snake[seg].yLoc = snake[seg - 1].yLoc;
			tail++;
		}
		else if ((snake[seg - 1].yLoc + 1) != MAP_HEIGHT)
		{
			snake[seg].xLoc = snake[seg - 1].xLoc;
			snake[seg].yLoc = snake[seg - 1].yLoc + 1;
			tail++;
		}
		else
		{
			snake[seg].xLoc = snake[seg - 1].xLoc;
			snake[seg].yLoc = snake[seg - 1].yLoc - 1;
			tail++;
		}

	}
	else if (snake[seg - 1].direction == '<')
	{
		if ((snake[seg - 1].xLoc + 1) != MAP_WIDTH)
		{
			snake[seg].xLoc = snake[seg - 1].xLoc + 1;
			snake[seg].yLoc = snake[seg - 1].yLoc;
			tail++;
		}
		else if ((snake[seg - 1].yLoc + 1) != MAP_HEIGHT)
		{
			snake[seg].xLoc = snake[seg - 1].xLoc;
			snake[seg].yLoc = snake[seg - 1].yLoc + 1;
			tail++;
		}
		else
		{
			snake[seg].xLoc = snake[seg - 1].xLoc;
			snake[seg].yLoc = snake[seg - 1].yLoc - 1;
			tail++;
		}
	}
	else if (snake[seg - 1].direction == 'v')
	{
		if ((snake[seg - 1].yLoc - 1) != 0)
		{
			snake[seg].xLoc = snake[seg - 1].xLoc;
			snake[seg].yLoc = snake[seg - 1].yLoc - 1;
			tail++;
		}
		else if ((snake[seg - 1].xLoc - 1) != 0)
		{
			snake[seg].xLoc = snake[seg - 1].xLoc - 1;
			snake[seg].yLoc = snake[seg - 1].yLoc;
			tail++;
		}
		else
		{
			snake[seg].xLoc = snake[seg - 1].xLoc + 1;
			snake[seg].yLoc = snake[seg - 1].yLoc;
			tail++;
		}

	}
	else
	{
		if ((snake[seg - 1].yLoc + 1) != MAP_HEIGHT)
		{
			snake[seg].xLoc = snake[seg - 1].xLoc;
			snake[seg].yLoc = snake[seg - 1].yLoc + 1;
			tail++;
		}
		else if ((snake[seg - 1].xLoc - 1) != 0)
		{
			snake[seg].xLoc = snake[seg - 1].xLoc - 1;
			snake[seg].yLoc = snake[seg - 1].yLoc;
			tail++;
		}
		else
		{
			snake[seg].xLoc = snake[seg - 1].xLoc + 1;
			snake[seg].yLoc = snake[seg - 1].yLoc;
			tail++;
		}
	} 
}



int SnakeLogic::getXLoc(int i)
{
	return snake[i].xLoc;
}

int SnakeLogic::getYLoc(int i)
{
	return snake[i].yLoc;
}

int SnakeLogic::getSize()
{
	return tail;
}

char SnakeLogic::dirChar(int i)
{
	return snake[i].direction;
}

void SnakeLogic::getDirection(char newDir)
{

	//the large if else statement prevents u turns.
	if (oldDir == 'd' and (newDir == 'w' or newDir == 's'))
	{
		oldDir = newDir;
	}
	else if (oldDir == 's' and (newDir == 'd' or newDir == 'a'))
	{
		oldDir = newDir;
	}
	else if (oldDir == 'a' and (newDir == 'w' or newDir == 's'))
	{
		oldDir = newDir;
	}
	else if (oldDir == 'w' and (newDir == 'd' or newDir == 'a'))
	{
		oldDir = newDir;
	}

	switch (oldDir)
	{
	case 'w': snake[0].yLoc = snake[0].yLoc - 1;
		snake[0].direction = '^';
		break;

	case 'd': snake[0].xLoc = snake[0].xLoc + 1;
		snake[0].direction = '>';
		break;

	case 's': snake[0].yLoc = snake[0].yLoc + 1;
		snake[0].direction = 'v';
		break;

	case 'a': snake[0].xLoc = snake[0].xLoc - 1;
		snake[0].direction = '<';
		break;
	}
	
}
