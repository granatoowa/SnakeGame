#include "Speed.h"
#include<time.h>

using namespace std;

Speed::Speed() : milisec(200) {

};

void Speed::speedUp() {
	if (this->milisec > 70) {
		this->milisec = this->milisec - 10;
		cout << endl << "pred: " << this->milisec << endl;
	}
};
 
int Speed::getMilisec() {
	return this->milisec;
};

void Speed::speed() {
	
	srand(time(0));
	int x = rand();
	if (x % 3 == 0) {
		speedUp();
	}
	
}

