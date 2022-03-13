#include "Food.h"
#include "Coordinates.h"


using namespace sf;

Food::Food(Snake snake, Obstacles obstacles) : foodColor(Color::Color(231, 71, 29)) {
	refresh(snake, obstacles);
};

Color Food::getFoodCol() {
	return this->foodColor;
};

void Food::refresh(Snake snake, Obstacles obstacles) {
	bool newPos = true;
	srand(time(0));
	while (newPos) {
		newPos = false;
		int x = (rand() % SNAKESIZE) * SNAKESIZE;
		int y = (rand() % 23) * SNAKESIZE;
		for (auto o : obstacles.getObstacles()) {
			if (getX() == o.getX() && getY() == o.getY()) {
				newPos = true;
			}
		}
		if (newPos == false) {
			this->setX(x);
			this->setY(y);
		}
		//cout << newPos << " ";
	}	
};