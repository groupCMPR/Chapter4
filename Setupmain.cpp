//Names: Alexis Martinez, Angie Campos, Neidy Malaga, & Vivian Huynh
//Date: 9/21/2023
//Description: Chapter 4 Assignment: Complex Numbers, Rational Numbers, Polynomials

#include <iostream> //For cout
#include "input.h"  //For input validation

//HEADER FILES
#include "ComplexNumbers.h"
#include "Rational.h"
#include "Polynomial.h"
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
void number_of_terms(Polynomial&, bool, string);
void specify_coefficients(Polynomial&, bool);
void eval_exp(Polynomial&);
void derivative(Polynomial&);
void integral(Polynomial&);
void optionBTwoPolynomials();

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
//Precondition : Calling function from main
//Postcondition: Output the complex numbers menu; goes to option A or B
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
//Precondition : Calling function from complex numbers menu
//Postcondition: Output option A complex number menu
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
		case 5: equation1.addition(inputDouble("\n\tEnter a value (double): ")); break;
		case 6: equation1.subtraction(inputDouble("\n\tEnter a value (double): ")); break;
		case 7: equation1.multiplication(inputDouble("\n\tEnter a value (double): ")); break;
		case 8: equation1.division(inputDouble("\n\tEnter a value (double): ")); break;
		default: cout << "\t\tERROR: - Invalid option. Please re-enter"; break;
		}
		cout << "\n";
		system("pause");
	} while (true);

	return 0;
}
//Precondition : Calling function from complex numbers menu
//Postcondition: Output option B multiple complex numbers menu
int optionBMultipleComplexNumbers()
{
	ComplexNumbers c1;
	ComplexNumbers c2;
	ComplexNumbers c3;

	do
	{
		system("cls");
		cout << "\n\tB> Multiple Complex Numbers";
		cout << "\n\t" << string(100, char(205));
		cout << "\n\t\t1. Enter complex number C1";
		cout << "\n\t\t2. Enter complex number C2";
		cout << "\n\t\t3. Verify condition operators (== and !=) of C1 and C2";
		cout << "\n\t\t4. Evaluate arithmatic operators (+, -, *, and /) of C1 and C2";
		cout << "\n\t\t5. Evaluate steps in (3 * (C1 + C2) / 7) / (C2 - C1 / 9) != (1.07109 + 0.120832i) ?";
		cout << "\n\t" << string(100, char(196));
		cout << "\n\t\t0. return";
		cout << "\n\t" << string(100, char(205));

		switch (inputInteger("\n\t\tOption: ", 0, 5))
		{
		case 0: return 0;
		case 1:
		{
			c1.setRealNumber(inputDouble("\n\tEnter a number (double value) for the real part of C1: "));
			c1.setImaginaryNumber(inputDouble("\tEnter a number (double value) for the imaginary part of C1: "));
			cout << "\n\t\tC1 = " << c1 << "\n";
		}break;
		case 2:
		{
			c2.setRealNumber(inputDouble("\n\tEnter a number (double value) for the real part of C2: "));
			c2.setImaginaryNumber(inputDouble("\tEnter a number (double value) for the imaginary part of C2: "));
			cout << "\n\t\tC2 = " << c2 << "\n";
		}break;
		case 3:
		{
			cout << "\t\tC1 == C2 -> (" << c1 << ") == (" << c2 << ") ? " << (c1 == c2 ? "FALSE" : "TRUE");
			cout << "\n\t\tC2 != C1 -> (" << c2 << ") != (" << c1 << ") ? " << (c2 != c1 ? "FALSE" : "TRUE");
		}break;
		case 4:
		{
			ComplexNumbers temp;

			temp = c1 + c2;
			cout << "\n\tAddition      : C1 + C2 -> (" << c1 << ") + (" << c2 << ") = " << temp;

			temp = c2 - c1;
			cout << "\n\tSubtraction   : C2 - C1 -> (" << c2 << ") - (" << c1 << ") = " << temp;

			temp = c1 * c2;
			cout << "\n\tMultiplication: C1 * C2 -> (" << c1 << ") * (" << c2 << ") = " << temp;

			temp = c2 / c1;
			cout << "\n\tDivision      : C2 / C1 -> (" << c2 << ") / (" << c1 << ") = " << temp;

		}break;
		case 5:
		{
			c3.setRealNumber(1.07109);
			c3.setImaginaryNumber(0.120832);

			cout << "\n\t\tC1 = " << c1;
			cout << "\n\t\tC2 = " << c2;
			cout << "\n\t\tC3 = " << c3;

			cout << "\n\n\t\tEvaluate Expression . . .";
			cout << "\n\t\t\t\t (3 * (C1 + C2) / 7) / (C2 - (C1 / 9)) != (1.07109 + 0.120832i) ?";
			cout << "\n\t\t\tstep #1: (3 * (" << c1 + c2 << ") / 7) / (C2 - (" << c1 / 9 << ")) != (1.07109 + 0.120832i)";
			cout << "\n\t\t\tstep #2: (" << 3 * (c1 + c2) << ") / 7) / (" << c2 - (c1 / 9) << ")) != (1.07109 + 0.120832i)";
			cout << "\n\t\t\tstep #3: (" << (3 * (c1 + c2)) / 7 << ") / (" << c2 - (c1 / 9) << ")) != (1.07109 + 0.120832i)";
			cout << "\n\t\t\tstep #4: (" << ((3 * (c1 + c2)) / 7) / (c2 - (c1 / 9)) << ")) != (1.07109 + 0.120832i)";
			cout << "\n\t\t\tstep #5:";
			cout << " " << (((3 * (c1 + c2)) / 7) / (c2 - (c1 / 9)) != c3 ? "FALSE\n" : "TRUE\n");

		}break;
		default: cout << "\t\tERROR: - Invalid option. Please re-enter"; break;
		}
		cout << "\n";
		system("pause");
	} while (true);

	return 0;
}

//================================================================================================================== 
// Option 2 - Rational Numbers Section
//================================================================================================================== 
//Precondition : Calling function from main
//Postcondition: Output the rational numbers menu; goes to option A or B
int rationalNumbers()
{
	do
	{
		system("cls");
		cout << "\n\tA rational number is a number that can be written as a fraction, a/b, where a is numerator and";
		cout << "\n\tb is denominator. Rational numbers are all real numbers, and can be positive or negative. A";
		cout << "\n\tnumber that is not rational is called irrational. Most of the numbers that people use in everyday";
		cout << "\n\tlife are rational. These include fractions, integers, and numbers with finite decimal digits.";
		cout << "\n\tIn general, a number that can be written as a fraction while it is in its own form is rational.\n";

		cout << "\n\t2> Rational Numbers";
		cout << "\n\t" << string(100, char(205));
		cout << "\n\t\tA> A Rational Number";
		cout << "\n\t\tB> Multiple Rational Numbers";
		cout << "\n\t" << string(100, char(196));
		cout << "\n\t\t0> return";
		cout << "\n\t" << string(100, char(205));

		switch (toupper(inputChar("\n\t\tOption: ", static_cast<string>("AB0"))))
		{
		case '0': return 0;
		case 'A': system("cls"); optionARationalNumber(); break;
		case 'B': system("cls"); optionBMultipleRationalNumbers(); break;

		default: cout << "\t\tERROR: - Invalid option. Please re-enter"; break;
		}
		cout << "\n";
		system("pause");
	} while (true);

	return 0;
}
//Precondition : Calling function from rational number menu
//Postcondition: Output option A rational number menu
int optionARationalNumber()
{
	Rational r1;
	Rational r2;
	int numerator = 0;
	int denominator = 1;

	do
	{
		system("cls");
		cout << "\n\tA> A Rational Number";
		cout << "\n\t" << string(100, char(205));
		cout << "\n\t\t1. Enter the numerator";
		cout << "\n\t\t2. Enter the denominator";
		cout << "\n\t\t3. Display the rational number";
		cout << "\n\t\t4. Normalize the rational number";
		cout << "\n\t\t5. Negate the rational number";
		cout << "\n\t\t6. Add(+) the rational number with a constant";
		cout << "\n\t\t7. Subtract(-) the rational number with a constant";
		cout << "\n\t\t8. Multiply(*) the rational number with a constant";
		cout << "\n\t\t9. Divide(/) the rational number with a constant";
		cout << "\n\t" << string(100, char(196));
		cout << "\n\t\t0. return";
		cout << "\n\t" << string(100, char(205));

		switch (inputInteger("\n\t\tOption: ", 0, 9))
		{
		case 0: return 0;
		case 1: numerator = inputInteger("\n\t\tEnter an integer for the numerator: ");
			r1.setNumerator(numerator);
			break;
		case 2:
			try {
				denominator = inputInteger("\n\t\tEnter an integer for the denominator: ");
				r1.setDenominator(denominator);
			}
			catch (Rational::ZeroDenominator& e)
			{
				r1.setDenominator(1);
				denominator = 1;
				cout << "\n\t\tEXCEPTION ERROR: Cannot use Rational number, " << e.toString() << ", with a zero denominator value. Default value 1 given";
			}

			break;
		case 3: cout << "\n\t\t\tRational number R1 = " << numerator << "/" << denominator; break;
		case 4:
		{
			r2 = r1;

			cout << "\n\t\t\tNormalized rational number R2 (a copy of R1)";
			cout << endl;
			cout << "\n\t\t\t" << r2;
			break;
		}
		case 5:
		{
			r2 = r1 * -1;

			cout << "\n\t\t\tNegated rational number R2 (a copy of R1)";
			cout << endl;
			cout << "\n\t\t\t-(" << r1 << ") = " << r2;

			break;
		}
		case 6:
		{
			int number = inputInteger("\n\t\t\tEnter an integer value: ");
			r2 = r1 + number;


			cout << "\n\t\t\tR2 + value";
			cout << "\n\t\t\t(" << r1 << ") + " << number << " = " << r2;
			cout << endl;
			r2 = number + r1;

			cout << "\n\t\t\tvalue + R2";
			cout << "\n\t\t\t" << number << " + (" << r1 << ") = " << r2;

			break;
		}
		case 7:
		{
			int number = inputInteger("\n\t\t\tEnter an integer value: ");
			r2 = r1 - number;


			cout << "\n\t\t\tR2 - value";
			cout << "\n\t\t\t(" << r1 << ") - " << number << " = " << r2;
			cout << endl;
			r2 = number - r1;

			cout << "\n\t\t\tvalue - R2";
			cout << "\n\t\t\t" << number << " - (" << r1 << ") = " << r2;

			break;
		}
		case 8:
		{
			int number = inputInteger("\n\t\t\tEnter an integer value: ");

			r2 = r1 * number;


			cout << "\n\t\t\tR2 * value";
			cout << "\n\t\t\t(" << r1 << ") * " << number << " = " << r2;
			cout << endl;
			r2 = number * r1;

			cout << "\n\t\t\tvalue * R2";
			cout << "\n\t\t\t" << number << " * (" << r1 << ") = " << r2;

			break;
		}
		case 9:
				{
			try {
				int number = inputInteger("\n\t\t\tEnter an integer value: ");
				r2 = r1 / number;


				cout << "\n\t\t\tR2 / value";
				cout << "\n\t\t\t(" << r1 << ") / " << number << " = " << r2;
				cout << endl;
				r2 = number / r1;

				cout << "\n\t\t\tvalue / R2";
				cout << "\n\t\t\t" << number << " / (" << r1 << ") = " << r2;
			}
			catch (Rational::ZeroDenominator& e){
				cout << "\n\t\t\tR2 / value";
				cout << "\n\t\t\t(" << r1 << ") /  0 = undefine";
				cout << endl;
				cout << "\n\t\t\tvalue / R2";
				cout << "\n\t\t\t" << "0 / (" << r1 << ") = 0/1";
			}
			break;
		}

		default: cout << "\t\tERROR: - Invalid option. Please re-enter"; break;
		}
		cout << "\n";
		system("pause");
	} while (true);

	return 0;
}
//Precondition : Calling function from rational number menu
//Postcondition: Output option B multiple rational number menu
int optionBMultipleRationalNumbers()
{
	Rational r1;
	Rational r2;
	Rational r3;

	do
	{
		system("cls");
		cout << "\n\tB> Multiple Rational Numbers";
		cout << "\n\t" << string(100, char(205));
		cout << "\n\t\t1. Enter rational number R1";
		cout << "\n\t\t2. Enter rational number R2";
		cout << "\n\t\t3. Verify condition operators (==, !=, >=, >, <= and <) of R1 and R2";
		cout << "\n\t\t4. Evaluate arithmatic operators (+, - , * and /) of R1 and R2";
		cout << "\n\t\t5. Evaluate (3 * (R1 + R2) / 7) / (R2 - R1 / 9) >= 621/889";
		cout << "\n\t" << string(100, char(196));
		cout << "\n\t\t0. return";
		cout << "\n\t" << string(100, char(205));

		switch (inputInteger("\n\t\tOption: ", 0, 5))
		{
		case 0: return 0;
		case 1:
		{
			try
			{
				int numerator = inputInteger("\n\t\t\tEnter the numerator for R1: ");
				int denominator = inputInteger("\t\t\tEnter the denominator for R1: ");
				Rational tempR1(numerator, denominator);
				r1 = tempR1;
				cout << "\n\t\t\tR1 = " << r1;
			}
			catch (Rational::ZeroDenominator& e)
			{
				cout << "\n\t\tEXCEPTION ERROR: Cannot use Rational number, " << e.toString() << ", with a zero denominator value.";
			}
		}break;
		case 2:
		{
			try {
				int numerator = inputInteger("\n\t\t\tEnter the numerator for R2: ");
				int denominator = inputInteger("\t\t\tEnter the denominator for R2: ");
				Rational tempR2(numerator, denominator);
				r2 = tempR2;

				cout << "\n\t\t\tR2 = " << r2;
			}
			catch (Rational::ZeroDenominator& e)
			{
				cout << "\n\t\tEXCEPTION ERROR: Cannot use Rational number, " << e.toString() << ", with a zero denominator value.";
			}

		}break;
		case 3:
		{
			cout << "\n\t\t\tR1 == R2 -> (" << r1 << ") == (" << r2 << ") ? ";
			cout << (r1 == r2 ? "TRUE" : "FALSE");
			cout << "\n\t\t\tR2 != R1 -> (" << r2 << ") != (" << r1 << ") ? ";
			cout << (r2 != r1 ? "TRUE" : "FALSE");
			cout << "\n\t\t\tR1 >= R2 -> (" << r1 << ") >= (" << r2 << ") ? ";
			cout << (r1 >= r2 ? "TRUE" : "FALSE");
			cout << "\n\t\t\tR2  > R1 -> (" << r2 << ")  > (" << r1 << ") ? ";
			cout << (r2 > r1 ? "TRUE" : "FALSE");
			cout << "\n\t\t\tR1 <= R2 -> (" << r1 << ") <= (" << r2 << ") ? ";
			cout << (r1 <= r2 ? "TRUE" : "FALSE");
			cout << "\n\t\t\tR2  < R1 -> (" << r2 << ")  < (" << r1 << ") ? ";
			cout << (r2 < r1 ? "TRUE" : "FALSE");

		}break;
		case 4:
		{
			try {
				Rational temp;
				temp = r1 + r2;

				cout << "\n\t\t\tAddition    : R1 + R2 -> (" << r1 << ") + (" << r2 << ") = " << temp;
				temp = r2 - r1;

				cout << "\n\t\t\tSubtraction : R2 - R1 -> (" << r2 << ") - (" << r1 << ") = " << temp;
				temp = r1 * r2;

				cout << "\n\t\t\tMutiplcation: R1 * R2 -> (" << r1 << ") * (" << r2 << ") = " << temp;
				temp = r2 / r1;

				cout << "\n\t\t\tDivision    : R2 / R1 -> (" << r2 << ") / (" << r1 << ") = " << temp;
			}
			catch (Rational::ZeroDenominator& e) {
				cout << "\n\t\t\tDivision    : R2 / R1 -> (" << r2 << ") / (" << r1 << ") = " << e.toString();
			}

		}break;
		case 5:
		{
			try
			{
				r3.setNumerator(621);
				r3.setDenominator(889);
				cout << "\n\t\t\tR1 = " << r1;
				cout << "\n\t\t\tR2 = " << r2;
				cout << "\n\t\t\tR3 = " << r3;
				cout << "\n\n\t\t\tEvaluating expression...";
				cout << "\n\t\t\t\t (3 * (R1 + R2) / 7) / (R2 - R1 / 9) >= 621/889 ?";
				cout << "\n\t\t\tstep #1: (3 * (" << r1 + r2 << ") / 7 ) / (R2 - (" << r1 / 9 << ")) >= " << r3 << " ?";
				cout << "\n\t\t\tstep #2: ((" << 3 * (r1 + r2) << ") / 7 / (" << r2 - (r1 / 9) << ") >= " << r3 << " ?";
				cout << "\n\t\t\tstep #3: (" << 3 * (r1 + r2) / 7 << ") / (" << r2 - (r1 / 9) << ") >= " << r3 << " ?";
				cout << "\n\t\t\tstep #4: " << (3 * (r1 + r2) / 7) / (r2 - (r1 / 9)) << " >= " << r3 << " ?";;
				cout << "\n\t\t\tstep #5: ";
				cout << (((3 * (r1 + r2) / 7) / (r2 - (r1 / 9)) >= r3) ? "TRUE" : "FALSE") << endl;
			}
			catch (Rational::ZeroDenominator& e) {
				cout << "\n\t\t\tstep #4: " << e.toString() << " >= 621/889 ? ";
				cout << "\n\t\t\tstep #5: TRUE";
			}
		}break;
		default: cout << "\t\tERROR: - Invalid option. Please re-enter"; break;
		}
		cout << "\n";
		system("pause");
	} while (true);

	return 0;
}

//================================================================================================================== 
// Option 3 - Polynomials Section
//================================================================================================================== 
//Precondition: Called from main
//Postcondition: Redirects to optionASinglePolynomial() or optionB
int polynomials()
{
	do
	{
		system("cls");
		cout << "\n\tA polynomial is an expression consisting of variables(also called indeterminates) and";
		cout << "\n\tcoefficients, that involves only the operations of addition, subtraction, multiplication,";
		cout << "\n\tand non - negative integer exponentiation of variables.\n";

		cout << "\n\t3> Polynomials";
		cout << "\n\t" << string(100, char(205));
		cout << "\n\t\tA> A Polynomial";
		cout << "\n\t\tB> Multiple Polynomials";
		cout << "\n\t" << string(100, char(196));
		cout << "\n\t\t0> return";
		cout << "\n\t" << string(100, char(205));

		switch (inputChar("\n\t\tOption: ", static_cast<string>("AB0")))
		{
		case '0': return 0;
		case 'A': system("cls"); optionASinglePolynomial(); break;
		case 'B': system("cls"); optionBTwoPolynomials(); break;

		default: cout << "\n\tERROR: - Invalid option. Please re-enter"; break;
		}
		cout << "\n";
		system("pause");
	} while (true);
	return 0;
}

//Precondition: called from polynomials()
//Postcondition: Redirects to number_of_terms(), specify_coefficients(), eval_exp(), derivative(), integral()
int optionASinglePolynomial()
{
	Polynomial p1;

	do
	{
		system("cls");
		cout << "\n\tA> Single Polynomial";
		cout << "\n\t" << string(100, char(205));
		cout << "\n\t\t1. Enter the number of terms";
		cout << "\n\t\t2. Specify the coefficients";
		cout << "\n\t\t3. Evaluate expression";
		cout << "\n\t\t4. Solve for the derivative";
		cout << "\n\t\t5. Solve for the integral";
		cout << "\n\t" << string(100, char(196));
		cout << "\n\t\t0. return";
		cout << "\n\t" << string(100, char(205));

		switch (inputInteger("\n\t\tOption: ", 0, 5))
		{
		case 0: return 0;
		case 1: number_of_terms(p1, true, "polynomial: "); break;
		case 2: {
			specify_coefficients(p1, true);
			cout << "\n\tThe P(x) is entered: ";
			p1.set_Choice(1);
			cout << p1;
		}break;
		case 3: eval_exp(p1); break;
		case 4: derivative(p1); break;
		case 5: integral(p1); break;
		default: cout << "\n\tERROR: - Invalid option. Please re-enter"; break;
		}
		cout << "\n";
		system("pause");
	} while (true);
	return 0;
}

//Precondition: class Polynomial, true or false to indicate whether you will manipulate hash maps: First_Poly or Second_Poly, prompt to cout
//Postcondition: sets size of First_Poly or Second_Poly 
//NOTICE: we only clear First_Poly because Second_Poly is used in Option B, where we deallocate the class Polynomial, we clear First_Poly 
//because we want to create an error message whenever the player attempts to reuse the past hashmap
void number_of_terms(Polynomial& p1, bool choice, string prompt) {

	int size = (inputInteger("\n\tEnter the number of terms(1..100) for the " + prompt, 1, 100));

	switch (choice) {
	case true: {
		p1.set_First_Size(&size);
		p1.set_First_Clear();
	} break;
	case false: {
		p1.set_Second_Size(&size);
	}
	}
}

//Precondition: class Polynomial, true or false to indicate whether you will manipulate hash maps: First_Poly or Second_Poly, must have already
//used number_of_terms to set a size
//Postcondition: fills in coefficients in First_Poly or Second_Poly, the [key] is useful as it will show us the power of the coefficient
void specify_coefficients(Polynomial& p1, bool choice) {
	int size = 0;

	//we clear the First_Poly just in case of errors
	//we do not clear Second_Poly as it is deallocated after use in Option B
	switch (choice) {
	case true: {
		p1.set_First_Clear();
		size = p1.get_First_Size();
	} break;
	case false: {
		size = p1.get_Second_Size();
	} break;
	}

	//setting is set in a way that will ensure it has the proper power (size - i)
	double number = 0;
	for (int i = 1; i <= size; i++) {
		number = inputDouble("\n\tEnter the coefficient for term #" + to_string(i) + " :");

		switch (choice) {
		case true: p1.set_First_Poly(&i, &number); break;
		case false: p1.set_Second_Poly(&i, &number); break;
		}
	}
}

//Precondition: class Polynomial, must have used specify_coefficients to set up First_Poly and valid size
//Postcondition: will display the number if it were inputted into x of a polynomial in First_Poly 
void eval_exp(Polynomial& p1) {

	//error messages: empty hashmap, empty size
	if (p1.get_First_Size() == 0) {
		cout << "\n\tERROR: Please confirm size of polynomials. Please chose option 1.";
		return;
	}

	if (p1.get_First_Empty()) {
		cout << "\n\tERROR: There are no inputted polynomials. Please chose option 2.";
		return;
	}

	//for always displaying how the polynomial looks
	cout << "\n\tP1(x) = ";
	p1.set_Choice(1);
	cout << p1;

	//temp is used to store coefficient(number)^(power)
	//adds all of temp to be used to display final answer
	double sum = 0, temp = 0;
	int number = inputInteger("\n\tEnter the value of x to evaluate the polynomial:");
	cout << "\n\t";

	for (int i = p1.get_First_Size() - 1; i > -1; i--) {
		temp = (p1.get_First_Poly((&i)) * pow(number, i)) * 1.00;

		if (i == 0)
			cout << "+";

		cout << temp << "<-\t" << p1.get_First_Poly((&i)) << "x^" << i << "\n\t";
		sum += temp;
	}

	cout << string(100, char(196)) << "\n\t" << sum;
}

//Precondition: class Polynomial, must have filled in First_Poly and valid size
//Postcondition: will do the derivative of First_Poly, store it into Final_Poly, and display
void derivative(Polynomial& p1) {

	//error messages: empty hashmap, empty size
	if (p1.get_First_Size() == 0) {
		cout << "\n\tERROR: Please confirm size of polynomials. Please chose option 1.";
		return;
	}

	if (p1.get_First_Empty()) {
		cout << "\n\tERROR: There are no inputted polynomials. Please chose option 2.";
		return;
	}

	//clears Final_Poly[] to make sure it doesn't have a greater size than the new one
	p1.set_Final_Clear();


	cout << "\n\tPolynomial(x) = ";
	p1.set_Choice(1);
	cout << p1;

	p1.set_Derive();

	cout << "\n\tDerivative    = ";
	p1.set_Choice(3);
	cout << p1;

}

//Precondition: class Polynomial, must have filled in First_Poly and valid size
//Postcondition: will do the integral of First_Poly, store it into Final_Poly, and display
void integral(Polynomial& p1) {

	//error messages: empty hashmap, empty size
	if (p1.get_First_Size() == 0) {
		cout << "\n\tERROR: Please confirm size of polynomials. Please chose option 1.";
		return;
	}

	if (p1.get_First_Empty()) {
		cout << "\n\tERROR: There are no inputted polynomials. Please chose option 2.";
		return;
	}

	p1.set_Final_Clear();

	cout << "\n\tPolynomial(x) = ";
	p1.set_Choice(1);
	cout << p1;

	p1.set_Integral();

	cout << "\n\tIntegral      = ";
	p1.set_Choice(3);
	cout << p1;

}

//Precondition: N/A
//Postcondition: fills in First_Poly and Second_Poly, adds/subtracts/multiplies them, and multiplies a value
//to both polynomials 
void optionBTwoPolynomials() {
	Polynomial p2;
	cout << "\n\tB> Two Polynomials";

	//gets size, fills in First_Poly, displays
	number_of_terms(p2, true, "first polynomial (P1): ");
	specify_coefficients(p2, true);

	cout << "\n\tThe first polynomial (P1) is entered: ";
	p2.set_Choice(1);
	cout << p2;

	//gets size, fills in Second_Poly, displays
	number_of_terms(p2, false, "second polynomial (P2): ");
	specify_coefficients(p2, false);


	cout << "\n\tThe second polynomial (P2) is entered: ";
	p2.set_Choice(2);
	cout << p2;

	//adds both poly, display
	p2.set_Add_Sub(true);

	cout << "\n\tAddition of polynomials       -> P1 + P2 = ";
	p2.set_Choice(3);
	cout << p2;

	//clears to ensure it will not retain past values
	p2.set_Final_Clear();

	//subtracts both poly, display
	p2.set_Add_Sub(false);

	cout << "\n\tSubtraction of polynomials     -> P1 - P2 = ";
	p2.set_Choice(3);
	cout << p2;

	//clears Final_Poly
	p2.set_Final_Clear();

	//multiplies both poly, display
	p2.set_Multiplication();

	cout << "\n\tMultiplication of polynomials -> P1 * P2 = ";
	p2.set_Choice(3);
	cout << p2;

	//data result multiplies value from player and the data from First_Poly
	//position is set to get number with greatest power, size - i ex:
	//3x^2 + x + 1 size = 3, position = 3-1 = 2 key = 2 (3x^2), 3-2 key = 1 (x), 3-3 key = 0 (1)
	const double player_val = inputDouble("\n\tEnter a constant value: ");
	double data_result = 0;
	int position = 0;

	for (int i = 1; i <= p2.get_First_Size(); i++) {
		position = p2.get_First_Size() - i;
		data_result = player_val * p2.get_First_Poly(&position);
		p2.set_First_Poly(&i, &data_result);
	}

	//displays new First_Poly
	cout << "\n\t" << to_string(player_val) << "* Polynomial(P1) = ";
	p2.set_Choice(1);
	cout << p2;

	//multiplies value with Second_Poly elements, then displays
	for (int i = 1; i <= p2.get_Second_Size(); i++) {
		position = p2.get_Second_Size() - i;
		data_result = player_val * p2.get_Second_Poly(&position);
		p2.set_Second_Poly(&i, &data_result);
	}


	//displays new First_Poly
	cout << "\n\t" << to_string(player_val) << "* Polynomial(P2) = ";
	p2.set_Choice(2);
	cout << p2;

}
