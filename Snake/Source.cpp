#include <iostream>

void map() {
	int height = 10, width = 10;
	// creating a two-dimensional array via(через) pointers
	char** array_map = new char*[height];
	for (int i = 0; i < height; i++) {
		*(array_map + i) = new char[width];
	}
	// the filling map
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (i == 0 || i == height - 1) *(*(array_map + i) + j) = '*';
			else if (j == 0 || j == width - 1) *(*(array_map + i) + j) = '*';
			else *(*(array_map + i) + j) = ' ';
		}
	}
	// the drawing map
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			std::cout << *(*(array_map+i)+j);
		}
		std::cout << std::endl;
	}
	// deleting memory
	for (int i = 0; i < height; i++) {
		delete[] *(array_map + i);
	}
	delete[]array_map;
}

int main() {
	map();
	return 0;
}