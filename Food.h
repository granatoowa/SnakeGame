/**@file*/
#ifndef Food_H
#define Food_H
#include "Coordinates.h"
#include "Global.h"
#include "Obstacles.h"
#include "Snake.h"
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

/** Klasa obs�uguj�ca po�ywienie.*/
class Food : public Coordinates {
protected:
	Color foodColor; ///< kolor jedzenia

public:
	/**Dwuargumentowy konstruktor klasy Food.
	@param snake obiekt klasy Snake
	@param obstacles obiekt klasy Obstacles
	*/
	Food(Snake snake, Obstacles obstacles);  

	/** Metoda zwracaj�ca kolor po�ywienia.*/
	Color getFoodCol();

	/**Metoda generuj�ca/od�wie�aj�ca po�o�enie po�ywienia.
	@param snake obiekt klasy Snake
	@param obstacles obiekt klasy Obstacles
	*/
	void refresh(Snake snake, Obstacles obstacles);

};

#endif