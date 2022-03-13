#include "Terminal.h"

using namespace sf;

Terminal::Terminal() : window(sf::VideoMode(WIDTH, HEIGHT), "SNAKE"), BGColour(Color::Color(170, 215, 81)) {
	font.loadFromFile("Bembo.ttf");
};

void Terminal::update(Snake snake, Obstacles obstacles, Food food, Scoreboard scoreboard) {
	clear();

	//draw snake
	drawSnake(snake);
	drawObstacles(obstacles);
	drawFood(food);

	// create a text
	displayTexts(scoreboard);

	//display
	display();
};

void Terminal::showError(string s, int x, int y) {
	window.clear(Color::Black);
	Text scoretxt(s, font);
	scoretxt.setCharacterSize(FONTSIZE * 3);
	scoretxt.setPosition(x, y);
	scoretxt.setStyle(Text::Regular);
	scoretxt.setFillColor(Color::White);
	window.draw(scoretxt);
	window.display();
};

void Terminal::switchEvent(Event event, Snake& snake, bool& wait) {
	switch (event.type) {
	case Event::Closed:
		window.close();
	case Event::KeyPressed:
		switch (event.key.code) {
		case Keyboard::Space:
			if (!snake.isDead()) {
				wait = !wait;
				pauseText();
			}
			break;
		case Keyboard::Left:
			snake.changeSnakeDirLeft();
			break;
		case Keyboard::Right:
			snake.changeSnakeDirRight();
			break;
		}
	}
};

void Terminal::getNameFromUser(bool& textent, string& userName, Scoreboard& scoreboard) {
	bool entered = false;
	Event event1;
	while (poolEvent(event1)) {
		switch (event1.type) {
		case Event::TextEntered:
			if (event1.text.unicode < 128) {
				userName += static_cast<char>(event1.text.unicode);
				displayUserName(userName, 200, 350);
			}
		case Event::KeyPressed:
			if (event1.key.code == Keyboard::Enter) {
				entered = true;
				cout << userName << endl;
				sleep(Time(milliseconds(LOOPPAUSE * 8)));

			}
		}
	}
	if (entered) {
		try {
			scoreboard.matchUserName(userName, textent);
			textent = true;
		}
		catch (const char* msg) {
			cout << msg;
			showError(msg, 10, 100);
			userName.clear();
			getNameFromUser(textent, userName, scoreboard);
		}
	}
}

void Terminal::close() {
	window.close();
};

void Terminal::clear() {
	window.clear(BGColour);
};

bool Terminal::isOpen() {
	return window.isOpen();
};

bool Terminal::poolEvent(Event& event) {
	return window.pollEvent(event);
};


void Terminal::welcomeText(bool& textent, int i, Scoreboard& scoreboard) {
	snakeText();
	i++;
	string userName;
	while (textent == false) {
		getNameFromUser(textent, userName, scoreboard);
	}
}


void Terminal::pauseText() {
	//window.clear(Color::Black);
	Text hello("PAUSED", font);
	hello.setCharacterSize(180);
	hello.setPosition(50, 150);
	hello.setStyle(Text::Regular);
	hello.setFillColor(Color::White);
	window.draw(hello);
	window.display();
}

void Terminal::displayTexts(Scoreboard scoreboard/*int score , int bestScore, string bestPlayer*/) {
	displayText("Score :", 100, 0);
	displayText(to_string(scoreboard.getScore()), 190, 0);
	displayText("Best score :", 300, 0);
	displayText(to_string(scoreboard.getBestScore()), 420, 0);
	displayText("Best player :", 500, 0);
	displayText(scoreboard.getBestPlayerName(), 630, 00);
}

void Terminal::snakeText() {
	//window.clear(Color::Black);
	Text hello("SNAKE", font);
	hello.setCharacterSize(200);
	hello.setPosition(50, 150);
	hello.setStyle(Text::Regular);
	hello.setFillColor(Color::White);
	Text stext("Enter your name:", font);
	stext.setCharacterSize(30);
	stext.setPosition(50, 500);
	stext.setStyle(Text::Regular);
	stext.setFillColor(Color::White);
	window.draw(hello);
	window.draw(stext);
	window.display();

}

void Terminal::gameOverText() {
	window.clear(Color::Black);
	Text hello("GAME OVER", font);
	hello.setCharacterSize(100);
	hello.setPosition(100, 250);
	hello.setStyle(Text::Regular);
	hello.setFillColor(Color::White);
	window.draw(hello);
	window.display();
	sleep(Time(milliseconds(3000)));
	window.close();
}

void Terminal::display() {
	window.display();
};

void Terminal::displayUserName(string s, int x, int y) {
	window.clear(Color::Black);
	Text nametxt("Your name: ", font);
	nametxt.setCharacterSize(FONTSIZE * 3);
	nametxt.setPosition(130, 200);
	nametxt.setStyle(Text::Regular);
	nametxt.setFillColor(Color::White);
	window.draw(nametxt);
	Text scoretxt(s, font);
	scoretxt.setCharacterSize(FONTSIZE * 3);
	scoretxt.setPosition(x, y);
	scoretxt.setStyle(Text::Regular);
	scoretxt.setFillColor(Color::White);
	window.draw(scoretxt);
	window.display();
};

void Terminal::displayText(string s, int x, int y) {
	Text scoretxt(s, font);
	scoretxt.setCharacterSize(FONTSIZE);
	scoretxt.setPosition(x, y);
	scoretxt.setStyle(Text::Regular);
	scoretxt.setFillColor(Color::Black);
	window.draw(scoretxt);
};




void Terminal::drawSnake(Snake snake) {
	int i = 0;
	for (auto s : snake.getBody()) {
		RectangleShape part;
		part.setPosition(s.first, s.second);
		part.setSize(Vector2f(SNAKESIZE, SNAKESIZE));
		if (i == 0)
			part.setFillColor(Color::Color(231, 71, 29));
		else
			part.setFillColor(snake.getSnakeCol());
		window.draw(part);
		i++;
	}
};


void Terminal::drawFood(Food food) {
	CircleShape apple(13.5);
	apple.setPosition(food.getX(), food.getY());
	apple.setFillColor(food.getFoodCol());
	window.draw(apple);
};

void Terminal::drawObstacles(Obstacles obstacles) {
	for (auto o : obstacles.getObstacles()) {
		RectangleShape part;
		part.setPosition(o.getX(), o.getY());
		part.setSize(Vector2f(SNAKESIZE, SNAKESIZE));
		part.setFillColor(obstacles.getColor());
		window.draw(part);
	}
};



