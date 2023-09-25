// Chapter 4: Complex Numbers, Rational Numbers, Polynomials 
// Group Names: Angie Campos, Neidy Malaga,Alexis Martinez, and Vivian Huynh
// Date: 9/24/2023
//					Vivian and Angie : Case 1 - Complex Numbers
//-------------------------------------------------------------------------------------------------
#include <iostream>
#include <cmath>
#include "input.h"
#include "MultipleComplexNumbers.h"

using namespace std;

int menuOption();
// case 1
void caseOne();
char caseOneMenu();
//case 1 : Part A
void caseOnePartA();
int caseOneMenu_PartA();
//case 1 : Part B
void caseOnePartB();
int caseOneMenu_PartB();

int main()
{
	do {
		system("cls");
		switch (menuOption())
		{
		case 0: return EXIT_SUCCESS; break;
		case 1: caseOne(); break;
		//case 2: caseTwo(); break;
			//case 3: caseThree(); break;
		default: cout << "\t\tERROR - Invalid option. Please re-enter a valid option."; break;
		}
		cout << "\n\n";
		system("pause");
	} while (true);

	return EXIT_SUCCESS;
}

int menuOption()
{
	cout << "\n\tCMPR131 Chapter 4: Complex Numbers, Rational Numbers, Polynomials";
	cout << "\n\t" << string(100, char(205));
	cout << "\n\t\t1> Complex Numbers";
	cout << "\n\t\t2> Rational Numbers";
	cout << "\n\t\t3> Polynomials";
	cout << "\n\t" << string(100, char(196));
	cout << "\n\t\t0> Exit";
	cout << "\n\t" << string(100, char(205));
	return inputInteger("\n\t\tOption: ", 0, 3);
}

void caseOne()
{
	do {
		system("cls");
		switch (caseOneMenu())
		{
		case '0': return; break;
		case 'A': caseOnePartA(); break;
		case 'B': caseOnePartB(); break;
		default: cout << "\t\tERROR - Invalid option. Please re-enter a valid option."; break;
		}
		cout << "\n\n";
		system("pause");
	} while (true);

	return;
}

char caseOneMenu()
{
	cout << "\n\tA complex number is a number that can be expressed in the form a + b i, where a and b are real";
	cout << "\n\tnumbers, and i represents the ""imaginary uni"", satisfying the equation i^2 = -1. Because no";
	cout << "\n\treal number satisfies this equation, i is called an imaginary number. For the complex number";
	cout << "\n\ta + b i, a is called the real part and b is called the imaginary part.";
	cout << "\n\t";
	cout << "\n\t1> Complex Numbers";
	cout << "\n\t" << string(100, char(205));
	cout << "\n\t\tA> A Complex Number";
	cout << "\n\t\tB> Multiple Complex Numbers";
	cout << "\n\t" << string(100, char(196));
	cout << "\n\t\t0> Exit";
	cout << "\n\t" << string(100, char(205));
	return inputChar("\n\t\tOption: ", static_cast<string>("AB0"));
}

//case 1 Part A
//-----------------------------------------------------------------------------------------------------------
void caseOnePartA()
{
	do {
		system("cls");
		switch (caseOneMenu_PartA())
		{
		case 0: return; break;
		case 1:; break;
		case 2:; break;
		case 3:; break;
		case 4:; break;
		case 5:; break;
		case 6:; break;
		case 7:; break;
		case 8:; break;
		default: cout << "\t\tERROR - Invalid option. Please re-enter a valid option."; break;
		}
		cout << "\n\n";
		system("pause");
	} while (true);

	return;
}
int caseOneMenu_PartA()
{
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
	cout << "\n\t\t0> Exit";
	cout << "\n\t" << string(100, char(205));
	return inputInteger("\n\t\tOption: ", 0, 8);
}
//case 1 Part B
//--------------------------------------------------------------------------------------------------------
void caseOnePartB()
{
	complex c1;
	complex c2;
	complex c3;
	do {
		system("cls");
		switch (caseOneMenu_PartB())
		{
		case 0: return; break;
		case 1: 
			c1.setReal(inputDouble("\n\tEnter a number (double value) for the real part of C1: "));
			c1.setImaginary(inputDouble("\n\tEnter a number (double value) for the imaginary part of C1: "));
			cout << "\n\t\tC1 = " << c1 << "\n"; break;
		case 2: 
			c2.setReal(inputDouble("\n\tEnter a number (double value) for the real part of C2: "));
			c2.setImaginary(inputDouble("\n\tEnter a number (double value) for the imaginary part of C2: "));
			cout << "\n\t\tC2 = " << c2 << "\n"; break;
		case 3:
			cout << "\t\tC1 == C2 ->(" << c1 << ") == ("<< c2 << ") ? " << (c1 == c2 ? "FALSE" : "TRUE");
			cout << "\n\t\tC2 != C1 ->(" << c2 << ") != (" << c1 << ") ? " << (c2 != c1 ? "FALSE" : "TRUE");
			; break;
		case 4:
		{complex temp;

		temp = c1 + c2;
		cout << "\n\tAddition      : C1 + C2 -> (" << c1 << ") + (" << c2 << ") = " << temp;

		temp = c1 - c2;
		cout << "\n\tSubtraction   : C1 - C2 -> (" << c1 << ") - (" << c2 << ") = " << temp;

		temp = c1 * c2;
		cout << "\n\tMultiplication: C1 * C2 -> (" << c1 << ") * (" << c2 << ") = " << temp;

		temp = c1 / c2;
		cout << "\n\tDivision      : C1 / C2 -> (" << c1 << ") / (" << c2 << ") = " << temp;

		}; break;
		case 5:
			c3.setReal(1.07109);
			c3.setImaginary(0.120832);

			cout << "\n\t\tC1 = " << c1;
			cout << "\n\t\tC2 = " << c2;
			cout << "\n\t\tC3 = " << c3;

			cout << "\n\t\tEvaluate Expression . . .";
			cout << "\n\t\t\t(3 * (C1 + C2) / 7) / (C2 - (C1 / 9)) != (1.07109 + 0.120832i) ?";
			cout << "\n\t\t\tstep #1: (3 * (" << c1 + c2 << ") / 7) / (C2 - (" << c1/9 << ")) != (1.07109 + 0.120832i)";
			cout << "\n\t\t\tstep #2: (" << 3 * (c1 + c2) << ")/7) / (" << c2 - (c1 / 9) << ")) != (1.07109 + 0.120832i)";
			cout << "\n\t\t\tstep #3: (" << (3 * (c1 + c2)) /7<< ") / (" << c2 - (c1 / 9) << ")) != (1.07109 + 0.120832i)";
			cout << "\n\t\t\tstep #4: (" << ((3 * (c1 + c2))/7) / (c2 - (c1 / 9)) << ")) != (1.07109 + 0.120832i)";
			cout << "\n\t\t\tstep #5:";
			cout << " " << (((3 * (c1 + c2)) / 7) / (c2 - (c1 / 9)) != c3 ? "FALSE" : "TRUE");

			; break;
		default: cout << "\t\tERROR - Invalid option. Please re-enter a valid option."; break;
		}
		cout << "\n\n";
		system("pause");
	} while (true);

	return;
}
int caseOneMenu_PartB()
{
	cout << "\n\tB> Multiple Complex Numbers";
	cout << "\n\t" << string(100, char(205));
	cout << "\n\t\t1. Enter complex number C1";
	cout << "\n\t\t2. Enter complex number C2";
	cout << "\n\t\t3. Verify condition operators (== and !=) of C1 and C2";
	cout << "\n\t\t4. Evaluate arithmatic operators (+, - , * and /) of C1 and C2";
	cout << "\n\t\t5. Evaluate steps in (3 * (C1 + C2) / 7) / (C2 - (C1 / 9)) != (1.07109 + 0.120832i) ?";
	cout << "\n\t" << string(100, char(196));
	cout << "\n\t\t0> Exit";
	cout << "\n\t" << string(100, char(205));
	return inputInteger("\n\t\tOption: ", 0, 5);
}

