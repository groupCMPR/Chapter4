//Names: Alexis Martinez, Angie Campos, Neidy Malaga, & Vivian Huynh
//Date: 9/21/2023
//Description: Chapter 4 Assignment: Complex Numbers, Rational Numbers, Polynomials

#include <iostream> //For cout
#include "input.h"  //For input validation

//HEADER FILES
#include "ComplexNumbers.h"
using namespace std;

//PROTOTYPES
int mainMenu();

//Option 1 - Complex Numbers
int complexNumbers();
int optionAComplexNumber();
int optionBMultipleComplexNumbers();

//Option 2 - Rational Numbers
int rationalNumbers();
int optionARationalNumber();
int optionBMultipleRationalNumbers();

//Option 3 - Polynomials
int polynomials();
int optionASinglePolynomial();
int optionBTwoPolynomials();

int main()
{
	do
	{
		system("cls");
		switch (mainMenu())
		{
		case 0: exit(0);
		case 1: system("cls"); complexNumbers(); break;
		case 2: system("cls"); rationalNumbers(); break;
		case 3: system("cls"); polynomials(); break;
		default: cout << "\t\tERROR: - Invalid option. Please re-enter"; break;
		}
		cout << "\n";
		system("pause");
	} while (true);

	return 0;
}

int mainMenu()
{
	cout << "\n\t CMPR131 Chapter 4: Complex Numbers, Rational Numbers, Polynomials by Group 5 (Vivian Huynh) 9/21/2023";
	cout << "\n\t" << string(100, char(205));
	cout << "\n\t\t1> Complex Numbers";
	cout << "\n\t\t2> Rational Numbers";
	cout << "\n\t\t3> Polynomials";
	cout << "\n\t" << string(100, char(196));
	cout << "\n\t\t0. Exit";
	cout << "\n\t" << string(100, char(205));

	return inputInteger("\n\t\tOption: ", 0, 3);
}

//==================================================================================================================
// Option 1 - Complex Numbers Section
//================================================================================================================== 
int complexNumbers()
{
	do
	{
		system("cls");
		cout << "\n\tA complex number is a number that can be expressed in the form a + bi, where a and b are real";
		cout << "\n\tnumbers, and i represents the \"imaginary uni\", satisfying the equation i^2 = -1. Because no";
		cout << "\n\treal number satisfies this equation, i is called an imaginary number. For the complex number";
		cout << "\n\ta + bi, a is called the real part and b is called the imaginary part.\n";

		cout << "\n\t1> Complex Numbers";
		cout << "\n\t" << string(100, char(205));
		cout << "\n\t\tA> A Complex Number";
		cout << "\n\t\tB> Multiple Complex Numbers";
		cout << "\n\t" << string(100, char(196));
		cout << "\n\t\t0> return";
		cout << "\n\t" << string(100, char(205));

		switch (toupper(inputChar("\n\t\tOption: ", static_cast<string>("AB0"))))
		{
		case '0': return 0;
		case 'A': system("cls"); optionAComplexNumber(); break;
		case 'B': system("cls"); optionBMultipleComplexNumbers(); break;
		default: cout << "\t\tERROR: - Invalid option. Please re-enter"; break;
		}
		cout << "\n";
		system("pause");
	} while (true);

	return 0;
}
int optionAComplexNumber()
{
	ComplexNumbers equation1;
	ComplexNumbers equation2;
	do
	{
		system("cls");
		cout << "\n\tA> A Complex Number";
		cout << "\n\t" << string(100, char(205));
		cout << "\n\t\t1. Enter the real number";
		cout << "\n\t\t2. Enter the imaginary number";
		cout << "\n\t\t3. Display the complex number";
		cout << "\n\t\t4. Negate the complex number";
		cout << "\n\t\t5. Add (+) the complex number with a constant";
		cout << "\n\t\t6. Subtract (-) the complex number with a constant";
		cout << "\n\t\t7. Multiply (*) the complex number with a constant";
		cout << "\n\t\t8. Divide (/) the complex number with a constant";
		cout << "\n\t" << string(100, char(196));
		cout << "\n\t\t0. return";
		cout << "\n\t" << string(100, char(205));

		switch (inputInteger("\n\t\tOption: ", 0, 8))
		{
		case 0: return 0;
		case 1: equation1.setRealNumber(inputDouble("\n\tEnter a number (double value) for the real part: ")); break;
		case 2: equation1.setImaginaryNumber(inputDouble("\n\tEnter a number (double value) for the imaginary part: ")); break;
		case 3: cout << "\n\tComplex Number C1 = " << equation1 << '\n'; break;
		case 4: 
		{
			equation2 = equation1;
			equation2.negateComplexNumber();
			cout << "\n\tNegated the complex number C2 (a copy of C1)\n";
			cout << "\n\t-(" << equation1 << ") = " << equation2 << '\n';
		}break;
		default: cout << "\t\tERROR: - Invalid option. Please re-enter"; break;
		}
		cout << "\n";
		system("pause");
	} while (true);

	return 0;
}
int optionBMultipleComplexNumbers()
{
	do
	{
		system("cls");
		cout << "\n\tB> Multiple Complex Numbers";
		cout << "\n\t" << string(100, char(205));
		cout << "\n\t\t1. Enter complex number C1";
		cout << "\n\t\t2. Enter complex number C2";
		cout << "\n\t\t3. Verify condition operators (== and !=) of C1 and C2";
		cout << "\n\t\t4. Evaluate arithmatic operators (+, - , * and /) of C1 and C2";
		cout << "\n\t\t5. Evaluate steps in (3 * (C1 + C2) / 7) / (C2 - C1 / 9) != (1.07109 + 0.120832i) ?";
		cout << "\n\t" << string(100, char(196));
		cout << "\n\t\t0. return";
		cout << "\n\t" << string(100, char(205));

		switch (inputInteger("\n\t\tOption: ", 0, 5))
		{
		case 0: return 0;
		default: cout << "\t\tERROR: - Invalid option. Please re-enter"; break;
		}
		cout << "\n";
		system("pause");
	} while (true);

	return 0;
}
