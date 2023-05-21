#include <iostream>
#include <conio.h>

bool GameOver;
const int width = 30;
const int height = 30;
int x, y, fruitX, fruitY, score;
int taliX[100], taliY[100];
int nTail;
enum class eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

void SetUp()
{
	GameOver = false;
	dir = eDirection::STOP;
	x = width/2 - 1;
	y = height/2 - 1;
	fruitX = rand() % (width -1);
	fruitY = rand() % (height-1); 
	score = 0;
}
void Draw()
{
	system("cls"); // the clean terminal
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
			if (i == y && j == x)
			{
				std::cout << "0";
			}
			else if (i == fruitY && j == fruitX)
			{
				std::cout << "F";
			}
			else
			{
				for (int k = 0; k < nTail; k++) {
					if (taliX[k] == j && taliY[k] == i)
						std::cout << 'o';
				}
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
	for (int i = 0; i < width+1; i++)
	{
		std::cout << "#";
	}
	std::cout << std::endl;
	std::cout << "YOUR SCORE : " << score << std::endl;
}
void Input()
 {
	if (_kbhit())
	{
		// std::cout << _getch();
		switch (_getch())
		{
		case 'a':
			dir = eDirection::LEFT;
			break;
		case 'd':
			dir = eDirection::RIGHT;
			break;
		case 'w':
			dir = eDirection::UP;
			break;
		case 's':
			dir = eDirection::DOWN;
			break;
		case 'x':
			GameOver = true;
			break;
		}
	}
}

void Logic()
{
	int prevx = taliX[0];
	int prevy = taliY[0];
	int prev2x, prev2y;
	for (int i = 1; i < nTail; i++) {
		prev2x = taliX[i];
		prev2y = taliY[i];
		taliX[i] = prevx;
		taliY[i] = prevy;
		prevx = prev2x;
		prevy = prev2y;
	}
	switch(dir)
	{ 
		case eDirection::LEFT:
			x--;
			// std::cout << x << " ";
			break;
		case eDirection::RIGHT:
			x++;
			break;
		case eDirection::UP:
			y--;
			// std::cout << y << " ";
			break;
		case eDirection::DOWN:
			y++;
			// std::cout << y << " ";
			break;
	}
	if (x > width || x < 0 || y > height || y < 0)
		GameOver = true;
	if (x == fruitX && y == fruitY) {
		score += 100;
		fruitX = rand() % (width -1);
		fruitY = rand() % (height -1);
		nTail++;
	}
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