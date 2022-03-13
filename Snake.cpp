#include "Snake.h"
#include"Global.h"
#include <list>
#include <iostream>
using namespace std;
using namespace sf;

Snake::Snake() : nSnakeDirection(3), bDead(false), snakeColor(Color::Color(70, 115, 232)) {
	this->addBody();
}

void Snake::addBody() {
	this->snakeBody.push_back(pair<int, int>(WIDTH/2, HEIGHT/2));
	this->snakeBody.push_back(pair<int, int>(WIDTH / 2 + SNAKESIZE, HEIGHT / 2));
	this->snakeBody.push_back(pair<int, int>(WIDTH / 2 + 2*SNAKESIZE , HEIGHT / 2));
}

Color Snake::getSnakeCol() {
	return this->snakeColor;
};

int Snake::getSnakeDirection() {
	return this->nSnakeDirection;
};


void Snake::changeSnakeDirLeft() {
	this->nSnakeDirection--;
	if (this->nSnakeDirection == -1) this->nSnakeDirection = 3;
};

void Snake::changeSnakeDirRight() {
	this->nSnakeDirection++;
	if (this->nSnakeDirection == 4) this->nSnakeDirection = 0;
};

bool Snake::isDead() {
	return this->bDead;
};

void Snake::deaf() {
	this->bDead = true;
};

void Snake::collisionWithBody() {
	for (list<pair<int, int>>::iterator i = this->snakeBody.begin(); i != this->snakeBody.end(); i++)
		if (i != this->snakeBody.begin() && i->first == this->snakeBody.front().first && i->second == this->snakeBody.front().second) {
			deaf();
			sleep(Time(milliseconds(LOOPPAUSE)));
		}		
};

void Snake::coliisionWithBox() {
	if (this->snakeBody.front().first < 0 || this->snakeBody.front().first >= WIDTH) {
		deaf();
		sleep(Time(milliseconds(LOOPPAUSE)));
	}
		
	if (this->snakeBody.front().second < 0 || this->snakeBody.front().second >= HEIGHT) {
		deaf();
		sleep(Time(milliseconds(LOOPPAUSE)));
	}	
};

void Snake::eaten() {
	this->snakeBody.push_back({ this->snakeBody.back().first, this->snakeBody.back().second });
}

void Snake::chopTail() {
	this->snakeBody.pop_back();
};

list<pair <int, int>> Snake::getBody() {
	return this->snakeBody;
};

int Snake::getHeadX() {
	return this->snakeBody.front().first;
};

int Snake::getHeadY() {
	return this->snakeBody.front().second;
};

void Snake::updateSnakePos() {
	switch (this->getSnakeDirection())
	{
	case 0: // UP
		this->snakeBody.push_front(make_pair(getHeadX(), getHeadY() - SNAKESIZE));
		break;
	case 1: // RIGHT
		this->snakeBody.push_front(make_pair(getHeadX() + SNAKESIZE, getHeadY()));
		break;
	case 2: // DOWN
		this->snakeBody.push_front(make_pair(getHeadX(), getHeadY() + SNAKESIZE));
		break;
	case 3: // LEFT
		this->snakeBody.push_front(make_pair(getHeadX() - SNAKESIZE, getHeadY()));
		break;
	}
}

