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

/** Klasa obs³uguj¹ca okno programu.*/
class Terminal {
private:
	RenderWindow window; ///< okno aplikacji
	Color BGColour; ///< kolor t³a
    Font font; ///< czcionka
public:

	/**Bezargumentowy konstruktor okna aplikacji.*/
	Terminal();

	/** Metoda zamykaj¹ca okno programu.*/
	void close();

	/** Metoda czyszcz¹ca okno programu.*/
	void clear();

	/** Metoda sprawdzaj¹ca czy okno programu jest otwarte.*/
	bool isOpen();

	/** Metoda umieszczaj¹ca wydarzenie na górze kolejki zdarzeñ, jeœli istnieje, i zwraca je.
	@param event wydarzenie
	*/
	bool poolEvent(Event& event);

	/** Metoda obs³uguj¹ca zdarzenie wprowadzone przez gracza.
	@param event zdarzenie
	@param snake obiekt klasy Snake
	@param wait flaga czekania
	*/
	void switchEvent(Event event, Snake& snake, bool &wait);

	/** Metoda pobieraj¹ca imiê od gracza.
	@param textent flaga imienia
	@param userName wprowadzane imiê
	@param scoreboard obiekt klasy Scoreboard
	*/
	void getNameFromUser(bool& textent, string& userName, Scoreboard& scoreboard);

	/** Metoda wyœwietlaj¹ca powitalny tekst oraz prosz¹ca o wpisanie imienia.
	@param textent flaga imienia
	@param i licznik
	@param scoreboard obiekt klasy Scoreboard
	*/
	void welcomeText(bool& textent, int i, Scoreboard& scoreboard);

	/** Metoda wyœwietlaj¹ca wpisywane przez u¿ytkownika imiê na ekran.
	@param s imiê
	@param x wspó³rzêdna x
	@param y wspó³rzêdna y
	*/
	void displayUserName(string s, int x, int y);
	
	/** Metoda wyœwietlaj¹ca na ekranie tekst przekazany w parametrze.
	@param s tekst do wyœwietlenia na ekran
	@param x wspó³rzêdna x
	@param y wspó³rzêdna y
	*/
	void displayText(string s, int x, int y);

	/** Metoda wyœwietlaj¹ca na ekranie aktualny wynik, najlepszy wynik oraz imiê najlepszego gracza.
	@param scoreboard obiekt klasy Scoreboard
	*/
	void displayTexts(Scoreboard scoreboard);

	/** Metoda wyœwietlaj¹ca na ekranie tekst gdy gra jest zatrzymana.*/
	void pauseText();

	/** Metoda wyœwietlaj¹ca na ekranie nazwê gry po rozpoczêciu programu.*/
	void snakeText();

	/** Metoda wyœwietlaj¹ca na ekranie tekst gdy gra zakoñczy³a siê.*/
	void gameOverText();

	/** Metoda wyœwietlaj¹ca b³¹d na ekran.
	@param s tekst do wyœwietlenia na ekran
	@param x wspó³rzêdna x
	@param y wspó³rzêdna y
	*/
	void showError(string s, int x, int y);

	/** Metoda wyœwietlaj¹ca na ekranie, co zosta³o do tej pory wyrenderowane w oknie.*/
	void display();

	/** Metoda renderuj¹ca cia³o wê¿a w oknie.
	@param snake obiekt klasy Snake
	*/
	void drawSnake(Snake snake);

	/** Metoda renderuj¹ca po¿ywienie w oknie.
	@param food obiekt klasy Food
	*/
	void drawFood(Food food);

	/** Metoda renderuj¹ca przeszkody w oknie.
	@param obstacles
	*/
	void drawObstacles(Obstacles obstacles);

	/** Metoda aktualizuj¹ca wê¿a, po¿ywienie, przeszkody oraz napisy na ekranie.
	@param snake obiekt klasy Snake
	@param obstacles obiekt klasy Obstacles
	@param food obiekt klasy Food
	@param scoreboard obiekt klasy Scoreboard
	*/
	void update(Snake snake, Obstacles obstacles, Food food, Scoreboard scoreboard);
};

#endif 
