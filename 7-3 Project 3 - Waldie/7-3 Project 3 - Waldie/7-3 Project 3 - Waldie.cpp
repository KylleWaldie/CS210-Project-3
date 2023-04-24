// 7-3 Project 3 - Waldie.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>
#include <algorithm>

#include "GroceryOutput.h"

using namespace std;

//Prints the menu.
void printMenu() {
    unsigned int i;

    for (i = 0; i < 30; i++) {
        cout << '=';
    }
    cout << endl << "Corner Grocer Item-tracker!\n";

    for (i = 0; i < 30; i++) {
        cout << '-';
    }

    cout << endl << "1. Print out number of items." << endl;
    cout << "2. Print item name and amount" << endl;
    cout << "3. Print Histogram" << endl;
    cout << "4. Exit Program" << endl;
}



int main()
{
    bool running = true;

    while (running) {
        	string line;
	int itemFrequency = 0;

        char option;
        string userItem;

        GroceryOutput grocery;

        printMenu();

        cout << "Choose an option from the list: ";
        cin >> option;
        cout << endl;

        switch (option) {
            case '1':
                cout << "What fruit or vegetable are you looking for: ";
                cin >> userItem;
                grocery.MenuOptionOne(userItem);
                break;

            case '2':
                cout << "The amount of items sold: \n";
                grocery.MenuOptionTwo();
                cout << "Backup file created." << endl;
                break;

            case '3':
                grocery.MenuOptionThree();
                break;

            case '4':
                running = false;                
                break;
        }
    }
}
