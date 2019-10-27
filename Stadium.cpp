#include <iostream>
#include <string>
#include "Stadium.h"

using namespace std;

Stadium::Stadium() {}
Stadium::Stadium(string nameS)
				: nameOfStad(nameS) {}
Stadium::~Stadium(){}

void Stadium::infoStad() {

	cout << "The Stadium 'Santiago Bernabeu' " << nameOfStad << endl;
	cout << "*************************** " << endl;
	cout << "\nCurrent balance of the Stadium is ->  " << balanceOfStad << endl << endl;
	cout << "If you wish to join our fan club REGISTER NOW!" << endl;
}
