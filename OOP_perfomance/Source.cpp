#include <iostream>


class Map {
	class Snake
	{
	public:
		int start_x;
		int start_y;
		Snake() : start_x(15), start_y(15) {
		}
		int width;
		int height;
	} udav;
public:
	Map(int width, int height): width(width), height(height) {
	}
	void GenerateMap() {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (i == 0) std::cout << "#";
				else if (j == width - 1 || j == 0) std::cout << "#";
				else if (i == height - 1) std::cout << "#";
				else if (i == udav.start_x && j == udav.start_y) std::cout << "0";
				else std::cout << " ";
			}
			std::cout << std::endl;
		}
	}
};

class Logic
{

};

class Input
{

};

int main() {
	int k = 0;
	Map rectangle(20, 20);
	while (true) {
		system("cls");
		rectangle.GenerateMap();
		// k++;
	}
}