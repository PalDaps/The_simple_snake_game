#include <iostream>
#include <conio.h>

bool GameOver;
const int width = 10;
const int height = 5;
int x, y, fruitX, fruitY, score;
enum eDirection { STOP = 0, LEFT, UP, RIGHT, UP, DOWN };
eDirection dir;

void SetUp()
{
	GameOver = false;
	// dir = STOP;
	x = width / 2 - 1;
	y = height / 2 - 1;
	fruitX = rand() % width;
	fruitX = rand() % height; 
	score = 0;
}

void Draw()
{
	// system("cls"); // the clean terminal
	for (int i = 0; i < width+1; i++)
	{
		std::cout << "#";
	}
	std::cout << std::endl;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0 || j == width-1)
			{
				std::cout << "#";
			}
			if (i == x && j == y)
			{
				std::cout << "0";
			}
			else if (i == fruitX && j == fruitX)
			{
				std::cout << "F";
			}
			else
				std::cout << " ";
			// std::cout << " ";
		}
		std::cout << std::endl;
	}
	for (int i = 0; i < width+1; i++)
	{
		std::cout << "#";
	}
}

void Input()
{
	/*
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'x':
			GameOver = true;
			break;
		}
	}
	*/
}

void Logic()
{
	/*
	switch(dir)
	{ 
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
		case UP:
			y++;
			break;
		case DOWN:
			y--;
			break;
	}
	*/

}

int main()
{
	SetUp();
	while (!GameOver)
	{
		Draw();
		Input();
		Logic();
	}
	return 0;
}