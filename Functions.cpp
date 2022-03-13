#include "Functions.h"

void collisionWithFood(Scoreboard& scoreboard, Snake& snake, Food& food, Obstacles& obstacles, Speed& speed) {
	if (snake.getHeadX() == food.getX() && snake.getHeadY() == food.getY()) {
		scoreboard.addPoint();
		snake.eaten();
		speed.speed();
		food.refresh(snake, obstacles);
	}
}

void collisionWithObstacles(Snake& snake, Obstacles& obstacles) {
	for (auto o : obstacles.getObstacles()) {
		if (snake.getHeadX() == o.getX() && snake.getHeadY() == o.getY()) {
			snake.deaf();
			sleep(Time(milliseconds(LOOPPAUSE)));
		}
	}
}

void logic(Scoreboard& scoreboard, Snake& snake, Food& food, Obstacles& obstacles, Terminal& window, Speed& speed, bool wait, int& i) {

	if (!wait) {
		snake.updateSnakePos();
		collisionWithFood(scoreboard, snake, food, obstacles, speed);
		collisionWithObstacles(snake, obstacles);
		snake.collisionWithBody();
		snake.coliisionWithBox();
		if (snake.isDead()) {
			window.gameOverText();
		}
		snake.chopTail();
		window.update(snake, obstacles, food, scoreboard); 
	}
}

void playGame() {
	Scoreboard scoreboard;
	Snake snake;
	Obstacles obstacles(snake);
	Food food(snake, obstacles);
	Terminal window;
	Speed speed;
	int i = 0;
	bool wait = false;
	bool nameEntered = false;
	while (window.isOpen()) {
		sleep(Time(milliseconds(speed.getMilisec()))); 
		if (nameEntered == false) {
			window.welcomeText(nameEntered, i, scoreboard);
		}
		Event event;
		while (window.poolEvent(event)) {
			window.switchEvent(event, snake, wait);
		}
		logic(scoreboard, snake, food, obstacles, window, speed, wait, i);
	}
	scoreboard.writeToFile();
}

