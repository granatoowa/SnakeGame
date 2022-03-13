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

/** Klasa obs�uguj�ca przeszkody.*/
class Obstacles {
private:
	list<Coordinates> listObs; ///< lista wsp�rz�dnych przeszk�d
	Color obstColor; ///< kolor przeszk�d

public:
	/**Jednoargumentowy konstruktor klasy Obstacles.
	@param snake obiekt klasy Snake
	*/
	Obstacles(Snake snake);

	/** Metoda generuj�ca liczb� przeszk�d.*/
	int randNumb();

	/** Metoda zwracaj�ca list� przeszk�d.*/
	list<Coordinates> getObstacles();

	/** Metoda zwracaj�ca kolor przeszk�d.*/
	Color getColor();

};



#endif

//void writeCoord();