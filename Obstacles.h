/**@file*/
#ifndef Obstacles_h
#define Obstacles_h
#include <list>
#include "Coordinates.h"
#include "Global.h"
#include "Snake.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

/** Klasa obs³uguj¹ca przeszkody.*/
class Obstacles {
private:
	list<Coordinates> listObs; ///< lista wspó³rzêdnych przeszkód
	Color obstColor; ///< kolor przeszkód

public:
	/**Jednoargumentowy konstruktor klasy Obstacles.
	@param snake obiekt klasy Snake
	*/
	Obstacles(Snake snake);

	/** Metoda generuj¹ca liczbê przeszkód.*/
	int randNumb();

	/** Metoda zwracaj¹ca listê przeszkód.*/
	list<Coordinates> getObstacles();

	/** Metoda zwracaj¹ca kolor przeszkód.*/
	Color getColor();

};



#endif

//void writeCoord();