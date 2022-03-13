/**@file*/
#ifndef Speed_H
#define Speed_H
#include <iostream>

/** Klasa obs�uguj�ca pr�dko�� w�a.*/
class Speed {
private:
	int milisec; ///< pr�dko�� od�wie�ania okna
public:

	/**Bezargumentowy konstruktor klasy Level.*/
	Speed();

	/** Metoda zwiekszaj�ca pr�dko��.*/
	void speedUp();
	
	/** Metoda zwracaj�ca pr�dko��.*/
	int getMilisec();
	
	/** Metoda decyduj�ca o zwi�kszeniu pr�dko�ci.*/
	void speed();

};

#endif
