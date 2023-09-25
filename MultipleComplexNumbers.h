#pragma once
//------------- Vivian Huynh & Angie Campos, 9/24 ------------------------------------
// Class Pointer for Multiple Complex Numbers 
// FILE : MultipleComplexNumbers.h 
// CLASS PROVIDED : complex
#include <iostream>
#include <iomanip>

using namespace std;

class complex
{
private:
	double real;
	double imaginary;

public:
	//CONSTRUCTORS
	complex(); //Default
	complex(const complex&); // Copy
	complex(double r, double i); //for operations

	//ACCESSORS
	double getReal()const;
	double getImaginary()const;

	//MUTATORS
	void setReal(double);
	void setImaginary(double);
	void negateImaginary();

	//FRIEND
	//operator for addtion of 2 real objects
	friend complex operator +(const complex&, const complex&);
	//operator for substraction of 2 complex objects
	friend complex operator -(const complex&, const complex&);
	//operator for multiplication of 2 complex objects
	friend complex operator *(const complex&, const complex&);
	//operator for division of 2 complex objects
	friend complex operator /(const complex&, const complex&);

	//operator for multiplication with a constant
	friend complex operator*(int, const complex&);
	friend complex operator*(const complex&, int);
	//operator for division with a constant 
	friend complex operator/(int, const complex&);
	friend complex operator/(const complex&,int);

	//checks if 2 complex objects are the same value
	friend bool operator ==(const complex&, const complex&);
	//checks if 2 complex objects are NOT the same value
	friend bool operator !=(const complex&, const complex&);
	//overloaded cout << 
	friend ostream& operator <<(ostream&, const complex&);


};
