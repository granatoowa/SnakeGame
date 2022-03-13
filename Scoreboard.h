/**@file*/
#ifndef Scoreboard_H
#define Scoreboard_H
#include <string>
#include <fstream>
#include <regex>

using namespace std;

/** Klasa obs³uguj¹ca punkty gracza.*/
class Scoreboard {
private:
	string name; ///< imiê gracza
	string bestPlayer; ///< imiê najlepszego gracza
	int score; ///< wynik gracza
	int bestScore; ///< wynik najlepszego gracza
public:

	/**Funkcja ustawiaj¹ca imiê lub najlepszy wynik gracza.
	@param strMatch wynik poszukiwañ ze wzorcem
	@param isName flaga imienia
	@param found flaga powodzenia operacji
	*/
	void ifMatches(smatch strMatch, bool isName, bool& found);

	/**Funkcja sprawdzaj¹ca zgodnoœc danej pobranej z pliku z podanym wzorcem wzorcem.
	@param str linia tekstu
	@param pattern wzór wyra¿enia regularnego
	@param isName flaga imienia
	*/
	void matches(string str, regex pattern, bool isName);

	/**Funkcja sprawdzaj¹ca poprawnoœæ danych pobranych z pliku.
	@param textLine linia tekstu pobrana z pliku
	*/
	void ifBestScoreAndBestPlayerNameGood(string textLine);
	
	/**Funkcja pobieraj¹ca dane z pliku.*/
	void getFromFile();

	/**Funkcja ustawiaj¹ca domyœlne wartoœci najlepszego gracza.*/
	void setBestScoreAndBestPlayerNameDefault();

	/**Bezargumentowy konstruktor klasy Scoreboard. Pobiera z pliku wynik i imiê najlepszego gracza.*/
	Scoreboard();

	/** Metoda zwracaj¹ca imiê gracza.*/
	string getName();
	
	/** Metoda zwracaj¹ca imiê najlepszego gracza.*/
	string getBestPlayerName();
	
	/** Metoda zwracaj¹ca wynik najlepszego gracza.*/
	int getBestScore();

	/** Metoda zwracaj¹ca wynik gracza.*/
	int getScore();

	/** Metoda ustawiaj¹ca imiê gracza.*/
	void setName(string _name);

	/** Metoda sprawdzaj¹ca czy imiê gracza jest poprawne.
	@param _name imiê wprowadzone przez gracza
	@param goodName flaga imienia gracza
	*/
	void matchUserName(string _name, bool& goodName);

	/** Metoda ustawiaj¹ca punkty najlepszego gracza.
	@param x punkty najlepszego gracza
	*/
	void setBestScore(int x);

	/** Metoda zapisuj¹ca wynik i imiê najlepszego gracza do pliku.
	@param file plik wyjœciowy
	*/
	void saveEndFile(fstream& file);

	/** Metoda sprawdzaj¹ca czy zapisaæ wyniki do pliku.*/
	void writeToFile();

	/** Metoda dodaj¹ca punkt do wyniku gracza.*/
	void addPoint();
};

#endif
