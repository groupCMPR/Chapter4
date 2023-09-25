//Names: Angie Campos & Vivian Huynh
//Date: 9/22/2023
//Description: Header File for the class of ComplexNumbers

#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class ComplexNumbers
{
private:
	double realNumber;
	double imaginaryNumber;

public:
	//CONSTRUCTORS
	ComplexNumbers(); //Default
	ComplexNumbers(const ComplexNumbers&); //Copy

	//ACCESSORS
	double getRealNumber() const;
	double getImaginaryNumber() const;

	//MUTATORS
	void setRealNumber(double);
	void setImaginaryNumber(double);
	void negateComplexNumber();
	void addition(double);
	void subtraction(double);
	void multiplication(double);
	void division(double);

	//FRIEND
	friend ostream& operator<<(ostream&, const ComplexNumbers&);
};
