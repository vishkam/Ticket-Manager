#ifndef STADIUM_H
#define STADIUM_H
#include <iostream>
#include <string>
#include "Employee.h"
#include "TicketAccount.h"
using namespace std;

class Stadium {
	friend class TicketAccount;  // I used friend classes for having an access to the private data members of the Stadium class
	friend class Staff;			// to be exact, for having an access to the Balance of the Stadium
	friend class CoachTeam;		// for using polymorphism in the inheritance with the base class Employee and 3 derived classes
	friend class Player;
								
private:
	const string nameOfStad;
	static double balanceOfStad;

public:
	Stadium ();		//default constructor
	Stadium(string);	//Overload constructor
	~Stadium();		//Destructor

	void infoStad();
};

#endif // !STADIUM_H
