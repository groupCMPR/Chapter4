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
//Precondition : Passing in valid private members
//Postcondition: Private members are changed into negative values
void ComplexNumbers::negateComplexNumber()
{
	realNumber *= -1;
	imaginaryNumber *= -1;
}
//Precondition : Passing in constant as any double value
//Postcondition: Calculate the addition and output
void ComplexNumbers::addition(double constant)
{
	ComplexNumbers temp;

	temp.realNumber = realNumber;
	temp.imaginaryNumber = imaginaryNumber;
	temp.realNumber += constant;

	cout << "\n\tC2 + value";
	cout << "\n\t(" << realNumber << " + " << imaginaryNumber << "i) + " << constant << " = " << temp << '\n';

	cout << "\n\tvalue + C2";
	cout << "\n\t" << constant << " + (" << realNumber << " + " << imaginaryNumber << "i) = " << temp << '\n';
}
//Precondition : Passing in constant as any double value
//Postcondition: Calculate the subtraction and output
void ComplexNumbers::subtraction(double constant)
{
	ComplexNumbers temp;
	ComplexNumbers temp2;

	temp.realNumber = realNumber;
	temp.imaginaryNumber = imaginaryNumber;
	temp2.realNumber = realNumber;
	temp2.imaginaryNumber = imaginaryNumber;

	temp.realNumber = temp.realNumber - constant;
	temp2.realNumber = constant - temp2.realNumber;

	cout << "\n\tC2 - value";
	cout << "\n\t(" << realNumber << " + " << imaginaryNumber << "i) - " << constant << " = " << temp << '\n';

	cout << "\n\tvalue - C2";
	cout << "\n\t" << constant << " - (" << realNumber << " + " << imaginaryNumber << "i) = " << temp2 << '\n';
}
//Precondition : Passing in constant as any double value
//Postcondition: Calculate the multiplication and output
void ComplexNumbers::multiplication(double constant)
{
	ComplexNumbers temp;

	temp.realNumber = realNumber;
	temp.imaginaryNumber = imaginaryNumber;
	temp.realNumber *= constant;
	temp.imaginaryNumber *= constant;

	cout << "\n\tC2 * value";
	cout << "\n\t(" << realNumber << " + " << imaginaryNumber << "i) * " << constant << " = " << temp << '\n';

	cout << "\n\tvalue * C2";
	cout << "\n\t" << constant << " * (" << realNumber << " + " << imaginaryNumber << "i) = " << temp << '\n';
}
//Precondition : Passing in constant as any double value
//Postcondition: Calculate the division and output
void ComplexNumbers::division(double constant)
{
	ComplexNumbers temp;
	ComplexNumbers temp2;

	temp.realNumber = realNumber;
	temp.imaginaryNumber = imaginaryNumber;
	temp2.realNumber = realNumber;
	temp2.imaginaryNumber = imaginaryNumber;

	temp.realNumber = temp.realNumber / constant;
	temp.imaginaryNumber = temp.imaginaryNumber / constant;
	temp2.realNumber = constant / temp2.realNumber;
	temp2.imaginaryNumber = constant / temp2.imaginaryNumber;

	cout << setprecision(6);
	cout << "\n\tC2 / value";
	cout << "\n\t(" << realNumber << " + " << imaginaryNumber << "i) / " << constant << " = " << temp << '\n';

	cout << "\n\tvalue / C2";
	cout << "\n\t" << constant << " / (" << realNumber << " + " << imaginaryNumber << "i) = " << temp2 << '\n';
}

//==============================================================================
// Friend Section
//==============================================================================
//Precondition : Passing in ostream and object with valid inputs
//Postcondition: Display the complex number equation
ostream& operator<<(ostream& out, const ComplexNumbers& obj)
{
	if (obj.getImaginaryNumber() == 0)
	{
		out << obj.getRealNumber();
		return out;
	}

	if (obj.getImaginaryNumber() < 0 && obj.getImaginaryNumber() != -1)
	{
		out << obj.getRealNumber() << " - " << -obj.getImaginaryNumber() << "i";
		return out;
	}
	else if (obj.getImaginaryNumber() < 0 && obj.getImaginaryNumber() != -1)
	{
		out << obj.getRealNumber() << " - " << "i";
		return out;
	}

	if (obj.getImaginaryNumber() > 0 && obj.getImaginaryNumber() != 1)
	{
		out << obj.getRealNumber() << " + " << obj.getImaginaryNumber() << "i";
		return out;
	}
	out << obj.getRealNumber() << " + " << obj.getImaginaryNumber() << "i";
	return out;
}
