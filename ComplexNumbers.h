//Names: Angie Campos & Vivian Huynh
//Date: 9/22/2023
//Description: Header File for the class of ComplexNumbers (Chapter 4)

#pragma once
#include <iostream> //For cout
#include <iomanip>  //For setprecision
using namespace std;

class ComplexNumbers
{
private:
	double realNumber;      //To contain the real number
	double imaginaryNumber; //To contain the imaginary number

public:
	//CONSTRUCTORS
	ComplexNumbers(); //Default
	ComplexNumbers(const ComplexNumbers&); //Copy
	ComplexNumbers(double, double); //Argument

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

	//FRIENDS
	//operator for addtion of 2 real objects
	friend ComplexNumbers operator +(const ComplexNumbers&, const ComplexNumbers&);
	//operator for substraction of 2 complex objects
	friend ComplexNumbers operator -(const ComplexNumbers&, const ComplexNumbers&);
	//operator for multiplication of 2 complex objects
	friend ComplexNumbers operator *(const ComplexNumbers&, const ComplexNumbers&);
	//operator for division of 2 complex objects
	friend ComplexNumbers operator /(const ComplexNumbers&, const ComplexNumbers&);

	//operator for multiplication with a constant
	friend ComplexNumbers operator*(int, const ComplexNumbers&);
	friend ComplexNumbers operator*(const ComplexNumbers&, int);
	//operator for division with a constant 
	friend ComplexNumbers operator/(int, const ComplexNumbers&);
	friend ComplexNumbers operator/(const ComplexNumbers&, int);

	//checks if 2 complex objects are the same value
	friend bool operator ==(const ComplexNumbers&, const ComplexNumbers&);
	//checks if 2 complex objects are NOT the same value
	friend bool operator !=(const ComplexNumbers&, const ComplexNumbers&);
	//overloaded cout << 
	friend ostream& operator<<(ostream&, const ComplexNumbers&);
};
