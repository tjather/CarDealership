//
// Project name : CarDealership
// Program name : functions.h
//
/*
	NAME: Talha Ather
	DESCRIPTION:The prupose of this program is to manage cars in diffrent dealerships.
				The program can read a list of dealers and cars from a file, display thoses dealers, choose a dealer, display and add cars, and then write the entire list to a new file.
				This file contains the the function headers for Programming Assignment 3.
	STATUS: Fully running and functioning program with no issues.
	IDE: Created using Microsoft Visual Studio 2017.
*/
// Section function.h

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>     // Needed for using cin/cout statments
#include <string>       // Needed for using string type
#include <fstream>      // Needed for using files
#include <vector>		// Needed for using vectors
#include "Dealer.h"
using namespace std;


//	Declare the function prototype for requried function that coressponds to 1. Read Dealers and Cars from file
void readDealers(ifstream &infile, vector<Dealer> &carDealers);

//	Declare the function prototype for requried function that coressponds to 2. Display Dealers
void displayDealers(vector<Dealer> &carDealers);

//	Declare the function prototype for requried function that coressponds to 3. Choose a Dealer Number, Display Cars
void displayCars(vector<Dealer> &carDealers);

//	Declare the function prototype for requried function that coressponds to 4. Choose a Dealer Number, Add Car
void addCar(vector<Dealer> &carDealers);

//	Declare the function prototype for extra credit function that coressponds to 5. Choose a Dealer Number, List Cars and Modify a Car
void modifyCar(vector<Dealer> &carDealers);

//	Declare the function prototype for extra credit function that coressponds to 6. Choose a Dealer, Sort cars by VIN
void sortDealerCars(vector<Dealer> &carDealers);

//	Declare the function prototype for requried function that coressponds to 7. Write Dealers and Cars to file
void writeDealers(ofstream &outfile, vector<Dealer> &carDealers);

//	Declare the function prototype to sort the cars by VIN
void bubblesortCar(Car *, int size);

//	Declare the function prototype to search for a specific dealer
int linearSearchDealer(vector <Dealer> &carDealers, int dealerNumber);

//	Declare the function prototype to search for a specific car
int linearSearchCar(Car *, string, int); 

#endif
