#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "Employee.h"
#include "Stadium.h"
using namespace std;

Employee::Employee() {}
Employee::Employee(string nameEm, int a, float wH, int exp)
		: nameOfEmpl(nameEm), age(a), workingHours(wH), experience(exp) {}


Staff::Staff() {}
Staff::Staff(string nameOfEmpl, int age, float workingHours, int experience, string area) : Employee(nameOfEmpl, age, workingHours, experience) {
	areaOfWork = area;
}

void Staff::newStaff() {

	cout << "New Staff" << endl;

	cout << "Name -> ";
	cin >> nameOfEmpl;
	cout << "\nAge -> ";
	cin >> age;
	cout << "\nWorking Hours -> ";
	cin >> workingHours;
	cout << "\nExperience (years) -> ";
	cin >> experience;
	cout << "\nArea of work -> ";
	cin >> areaOfWork;

	ofstream empl;   //create the file for saving information inside 
	empl.open("Staff.doc", ios::app); //writing the file

	empl << nameOfEmpl << " " << age << " " << workingHours << " " << experience << " "<< areaOfWork << "\n";; //input the info inside the file

	empl.close();
}

void Staff::staffInfo() {

	ifstream emp; //reading the file
	emp.open("Staff.doc");

	bool ifExist = false;
	string name;
	cout << "\nWrite the Staff's Name -> ";
	cin >> name;
	
	while (!emp.eof()) {  //while Not the end of file look for the appropriate name
		emp >> nameOfEmpl >> age >> workingHours >> experience >> areaOfWork;
		if (nameOfEmpl == name)
		{
			ifExist = true;
			cout << "\n\t#Basic Information" << endl;
			cout << "Name -> " << nameOfEmpl << endl;
			cout << "Age -> " << age << endl;
			cout << "Working Hours -> " << workingHours << endl;
			cout << "Experience -> " << experience << " years\n" << endl;
			cout << "Area of Working -> " << areaOfWork << endl;
			break;
		}

	}
	if (!ifExist)
	{
		cout << "\nThere is no appropriate Name!\n" << endl;
	}

	emp.close();
}

double Staff::shareSalary() {  //polymorphism
	cout << "\nStaff's Salary -> ";
	return Stadium::balanceOfStad * 0.1;
}

CoachTeam::CoachTeam() {}
CoachTeam::CoachTeam(string nameEm, int a, float wH, int exp, string specialization) : Employee(nameEm, a, wH, exp) {
	this->specialization = specialization;
}

void CoachTeam::newCoach() { 
	
	cout << "New Coach" << endl;

	cout << "Name -> ";
	cin >> nameOfEmpl;
	cout << "\nAge -> ";
	cin >> age;
	cout << "\nWorking Hours -> ";
	cin >> workingHours;
	cout << "\nExperience (years) -> ";
	cin >> experience;
	cout << "\nSpecializaion -> ";
	cin >> specialization;

	ofstream empl("Coach_Team.doc", ios::app); // write the info to the inside of file

	empl << nameOfEmpl << " " << age << " " << workingHours << " " << experience << " " << specialization << endl;

	empl.close();
	
}

void CoachTeam::coachInfo() {
	
	ifstream emp; 
	emp.open("Coach_Team.doc");

	bool ifExist = false;
	string name;
	cout << "\nWrite the Coach's Name -> ";
	cin >> name;

	while (!emp.eof()) { //while Not the end of file look for the appropriate name
		emp >> nameOfEmpl >> age >> workingHours >> experience >> specialization;
		if (nameOfEmpl == name)
		{
			ifExist = true;
			cout << "\n\t#Basic Information" << endl;
			cout << "Name -> " << nameOfEmpl << endl;
			cout << "Age -> " << age << endl;
			cout << "Working Hours -> " << workingHours << endl;
			cout << "Experience -> " << experience << " years\n" << endl;
			cout << "Specialization -> " << specialization << endl;
			break;
		}

	}
	if (!ifExist)
	{
		cout << "\nThere is no appropriate Name!\n" << endl;
	}

	emp.close();
}

double CoachTeam::shareSalary() {
	cout << "\nCoach's Salary -> ";
	return Stadium::balanceOfStad * 0.3;
}

Player::Player(){}
Player::Player(string nameEm, int a, float wH, int exp, string plPos, float height, float weight, int num, string currStat)
: Employee(nameEm, a, wH, exp)
{
	playingPos = plPos;
	this->height = height;
	this->weight = weight;
	numOfPlayer = num;
	currentStat = currStat;
}

void Player::newPlayer() {
	
	cout << "New Player" << endl;

	cout << "Name -> ";
	cin >> nameOfEmpl;
	cout << "\nAge -> ";
	cin >> age;
	cout << "\nWorking Hours -> ";
	cin >> workingHours;
	cout << "\nExperience (years) -> ";
	cin >> experience;
	cout << "\nPlaying position -> ";
	cin >> playingPos;
	cout << "\nHeight -> ";
	cin >> height;
	cout << "\nWeight -> ";
	cin >> weight;
	cout << "\nNumber of Player -> ";
	cin >> numOfPlayer;
	cout << "\nCurrent Status -> ";
	cin >> currentStat;


	ofstream empl;
	empl.open("Players.doc", ios::app);  //write the file to the inside of file

	empl << nameOfEmpl << " " << age << " " << workingHours << " ";
	empl << experience << " " << playingPos << " " << height << " ";
	empl << weight << " " << numOfPlayer << " " << currentStat << "\n";

	empl.close();

}

void Player::playerInfo() {
	ifstream emp;
	emp.open("Players.doc"); //read the info from the file

	bool ifExist = false;
	string name;
	cout << "\nWrite the Player's Name -> ";
	cin >> name;

	while (!emp.eof()) { //while Not the end of file look for the appropriate name
		emp >> nameOfEmpl >> age >> workingHours >> experience >> playingPos >> height >> weight >> numOfPlayer >> currentStat;
		if (nameOfEmpl == name)
		{
			ifExist = true;
			cout << "\n\t#Basic Information" << endl;
			cout << "Name -> " << nameOfEmpl << endl;
			cout << "Age -> " << age << endl;
			cout << "Working Hours -> " << workingHours << endl;
			cout << "Experience -> " << experience << " years\n" << endl;
			cout << "Playing position -> " << playingPos << endl;
			cout << "Height -> " << height << endl;
			cout << "Weight -> " << weight << endl;
			cout << "Number of Player -> " << numOfPlayer << endl;
			cout << "Current Status -> " << currentStat << endl;
			break;
		}
	}

	if (!ifExist)
	{
		cout << "\nThere is no appropriate Name!\n" << endl;
	}

	emp.close();


}

double Player::shareSalary(){
	cout << "\nPlayer's Salary -> ";
	return Stadium::balanceOfStad * 0.5;
}