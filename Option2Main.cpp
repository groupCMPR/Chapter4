//Alexis Martinez
#include <iostream>
#include "input.h"
#include "Rational.h"

using namespace std;

int menuOption();
void caseTwo();
char caseTwoMenu();
void caseTwoOptionA();
void caseTwoOptionB();

int main() {
	
	do {
		system("cls");
		switch (menuOption()) {
		case 0: return EXIT_SUCCESS;
		//case 1: break;
		case 2: caseTwo(); break;
		//case 3: break;
		default: cout << "\n\tERROR - INVALID CHOICE"; break;

		}
		cout << "\n\t";
		system("pause");
	} while (true);

	return EXIT_SUCCESS;
}


int menuOption() {

	cout << "\n\tCMPR131 Chapter 4: Complex Numbers, Rational Numbers, Polynomials";
	cout << "\n\t" << string(100, char(205));
	cout << "\n\t\t1> Complex Numbers";
	cout << "\n\t\t2> Rational Numbers";
	cout << "\n\t\t3> Polynomials";
	cout << "\n\t" << string(100, char(196));
	cout << "\n\t\t0> exit";
	cout << "\n\t" << string(100, char(205));

	return inputInteger("\n\t\tOption: ", 0, 3);

}

void caseTwo() {
	do {
		system("cls");
		cout << "\n\t\tA rational number is a number that can be written as a fraction, a/b, where a is numerator and";
		cout << "\n\t\tb is denominator. Rational numbers are all real numbers, and can be positive or negative. A";
		cout << "\n\t\tnumber that is not rational is called irrational. Most of the numbers that people use in everyday";
		cout << "\n\t\tlife are rational.These include fractions, integers and numbers with finite decimal digits.";
		cout << "\n\t\tIn general, a number that can be written as a fraction while it is in its own form is rational.";
		cout << endl;
		cout << "\n\t\t2> Rational Numbers";
		cout << "\n\t\t" << string(100, char(205));
		cout << "\n\t\t\tA> A Rational Number";
		cout << "\n\t\t\tB> Multiple Rational Numbers";
		cout << "\n\t\t" << string(100, char(196));
		cout << "\n\t\t\t0> return";
		cout << "\n\t\t" << string(100, char(205));

		char option = inputChar("\n\t\t\tOption: ", static_cast<string>("AB0"));

		switch (option) {
		case '0': return; break;
		case 'A': caseTwoOptionA(); break;
		case 'B': caseTwoOptionB(); break;
		}

	} while (true);
}

char caseTwoMenu() {
	cout << "\n\t\tA rational number is a number that can be written as a fraction, a/b, where a is numerator and";
	cout << "\n\t\tb is denominator. Rational numbers are all real numbers, and can be positive or negative. A";
	cout << "\n\t\tnumber that is not rational is called irrational. Most of the numbers that people use in everyday";
	cout << "\n\t\tlife are rational.These include fractions, integers and numbers with finite decimal digits.";
	cout << "\n\t\tIn general, a number that can be written as a fraction while it is in its own form is rational.";
	cout << endl;
	cout << "\n\t\t2> Rational Numbers";
	cout << "\n\t\t" << string(100, char(205));
	cout << "\n\t\t\tA> A Rational Number";
	cout << "\n\t\t\tB> Multiple Rational Numbers";
	cout << "\n\t\t" << string(100, char(196));
	cout << "\n\t\t\t0> return";
	cout << "\n\t\t" << string(100, char(205));

	return inputChar("\n\t\t\tOption: ", static_cast<string>("AB0"));
}

void caseTwoOptionA() {
	Rational r1;
	Rational r2;
	int numerator = 0;
	int denominator = 1;
	do {
		system("cls");
		cout << "\n\t\tA> A Rational Number";
		cout << "\n\t\t" << string(100, char(205));
		cout << "\n\t\t\t1. Enter the numerator";
		cout << "\n\t\t\t2. Enter the deminator";
		cout << "\n\t\t\t3. Display the rational number";
		cout << "\n\t\t\t4. Normalize the rational number";
		cout << "\n\t\t\t5. Negate the rational number";
		cout << "\n\t\t\t6. Add (+) the rational number with a constant";
		cout << "\n\t\t\t7. Subtract (-) the rational number with a constant";
		cout << "\n\t\t\t8. Multiply (*) the rational number with a constant";
		cout << "\n\t\t\t9. Divide (/) the rational number with a constant";
		cout << "\n\t\t" << string(100, char(196));
		cout << "\n\t\t\t0. return";
		cout << "\n\t\t" << string(100, char(205));

		int option = inputInteger("\n\t\t\tOption: ", 0, 9);

		switch (option) {
		case 0:
			cout << "\n\n\t\t";
			system("pause"); return;
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
			int number = inputInteger("\n\t\t\tEnter an integer value: ");
			r2 = r1 / number;
			

			cout << "\n\t\t\tR2 / value";
			cout << "\n\t\t\t(" << r1 << ") / " << number << " = " << r2;
			cout << endl;
			r2 = number / r1;
			
			cout << "\n\t\t\tvalue / R2";
			cout << "\n\t\t\t" << number << " / (" << r1 << ") = " << r2;
			break;
		}

		default: cout << "\n\t\t\tERROR - INVALID CHOICE"; break;
		}
		cout << "\n\n\t\t";
		system("pause");
	}while (true);
}

void caseTwoOptionB() {
	Rational r1;
	Rational r2;
	Rational r3;
	do {
		system("cls");
		cout << "\n\t\tB> Multiple Rational Numbers";
		cout << "\n\t\t" << string(100,char(205));
		cout << "\n\t\t\t1. Enter rational number R1";
		cout << "\n\t\t\t2. Enter rational number R2";
		cout << "\n\t\t\t3. Verify condition operators (==, !=, >=, >, <= and <) of R1 and R2";
		cout << "\n\t\t\t4. Evaluate arithmatic operators (+, - , * and /) of R1 and R2";
		cout << "\n\t\t\t5. Evaluate (3 * (R1 + R2) / 7) / (R2 - R1 / 9) >= 621/889";
		cout << "\n\t\t" << string(100, char(196));
		cout << "\n\t\t\t0. return";
		cout << "\n\t\t" << string(100, char(205));
		int option = inputInteger("\n\t\t\tOption: ", 0, 9);

		switch (option) {
		case 0: 
			cout << "\n\n\t\t";
			system("pause"); return;
		case 1:
			try {
				int numerator = inputInteger("\n\t\t\tEnter the numerator for R1: ");
				int denominator = inputInteger("\n\t\t\tEnter the denominator for R1: ");
				Rational tempR1(numerator, denominator);
				r1 = tempR1;
				cout << "\n\t\t\tR1 = " << r1;
			}
			catch (Rational::ZeroDenominator& e)
			{
				cout << "\n\t\tEXCEPTION ERROR: Cannot use Rational number, " << e.toString() << ", with a zero denominator value.";
			}
			break;
		case 2: 
			try {
				int numerator = inputInteger("\n\t\t\tEnter the numerator for R2: ");
				int denominator = inputInteger("\n\t\t\tEnter the denominator for R2: ");
				Rational tempR2(numerator, denominator);
				r2 = tempR2;
			
				cout << "\n\t\t\tR2 = " << r2;
			}
			catch (Rational::ZeroDenominator& e)
			{
				cout << "\n\t\tEXCEPTION ERROR: Cannot use Rational number, " << e.toString() << ", with a zero denominator value.";
			}

			break;
		case 3:
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

			break;

		case 4: 
			try {
				Rational temp;
				temp = r1 + r2;
			
				cout << "\n\t\t\tAddition    : R1 + R2 -> (" << r1 << ") + (" << r2 << ") = " << temp;
				temp = r1 - r2;
				
				cout << "\n\t\t\tSubtraction : R2 - R1 -> (" << r1 << ") - (" << r2 << ") = " << temp;
				temp = r1 * r2;
				
				cout << "\n\t\t\tMutiplcation: R1 * R2 -> (" << r1 << ") * (" << r2 << ") = " << temp;
				temp = r1 / r2;
	
				cout << "\n\t\t\tDivision    : R2 / R1 -> (" << r1 << ") / (" << r2 << ") = " << temp;
			}
			catch (Rational::ZeroDenominator& e) {
				cout << "\n\t\t\tDivision    : R2 / R1 -> (" << r1 << ") / (" << r2 << ") = " << e.toString();
			}
	
			break;

		case 5: 
			try {
				r3.setNumerator(621);
				r3.setDenominator(889);
				cout << "\n\t\t\tR1 = " << r1;
				cout << "\n\t\t\tR2 = " << r2;
				cout << "\n\t\t\tR3 = " << r3;
				cout << "\n\t\t\tEvaluating expression...";
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
		}

		cout << "\n\n\t\t";
		system("pause");
	} while (true);
}
