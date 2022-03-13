/**@file*/
#ifndef Snake_H
#define Snake_H
#include <list>

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

/** Klasa obs³uguj¹ca wê¿a.*/
class Snake {
private:
	list<pair <int, int>> snakeBody; ///< wspó³rzêdne cia³a wê¿a
	int nSnakeDirection; ///< kierunek wê¿a
	bool bDead; ///< stan wê¿a
	Color snakeColor; ///< kolor wê¿a

public:
	/**Bezargumentowy konstruktor klasy Snake.*/
	Snake();

	/** Metoda tworz¹ca cia³o wê¿a.*/
	void addBody();

	/** Metoda zwracaj¹ca kierunek wê¿a.*/
	int getSnakeDirection();

	/** Metoda zmieniaj¹ca kierunek wê¿a w lewo.*/
	void changeSnakeDirLeft();

	/** Metoda zmieniaj¹ca kierunek wê¿a w prawo.*/
	void changeSnakeDirRight();

	/** Metoda zwracaj¹ca stan wê¿a.*/
	bool isDead();

	/** Metoda zmieniaj¹ca stan wê¿a(œmieræ).*/
	void deaf();

	/** Metoda sprawdzaj¹ca kolizjê g³owy wê¿a z jego cia³em.*/
	void collisionWithBody();

	/** Metoda sprawdzaj¹ca kolizjê g³owy wê¿a z granicami planszy.*/
	void coliisionWithBox();

	/** Metoda dodaj¹ca ogon po zjedzeniu po¿ywienia.*/
	void eaten();

	/** Metoda usuwaj¹ca ogon.*/
	void chopTail();

	/** Metoda zwracaj¹ca kolor wê¿¹.*/
	Color getSnakeCol();

	/** Metoda zwracaj¹ca listê wspó³rzêdnych cia³a wê¿a.*/
	list<pair<int, int>> getBody();

	/** Metoda zwracaj¹ca po³o¿enie wspó³rzêdnej x g³owy wê¿a.*/
	int getHeadX();

	/** Metoda zwracaj¹ca po³o¿enie wspó³rzêdnej y g³owy wê¿a.*/
	int getHeadY();

	/** Metoda zmieniaj¹ca po³o¿enie wê¿a.*/
	void updateSnakePos();

};



#endif 