/**@file*/
#ifndef Coordinates_h
#define Coordinates_h

/** Klasa obs�uguj�ca wsp�rz�dne.*/
class Coordinates {
protected:
	int x; ///< wsp�rz�dna x
	int y; ///< wsp�rz�dna y
public:

	/**Bezargumentowy konstruktor klasy Coordinates.*/
	Coordinates();

	/**Dwuargumentowy konstruktor klasy Coordinates.
	@param _x wsp�rz�dna x
	@param _y wsp�rz�dna y
	*/
	Coordinates(int _x, int _y);

	/** Metoda zwracaj�ca wsp�rz�dn� x.*/
	int getX();

	/** Metoda zwracaj�ca wsp�rz�dn� y.*/
	int getY();

	/** Metoda ustawiaj�ca wsp�rz�dn� x.
	@param _x wsp�rz�dna x
	*/
	void setX(int _x);

	/** Metoda ustawiaj�ca wsp�rz�dn� y.
	@param _y wsp�rz�dna y
	*/
	void setY(int _y);
};

#endif
