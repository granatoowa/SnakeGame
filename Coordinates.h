/**@file*/
#ifndef Coordinates_h
#define Coordinates_h

/** Klasa obs³uguj¹ca wspó³rzêdne.*/
class Coordinates {
protected:
	int x; ///< wspó³rzêdna x
	int y; ///< wspó³rzêdna y
public:

	/**Bezargumentowy konstruktor klasy Coordinates.*/
	Coordinates();

	/**Dwuargumentowy konstruktor klasy Coordinates.
	@param _x wspó³rzêdna x
	@param _y wspó³rzêdna y
	*/
	Coordinates(int _x, int _y);

	/** Metoda zwracaj¹ca wspó³rzêdn¹ x.*/
	int getX();

	/** Metoda zwracaj¹ca wspó³rzêdn¹ y.*/
	int getY();

	/** Metoda ustawiaj¹ca wspó³rzêdn¹ x.
	@param _x wspó³rzêdna x
	*/
	void setX(int _x);

	/** Metoda ustawiaj¹ca wspó³rzêdn¹ y.
	@param _y wspó³rzêdna y
	*/
	void setY(int _y);
};

#endif
