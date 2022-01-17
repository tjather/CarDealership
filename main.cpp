//
// Project name : Programming Assignment 3
// Program name : main.cpp
//
/*
	NAME: Talha Ather
	CLASS: CSCI 1410
	DESCRIPTION:The prupose of this program is to manage cars in diffrent dealerships.
				The program can read a list of dealers and cars from a file, display thoses dealers, choose a dealer, display and add cars, and then write the entire list to a new file.
				This file contains the main() scope for Programming Assignment 3.
	STATUS: Fully running and functioning program with no issues.
	IDE: Created using Microsoft Visual Studio 2017.
*/
// Section main.cpp

//#include "pch.h"		// Needed for compilation to succeed in Visual Studio 2017
#include <iostream>     // Needed for using cin/cout statments
#include <string>       // Needed for using string type
#include <fstream>      // Needed for using files
#include <vector>		// Needed for using vectors
#include "Dealer.h"
#include "functions.h"

using namespace std;

int main() {
	int choice;	// Declare space in memory for int choice for the menu options.

	vector<Dealer> carDealers; // Declare vector<Dealer> carDealers which will be updated to hold the information that is read from a file.

	ifstream infile;	// Declare input file stream (ifstream) infile to be able to read a file
	ofstream outfile;	// Declare output file stream (ofstream) outfile to be able to write to a file

	do { //Start of the posttest loop for the menu.
		cout << "Car Dealership!" << endl; // Display a menu that says "Car Dealership!"
		
		// Display the eight options for the menu on the screen: "1. Read Dealers and Cars from file",  "2. Display Dealers", "3. Choose a Dealer Number, Display Cars", "4. Choose a Dealer Number, Add Car", "5. Choose a Dealer Number, List Cars and Modify a Car", "6. Choose a Dealer, Sort cars by VIN", "7. Write Dealers and Cars to file" , and "8. Exit"
		cout << "1. Read Dealers and Cars from file" << endl
			<< "2. Display Dealers" << endl
			<< "3. Choose a Dealer Number, Display Cars" << endl
			<< "4. Choose a Dealer Number, Add Car" << endl
			<< "5. Choose a Dealer Number, List Cars and Modify a Car" << endl
			<< "6. Choose a Dealer, Sort cars by VIN" << endl
			<< "7. Write Dealers and Cars to file" << endl
			<< "8. Exit" << endl;

		cout << "Pick an option:" << endl;	// Display a message on the screen that says, "Pick an option:"
		cin >> choice;						// Wait for the user to enter their choice. Once an input is entered, store data in memory named choice. 
		cin.ignore();						// Ignore the newline after the user enters their choice for the menu.

		if (choice == 1){ // Start of the if statment for the option "Read Dealers and Cars from file"
			readDealers(infile, carDealers); // Call function readDealers
		} // End of the if statment
		else if (choice == 2){ // Start of the else if statment for the option "Display Dealers"
			if (carDealers.size() > 0) { // Start of the if statment that checks if the vector is empty
				displayDealers(carDealers); // Call function displayDealers
			} // End of the if statment
			else { // Start of the scope for the else statement
				cout << "Please choose choice 1 to gain dealership info before selecting choice 2." << endl; // Display a message on the screen that says, "Please choose choice 1 to gain dealership info before selecting choice 2."
			} // End of the else statment
		} // End of the else if statment
		else if (choice == 3){ // Start of the else if statment for the option "Choose a Dealer Number, Display Cars"
			if (carDealers.size() > 0) { // Start of the if statment that checks if the vector is empty
				displayCars(carDealers); //Call function displayCars
			} // End of the if statment
			else { // Start of the scope for the else statement
				cout << "Please choose choice 1 to gain dealership info before selecting choice 3." << endl; // Display a message on the screen that says, "Please choose choice 1 to gain dealership info before selecting choice 3."
 			} // End of the else statment
		} // End of the else if statment
		else if (choice == 4){ // Start of the else if statment for the option "Choose a Dealer Number, Add Car"
			if (carDealers.size() > 0) { // Start of the if statment that checks if the vector is empty
				addCar(carDealers); // Call function addCar
			} // End of the if statment
			else { // Start of the scope for the else statement
				cout << "Please choose choice 1 to gain dealership info before selecting choice 4." << endl; // Display a message on the screen that says, "Please choose choice 1 to gain dealership info before selecting choice 4."
 			} // End of the else statment
		} // End of the else if statment
		else if (choice == 5){ // Start of the else if statment for the option "Choose a Dealer Number, List Cars and Modify a Car"
			if (carDealers.size() > 0) { // Start of the if statment that checks if the vector is empty
				modifyCar(carDealers); // Call function modifyCar
			} // End of the if statment
			else { // Start of the scope for the else statement
				cout << "Please choose choice 1 to gain dealership info before selecting choice 5." << endl; // Display a message on the screen that says, "Please choose choice 1 to gain dealership info before selecting choice 5."
 			} // End of the else statment
		} // End of the else if statment
		else if (choice == 6){ // Start of the else if statment for the option "Choose a Dealer, Sort cars by VIN"
			if (carDealers.size() > 0) { // Start of the if statment that checks if the vector is empty
				sortDealerCars(carDealers); // Call function sortDealerCars
 			} // End of the if statment
			else { // Start of the scope for the else statement
				cout << "Please choose choice 1 to gain dealership info before selecting choice 6." << endl; // Display a message on the screen that says, "Please choose choice 1 to gain dealership info before selecting choice 6."
 			} // End of the else statment
		} // End of the else if statment
		else if (choice == 7){ // Start of the else if statment for the option "Write Dealers and Cars to file
			if (carDealers.size() > 0) { // Start of the if statment that checks if the vector is empty
				writeDealers(outfile, carDealers); // Call function writeDealers
			} // End of the if statment
			else { // Start of the scope for the else statement
				cout << "Please choose choice 1 to gain dealership info before selecting choice 7." << endl; // Display a message on the screen that says, "Please choose choice 1 to gain dealership info before selecting choice 7."
 			} // End of the else statment
		} // End of the else if statment
		else if (choice == 8){ // Start of the else if statment for the option "Exit"
			cout << "Goodbye!";	// Display a message on the screen that says, "Goodbye!".
		} // End of the else if statment
		else{ // Start of the scope for the else statement that gives an error message if the user enters an invalid choice.
			cout << "Please pick a valid choice." << endl << endl; // Display a message on the screen that says, "Please pick a valid choice." 
		}
	} while (choice != 8); // Stay in the posttest loop until the user selects Exit and wants to leave.
	return 0;
}
