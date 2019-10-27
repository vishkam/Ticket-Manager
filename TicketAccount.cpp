#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Stadium.h"

using namespace std;


vector <TicketAccount> ticketacc;

TicketAccount::TicketAccount() {}
TicketAccount::TicketAccount(int id, string name, int age, int numOfCard, double balance)
 {
	ID = id;
	this->name = name;
	this->age = age;
	this->numOfCard = numOfCard;
	this->balance = balance;
}
TicketAccount::	~TicketAccount() {}


int TicketAccount::getID(){
	return ID;
}
string TicketAccount::getName() const{     //const
	return name;
}   
int TicketAccount::getAge(){
	return age;
}
int TicketAccount::getNumOfCard(){
	return numOfCard;
}
double TicketAccount::getBal(){
	return balance;
}

void TicketAccount::newAcc() {
	cout << "\n *Personal Info* \n";
	while (!(cin >> ID) | ID<0 ) 
	{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "ID ->";
	}
	
	cout << "\nName -> ";
	cin >> name;
	while (!(cin >> age) | age < 0)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\nAge -> ";
	}
	if (age<0)
	{
		cout << "Try again: Age -> ";
		cin >> age;
	}
	try{       // exception
		if (age < 18) 
		{   // If you're less than 18, you can't register or buy tickets
			throw 100;
		}
		while (!(cin >> numOfCard) | numOfCard < 0)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\nNumber of the Card -> ";
		}
		while (!(cin >> balance))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\nBalance -> ";
		}

		TicketAccount tick(ID, name, age, numOfCard, balance);
		ticketacc.push_back(tick);
		this->writeVectorFile();
		
	}
	catch (int x) {cout << "\nYou are too young to register and buy tickets!\n" << x; }
	
}

void TicketAccount:: writeVectorFile() {
	ofstream file;
	file.open("Accounts.doc");

	for (unsigned int i = 0; i < ticketacc.size(); i++) {
		file << ticketacc[i].ID << " " << ticketacc[i].name << " " << ticketacc[i].age << " " << ticketacc[i].numOfCard << " " << ticketacc[i].balance << endl;
	}

	file.close();
	
}

void TicketAccount::checkAcc() {	
	this->readVectorFile();
	unsigned int i = 0;
	int id;
	while (!(cin >> id) | id < 0)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter your ID ->";
	}
	for (unsigned int i = 0; i < ticketacc.size(); i++) {

		if (ticketacc[i].getID() == id)
		{
			ticketacc[i].showInfo();
		}
	}
}

void TicketAccount:: showInfo() {

	cout << "\nAccount: \n";
	cout << "ID -> " << ID;
	cout << "\nName -> " << name;
	cout << "\nAge -> " << age;
	cout << "\nNumber of the Card -> " << numOfCard;
	cout << "\nBalance -> " << balance;
	cout << endl << endl;
}

void TicketAccount::readVectorFile() {
	
	ifstream ifile;
	ifile.open("Accounts.doc");

	TicketAccount acc;
	while (!ifile.eof()) {
		ifile >> acc.ID >> acc.name >> acc.age >> acc.numOfCard >> acc.balance;
		
		ticketacc.push_back(acc);
	}
}

void TicketAccount::transferT() {
	this->readVectorFile();
	unsigned int i = 0;
	int id;
	while (!(cin >> id) | id < 0)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter your ID ->";
	}
	for (unsigned int i = 0; i < ticketacc.size(); i++) {

		if (ticketacc[i].getID() == id)
		{
			ticketacc[i].showInfo();


			int am;
			char ans;
			double priceT = 40;
			cout << "\nHow many tickets do you need?";
			cin >> am;
			cout << "\n It will cost you " << am*priceT << "$ \nIf you want to buy press Y, if don't press N\n ";
			cin >> ans;
			if (ans = 'Y'){
				try{								//exception
					if (ticketacc[i].getBal() < am*priceT) {
						throw 101;
					}

					Stadium::balanceOfStad += am*priceT;
					ticketacc[i].balance -= am*priceT;
					amountTour -= am;
					cout << "\nCongrats! You successfully bought " << am << "tickets. Welcome to the Stadium =)\n";
					this->writeVectorFile();
				}
				catch (int x) {
					cout << "\nYou don't have enough money! ERROR" << x << endl;
				}
			}
			else { cout << "bye"; }
		}
	}
}


void TicketAccount::transferM(){
	this->readVectorFile();
	unsigned int i = 0;
	int id;
	while (!(cin >> id) | id<0)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter your ID -> ";
	}
	for (unsigned int i = 0; i < ticketacc.size(); i++) {

		if (ticketacc[i].getID() == id)
		{
			ticketacc[i].showInfo();

			int am;
			char ans;
			double priceM = 80;
			cout << "\nHow many tickets do you need?";
			cin >> am;
			cout << "\n It will cost you " << am*priceM << "$ \nIf you want to buy press Y, if don't press N\n ";
			cin >> ans;
			if (ans = 'Y'){
				try{								//exception
					if (ticketacc[i].getBal() < am*priceM) {
						throw 101;
					}

					Stadium::balanceOfStad += am*priceM;
					ticketacc[i].balance -= am*priceM;
					amountTour -= am;
					cout << "\nCongrats! You successfully bought " << am << "tickets. Welcome to the Stadium =)\n";
					this->writeVectorFile();
				}
				catch (int x) {
					cout << "\nYou don't have enough money! ERROR" << x << endl;
				}
			}
		}
	}
}

void TicketAccount:: amountT(){
cout << "\nAmount of the tickets -> " << amountTour; 
}


void  TicketAccount::amountM() {
	cout << "\nAmount of the tickets -> " << amountMatch;
}