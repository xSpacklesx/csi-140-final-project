#include "header.h"

//add stopChack to after every cin

const string OUTPUT_FILE = "accounts.dat";
const int MAX_ACCOUNT_NUM = 10;

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
	cout << "Add a new account" << endl;
	ofstream fout;	
	fout.open(OUTPUT_FILE, ios::app);
	if (fout.fail())
	{
		cout << "This file could not be opened sorry" << endl;
		return;
	}
	srand(time(NULL));
	stringstream str;
	str << rand() % 9;
	str << rand() % 9;
	str << rand() % 9;
	str << rand() % 9;
	str << rand() % 9;
	string accountNumString = str.str();
	cout << "Account number: " << accountNumString << endl;
	string newAccountName;
	string newAccountSSN;
	string newAccountAddress;
	string newAccountPhone;
	cin.ignore();
	cout << "New account name:";
	getline(cin, newAccountName);
	cout << "New account SSN:";
	cin >> newAccountSSN;
	cin.ignore();
	cout << "New account address:";
	getline(cin, newAccountAddress);
	cout << "New account phone number:";
	cin >> newAccountPhone;
	fout << accountNumString
		<< endl << newAccountSSN[0] << newAccountSSN[1] << newAccountSSN[2]  << "-" << newAccountSSN[3] << newAccountSSN[4] << "-"
		<< newAccountSSN[5] << newAccountSSN[6] << newAccountSSN[7]  << newAccountSSN[8]
		<< endl << newAccountName << endl << newAccountAddress << endl 
		<< '(' << newAccountPhone[0] << newAccountPhone[1] << newAccountPhone[2] << ')'
		<< newAccountPhone[3] << newAccountPhone[4] << newAccountPhone[5] << '-'
		<< newAccountPhone[6] << newAccountPhone[7] << newAccountPhone[8] << newAccountPhone[9] << endl;
	fout.close();
	float accountBalance = 0.0;
	cout << "New account balance:";
	cin >> accountBalance;
	createAccountFile(accountNumString, accountBalance);
	displayMenu();
}

void createAccountFile(string fileName, float accountBalance) {
	ofstream fout;
	fout.open(fileName + ".dat");
	fout << '$' << fixed << setprecision(2) << accountBalance;
	fout.close();
	return;
}

void deleteAccount() {
	cout << "Delete an account" << endl;

	ifstream fin;
	fin.open(OUTPUT_FILE);
	string transfer;
	string junk;
	string accountNumbers[MAX_ACCOUNT_NUM];
	int x = 0;
	cout << "Enter account number:";
	string userInput = "";
	cin >> userInput;
	while (!fin.eof())
	{
		getline(fin, accountNumbers[x]);
		getline(fin, junk);
		getline(fin, junk);
		getline(fin, junk);
		getline(fin, junk);
		//cout << accountNumbers[i] << endl;
		x++;

	}
	fin.close();

	fin.open(OUTPUT_FILE);
	ofstream fout;
	fout.open("temp.dat");
	for (int i = 0; i < x; i++)
	{
		if (userInput == accountNumbers[i]) 
		{
			cout << "account found" << endl;
			for (int j = 0; j < (i * 5) -1; j++) 
			{
				getline(fin, transfer);
				fout << transfer << endl;
			}
			for (int y = 0; y < 5; y++) 
			{
				getline(fin, junk);
			}
			while (!fin.eof())
			{
				getline(fin, transfer);
				fout << transfer << endl;
			}
			cout << "account deleted" << endl;
		}
	}
	 fin.close();
	 fout.close();
	 if (remove("accounts.dat") != 0) {
		 cout << "removal failed" << endl;
	 }
	 rename("temp.dat", "accounts.dat");

}

void updateAccount() {
	cout << "Update account" << endl;
	ifstream fin;
	fin.open(OUTPUT_FILE);
	//11 is the max number of accounts
	string accountNumbers[MAX_ACCOUNT_NUM];
	string junk;
	int i = 0;
	string userInput;
	while (!fin.eof()) 
	{
		getline(fin, accountNumbers[i]);
		getline(fin, junk);
		getline(fin, junk);
		getline(fin, junk);
		getline(fin, junk);
		//cout << accountNumbers[i] << endl;
		i++;

	}
	fin.close();
	cout << "Please enter the number of the account you want to edit:";
	cin >> userInput;
	ofstream fout;
	fin.open(OUTPUT_FILE);
	fout.open("temp.dat");
	string newName;
	for (int j = 0; j < i; j++) 
	{
		if (userInput == accountNumbers[j]) 
		{
			cout << "Account found" << endl;
			//(j * 5) + 3 = nameChanged
			for (int k = 0; k < ((j * 5) + 3) - 1; k++) 
			{
				getline(fin, junk);
				fout << junk << endl;
			}
			cout << "Enter new name:";
			cin.ignore();
			getline(cin, newName);
			fout << newName << endl;
			getline(fin, junk);
			while (!fin.eof()) 
			{
				getline(fin, junk);
				fout << junk << endl;
			}
			fin.close();
			fout.close();
			if (remove("accounts.dat") != 0) {
				cout << "removal failed" << endl;
			}
			rename("temp.dat", "accounts.dat");
			cout << "Name Changed" << endl;
		}
	}
	displayMenu();
}

void searchAccount() {
	cout << "Search account";
	//add ability to search for an account by number and display info 
	//any extra search ability is a bonus

}

void deposit() {
	cout << "Deposit" << endl;
	//cycle through pull out account numbers
	//recive account number input
	//compare input and array

	ifstream fin;
	fin.open(OUTPUT_FILE);
	string accountNumbers[MAX_ACCOUNT_NUM];
	string junk;
	int i = 0;
	string userInput;
	while (!fin.eof())
	{
		getline(fin, accountNumbers[i]);
		getline(fin, junk);
		getline(fin, junk);
		getline(fin, junk);
		getline(fin, junk);
		//cout << accountNumbers[i] << endl;
		i++;

	}
	fin.close();
	cout << "Enter the account number that you want to deposit to:";
	cin >> userInput;

	for (int j = 0; j < i; j++) 
	{
		if (userInput == accountNumbers[j]) 
		{
			userInput.append(".dat");
			ifstream cashFileIn;
			cashFileIn.open(userInput);
			string accountBalance;
			getline(cashFileIn, accountBalance);
			cashFileIn.close();
			accountBalance.erase(0, 1);
			float accountBalanceFloat;
			accountBalanceFloat = stof(accountBalance);
			//cout << accountBalanceFloat << endl;
			cout << "How much are you depositing:";
			float depositAmount;
			cin >> depositAmount;
			ofstream cashFileOut;
			accountBalanceFloat += depositAmount;
			cashFileOut.open("temp.dat");
			cashFileOut << "$" << fixed << setprecision(2) << accountBalanceFloat;
			cashFileOut.close();
			if (remove((userInput).c_str()) == 0) {
				cout << "Account deleted" << endl;
				rename("temp.dat", userInput.c_str());
			}
			else 
			{
				cout << "error deleting" << endl;
			}
		}
	}

	//prompt for account number and make sure we have it
	//take in the value from that accounts file
	//add the deposit ammount to that number
	//change the value in the file to reflect the addition
	//close file

}

void withdraw() {
	cout << "Withdraw";
	//prompt for account number and make sure we have it
	//take in the value from that accounts file
	//subtract the ammount to that number
	//change the value in the file to reflect the change
	//close file
	ifstream fin;
	fin.open(OUTPUT_FILE);
	string accountNumbers[MAX_ACCOUNT_NUM];
	string junk;
	int i = 0;
	string userInput;
	while (!fin.eof())
	{
		getline(fin, accountNumbers[i]);
		getline(fin, junk);
		getline(fin, junk);
		getline(fin, junk);
		getline(fin, junk);
		//cout << accountNumbers[i] << endl;
		i++;

	}
	fin.close();
	cout << "Enter the account number that you want to withdraw:";
	cin >> userInput;

	for (int j = 0; j < i; j++)
	{
		if (userInput == accountNumbers[j])
		{
			userInput.append(".dat");
			ifstream cashFileIn;
			cashFileIn.open(userInput);
			string accountBalance;
			getline(cashFileIn, accountBalance);
			cashFileIn.close();
			accountBalance.erase(0, 1);
			float accountBalanceFloat;
			accountBalanceFloat = stof(accountBalance);
			//cout << accountBalanceFloat << endl;
			cout << "How much are you depositing:";
			float withdrawAmount;
			cin >> withdrawAmount;
			ofstream cashFileOut;
			accountBalanceFloat -= withdrawAmount;
			cashFileOut.open("temp.dat");
			cashFileOut << "$" << fixed << setprecision(2) << accountBalanceFloat;
			cashFileOut.close();
			if (remove((userInput).c_str()) == 0) {
				cout << "Account deleted" << endl;
				rename("temp.dat", userInput.c_str());
			}
			else
			{
				cout << "error deleting" << endl;
			}

		}
	}

}

void checkBalance() {
	cout << "check balance";
	//prompt for account number
	//check that we have that account on file
	//oppen that account file

}

void quit() {
	cout << "quit";
	//exit program
}
