#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

#include "GroceryOutput.h"


using namespace std;

//Function for option one to print out the number of a certain item.
void GroceryOutput::MenuOptionOne(string userInput) {

	string line;
	int itemFrequency = 0;
	int offset;
	string search;

	ifstream myFile;
	myFile.open("CS210_Project_Three_Input_File.txt");//Opens the file.

	//Checks if the file is open and starts to loop through it.
	if (myFile.is_open()) {
		while (!myFile.eof()) {

		//Loops through the file and compares the userInput to the desired name and counts how many there are adding it to itemFrequency.
			getline(myFile, line);
			if ((offset = line.find(userInput, 0)) != string::npos) { 
				itemFrequency += 1;
			}

		}
		cout << "The number of " << userInput << "'s are: " << itemFrequency << endl;;
		cout << endl;
	}
	myFile.close(); //closes the file.
}

//Function to print out all the items and the number of them that have been sold. 
void GroceryOutput::MenuOptionTwo() {
	unsigned int i;
	string line;
	vector<string> groceryList;

	ofstream newFile;
	ifstream myFile;
	myFile.open("CS210_Project_Three_Input_File.txt");
	newFile.open("frequency.dat");

	if (myFile.is_open()) {
		while (!myFile.eof()) {

			getline(myFile, line);
			groceryList.push_back(line);
		}
		sort(groceryList.begin(), groceryList.end());

		int vectorSize = groceryList.size();
		int amountOfTimes = 0;
		string groceries = groceryList[0];

		for (int i = 0; i < vectorSize; i++) {
			if (groceries != groceryList[i]) {

				cout << groceries << ":  " << amountOfTimes << endl;
				newFile << groceries << ":  " << amountOfTimes << endl;
				amountOfTimes = 0;
				groceries = groceryList[i];

			}
			amountOfTimes++;
		}
		newFile.close();
		myFile.close();
	}
}

void GroceryOutput::MenuOptionThree() {
	unsigned int i;
	string line;
	vector<string> groceryList;

	ifstream myFile;
	myFile.open("CS210_Project_Three_Input_File.txt");

	if (myFile.is_open()) {
		while (!myFile.eof()) {

			getline(myFile, line);
			groceryList.push_back(line);
		}
		sort(groceryList.begin(), groceryList.end());

		int vectorSize = groceryList.size();
		int amountOfTimes = 0;
		string groceries = groceryList[0];

		for (int i = 0; i < vectorSize; i++) {
			if (groceries != groceryList[i]) {

				cout << groceries << " ";
				for (int i = 0; i < amountOfTimes; i++) {
					cout << '*';
				}
				cout << endl;
				amountOfTimes = 0;
				groceries = groceryList[i];

			}
			amountOfTimes++;
		}

		myFile.close();
	}
}