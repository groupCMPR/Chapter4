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

	//OVERLOADED OPERATORS
	ComplexNumbers operator + (const ComplexNumbers&); //Addition
	ComplexNumbers operator - (const ComplexNumbers&); //Subtraction
	ComplexNumbers operator * (const ComplexNumbers&); //Multiplication
	ComplexNumbers operator / (const ComplexNumbers&); //Division

	//FRIEND
	friend ostream& operator<<(ostream&, const ComplexNumbers&);
};

