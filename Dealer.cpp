//
// Project name : Programming Assignment 3
// Program name : dealer.cpp
//
/*
	NAME: Talha Ather
	CLASS: CSCI 1410
	DESCRIPTION:The prupose of this program is to manage cars in diffrent dealerships.
				The program can read a list of dealers and cars from a file, display thoses dealers, choose a dealer, display and add cars, and then write the entire list to a new file.
				This file contains the Dealer and Car class member definitions for Programming Assignment 3.
	STATUS: Fully running and functioning program with no issues.
	IDE: Created using Microsoft Visual Studio 2017.
*/
// Section Dealer.cpp

//#include "pch.h"	// Needed for compilation to succeed in Visual Studio 2017
#include "Dealer.h"

Dealer::Dealer(){
	this->dealerName = "";			// Set string dealerName to blank
	this->dealerNumber = 0;			// Set int dealerNumber to 0
	this->numberOfCars = 0;			// Set int numberOfCars to 0
	Car *carArrayPtr = nullptr;		// Set the dynamic array to nullptr
}

Dealer::Dealer(string & _dealerName, int _dealerNumber){
	dealerName = _dealerName; // set var dealerName equal to var _dealerName
	dealerNumber = _dealerNumber; //set var dealerNumber equal to var _dealerNumber
}

string Dealer::getDealerName(){
	return dealerName;	// return the dealerName
}

void Dealer::setDealerName(string dealerName){
	this->dealerName = dealerName; // set private var dealerName equal to var dealerName
}

int Dealer::getDealerNumber(){
	return dealerNumber; // return the dealerNumber
}

void Dealer::setDealerNumber(int dealerNumber){
	this->dealerNumber = dealerNumber; // set private var dealerNumber equal to var dealerNumber
}

int  Dealer::getNumberOfCars(){
	return numberOfCars; // return the NumberOfCars
}

void  Dealer::setNumberOfCars(int numberOfCars){
	this->numberOfCars = numberOfCars; // set private var numberOfCars equal to var numberOfCars
}

Car::Car(){
	this->vin = "";		// Set string vin to blank
	this->make = "";	// Set string make to blank
	this->model = "";	// Set string model to blank
	this->year = 0;		// Set int year to 0
	this->price = 0;	// Set double price to 0
}

Car::Car(string _vin, string _make, string _model, int _year, double _price){
	vin = _vin;		// set var vin equal to var _VIN
	make = _make;	// set var make equal to var _make	
	model = _model;	// set var model equal to var _model	
	year = _year;	// set var year equal to var _year	
	price = _price;	// set var price equal to var _price	
}

string Car::getVIN(){
	return vin; // return the VIN
} 

void Car::setVIN(string _VIN){
	vin = _VIN;	// set var vin equal to var _VIN
} 

string Car::getMake(){
	return make; // return the make
} 

void Car::setMake(string _make){
	make = _make;// set var make equal to var _make	
}  

string Car::getModel(){
	return model; // return the model
}  

void Car::setModel(string _model){
	model = _model;// set var model equal to var _model	
} 

int Car::getYear(){
	return year; // return the year
}  

void Car::setYear(int _year){
	year = _year;// set var year equal to var _year	
}  

double Car::getPrice(){
	return price; // return the price
}  

void Car::setPrice(double _price){
	price = _price;// set var price equal to var _price	
}
