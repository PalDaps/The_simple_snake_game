#include <iostream>
#include <conio.h>

char input = ' ';
bool TheEnd = false;

struct Map {
	Map() : height(32), width(32) {
	}
	int height;
	int width;
}map;

struct Snake {
	Snake() : x(map.height/2), y(map.width/2), score(0), number_of_tails(0) {
	}
	int x;
	int y;
	int score;
	int number_of_tails;
	int x_tail [100];
	int y_tail [100];
}snake;

struct Fruit {
	Fruit() : x(rand() % map.height), y(rand() % map.width) {
	}
	int x;
	int y;
}fruit1, fruit2;


void map_generator() {
	// creating a two-dimensional array via(через) pointers
	char** array_map = new char*[map.height];
	for (int i = 0; i < map.height; i++) {
		*(array_map + i) = new char[map.width];
	}
	// the filling map
	for (int i = 0; i < map.height; i++) {
		for (int j = 0; j < map.width; j++) {
			/*if (i == 0 || i == map.height - 1) *(*(array_map + i) + j) = '*';
			else if (j == 0 || j == map.width - 1) *(*(array_map + i) + j) = '*';
			else if (j == snake.x && i == snake.y ) *(*(array_map + i) + j) = '0'; 
			else if (j == fruit1.x && i == fruit1.y) *(*(array_map + i) + j) = '@';
			else if (j == fruit2.x && i == fruit2.y) *(*(array_map + i) + j) = '@';
			else *(*(array_map + i) + j) = ' ';*/
			if (i == 0 || i == map.height - 1) *(*(array_map + i) + j) = '#';
			else if (i == 1 || i == map.height - 2) *(*(array_map + i) + j) = '*';
			else if (j == 1 || j == map.width - 2) *(*(array_map + i) + j) = '*';
			else if (j == 0 || j == map.width - 1) *(*(array_map + i) + j) = '#';
			else if (j == snake.x && i == snake.y) *(*(array_map + i) + j) = '0';
			else if (j == fruit1.x && i == fruit1.y) *(*(array_map + i) + j) = '@';
			else if (j == fruit2.x && i == fruit2.y) *(*(array_map + i) + j) = '@';
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
	std::cout << "SCORE : " << snake.score << std::endl;
	char word[] = "LogData\0";
	std::cout << word << std::endl;
	std::cout << "snake.x : " << snake.x << " | " << "snake.y : " << snake.y << std::endl;
	std::cout << "fruit1.x : " << fruit1.x << " | " << "fruit1.y : " << fruit1.y << std::endl;
	std::cout << "fruit2.x : " << fruit2.x << " | " << "fruit2.y : " << fruit2.y << std::endl;
	for (int i = 0; i < snake.number_of_tails; i++) {
		std::cout << "snake.x_tail[" << i <<"] : " << snake.x_tail[i] << " | " << "snake.x_tail["<< i << "] : " << snake.x_tail[i] << std::endl;
	}
	// deleting memory
	for (int i = 0; i < map.height; i++) {
		delete[] *(array_map + i);
	}
	delete[]array_map;
}

void logic() {
	int prev_x;
	int prev_y;
	if (_kbhit()) {
		input = _getch();
	}
		switch (input) { // a
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
		default :
			break;
		}
		if (snake.x == fruit1.x && snake.y == fruit1.y) {
			fruit1.x = rand() % (map.height-2);
			fruit1.y = rand() % (map.width-2);
			snake.score += 10;
			snake.number_of_tails++;
	}
		if (snake.x == fruit2.x && snake.y == fruit2.y) {
			fruit2.x = rand() % (map.height-2);
			fruit2.y = rand() % (map.width-2);
			snake.score += 10;
			snake.number_of_tails++;
		}
		if (snake.x < 1 || snake.x > map.width - 2 || snake.y < 1 || snake.y > map.width - 2) {
			TheEnd = true;
		}
		for (int i = 0; i < snake.number_of_tails; i++) {
			snake.x_tail[i] = snake.x;
			snake.y_tail[i] = snake.y;
		}

}


int main() {
	while (!TheEnd) {
		map_generator();
		// logic();
		if(!TheEnd) std::system("cls");
	}
	return 0;
}