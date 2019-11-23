#include "pch.h"
#include "header.h"

void callLogIn(string loginFile) {
	if (logIn(loginFile) == true) {
		cout << "Welcome to the Bank of Spack Teller." << endl << endl;
		displayMenu();
	}
	else
	{
		cout << "login information was incorrect" << endl;
		callLogIn(loginFile);
	}
	return;
}



bool logIn(const string tellerFile) {
	const int SIZE = 4;
	ifstream fin;
	ofstream fout;
	fin.open(tellerFile);
	if (fin.fail())
	{
		cout << "This file could not be opened sorry" << endl;
		return 0;
	}
	string username[SIZE];
	string password[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		fin >> username[i];
		fin >> password[i];
		//cout << username[i] << " " << password[i] << endl;
	}
	fin.close();
	string usernameInput = "";
	string passwordInput = "";

	cout << "Enter username" << endl;
	cin >> usernameInput;

	cout << endl << "Enter password" << endl;
	cin >> passwordInput;
	cout << endl;

	for (int i = 0; i < SIZE; i++)
	{
		if (usernameInput == username[i])
		{
			if (passwordInput == password[i])
			{
				return true;
			}
		}
	}
	return false;

}

void displayMenu() {
	cout << endl << "What would you like to do" << endl;
	cout << "1.    Add a new account" << endl
		<< "2.    Delete an existing account" << endl
		<< "3.    Update information on an existing account" << endl
		<< "4.    Search account information" << endl
		<< "5.    Deposit money into an account" << endl
		<< "6.    Withdraw money from an account" << endl
		<< "7.    Check balance on an account" << endl
		<< "8.    Quit program" << endl;

	menuSwitch();
}

void menuSwitch() {
	int userInput = 0;
	cin >> userInput;
	if (userInput >= 1 && userInput <= 8)
	{
		switch (userInput)
		{
		case 1:	 addNewAccount();
			break;
					
		case 2: deleteAccount();
			break;
		case 3: updateAccount();
			break;
		case 4: searchAccount();
			break;
		case 5: deposit();
			break;
		case 6:  withdraw();
			break;
		case 7:  checkBalance();
			break;
		case 8: quit();
			break;

		default: cout << "enter a valid menu option" << endl;

			break;
		}
	}
}

void addNewAccount() {
	cout << "Add a new account";

}

void deleteAccount() {
	cout << "Delete an account";

}

void updateAccount() {
	cout << "Update account";

}

void searchAccount() {
	cout << "Search account";

}

void deposit() {
	cout << "Deposit";

}

void withdraw() {
	cout << "Withdraw";

}

void checkBalance() {
	cout << "check balance";

}

void quit() {
	cout << "quit";
}
