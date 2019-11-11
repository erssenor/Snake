//Created by Ethan Senor

#pragma once
/*
#include <list>
#include <Windows.h>
#include <iostream>
#include "GlobalVar.h"
*/
#include "snakeSegment.h"


using namespace std;

class SnakeLogic
{
private:
 
	int tail;
	//the x,y coord for all the segments of the snake
	snakeSegment snake[1000];

	char oldDir;
	

public:
	//each new segment will be constructed after a fruit is taken. The new segment will take the place of the last segment on snake after first movement after fruit has been taken. 
	SnakeLogic();

	void saveLoc(int i);

	void update(int i);

	//adds a segemnt onto the snake.
	void addSegment(int seg);

	//the two funcions below simply return the nodes location.
	int getXLoc(int i);

	int getYLoc(int i);

	//returns size of entire array.
	int getSize();

	//returns char value for the snake.
	char dirChar(int i);

	//reads in value for which way it will go. 
	void getDirection(char newDir);
	

};

