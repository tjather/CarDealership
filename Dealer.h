//
// Project name : CarDealership
// Program name : dealer.h
//
/*
	NAME: Talha Ather
	DESCRIPTION:The prupose of this program is to manage cars in diffrent dealerships.
				The program can read a list of dealers and cars from a file, display thoses dealers, choose a dealer, display and add cars, and then write the entire list to a new file.
				This file contains the Dealer and Car class definitions for Programming Assignment 3.
	STATUS: Fully running and functioning program with no issues.
	IDE: Created using Microsoft Visual Studio 2017.
*/
// Section Dealer.h

#ifndef DEALER_H
#define DEALER_H

#include <iostream>     // Needed for using cin/cout statments
#include <string>       // Needed for using string type
#include <fstream>      // Needed for using files
#include <vector>		// Needed for using vectors
using namespace std;

class Dealer;	// Declare class dealer
class Car;		// Declare class car

class Dealer { // Start of the Dealer class defintion
private: // Delcare private method prototypes
	string dealerName;	// Declare variable string dealerName
	int dealerNumber;	// Declare variable int dealerNumber
	int numberOfCars;	// Declare variable int numberOfCars
public: // Delcare public method prototypes
	Dealer(); // Declare the default constructor
	Dealer(string & _dealerName, int _dealerNumber);  // Declare the constructor

	Car *carArrayPtr;		// Declare a pointer to a dynamic car array
	Car *newCarArrayPtr;	// Declare a pointer to a temp dynamic car array

	string getDealerName(); //Declare get protoype for DealerName
	void setDealerName(string dealerName); //Declare set protoype for DealerName

    int getDealerNumber(); //Declare get protoype for DealerNumber
	void setDealerNumber(int dealerNumber); //Declare set protoype for DealerNumber

	int getNumberOfCars(); //Declare get protoype for NumberOfCars
	void setNumberOfCars(int numberOfCars); //Declare set protoype for NumberOfCars

	friend ostream & operator << (ostream & out, Dealer & _dealer){ // This is the header of the overload function
		// Print the dealer name, number, and number of cars and then a blank line for a specific dealer.
		out << _dealer.getDealerName() << endl;
		out << _dealer.getDealerNumber() << endl;
		out << _dealer.getNumberOfCars() << endl << endl;
		return out; // return out to the overload operator
	} // End of overload function
}; // Close class Dealer

class Car { // Start of the Car class defintion
private: // Delcare private method prototypes
	string vin, make, model;	// Declare variable string vin, make, and model
	int year;					// Declare variable int year
	double price;				// Declare variable double price
public: // Delcare public method prototypes
	Car(); // Declare the default constructor
	Car(string _vin, string _make, string _model, int _year, double _price);  // Declare the constructor

	string getVIN(); //Declare get protoype for getVIN
	void setVIN(string _VIN); //Declare set protoype for setVIN

	string getMake(); //Declare get protoype for getMake
	void setMake(string _make); //Declare set protoype for setMake

	string getModel(); //Declare get protoype for getModel
	void setModel(string _VIN); //Declare set protoype for setModel

	int getYear(); //Declare get protoype for getYear
	void setYear(int _year); //Declare set protoype for setYear

	double getPrice(); //Declare get protoype for getPrice
	void setPrice(double _price); //Declare set protoype for setPrice

	friend ostream & operator << (ostream & out, Car c){ // This is the header of the overload function (haven't gotten to overload function yet in class)
		// Print out VIN, Make, Model, Year, Price and Blank line for a specific car.
		out << c.getVIN() << endl;
		out << c.getMake() << endl;
		out << c.getModel() << endl;
		out << c.getYear() << endl;
		out << c.getPrice() << endl << endl;
		return out; // return out to the overload operator
	} // End of overload function
}; // Close class Car

#endif
