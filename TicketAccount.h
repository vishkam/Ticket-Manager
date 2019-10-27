#ifndef TICKETACCOUNT_H
#define TICKETACCOUNT_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Stadium.h"

using namespace std;

class TicketAccount {
private:
	int ID;
	string name;
	int age;
	int numOfCard;
	double balance;
	static int amountTour;
	static int amountMatch;
	static vector <TicketAccount> TicketAccounts;
public:
	TicketAccount(); //default constructor
	TicketAccount(int, string, int, int, double); //Overload constructor
	
	~TicketAccount(); // destructor
	
	//function prototypes
	//friend void scheduleT();
	//friend void scheduleM();

	void newAcc(); 
	void writeVectorFile();
	
	void checkAcc();
	void readVectorFile();

	void showInfo();

	void amountT();
	void amountM();

	int getID(); 
	string getName() const; //constant
	int getAge();
	int getNumOfCard();
	double getBal();

	void transferT(); //transfer money for buying tour day tickets 
	void transferM(); //transfer money for buying match day tickets
};

#endif