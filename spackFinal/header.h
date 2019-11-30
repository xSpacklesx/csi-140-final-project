#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <cstdio>

using namespace std;
/*
	Purpose: to call th login system
	Pre: takes in the login file
	Post: calls menu or reprompts for login 
*/

void callLogIn(string loginFile);
/*
	Purpose: to validate that the uer is a teller
	Pre: takes in login file 
	Post: returns true if login works false if login fails
*/

bool logIn(string tellerFile);
/*
	Purpose: to disply the menu
	Pre: takes in nothing
	Post: outputs the menu to the user and calls the switch
*/

void displayMenu();
/*
	Purpose: to call the function th user wants to use
	Pre: takes innothing
	Post: calls the function the user wanted
*/

void menuSwitch();

/*
	Purpose: to add a new account to the account file and make a data file for their balance
	Pre: takes in nothing
	Post: outputs the information to the files and re calls the menu
*/
void addNewAccount();

/*
	Purpose: to create the new account files
	Pre: takes in the name of the account that is geting a file and the alance for that account
	Post: outputs a new fie with an account balanc
*/
void createAccountFile(string fileName, float accountBalance);

/*
	Purpose: to delete an account from the accounts.dat file as wel as delete the accounts balance
	Pre: takes in nothing
	Post: outputs a changed file and deletes the balance filefor the account
*/
void deleteAccount();

/*
	Purpose: to update the name on an account
	Pre: takes in nothing
	Post: outputs a newly updated file and calls the menu
*/
void updateAccount();

/*
	Purpose: fin an account and check its information
	Pre: nothing
	Post: outputs the accounts information;
*/
void searchAccount();

/*
	Purpose: add money to an account
	Pre: nothing
	Post: outputs a new data file for the account with an updated balance
*/
void deposit();

/*
	Purpose: To remove money from an ccount
	Pre: nothing
	Post: outputs a new data file or the account with an updated balance
*/
void withdraw();

/*
	Purpose: to check the balance of an accont
	Pre: nothing
	Post: outputs the balance of the selected account
*/
void checkBalance();

/*
	Purpose: to see if the user typed quit
	Pre: the user's input
	Post: either calls quit or does nothing
*/
void stopCheck(string input);

/*
	Purpose:to end the program
	Pre: nothng
	Post: quits program
*/
void quit();

/*
	Purpose: to make sure there are no dulicate account numers generated
	Pre: the new account number
	Post: compares the two numbers and re calls the function to make a new account number;
*/
void accountNumCheck(string accountNumber);


#endif
