/**@file*/
#ifndef Functions_H
#define Functions_H
#include "Snake.h"
#include "Scoreboard.h"
#include "Global.h"
#include "Food.h"
#include "Obstacles.h"
#include "Speed.h"
#include "Terminal.h"

/**Funkcja sprawdzaj�ca czy w�� zebra� jedzenie.
@param scoreboard obiekt klasy Scoreboard
@param snake obiekt klasy Snake
@param food obiekt klasy Food
@param obstacles obiekt klasy Obstacles
@param speed obiekt klasy Speed
*/
void collisionWithFood(Scoreboard& scoreboard, Snake& snake, Food& food, Obstacles& obstacles, Speed& speed);

/**Funkcja sprawdzaj�ca czy w�� zderzy� si� ze �cian�.
@param snake obiekt klasy Snake
@param obstacles obiekt klasy Obstacles
*/
void collisionWithObstacles(Snake& snake, Obstacles& obstacles);

/**Funkcja kontroluj�ca logik� gry.
@param scoreboard obiekt klasy Scoreboard
@param snake obiekt klasy Snake
@param food obiekt klasy Food
@param obstacles obiekt klasy Obstacles
@param window obiekt klasy Terminal
@param speed obiekt klasy Speed
@param wait flaga czekania
@param i licznik wykona�
*/
void logic(Scoreboard& scoreboard, Snake& snake, Food& food, Obstacles& obstacles, Terminal& window, Speed& speed, bool wait, int& i);

/**Funkcja rozpoczynaj�ca gr�.*/
void playGame();

#endif
