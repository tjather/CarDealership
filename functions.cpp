//
// Project name : CarDealership
// Program name : functions.cpp
//
/*
	NAME: Talha Ather
	DESCRIPTION:The prupose of this program is to manage cars in diffrent dealerships.
				The program can read a list of dealers and cars from a file, display thoses dealers, choose a dealer, display and add cars, and then write the entire list to a new file.
				This file contains the the function definitions and algorithms for Programming Assignment 3.
	STATUS: Fully running and functioning program with no issues.
	IDE: Created using Microsoft Visual Studio 2017.
*/
// Section function.cpp

//#include "pch.h"	// Needed for compilation to succeed in Visual Studio 2017
#include "functions.h"
#include "Dealer.h"

using namespace std;

void readDealers(ifstream &infile, vector<Dealer> &carDealers){ // Start of the readDealers function
	string name;				// Declare space in memory for a string variable called name
	int dealerNum, numOfCars;	// Declare space in memory for a int variable called dealerNum and numOfCars
	string vin, make, model;	// Declare space in memory for a string varible called vin, make, and model
	int year;					// Declare space in memory for a int variable called year
	double price;				// Declare space in memory for a double variable called price
	
	Dealer objDealer; // Declare Dealer objDealer which will be filled and then pusshed into the vector
	
	infile.open("in.txt");	// Open in.txt
	
	cout << "Now opening in.txt. Press any key to continue:" << endl; // Display a message on the screen that says, "Now opening in.txt. Press any key to continue:"
	cin.get();		 // Wait for the user to press any key
	
	if (!infile.is_open()) {
		cout << "Unable to open in.txt" << endl; // Display a message on the screen that says, "Unable to open in.txt"
	} 
	else {
		while (!infile.eof()) { // Start of the scope of a while loop to read from the beginning of the file to the end of the file
			getline(infile, name);			// Read line 1 and assign it to string name
			objDealer.setDealerName(name);	// Call void setDealerName(with value name)		

			infile >> dealerNum;					// Read line 2 and assign it to int dealerNum
			infile.ignore();						// Ignore the newline
			objDealer.setDealerNumber(dealerNum);	// Call void setDealerNumber(with value number)

			infile >> numOfCars;					// Read line 3 and assign it to carNum
			infile.ignore();						// Ignore the newline
			objDealer.setNumberOfCars(numOfCars);	// Call void setNumberOfCars(with value carNum)

			objDealer.carArrayPtr = new Car[numOfCars];	// Assign dynamic array carArrayPtr a size of numOfCars

			for(int i = 0; i < numOfCars; i++){	// Start of a for loop that reads the all the cars that a dealer has
				getline(infile, vin);					// Read the whole next line and assign it to vin
				objDealer.carArrayPtr[i].setVIN(vin);	// Call void setVIN(with value vin)
				
				getline(infile, make);					// Read the whole next line and assign it to make
				objDealer.carArrayPtr[i].setMake(make);	// Call void setMake(with value make)

				getline(infile, model);						// Read the whole next line and assign it to model	
				objDealer.carArrayPtr[i].setModel(model);	// Call void setModel(with value model)

				infile >> year;							// Read the whole next line and assign it to year
				infile.ignore();						// Ignore the newline
				objDealer.carArrayPtr[i].setYear(year);	// Call void setYear(with value year)

				infile >> price;							// Read the whole next line and assign it to price
				infile.ignore();							// Ignore the newline
				objDealer.carArrayPtr[i].setPrice(price);	// Call void setPrice(with value price)
			} //  End of the for scope
			carDealers.push_back(objDealer); // Add the completed objDealer into the vector
		} // End of the while statment
		cout << "Dealer information has been sucessfully obtained." << endl << endl; // Display a message on the screen that says, "Dealer information has been sucessfully obtained." 
	}//End of the else stament
	
	infile.close(); // Close in.txt
} // End of the readDealers function

void displayDealers(vector<Dealer> &carDealers){ // Start of the displayDealers function
	cout << "The dealer names, dealer numbers, and ammount of cars they each have are:" << endl; // Display a message on the screen that says, "The dealers and their associated numbers are:"
	for (int i = 0; i < carDealers.size(); i++) { // Start of a for loop to display the dealer name and number for each dealer
		cout << carDealers[i]; // Display a message on the screen that reads all the dealer information using the overloaded operator <<
	} // End of the for scope
} // End of the displayDealers function

void displayCars(vector<Dealer> &carDealers){ // Start of the displayCars function
	int dealerChoice;	// Declare space in memory for the users choice
	int dealerIndex;	// Declare space in memory for int delaerIndex

	displayDealers(carDealers); // Call the displayDealers function to display the Dealer Names and Numbers
	
	cout << "Please choose a dealer number that you would like to view." << endl; // Display a message on the screen that says "Please choose a dealer number that you would like to view."
	cin >> dealerChoice; // Wait for the user to enter a response then store it in int dealerChoice

	dealerIndex = linearSearchDealer(carDealers, dealerChoice);	//Search the vector for the value entered by the user then store the location in variable dealerIndex 

	if(dealerIndex == -1){ // Start of the if stament to see if the dealer is found
		cout << "That is an invalid dealer number." << endl << endl; // Display a message on the screent that says "That is an invalid dealer number."
	} // End of the if statment
	else{ // Start of the else statment 
		cout << "Dealer number " << dealerChoice << " has the following cars:" << endl; // Display a message on the screen that says "Dealer number " the choice of the user " has the following cars:"

		for (int i = 0; i < carDealers[dealerIndex].getNumberOfCars(); i++) { // Start of a for loop to display the cars that a dealer owns
			cout << carDealers[dealerIndex].carArrayPtr[i]; // Display a message on the screen that reads all the car infomation using the overloaded operator <<
		} // End of the for scope
	} // End of the else scope
} // End of the displayCars function

void addCar(vector<Dealer> &carDealers){ // Start of the addCar function
	int dealerChoice;	// Declare space in memory for the users choice
	int dealerIndex;	// Declare space in memory for int delaerIndex
	int newCarSize;		// Declare space in memory for int newCarSize

	string newVin, newMake, newModel;	// Declare space in memory for a string varible called newVin, newMake, and newModel
	int newYear;						// Declare space in memory for a int variable called newYear
	double newPrice;					// Declare space in memory for a double variable called newPrice
	
	displayDealers(carDealers); // Call the displayDealers function to display the Dealer Names and Numbers

	cout << "Please choose a dealer number that you would like to view." << endl; // Display a message on the screen that says "Please choose a dealer number that you would like to view."
	
	cin >> dealerChoice; // Wait for the user to enter a response then store it in int dealerChoice
	cin.ignore();		 // Ignore the newline after the user enters their choice
	
	dealerIndex = linearSearchDealer(carDealers, dealerChoice);	//Search the vector for the value entered by the user then store the location in variable dealerIndex 

	if (dealerIndex == -1) { // Start of the if stament to see if the dealer is found
		cout << "That is an invalid dealer number." << endl << endl; // Display a message on the screent that says "That is an invalid dealer number."
	} // End of the if statment
	else { // Start of the else statment 
		Car *newCarArrayPtr = nullptr;	// Set the temp dynamic array to nullptr

		newCarSize = carDealers[dealerIndex].getNumberOfCars() + 1; // Set the new size equal to one more than the old size

		carDealers[dealerIndex].newCarArrayPtr = new Car[newCarSize]; // Assign dynamic array newCarArrayPtr a size of int newCarSize

		for (int index = 0; index < carDealers[dealerIndex].getNumberOfCars(); index++) { // Start of the for loop to copy the old array into the new array
			carDealers[dealerIndex].newCarArrayPtr[index].setVIN(carDealers[dealerIndex].carArrayPtr[index].getVIN());		// Set the vin at index newCarArrayPtr equal to the vin at index carArrayPtr
			carDealers[dealerIndex].newCarArrayPtr[index].setMake(carDealers[dealerIndex].carArrayPtr[index].getMake());	// Set the make at index newCarArrayPtr equal to the make at index carArrayPtr
			carDealers[dealerIndex].newCarArrayPtr[index].setModel(carDealers[dealerIndex].carArrayPtr[index].getModel());	// Set the model at index newCarArrayPtr equal to the model at index carArrayPtr
			carDealers[dealerIndex].newCarArrayPtr[index].setYear(carDealers[dealerIndex].carArrayPtr[index].getYear());	// Set the year at index newCarArrayPtr equal to the year at index carArrayPtr
			carDealers[dealerIndex].newCarArrayPtr[index].setPrice(carDealers[dealerIndex].carArrayPtr[index].getPrice());	// Set the price at index newCarArrayPtr equal to the price at index carArrayPtr
		} // End of the for scope

		delete[] carDealers[dealerIndex].carArrayPtr; // Free the dynamically allocated memory

		carDealers[dealerIndex].carArrayPtr = carDealers[dealerIndex].newCarArrayPtr; // Make carArrayPtr point to newCarArrayPtr

		cout << "Please enter the information for the new car." << endl; // Display a message on the screen that says "Please enter the information for the new car."

		cout << "Please enter the new car's VIN" << endl;					// Display a message on the screen that says "Please enter the new car's VIN"
		getline(cin, newVin);												// Read the users whole input including spaces and assign it to newVin	
		carDealers[dealerIndex].carArrayPtr[newCarSize - 1].setVIN(newVin); // Set the vin at the last position of the array to the users input

		cout << "Please enter the new car's make" << endl;						// Display a message on the screen that says "Please enter the new car's make"
		getline(cin, newMake);													// Read the users whole input including spaces and assign it to newMake	
		carDealers[dealerIndex].carArrayPtr[newCarSize - 1].setMake(newMake);	// Set the make at the last position of the array to the users input
		
		cout << "Please enter the new car's model" << endl;						// Display a message on the screen that says "Please enter the new car's model"
		getline(cin, newModel);													//  Read the users whole input including spaces and assign it to newModel	
		carDealers[dealerIndex].carArrayPtr[newCarSize - 1].setModel(newModel);	// Set the model at the last position of the array to the users input

		cout << "Please enter the new car's year" << endl;						// Display a message on the screen that says "Please enter the new car's year"
		cin >> newYear;															// Read the users input and assign it to newYear
		carDealers[dealerIndex].carArrayPtr[newCarSize - 1].setYear(newYear);	// Set the year at the last position of the array to the users input

		cout << "Please enter the new car's price" << endl;						// Display a message on the screen that says "Please enter the new car's price"
		cin >> newPrice;														// Read the users input and assign it to newPrice
		carDealers[dealerIndex].carArrayPtr[newCarSize - 1].setPrice(newPrice);	// Set the price at the last position of the array to the users input

		carDealers[dealerIndex].setNumberOfCars(newCarSize); //Once the new car has been updated, set the number of cars equal to int newCarSize

		cout << "The new car has been added." << endl; // Display a message on the screen that says "The new car has been added."

		cout << "Dealer number " << dealerChoice << " now has the following cars:" << endl; // Display a message on the screen that says "Dealer number " the choice of the user " now has the following cars:"

		for (int i = 0; i < carDealers[dealerIndex].getNumberOfCars(); i++) { // Start of a for loop to display the cars that a dealer owns
			cout << carDealers[dealerIndex].carArrayPtr[i]; // Display a message on the screen that reads all the car infomation using the overloaded operator <<
		} // End of the for scope
	} // End of the else scope
} // End of the addCar function

void modifyCar(vector<Dealer> &carDealers) {  // Start of the modifyCar function
	string carChoice;	// Declare space in memory for the users choice
	int carIndex;		// Declare space in memory for int carIndex
	int numOfCar;		// Declare space in memory for int numOfCar

	int dealerChoice;	// Declare space in memory for the users choice
	int dealerIndex;	// Declare space in memory for int delaerIndex

	string newVin, newMake, newModel;	// Declare space in memory for a string varible called newVin, newMake, and newModel
	int newYear;						// Declare space in memory for a int variable called newYear
	double newPrice;					// Declare space in memory for a double variable called newPrice

	displayDealers(carDealers); // Call the displayDealers function to display the Dealer Names and Numbers

	cout << "Please choose a dealer number that you would like to view." << endl; // Display a message on the screen that says "Please choose a dealer number that you would like to view."
	cin >> dealerChoice; // Wait for the user to enter a response then store it in int dealerChoice

	dealerIndex = linearSearchDealer(carDealers, dealerChoice);	//Search the vector for the value entered by the user then store the location in variable dealerIndex 

	if (dealerIndex == -1) { // Start of the if stament to see if the dealer is found
		cout << "That is an invalid dealer number." << endl << endl; // Display a message on the screent that says "That is an invalid dealer number."
	} // End of the if statment
	else { // Start of the else statment 
		cout << "Dealer number " << dealerChoice << " has the following cars:" << endl; // Display a message on the screen that says "Dealer number " the choice of the user " has the following cars:"

		for (int i = 0; i < carDealers[dealerIndex].getNumberOfCars(); i++) { // Start of a for loop to display the cars that a dealer owns
			cout << carDealers[dealerIndex].carArrayPtr[i]; // Display a message on the screen that reads all the car infomation using the overloaded operator <<
		} // End of the for scope

		numOfCar = carDealers[dealerIndex].getNumberOfCars(); // Set int numOfCar equal to the number of cars in the vector at index dealerIndex

		cout << "Which car would you like to update? Please enter the VIN. (VIN's are case sensitive)" << endl; // Display a message on the screen that says, "Which car would you like to update?"

		cin >> carChoice;	// Wait for the user to enter a response then store it in int dealerChoice
		cin.ignore();		// Ignore the newline after the user enters their choice

		carIndex = linearSearchCar(carDealers[dealerIndex].carArrayPtr, carChoice, numOfCar); // Search the array for the value entered by the user then store the location in variable carIndex 

		if (carIndex == -1) { // Start of the if stament to see if the car is found
			cout << "That is an invalid VIN." << endl; // Display a message on the screent that says "That is an invalid dealer number."
		} // End of the if statment
		else { // Start of the else statment 
			cout << "Please enter the updated information for the car." << endl; // Display a message on the screen that says "Please enter the updated information for the car."

			cout << "Please enter the car's updated VIN" << endl;			// Display a message on the screen that says "Please enter the car's updated VIN"
			getline(cin, newVin);											// Read the users whole input including spaces and assign it to newVin	
			carDealers[dealerIndex].carArrayPtr[carIndex].setVIN(newVin);	// Set the vin at carIndex to the users input

			cout << "Please enter the car's updated make" << endl;			// Display a message on the screen that says "Please enter the car's updated make"
			getline(cin, newMake);											// Read the users whole input including spaces and assign it to newMake	
			carDealers[dealerIndex].carArrayPtr[carIndex].setMake(newMake);	// Set the make at carIndex to the users input

			cout << "Please enter the car's updated model" << endl;				// Display a message on the screen that says "Please enter the car's updated model"
			getline(cin, newModel);												// Read the users whole input including spaces and assign it to newModel	
			carDealers[dealerIndex].carArrayPtr[carIndex].setModel(newModel);	// Set the model at carIndex to the users input

			cout << "Please enter the car's updated year" << endl;			// Display a message on the screen that says "Please enter the car's updated year"
			cin >> newYear;													// Read the users input and assign it to newYear
			carDealers[dealerIndex].carArrayPtr[carIndex].setYear(newYear);	// Set the year at carIndex to the users input

			cout << "Please enter the car's updated price" << endl;				// Display a message on the screen that says "Please enter the car's updated price"
			cin >> newPrice;													// Read the users input and assign it to newPrice
			carDealers[dealerIndex].carArrayPtr[carIndex].setPrice(newPrice);	// Set the year at carIndex to the users input

			cout << "The car's information has been successfully updated." << endl; // Display a message on the screen that says "The car's information has been successfully updated."

			cout << "Dealer number " << dealerChoice << " now has the following cars:" << endl; // Display a message on the screen that says "Dealer number " the choice of the user " now has the following cars:"

			for (int i = 0; i < carDealers[dealerIndex].getNumberOfCars(); i++) { // Start of a for loop to display the cars that a dealer owns
				cout << carDealers[dealerIndex].carArrayPtr[i]; // Display a message on the screen that reads all the car infomation using the overloaded operator <<
			} // End of the for scope
		} // End of the else scope
	} // End of the else scope
}// End of the modifyCar function

void sortDealerCars(vector<Dealer> &carDealers) { // Start of the sortDealerCars function
	int dealerChoice;	// Declare space in memory for the users choice
	int dealerIndex;	// Declare space in memory for int delaerIndex
	int numOfCar;		// Declare space in memory for int numOfCar

	displayDealers(carDealers); // Call the displayDealers function to display the Dealer Names and Numbers

	cout << "Please choose a dealer number that you would like to view and sort the cars for." << endl; // Display a message on the screen that says "Please choose a dealer number that you would like to view."
	cin >> dealerChoice; // Wait for the user to enter a response then store it in int dealerChoice

	dealerIndex = linearSearchDealer(carDealers, dealerChoice);	//Search the vector for the value entered by the user then store the location in variable dealerIndex 

	if (dealerIndex == -1) { // Start of the if stament to see if the dealer is found
		cout << "That is an invalid dealer number." << endl << endl; // Display a message on the screent that says "That is an invalid dealer number."
	} // End of the if statment
	else { // Start of the else statment 
		numOfCar = carDealers[dealerIndex].getNumberOfCars(); // Set int numOfCar equal to the number of cars in the vector at index dealerIndex

		bubblesortCar(carDealers[dealerIndex].carArrayPtr, numOfCar); // Search the array for the value entered by the user then store the location in variable carIndex 
		
		cout << "The dealer cars have been successfully sorted." << endl; // Display a message on the screen that says "The dealer cars have been successfully sorted."

		cout << "Dealer number " << dealerChoice << " has the following cars:" << endl; // Display a message on the screen that says "Dealer number " the choice of the user " has the following cars:"

		for (int i = 0; i < carDealers[dealerIndex].getNumberOfCars(); i++) { // Start of a for loop to display the cars that a dealer owns
			cout << carDealers[dealerIndex].carArrayPtr[i]; // Display a message on the screen that reads all the car infomation using the overloaded operator <<
		} // End of the for scope
	} // End of the else scope							
} // End of the sortDealerCars function

void writeDealers(ofstream &outfile, vector<Dealer> &carDealers){ // Start of the writeDealers function
	outfile.open("out.txt"); // Create and open out.txt

	cout << "Now creating out.txt and writing dealership information. Press any key to continue:" << endl; // Display a message on the screen that says, "Now creating out.txt. Press any key to continue:"
	cin.get(); // Wait for the user to press any key

	for (int i = 0; i < carDealers.size(); i++) { // Start of a for loop to read the every dealer
		outfile << carDealers[i].getDealerName() << endl	// Write the dealer name at position i 
			<< carDealers[i].getDealerNumber() << endl		// Write the dealer number at position i 
			<< carDealers[i].getNumberOfCars() << endl;		// Write the number of cars for dealer i
		for (int j = 0; j < carDealers[i].getNumberOfCars(); j++) { // Start of a for loop to read the every car that a dealer has
			outfile << carDealers[i].carArrayPtr[j].getVIN() << endl // Write out the VIN for the car in position j in dealer i
				<< carDealers[i].carArrayPtr[j].getMake() << endl	 // Write out the make of the car in position j in dealer i
				<< carDealers[i].carArrayPtr[j].getModel() << endl	 // Write out the model of the car in position j in dealer i
				<< carDealers[i].carArrayPtr[j].getYear() << endl	 // Write out the year of the car in position j in dealer i
				<< carDealers[i].carArrayPtr[j].getPrice() << endl;	 // Write out the price of the car in position j in dealer i
		} // End of the for scope								
	} // End of the for scope
	outfile.close(); //		Close out.txt
	cout << "out.txt has been created." << endl << endl;
} // End of the writeDealers function

void bubblesortCar(Car *carArrayPtr, int size) { // Start of the bubblesortCar function
	bool swap;	// Declare bool swap 
	Car temp;	// Declare Car temp
	do { 
		swap = false; // Initizalize swap with false
		for (int count = 0; count < (size - 1); count++) { 
			if (carArrayPtr[count].getVIN() > carArrayPtr[count + 1].getVIN()) {
				temp = carArrayPtr[count];
				carArrayPtr[count] = carArrayPtr[count + 1];
				carArrayPtr[count + 1] = temp; 
				swap = true;
			} 
		} 
	} while (swap);
} // End of the bubblesortCar function

int linearSearchDealer(vector <Dealer> &carDealers, int dealerNumber){ // Start of the linearSearchDealer function
	int index = 0;       // Declare int index and intialize it with 0
	int position = -1;   // Declare int position and intizlie it with -1
	bool found = false;  // Declare bool found to indicate if the value is found

	while (index < carDealers.size() && !found) { // Start of the while loop that searches for the users choice
		if (carDealers[index].getDealerNumber() == dealerNumber) { // Start of the if statment that confirms the dealer was found
			found = true;		// Set bool found to true
			position = index;	// Assign position with the index of the dealer
		} // End of the if statment
		index++; // Add one to the index
	} // End of the while scope
	
	return position; // Return int position to the function
} // End of the linearSearchDealer function

int linearSearchCar(Car *carArrayPtr, string carVin, int size) { // Start of the linearSearchCar function
	int index = 0;       // Declare int index and intialize it with 0
	int position = -1;   // Declare int position and intizlie it with -1
	bool found = false;  // Declare bool found to indicate if the value is found
	while (index < size && !found) {
		if (carArrayPtr->getVIN() == carVin) { // Start of the if statment that confirms the dealer was found
			found = true;		// Set bool found to true
			position = index;	// Assign position with the index of the dealer
		} // End of the if statment
		index++; // Add one to the index
	}

	return position; // Return int position to the function
} // End of the linearSearchCar function
