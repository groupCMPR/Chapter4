//----------------------- Vivian Huynh & Angie Campos, 9/24 -----------------------------------
#include <iostream>
//#include <cmath>
#include "MultipleComplexNumbers.h"

using namespace std;

//CONSTRUCTORS 
//--------------------------------------------------------------------------------------------------
//Precondition : N/A
//Postcondition : Initalize the private members into any double value
complex::complex():real(0),imaginary(0){}

//Precondition : Passing values 
//Postcondition : Copy object to a new object and initialize 
complex::complex(const complex& num)
{
	real = num.real;
	imaginary = num.imaginary;

}

//Precondition : Passing values 
//Postcondition : Copy object to a new object and initialize for each complex
complex::complex(double r, double i)
{
	real = r;
	imaginary = i;
}


//ACCESSORS 
//----------------------------------------------------------------------------------------------
//Precondition : N/A
//Postcondition : Return the private member real
double complex::getReal()const
{
	return real;
}

//Precondition : N/A
//Postcondition : Return the private member imaginary
double complex::getImaginary()const
{
	return imaginary;
}

//MUTATORS 
//---------------------------------------------------------------------------------------------
//Precondition : Passing a newReal1 on to any double value
//Postcondition : Private member real1 is changed 
void complex::setReal(double newReal)							//Might have to reSet the sets
{
	real = newReal;
}

//Precondition : Passing a newImaginary1 on to any double value
//Postcondition : Private member imaginary1 is changed 
void complex::setImaginary(double newImaginary)
{
	imaginary = newImaginary;
}

//Precondition : Passing in valid private member
//Postcondition : Private imaginary1 & imaginary2 are changed into negative values
void complex::negateImaginary()
{
	imaginary *= -1;
}

//FRIEND
// ---------------------------------------------------------------------------------------------
//Precondition : Two complex numbers are needed
//Postcondition : allows addition between the two complex numbers
complex operator +(const complex& c1, const complex& c2)
{
	return complex(c1.real + c2.real, c1.imaginary + c2.imaginary);
}

//Precondition : Two complex numbers are needed
//Postcondition : allows subtraction between the two complex numbers
complex operator -(const complex& c1, const complex& c2)
{
	return complex(c2.real-c1.real,c2.imaginary-c1.imaginary);
}

//Precondition : Two complex numbers are needed
//Postcondition : allows multiplication between the two complex numbers
complex operator *(const complex& c1, const complex& c2)
{
	double v1 = c1.real * c2.real;
	double v2 = (c1.real * c2.imaginary) + (c1.imaginary * c2.real);
	double v3 = c1.imaginary * c2.imaginary * (-1);

	double real3 = v1 + v3;
	double imaginary3 = v2;

	return complex(real3, imaginary3);
}

//Precondition : Two complex numbers are needed
//Postcondition : allows division between the two complex numbers
complex operator /(const complex& c1, const complex& c2)
{
	//numerator
	double v1 = c1.real * c2.real;
	double v2 = (c2.real * (-1) * c1.imaginary) + (c1.real * c2.imaginary);
	double v3 = (c2.imaginary * (-1) * c1.imaginary) * (-1);

	double real3 = v1 + v3;
	double imaginary3 = v2;

	//denominator

	double v4 = c2.real + (c1.imaginary * (-1) * c1.imaginary * (-1));

	return complex(real3 / v4, imaginary3 / v4);
}

//Precondition : A complex number and a int 
//Postcondition : allows multiplication between a complex number and a integer number
complex operator *(int num, const complex& c)
{
	double newReal = c.getReal() * num;
	double newImaginary = c.getImaginary() * num;

	return complex(newReal, newImaginary);
}

complex operator *(const complex& c, int num)
{
	double newReal = c.getReal() * num;
	double newImaginary = c.getImaginary() * num;

	return complex(newReal, newImaginary);
}

//Precondition : A complex number and a int 
//Postcondition : allows division between a complex number and a integer number
complex operator /(int num, const complex& c)
{
	double newReal = num / c.getReal();
	double newImaginary = num/c.getImaginary();

	return complex(newReal, newImaginary);
}

complex operator /(const complex& c, int num)
{
	double newReal = c.getReal()/num;
	double newImaginary = c.getImaginary()/num;

	return complex(newReal, newImaginary);
}

//Precondition : Two complex numbers are needed
//Postcondition : Checks if both complex numbers are the same
bool operator ==(const complex& c1, const complex& c2)
{
	return (c1.real && c1.imaginary) == (c2.real && c2.imaginary);
	//OR do this 
	//return (c1 == c2);
}

//Precondition : Two complex numbers are needed
//Postcondition : Checks if both complex numbers are NOT the same
bool operator !=(const complex& c1, const complex& c2)
{
	return !(c2 == c1);
}

//Precondition : Passing in ostream and object with valid inputs
//Postcondition: Display the complex number equation
ostream& operator <<(ostream& out, const complex& obj)
{
	if (obj.getImaginary() == 0)
	{
		out << obj.getReal();
		return out;
	}

	if (obj.getImaginary() < 0 && obj.getImaginary() != -1)
	{
		out << obj.getReal() << " - " << -obj.getImaginary() << "i";
		return out;
	}
	else if (obj.getImaginary() < 0 && obj.getImaginary() != -1)
	{
		out << obj.getReal() << " - i";
		return out;
	}

	if (obj.getImaginary() > 0 && obj.getImaginary() != 1)
	{
		out << obj.getReal() << " + " << obj.getImaginary() << "i";
		return out;
	}
	out << obj.getReal() << " + " << obj.getImaginary() << "i";
	return out;

}

