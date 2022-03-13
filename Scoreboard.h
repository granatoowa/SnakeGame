/**@file*/
#ifndef Scoreboard_H
#define Scoreboard_H
#include <string>
#include <fstream>
#include <regex>

using namespace std;

/** Klasa obs�uguj�ca punkty gracza.*/
class Scoreboard {
private:
	string name; ///< imi� gracza
	string bestPlayer; ///< imi� najlepszego gracza
	int score; ///< wynik gracza
	int bestScore; ///< wynik najlepszego gracza
public:

	/**Funkcja ustawiaj�ca imi� lub najlepszy wynik gracza.
	@param strMatch wynik poszukiwa� ze wzorcem
	@param isName flaga imienia
	@param found flaga powodzenia operacji
	*/
	void ifMatches(smatch strMatch, bool isName, bool& found);

	/**Funkcja sprawdzaj�ca zgodno�c danej pobranej z pliku z podanym wzorcem wzorcem.
	@param str linia tekstu
	@param pattern wz�r wyra�enia regularnego
	@param isName flaga imienia
	*/
	void matches(string str, regex pattern, bool isName);

	/**Funkcja sprawdzaj�ca poprawno�� danych pobranych z pliku.
	@param textLine linia tekstu pobrana z pliku
	*/
	void ifBestScoreAndBestPlayerNameGood(string textLine);
	
	/**Funkcja pobieraj�ca dane z pliku.*/
	void getFromFile();

	/**Funkcja ustawiaj�ca domy�lne warto�ci najlepszego gracza.*/
	void setBestScoreAndBestPlayerNameDefault();

	/**Bezargumentowy konstruktor klasy Scoreboard. Pobiera z pliku wynik i imi� najlepszego gracza.*/
	Scoreboard();

	/** Metoda zwracaj�ca imi� gracza.*/
	string getName();
	
	/** Metoda zwracaj�ca imi� najlepszego gracza.*/
	string getBestPlayerName();
	
	/** Metoda zwracaj�ca wynik najlepszego gracza.*/
	int getBestScore();

	/** Metoda zwracaj�ca wynik gracza.*/
	int getScore();

	/** Metoda ustawiaj�ca imi� gracza.*/
	void setName(string _name);

	/** Metoda sprawdzaj�ca czy imi� gracza jest poprawne.
	@param _name imi� wprowadzone przez gracza
	@param goodName flaga imienia gracza
	*/
	void matchUserName(string _name, bool& goodName);

	/** Metoda ustawiaj�ca punkty najlepszego gracza.
	@param x punkty najlepszego gracza
	*/
	void setBestScore(int x);

	/** Metoda zapisuj�ca wynik i imi� najlepszego gracza do pliku.
	@param file plik wyj�ciowy
	*/
	void saveEndFile(fstream& file);

	/** Metoda sprawdzaj�ca czy zapisa� wyniki do pliku.*/
	void writeToFile();

	/** Metoda dodaj�ca punkt do wyniku gracza.*/
	void addPoint();
};

#endif
