#include <iostream>
#include <conio.h>



struct Map {
	Map() : height(30), width(30) {
	}
	int height;
	int width;
}map;

struct Snake {
	Snake() : x(map.height/2), y(map.width/2) {
	}
	int x;
	int y;
}snake;

struct Fruit {
	Fruit() : x(rand() % map.height), y(rand() % map.width) {
	}
	int x;
	int y;
}fruit;


void map_generator() {
	// creating a two-dimensional array via(через) pointers
	char** array_map = new char*[map.height];
	for (int i = 0; i < map.height; i++) {
		*(array_map + i) = new char[map.width];
	}
	// the filling map
	for (int i = 0; i < map.height; i++) {
		for (int j = 0; j < map.width; j++) {
			if (i == 0 || i == map.height - 1) *(*(array_map + i) + j) = '*';
			else if (j == 0 || j == map.width - 1) *(*(array_map + i) + j) = '*';
			else if (j == snake.x && i == snake.y ) *(*(array_map + i) + j) = '0';
			else if (i == fruit.x && j == fruit.y ) *(*(array_map + i) + j) = '@';
			else *(*(array_map + i) + j) = ' ';
		}
	}
	// the drawing map
	for (int i = 0; i < map.height; i++) {
		for (int j = 0; j < map.width; j++) {
			std::cout << *(*(array_map+i)+j);
		}
		std::cout << std::endl;
	}
	char word[] = "LogData\0";
	std::cout << word << std::endl;

	// deleting memory
	for (int i = 0; i < map.height; i++) {
		delete[] *(array_map + i);
	}
	delete[]array_map;
}

void logic() {
	switch (_getch()) {
		case 'a':
			snake.x--;
			break;
		case 'd':
			snake.x++;
			break;
		case 'w':
			snake.y--;
			break;
		case 's':
			snake.y++;
			break;
		default:
			break;
	}
}

int main() {
	while (true) {
		map_generator();
		logic();
		std::system("cls");
	}
	return 0;
}