/**@file*/
#ifndef Speed_H
#define Speed_H
#include <iostream>

/** Klasa obs³uguj¹ca prêdkoœæ wê¿a.*/
class Speed {
private:
	int milisec; ///< prêdkoœæ odœwie¿ania okna
public:

	/**Bezargumentowy konstruktor klasy Level.*/
	Speed();

	/** Metoda zwiekszaj¹ca prêdkoœæ.*/
	void speedUp();
	
	/** Metoda zwracaj¹ca prêdkoœæ.*/
	int getMilisec();
	
	/** Metoda decyduj¹ca o zwiêkszeniu prêdkoœci.*/
	void speed();

};

#endif
