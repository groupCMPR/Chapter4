//Names: Angie Campos & Vivian Huynh
//Date: 9/22/2023
//Description: cpp File for the class of ComplexNumbers (Chapter 4)

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
	realNumber = obj.realNumber;
	imaginaryNumber = obj.imaginaryNumber;
}
//Precondition : Passing values 
//Postcondition: Copy object to a new object and initialize for each complex
ComplexNumbers::ComplexNumbers(double newRealNumber, double newImaginaryNumber)
{
	realNumber = newRealNumber;
	imaginaryNumber = newImaginaryNumber;
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
	ComplexNumbers temp; //Contains the temporary object

	//Set values into temp object
	temp.realNumber = realNumber;
	temp.imaginaryNumber = imaginaryNumber;

	//Calculation (+)
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
	//Contains the temorary objects
	ComplexNumbers temp;
	ComplexNumbers temp2;

	//Set values into the temporary objects
	temp.realNumber = realNumber;
	temp.imaginaryNumber = imaginaryNumber;
	temp2.realNumber = realNumber;
	temp2.imaginaryNumber = imaginaryNumber;

	//Calculate (-)
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
	ComplexNumbers temp; //Contain the temporary object

	//Set the values into the temporary object
	temp.realNumber = realNumber;
	temp.imaginaryNumber = imaginaryNumber;

	//Calculate (*)
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
	//Contain the temporary objects
	ComplexNumbers temp;
	ComplexNumbers temp2;

	//Set the values into the temporary objects
	temp.realNumber = realNumber;
	temp.imaginaryNumber = imaginaryNumber;
	temp2.realNumber = realNumber;
	temp2.imaginaryNumber = imaginaryNumber;

	//Calculate (/)
	temp.realNumber = temp.realNumber / constant;
	temp.imaginaryNumber = temp.imaginaryNumber / constant;
	temp2.realNumber = constant / temp2.realNumber;
	temp2.imaginaryNumber = constant / temp2.imaginaryNumber;

	cout << setprecision(6); //Stops any decimal from going any futher than 6 decimal values
	cout << "\n\tC2 / value";
	cout << "\n\t(" << realNumber << " + " << imaginaryNumber << "i) / " << constant << " = " << temp << '\n';

	cout << "\n\tvalue / C2";
	cout << "\n\t" << constant << " / (" << realNumber << " + " << imaginaryNumber << "i) = " << temp2 << '\n';
}

//==============================================================================
// Friends Section
//==============================================================================
//Precondition : Two complex numbers are needed
//Postcondition : allows addition between the two complex numbers
ComplexNumbers operator +(const ComplexNumbers& c1, const ComplexNumbers& c2)
{
	return ComplexNumbers(c1.realNumber + c2.realNumber, c1.imaginaryNumber + c2.imaginaryNumber);
}
//Precondition : Two complex numbers are needed
//Postcondition : allows subtraction between the two complex numbers
ComplexNumbers operator -(const ComplexNumbers& c1, const ComplexNumbers& c2)
{
	return ComplexNumbers(c1.realNumber - c2.realNumber, c1.imaginaryNumber - c2.imaginaryNumber);
}
//Precondition : Two complex numbers are needed
//Postcondition : allows multiplication between the two complex numbers
ComplexNumbers operator *(const ComplexNumbers& c1, const ComplexNumbers& c2)
{
	double v1 = c1.realNumber * c2.realNumber;
	double v2 = (c1.realNumber * c2.imaginaryNumber) + (c1.imaginaryNumber * c2.realNumber);
	double v3 = c1.imaginaryNumber * c2.imaginaryNumber * (-1);

	double real3 = v1 + v3;
	double imaginary3 = v2;

	return ComplexNumbers(real3, imaginary3);
}
//Precondition : Two complex numbers are needed
//Postcondition : allows division between the two complex numbers
ComplexNumbers operator /(const ComplexNumbers& c1, const ComplexNumbers& c2)
{
	//numerator
	double v1 = c1.realNumber * c2.realNumber;
	double v2 = (c1.realNumber * c2.imaginaryNumber * -1) + (c1.imaginaryNumber * c2.realNumber);
	double v3 = c1.imaginaryNumber * c2.imaginaryNumber;

	//denominator
	double v4 = pow(c2.realNumber, 2) + pow(c2.imaginaryNumber, 2);

	double real3 = (v1 + v3) / v4;
	double imaginary3 = v2 / v4;


	return ComplexNumbers(real3, imaginary3);
}
//Precondition : An int and a complex number 
//Postcondition : allows multiplication between an integer number and a complex number
ComplexNumbers operator *(int num, const ComplexNumbers& c)
{
	double newReal = c.getRealNumber() * num;
	double newImaginary = c.getImaginaryNumber() * num;

	return ComplexNumbers(newReal, newImaginary);
}
//Precondition : A complex number and an int 
//Postcondition : allows multiplication between a complex number and an integer number
ComplexNumbers operator *(const ComplexNumbers& c, int num)
{
	double newReal = c.getRealNumber() * num;
	double newImaginary = c.getImaginaryNumber() * num;

	return ComplexNumbers(newReal, newImaginary);
}
//Precondition : A complex number and a int 
//Postcondition : allows division between a complex number and a integer number
ComplexNumbers operator /(int num, const ComplexNumbers& c)
{
	double newReal = num / c.getRealNumber();
	double newImaginary = num / c.getImaginaryNumber();

	return ComplexNumbers(newReal, newImaginary);
}
//Precondition : A complex number and a int 
//Postcondition : allows division between a complex number and a integer number
ComplexNumbers operator /(const ComplexNumbers& c, int num)
{
	double newReal = c.getRealNumber() / num;
	double newImaginary = c.getImaginaryNumber() / num;

	return ComplexNumbers(newReal, newImaginary);
}
//Precondition : Two complex numbers are needed
//Postcondition : Checks if both complex numbers are the same
bool operator ==(const ComplexNumbers& c1, const ComplexNumbers& c2)
{
	return (c1.realNumber && c1.imaginaryNumber) == (c2.realNumber && c2.imaginaryNumber);
	//OR do this 
	//return (c1 == c2);
}
//Precondition : Two complex numbers are needed
//Postcondition : Checks if both complex numbers are NOT the same
bool operator !=(const ComplexNumbers& c1, const ComplexNumbers& c2)
{
	return !(c2 == c1);
}
//Precondition : Passing in ostream and object with valid inputs
//Postcondition: Display the complex number equation
ostream& operator<<(ostream& out, const ComplexNumbers& obj)
{
	if (obj.getRealNumber() == 0 && obj.getImaginaryNumber() == 0)
	{
		out << "0";
		return out;
	}
	if (obj.getImaginaryNumber() == 0)
	{
		out << obj.getRealNumber();
		return out;
	}
	if (obj.getRealNumber() == 0)
	{
		out << obj.getImaginaryNumber() << "i";
		return out;
	}

	if (obj.getImaginaryNumber() < 0 && obj.getImaginaryNumber() != -1)
	{
		out << obj.getRealNumber() << " - " << -obj.getImaginaryNumber() << "i";
		return out;
	}
	else if (obj.getImaginaryNumber() < 0 && obj.getImaginaryNumber() == -1)
	{
		out << obj.getRealNumber() << " - " << "i";
		return out;
	}

	if (obj.getImaginaryNumber() > 0 && obj.getImaginaryNumber() == 1)
	{
		out << obj.getRealNumber() << " + " << "i";
		return out;
	}
	out << obj.getRealNumber() << " + " << obj.getImaginaryNumber() << "i";
	return out;
}
