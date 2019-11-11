// Snake.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Created by Ethan Senor

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "SnakeLogic.h"
#include "GlobalVar.h"
#include "Fruit.h"


using namespace std;

void gen_map(SnakeLogic &, Fruit &, bool &, int &);

bool game_over(SnakeLogic);

void clearScreen(); // makes the console prettier


void ShowConsoleCursor(bool showFlag); // ^^


int main()
{
	SnakeLogic s1;

	Fruit fruit;

	bool game = true;

	int score = 0; //self explanatory

	//used for directional logic for preventing U turns.
	char newDir = 'd';

	ShowConsoleCursor(false);

	while (game)
	{
		gen_map(s1, fruit, game, score);
		if (_kbhit())
		{
			newDir = _getch();
		}
		s1.getDirection(newDir);
		Sleep(250);

		if (game == true)
			clearScreen();
			//system("cls");
	}

	cout << "***GAME OVER***" << endl << "***SCORE: " << score << "***" << endl;
	//print_map();

	return 0;
}



//boarders of map rep by #
void gen_map(SnakeLogic &s1, Fruit &fruit, bool &game, int &score)
{
	//map[y][x]
	char map[MAP_HEIGHT + 1][MAP_WIDTH + 1];


	//assigns values of map for basic layout.
	for (int w = 0; w <= MAP_WIDTH; w++)
	{
		for (int h = 0; h <= MAP_HEIGHT; h++)
		{
			if (w == 0)
				map[w][h] = '#';
			else if (w == MAP_WIDTH)
				map[w][h] = '#';
			else if (h == 0 and (w != 0 and w != MAP_WIDTH))
				map[w][h] = '#';
			else if (h == MAP_HEIGHT and (w != 0 and w != MAP_WIDTH))
				map[w][h] = '#';
			else
				map[w][h] = ' ';
		}
	}


	//decides if head has taken a fruit. If so generates a new location for fruit, increases score and size of snake.
	//Both outcomes put the location of the fruit on the map
	if (s1.getXLoc(0) == fruit.getfxloc() and s1.getYLoc(0) == fruit.getfyloc())
	{
		
		//generates new location of fruit.
		fruit.getNewLoc(s1);

		//adds segment to snake. 
		s1.addSegment(s1.getSize());

		//increment score
		score += 10;

		map[fruit.getfyloc()][fruit.getfxloc()] = 'F';
	}
	else
	{
		map[fruit.getfyloc()][fruit.getfxloc()] = 'F';
	}



	//inserts each part of the snake into the map.
	for (int seg = 0; seg <= s1.getSize(); seg++)
	{
		//saves location into temp variables
		s1.saveLoc(seg);

		//changes position of all segments to where its predecessor was. 
		if (seg != 0)
			s1.update(seg);

		map[s1.getYLoc(seg)][s1.getXLoc(seg)] = s1.dirChar(seg);
		
	}


	//prints out map.
	for (int w = 0; w <= MAP_WIDTH; w++)
	{
		for (int h = 0; h <= MAP_HEIGHT; h++)
			if (h != MAP_HEIGHT)
				cout << map[w][h] << ' '; //space is used for visual purposes
			else
				cout << map[w][h] << endl;
	}


	//determines if the snake head hit a wall.
	game = game_over(s1);
}

bool game_over(SnakeLogic s1)
{

	//if ran into the right wall or bottom wall end game.
	if (s1.getXLoc(0) == MAP_WIDTH || s1.getYLoc(0) == MAP_HEIGHT)
	{
		return false;
	}

	//if ran into the top wall or left wall end game. 
	else if (s1.getXLoc(0) == 0 || s1.getYLoc(0) == 0)
	{
		return false;
	}

	for (int seg = 4; seg < s1.getSize(); seg++)
	{
		if (s1.getXLoc(0) == s1.getXLoc(seg) and s1.getYLoc(0) == s1.getYLoc(seg))
			return false;
	}


	//literally anywhere else just keep the game running. 
	return true;
}


void clearScreen()
{
	HANDLE hOut;
	COORD Position;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}


void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
