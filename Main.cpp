#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "Employee.h"
#include "Stadium.h"
#include "TicketAccount.h"
#include "FanClub.h"

using namespace std;

double Stadium::balanceOfStad = 50000;
int TicketAccount::amountTour = 900;
int TicketAccount::amountMatch = 5000;

//switch cases

void MainMenu();
void FanMenu();
void FanClubMenu();
void AdminMenu();
void EmployeeMenu();
void scheduleM();
void scheduleT();
void CteamSalary();
void StaffSalary();
void PlayerSalary();
void Account();

void MainMenu() {
	bool var = true;
	do {
		cout << "********************************\n";
		cout << "  Welcome to SM Entertainment\n\n";
		cout << "  1. Fan's Menu\n";
		cout << "  2. Administration's Menu\n";
		cout << "  3. Employee's Menu\n";
		cout << "  0. <- Quit ->\n";
		cout << "\n********************************\n";
		int n;

		cin >> n;
		system("cls");
		switch (n) {
		case 1: FanMenu();
			break;
		case 2: AdminMenu();
			break;
		case 3: EmployeeMenu();
		case 0: break;
		default: cout << "There is no appropriate option!\n Choose again!\n";
			MainMenu();
			break;
		}
		if (n == 0)
			var = false;
	} while (var);
}

void Account() {
	
	bool var = true;

	TicketAccount tick;
	do{

		cout << "1.Registration New Account\n";
		cout << "2. Find and Check Account\n";
		cout << "3. <- Main Menu ->\n";
		cout << "0. <- Quit ->\n";
	int num;
	cin >> num;
	
	switch (num) {
		case 1: tick.newAcc();
			break;
		case 2: tick.checkAcc();
			break;
		case 3: MainMenu();
			break;
		case 0: exit(0);
		default: cout << "There is no appropriate option!\n Choose again!\n";
			Account();
			break;

		}
		if (num == 0)
			var = false;
	} while (var);
}

void scheduleBuy() {
	
	bool var = true;
	
	do {
		int ans;
		cout << "\n  1. Tour Day\n";
		cout << "  2.Match Day\n";
		cout << "  3. <- Main Menu ->\n";
		cout << "  0. <- Back ->\n";
		cin >> ans;

	switch (ans) {
	case 1: scheduleT();
		break;
	case 2: scheduleM();
		break;
	case 3: MainMenu();
		break;
	case 0: exit(0);
	default: cout << "\n**There is no appropriate number!**\n";
		FanMenu();
		break;
	}
	if (ans == 0)
		var = false;
} while (var);

	}


void FanMenu() {
	Player play;
	CoachTeam cTeam;
	Staff staff;
	TicketAccount acc;
	
	bool var = true;

	do {
		int num;
		cout << "     Fan's Menu\n\n";
		cout << "  1. Fan Club\n";
		cout << "  2. Player's info\n";
		cout << "  3. Coach Team's info\n";
		cout << "  4. Staff's info\n";
		cout << "  5. Schedule + Buy Tickets\n";
		cout << "  6. Accounts\n";
		cout << "  7. <- Main Menu ->\n";
		cout << "  0. <- Quit ->\n";
		cin >> num;
		system("cls");
		switch (num) {
		case 1: FanClubMenu();
			break;
		case 2: play.playerInfo();
			break;
		case 3: cTeam.coachInfo();
			break;
		case 4: staff.staffInfo();
			break;
		case 5: scheduleBuy();
			break;
		case 6: Account();
			break;
		case 7: MainMenu();
			break;
		case 0: exit(0);
		default: cout << "\n**There is no appropriate number!**\n";
			FanMenu();
			break;
		}
		if (num == 0)
			var = false;
	} while (var);
	}

void FanClubMenu() {
	FanClub fn;
	
	bool var = true;

	do {
		cout << "\n** Fan Club **\n";
		cout << "1. Registration\n";
		cout << "2. Members of the Fan Club\n";
		cout << "3. <- Fan Menu -> \n";
		cout << "4. <- Main Menu -> \n";
		cout << "0. <- Quit ->\n";
		int num;
		cin >> num;
		system("cls");
	switch (num) {
	case 1: fn.createNewFan(fn.fans);
		break;
	case 2: fn.checkFans(fn.fans);
		break;
	case 3: FanMenu();
		break;
	case 4: MainMenu();
		break;
	case 0: exit(0);
	default: cout << "\n**There is no appropriate number!**\n";
		FanClubMenu();
		break;
	}
	if (num == 0)
		var = false;
} while (var);
}

void AdminMenu() {

	Stadium stad;
	Staff staff;
	Player pl;
	CoachTeam cT;
	bool var = true;
	
	do {
		int ans;
		cout << "    **Admin Menu**\n\n";
		cout << "  1. Stadium's Info\n";
		cout << "  2. Create new Staff\n";
		cout << "  3. Create new Player\n";
		cout << "  4. Create new Coach\n";
		cout << "  5. <- Main Menu ->\n";
		cout << "  0. <- Quit -> \n";
		cin >> ans;
		system("cls");
		switch (ans) {
		case 1: stad.infoStad();
			break;
		case 2: staff.newStaff();
			break;
		case 3: pl.newPlayer();
			break;
		case 4: cT.newCoach();
			break;
		case 5: MainMenu();
			break;
		case 0: exit(0);
		default: cout << "\n**There is no appropriate number!**\n";
			AdminMenu();
			break;
		}
		if (ans == 0)
			var = false;
	} while (var);
}

void EmployeeMenu() {
	
	bool var = true;
	do {
		cout << "   **Employee Menu**\n\n";
		cout << "  1. Staff's salary\n";
		cout << "  2. Player's salary\n";
		cout << "  3. Coach's salary\n";
		cout << "  4. <- Main Menu ->\n";
		cout << "  0. <- Quit ->\n";
		int ans;
		cin >> ans;
		system("cls");
		switch (ans) {
		case 1: StaffSalary();
			break;
		case 2: PlayerSalary();
			break;
		case 3: CteamSalary();
			break;
		case 4: MainMenu();
			break;
		case 0: exit(0);
		default: cout << "There is no appropriate number";
			EmployeeMenu();
			break;
		} if (ans == 0)
			var = false;
	} while (var);
}

 void scheduleT() {
	 TicketAccount tick;
	 cout << "\n Monday -> Tour Day\n\t 11:00am - 6:30pm\n\t\t Price -> 40$\n";
		cout << "\n Tuesday -> Tour Day\n\t 11:00am - 6:30pm\n\t\t Price -> 40$\n";
		cout << "\n Sunday -> Tour Day\n\t 11:00am - 6:30pm\n\t\t Price -> 40$\n";
		tick.amountT();
		

		bool var = true;
	int ans;
	do{
		cout << " If you wish to :\n";
		cout << "1. Buy tickets to the Tour\n";
		cout << "2. <- Fan Menu ->\n";
		cout << "3. <- Main Menu ->\n";
		cout << "0. <- Quit ->\n";
		cout << "\t\t\t press the appropriate number: \n";
		cin >> ans;
		system("cls");
		switch (ans) {
		case 1: tick.transferT();
			break;
		case 2: FanMenu();
			break;
		case 3: MainMenu();
			break;
		case 0: exit(0);
		default: cout << "\n**There is no appropriate number!**\n";
			scheduleT();
			break;
		}
		if (ans == 0)
			var = false;
	} while (var);
}

 void scheduleM() {
	 TicketAccount tick;
	 cout << "\n Wednesday -> Tour Day\n\t 19:00am - 20:30pm\n\t\t Price -> 80$\n";
	 cout << "\n Thursday -> Tour Day\n\t 19:00am - 20:30pm\n\t\t Price -> 80$\n";
	 cout << "\n Friday -> Tour Day\n\t 19:00am - 20:30pm\n\t\t Price -> 80$\n";
	 tick.amountM();


	 bool var = true;
	 int ans;
	 do{
	 cout << " If you wish to :\n";
	 cout << "1. Buy tickets to the Match\n";
	 cout << "2. <- Fan Menu ->\n";
	 cout << "3. <- Main Menu ->\n";
	 cout << "0. <- Quit ->\n";
	 cout << "\t\t\t press the appropriate number: \n";
	 cin >> ans;
	 system("cls");
	 switch (ans) {
	 case 1: tick.transferM();
		 break;
	 case 2: FanMenu();
		 break;
	 case 3: MainMenu();
		 break;
	 case 0: exit(0);
	 default: cout << "\n**There is no appropriate number!**\n";
		 scheduleM();
		 break;
	 }	if (ans == 0)
		 var = false;
 } while (var);
 }

void CteamSalary() {
	Employee *em;
	CoachTeam cT;
	em = &cT;
	cout << em->shareSalary() << endl;
}

void StaffSalary() {
	Employee *em;
	Staff st;
	em = &st;
	cout << em->shareSalary() << endl;
}

void PlayerSalary() {
	Employee *em;
	Player pl;
	em = &pl;
	cout << em->shareSalary() << endl;
}

int main() {

	
//
	MainMenu();

	//system("pause");
	return 0;

}