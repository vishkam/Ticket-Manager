#include <iostream>
#include <vector>
#include <string>
#include "FanClub.h"
using namespace std;

FanClub::FanClub() {} // default constructor

FanClub::FanClub(string name, int age, string mail, int phone) 
			: nameOfFan(name), ageOfFan(age), mail(mail), telephone(phone) {} // Overload constructor

FanClub::~FanClub() {} //Destructor

string FanClub::getName(){
	return nameOfFan;
}

int FanClub::getAge() {
	return ageOfFan;
}

string FanClub::getEmail() {
	return mail;
}

long long int FanClub:: getPhone(){
	return telephone;
}

void FanClub::createNewFan(vector <FanClub>& newFan) {
	
	cout << "Registration of the New Fan ->\n";
	cout << "\nName -> ";
	cin >> nameOfFan;
	cout << "\nAge -> ";  
	while (!(cin >> ageOfFan) | ageOfFan<0 | ageOfFan >100)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Age -> ";
	}
	cout << "\nE-Mail -> "; 
	cin >> mail;
	cout << "\nPhone Number -> ";
	cin >> telephone;
	while (telephone < 0)
	{
		cin >> mail;
		cout << "\nTry again. Phone Number -> ";
	}
	while (!(cin >> telephone))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Wrong number. Use numbers. Try again: Telephone -> ";
	}
	cout << "\nThanks for Registration!\n";
	
	FanClub fn(nameOfFan, ageOfFan, mail, telephone);
	newFan.push_back(fn);
}
void FanClub::checkFans(vector <FanClub>& newFan){

	for (unsigned int i = 0; i < newFan.size(); i++) {
		cout << "\n\t#Base Fans' Information \n";
		cout << "\nName -> " << newFan[i].getName();
		cout << "\nAge -> " << newFan[i].getAge();
		cout << "\nE-Mail -> " << newFan[i].getEmail();
		cout << "\nPhone Number -> " << newFan[i].getPhone();
		cout << "\n\n";
	}
}