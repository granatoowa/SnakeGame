#include "Obstacles.h"

using namespace std;

Obstacles::Obstacles(Snake snake): obstColor(Color::Color(27, 26, 23)/*Black*/) {
	int z = randNumb();
	srand(time(0));
	for (int i = 0; i < z; i++) {
		bool newPos = false;
		while (!newPos) {
			newPos = true;
			int x = (rand() % (WIDTH/SNAKESIZE)) * SNAKESIZE;
			int y = (rand() % (HEIGHT/SNAKESIZE - 2)) * SNAKESIZE + 25;
			int f = 0;
			for (auto s : snake.getBody()) {
				if (f == 0) {
					if ((x + 50 == s.first && y==s.second) || (x+25 == s.first && y==s.second)) {
						newPos = false;
					}
				}
				if (x == s.first && y == s.second) {
					newPos = false;
				}
			}
			if (newPos == true) {
				listObs.push_back(Coordinates(x, y));
			}
			//cout << newPos << " ";
		}
	}
	//writeCoord();
};

int Obstacles::randNumb() {
	srand(time(0));
	while (true) {
		int x = rand() % 11;
		if (x > 5 && x < 10) {
			return x;
		}
	}
};

list<Coordinates> Obstacles::getObstacles() {
	return this->listObs;
};

Color Obstacles::getColor() {
	return this->obstColor;
};

//void Obstacles::writeCoord() {
//	for (auto ob : listObs) {
//		cout << ob.getX() << " " << ob.getY() << endl;
//	}
//};