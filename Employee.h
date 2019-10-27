#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "Stadium.h"

using namespace std;

class Employee {
protected:   //protected base class
	string nameOfEmpl;
	int age;
	float workingHours;
	int experience;
public:
	Employee(); //default constructor
	Employee(string, int, float, int); //Overload constructor
	

	virtual double shareSalary() = 0;  //polymorphism
};

class Staff : public Employee {  //derived class
private:
	string areaOfWork;
public:
	Staff();
	Staff(string, int, float, int, string);

	void newStaff();
	void staffInfo();
	double shareSalary(); //polymorphism
};

class CoachTeam : public Employee {
private:
	string specialization;
public:
	CoachTeam();
	CoachTeam(string, int, float, int, string);
	void newCoach();
	void coachInfo();
	double shareSalary(); //polymorphism
};

class Player : public Employee {
private:
	string playingPos;
	float height;
	float weight;
	int numOfPlayer;
	string currentStat;
public:
	Player();
	Player(string, int, float, int, string, float, float, int, string);
	
	void newPlayer();
	void playerInfo();
	double shareSalary(); //polymorphism
};


#endif