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

/**Funkcja sprawdzaj¹ca czy w¹¿ zebra³ jedzenie.
@param scoreboard obiekt klasy Scoreboard
@param snake obiekt klasy Snake
@param food obiekt klasy Food
@param obstacles obiekt klasy Obstacles
@param speed obiekt klasy Speed
*/
void collisionWithFood(Scoreboard& scoreboard, Snake& snake, Food& food, Obstacles& obstacles, Speed& speed);

/**Funkcja sprawdzaj¹ca czy w¹¿ zderzy³ siê ze œcian¹.
@param snake obiekt klasy Snake
@param obstacles obiekt klasy Obstacles
*/
void collisionWithObstacles(Snake& snake, Obstacles& obstacles);

/**Funkcja kontroluj¹ca logikê gry.
@param scoreboard obiekt klasy Scoreboard
@param snake obiekt klasy Snake
@param food obiekt klasy Food
@param obstacles obiekt klasy Obstacles
@param window obiekt klasy Terminal
@param speed obiekt klasy Speed
@param wait flaga czekania
@param i licznik wykonañ
*/
void logic(Scoreboard& scoreboard, Snake& snake, Food& food, Obstacles& obstacles, Terminal& window, Speed& speed, bool wait, int& i);

/**Funkcja rozpoczynaj¹ca grê.*/
void playGame();

#endif
