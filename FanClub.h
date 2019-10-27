#ifndef FANCLUB_H
#define FANCLUB_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class FanClub {
private:
	string nameOfFan;
	int ageOfFan;
	string mail;
	long long int telephone;
public: 
	FanClub();
	FanClub(string, int, string, int);
	~FanClub();

	 vector <FanClub> fans;

	void createNewFan(vector <FanClub>&);
	void checkFans(vector <FanClub>&);

	string getName();
	int getAge();
	string getEmail();
	long long int getPhone();
};

#endif