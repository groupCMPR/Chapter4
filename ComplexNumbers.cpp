//Names: Angie Campos & Vivian Huynh
//Date: 9/22/2023
//Description: cpp File for the class of ComplexNumbers

#include "ComplexNumbers.h"

//==============================================================================
// Constructors Section
//==============================================================================
//Precondition : N/A
//Postcondition: Initalize the private members into any double value
ComplexNumbers::ComplexNumbers() : realNumber(0), imaginaryNumber(0)
{}
//Precondition : Passing in valid inputs of the private members in the first object
//Postcondition: Copy the object to the new object and intialize the private members to negative values
ComplexNumbers::ComplexNumbers(const ComplexNumbers& obj)
{
	//realNumber = -1 * obj.realNumber;
	//imaginaryNumber = -1 * obj.imaginaryNumber;
	realNumber = obj.realNumber;
	imaginaryNumber = obj.imaginaryNumber;
}

//==============================================================================
// Accessors Section
//==============================================================================
//Precondition : N/A
//Postcondition: Return the private member realNumber
double ComplexNumbers::getRealNumber() const
{
	return realNumber;
}
//Precondition : N/A
//Postcondition: Return the private member imaginaryNumber
double ComplexNumbers::getImaginaryNumber() const
{
	return imaginaryNumber;
}

//==============================================================================
// Mutators Section
//==============================================================================
//Precondition : Passing newRealNumber into any double value
//Postcondition: Private member realNumber is changed
void ComplexNumbers::setRealNumber(double newRealNumber)
{
	realNumber = newRealNumber;
}
//Precondition : Passing newImaginaryNumber into any double value
//Postcondition: Private member imaginaryNumber is changed
void ComplexNumbers::setImaginaryNumber(double newImaginaryNumber)
{
	imaginaryNumber = newImaginaryNumber;
}
//Precondition : N/A
//Postcondition: Private member imaginaryNumber is changed into negative values
void ComplexNumbers::negateComplexNumber()
{
	realNumber *= -1;
	imaginaryNumber *= -1;
}

//==============================================================================
// Overloaded Operators Section
//==============================================================================
//Precondition : Passing in object with valid inputs
//Postcondition: Adding the constant and returning the changed complex number
ComplexNumbers ComplexNumbers::operator + (const ComplexNumbers& obj)
{
	ComplexNumbers temp;

	temp.realNumber = obj.realNumber;
	return temp;
}
//Precondition : Passing in object with valid inputs
//Postcondition: Subtracting the constant and returning the changed complex number
ComplexNumbers ComplexNumbers::operator - (const ComplexNumbers& obj)
{
	ComplexNumbers temp;

	return temp;
}
//Precondition : Passing in object with valid inputs
//Postcondition: Multiplying the constant and returning the changed complex number
ComplexNumbers ComplexNumbers::operator * (const ComplexNumbers& obj)
{
	ComplexNumbers temp;

	return temp;
}
//Precondition : Passing in object with valid inputs
//Postcondition: Dividing the constant and returning the changed complex number
ComplexNumbers ComplexNumbers::operator / (const ComplexNumbers& obj)
{
	ComplexNumbers temp;

	return temp;
}

//==============================================================================
// Friend Section
//==============================================================================
//Precondition : Passing in ostream and object with valid inputs
//Postcondition: Display the complex number equation
ostream& operator<<(ostream& out, const ComplexNumbers& obj)
{
	if (obj.getImaginaryNumber() < 0)
	{
		out << obj.getRealNumber() << " - " << -obj.getImaginaryNumber() << "i";
		return out;
	}
	out << obj.getRealNumber() << " + " << obj.getImaginaryNumber() << "i";
	return out;
}