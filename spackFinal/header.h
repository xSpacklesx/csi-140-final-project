#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

void callLogIn(string loginFile);
bool logIn(string tellerFile);
void displayMenu();
void menuSwitch();

void addNewAccount();
void deleteAccount();
void updateAccount();
void searchAccount();
void deposit();
void withdraw();
void checkBalance();
void quit();


#endif