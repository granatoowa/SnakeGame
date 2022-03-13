#include "Coordinates.h"

Coordinates::Coordinates() : x(10), y(25) {};

Coordinates::Coordinates(int _x, int _y) : x(_x), y(_y) {};

int Coordinates::getX() {
	return x;
}

int Coordinates::getY() {
	return y;
}

void Coordinates::setX(int _x) {
	x = _x;
};

void Coordinates::setY(int _y) {
	y = _y;
};