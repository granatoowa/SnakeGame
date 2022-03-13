/**@file*/
#ifndef Snake_H
#define Snake_H
#include <list>

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

/** Klasa obs�uguj�ca w�a.*/
class Snake {
private:
	list<pair <int, int>> snakeBody; ///< wsp�rz�dne cia�a w�a
	int nSnakeDirection; ///< kierunek w�a
	bool bDead; ///< stan w�a
	Color snakeColor; ///< kolor w�a

public:
	/**Bezargumentowy konstruktor klasy Snake.*/
	Snake();

	/** Metoda tworz�ca cia�o w�a.*/
	void addBody();

	/** Metoda zwracaj�ca kierunek w�a.*/
	int getSnakeDirection();

	/** Metoda zmieniaj�ca kierunek w�a w lewo.*/
	void changeSnakeDirLeft();

	/** Metoda zmieniaj�ca kierunek w�a w prawo.*/
	void changeSnakeDirRight();

	/** Metoda zwracaj�ca stan w�a.*/
	bool isDead();

	/** Metoda zmieniaj�ca stan w�a(�mier�).*/
	void deaf();

	/** Metoda sprawdzaj�ca kolizj� g�owy w�a z jego cia�em.*/
	void collisionWithBody();

	/** Metoda sprawdzaj�ca kolizj� g�owy w�a z granicami planszy.*/
	void coliisionWithBox();

	/** Metoda dodaj�ca ogon po zjedzeniu po�ywienia.*/
	void eaten();

	/** Metoda usuwaj�ca ogon.*/
	void chopTail();

	/** Metoda zwracaj�ca kolor w꿹.*/
	Color getSnakeCol();

	/** Metoda zwracaj�ca list� wsp�rz�dnych cia�a w�a.*/
	list<pair<int, int>> getBody();

	/** Metoda zwracaj�ca po�o�enie wsp�rz�dnej x g�owy w�a.*/
	int getHeadX();

	/** Metoda zwracaj�ca po�o�enie wsp�rz�dnej y g�owy w�a.*/
	int getHeadY();

	/** Metoda zmieniaj�ca po�o�enie w�a.*/
	void updateSnakePos();

};



#endif 