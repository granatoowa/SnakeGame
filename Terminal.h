/**@file*/
#ifndef Terminal_H
#define Terminal_H
#include "Global.h"
#include "Food.h"
#include "Snake.h"
#include "Obstacles.h"
#include "Scoreboard.h"
#include <SFML/Graphics.hpp>

using namespace sf;

/** Klasa obs�uguj�ca okno programu.*/
class Terminal {
private:
	RenderWindow window; ///< okno aplikacji
	Color BGColour; ///< kolor t�a
    Font font; ///< czcionka
public:

	/**Bezargumentowy konstruktor okna aplikacji.*/
	Terminal();

	/** Metoda zamykaj�ca okno programu.*/
	void close();

	/** Metoda czyszcz�ca okno programu.*/
	void clear();

	/** Metoda sprawdzaj�ca czy okno programu jest otwarte.*/
	bool isOpen();

	/** Metoda umieszczaj�ca wydarzenie na g�rze kolejki zdarze�, je�li istnieje, i zwraca je.
	@param event wydarzenie
	*/
	bool poolEvent(Event& event);

	/** Metoda obs�uguj�ca zdarzenie wprowadzone przez gracza.
	@param event zdarzenie
	@param snake obiekt klasy Snake
	@param wait flaga czekania
	*/
	void switchEvent(Event event, Snake& snake, bool &wait);

	/** Metoda pobieraj�ca imi� od gracza.
	@param textent flaga imienia
	@param userName wprowadzane imi�
	@param scoreboard obiekt klasy Scoreboard
	*/
	void getNameFromUser(bool& textent, string& userName, Scoreboard& scoreboard);

	/** Metoda wy�wietlaj�ca powitalny tekst oraz prosz�ca o wpisanie imienia.
	@param textent flaga imienia
	@param i licznik
	@param scoreboard obiekt klasy Scoreboard
	*/
	void welcomeText(bool& textent, int i, Scoreboard& scoreboard);

	/** Metoda wy�wietlaj�ca wpisywane przez u�ytkownika imi� na ekran.
	@param s imi�
	@param x wsp�rz�dna x
	@param y wsp�rz�dna y
	*/
	void displayUserName(string s, int x, int y);
	
	/** Metoda wy�wietlaj�ca na ekranie tekst przekazany w parametrze.
	@param s tekst do wy�wietlenia na ekran
	@param x wsp�rz�dna x
	@param y wsp�rz�dna y
	*/
	void displayText(string s, int x, int y);

	/** Metoda wy�wietlaj�ca na ekranie aktualny wynik, najlepszy wynik oraz imi� najlepszego gracza.
	@param scoreboard obiekt klasy Scoreboard
	*/
	void displayTexts(Scoreboard scoreboard);

	/** Metoda wy�wietlaj�ca na ekranie tekst gdy gra jest zatrzymana.*/
	void pauseText();

	/** Metoda wy�wietlaj�ca na ekranie nazw� gry po rozpocz�ciu programu.*/
	void snakeText();

	/** Metoda wy�wietlaj�ca na ekranie tekst gdy gra zako�czy�a si�.*/
	void gameOverText();

	/** Metoda wy�wietlaj�ca b��d na ekran.
	@param s tekst do wy�wietlenia na ekran
	@param x wsp�rz�dna x
	@param y wsp�rz�dna y
	*/
	void showError(string s, int x, int y);

	/** Metoda wy�wietlaj�ca na ekranie, co zosta�o do tej pory wyrenderowane w oknie.*/
	void display();

	/** Metoda renderuj�ca cia�o w�a w oknie.
	@param snake obiekt klasy Snake
	*/
	void drawSnake(Snake snake);

	/** Metoda renderuj�ca po�ywienie w oknie.
	@param food obiekt klasy Food
	*/
	void drawFood(Food food);

	/** Metoda renderuj�ca przeszkody w oknie.
	@param obstacles
	*/
	void drawObstacles(Obstacles obstacles);

	/** Metoda aktualizuj�ca w�a, po�ywienie, przeszkody oraz napisy na ekranie.
	@param snake obiekt klasy Snake
	@param obstacles obiekt klasy Obstacles
	@param food obiekt klasy Food
	@param scoreboard obiekt klasy Scoreboard
	*/
	void update(Snake snake, Obstacles obstacles, Food food, Scoreboard scoreboard);
};

#endif 
