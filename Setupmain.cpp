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
void polynomials();
void optionASinglePolynomial();
void number_of_terms(Polynomial&, bool, string);
void specify_coefficients(Polynomial&, bool);
void eval_exp(const Polynomial&);
void derivative(Polynomial&);
void integral(Polynomial&);
void display_Poly(const Polynomial&, const string&, const int&);
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

//================================================================================================================== 
// Option 2 - Rational Numbers Section
//================================================================================================================== 
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
int optionARationalNumber()
{
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
		default: cout << "\t\tERROR: - Invalid option. Please re-enter"; break;
		}
		cout << "\n";
		system("pause");
	} while (true);

	return 0;
}
int optionBMultipleRationalNumbers()
{
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
//Precondition: N/A
//Postcondition: Redirects to optionASinglePolynomial() or optionB
void polynomials()
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
			case '0': return;
			case 'A': system("cls"); optionASinglePolynomial(); break;
			case 'B': system("cls"); optionBTwoPolynomials(); break;

			default: cout << "\n\tERROR: - Invalid option. Please re-enter"; break;
		}
		cout << "\n";
		system("pause");
	} while (true);

}

//Precondition: N/A
//Postcondition: Redirects to number_of_terms(), specify_coefficients(), eval_exp(), derivative(), integral()
void optionASinglePolynomial()
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
			case 0: return;
			case 1: number_of_terms(p1, true, "polynomial: "); break;
			case 2: specify_coefficients(p1, true);  break;
			case 3: eval_exp(p1); break;
			case 4: derivative(p1); break;
			case 5: integral(p1); break;
			default: cout << "\n\tERROR: - Invalid option. Please re-enter"; break;
		}
		cout << "\n";
		system("pause");
	} while (true);

}

//Precondition: class Polynomial, true or false to indicate whether you will manipulate hash maps: First_Poly or Second_Poly, prompt to cout
//Postcondition: sets size of First_Poly or Second_Poly 
//NOTICE: we only clear First_Poly because Second_Poly is used in Option B, where we deallocate the class Polynomial, we clear First_Poly 
//because we want to create an error message whenever the player attempts to reuse the past hashmap
void number_of_terms(Polynomial & p1, bool choice, string prompt) {

	int size = (inputInteger("\n\tEnter the number of terms(1..100) for the "+prompt, 1, 100));
	
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
void specify_coefficients(Polynomial & p1, bool choice) {
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
void eval_exp(const Polynomial & p1) {

	//error messages: empty hashmap, empty size
	if (p1.get_First_Size() == 0) {
		cout << "\n\tERROR: Please confirm size of polynomials. Please chose option 1.";
		return;
	}

	if (p1.get_First_Empty()) {
		cout << "\n\tERROR: There are no inputted polynomials. Please chose option 2.";
		return;
	}

	display_Poly(p1, "P1(x) = ", 1);

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

	display_Poly(p1, "Polynomial(x) = ", 1);

	p1.set_Derive();

	display_Poly(p1, "Derivative    = ", 3);

}

//Precondition: class Polynomial, must have filled in First_Poly and valid size
//Postcondition: will do the integral of First_Poly, store it into Final_Poly, and display
void integral (Polynomial& p1) {

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

	display_Poly(p1, "Polynomial(x) = ", 1);

	p1.set_Integral();

	display_Poly(p1, " Integral      = ", 3);

}

//Precondition: class Polynomial, string prompt for display, choice gives you the ability to display 1-First_Poly
// 2-Second_Poly, 3-Final_Poly, must have filled the correct hash map to display
//Postcondition: will display contents in 1-First_Poly 2-Second_Poly, 3-Final_Poly in format of polynomial
void display_Poly(const Polynomial & p1, const string & prompt, const int & choice){

	cout << "\n\t" << prompt;
	int size = 0;
	double data_val = 0; //used to retrieve the value inside one of the hashmap
	int limit = -1;

	//gets the size of the Poly hashmap we are using and possibly the (lower) limit
	//NOTICE: For First_Poly and Second_Poly the size starts at size = -1 and ends at 0 (limit is -1) as 
	//key will start with greatest power and end with lowest Ex: size = 4 3x^3 .... + 1x^0
	//Final_Size may follow these rules as well, but if it is made to display the integral, key starts at
	//size and ends at 1 (limit is 0) ex: size = 4 1/4(x^4)+....1x^(1)
	// if it is made to display a derivative, power is subtracted by 1, causing size to be subtracted by 2
	// size - 2 to end 0 (limit -1).. 2x^2+x+2 = 4x+1 (key = 1 value = 4, key = 0, value = 1)
	//otherwise, it will follow the same rules as First_Poly and Second_Poly
	switch (choice) {
		case 1: size = p1.get_First_Size() - 1; break;
		case 2: size = p1.get_Second_Size() - 1; break;
		case 3: size = p1.get_Final_Size(); limit = p1.get_Limit();  break;
		default: "\n\tERROR, input must be between 1 and 3"; return;
	}

	//gains first data (ex: 3x^3+2x^2+x+8, will get 3x^3 first, then 2x^2....)
	for (int i = size; i > p1.get_Limit(); i--) {

		switch (choice) {
		case 1: data_val = p1.get_First_Poly(&i); break;
		case 2: data_val = p1.get_Second_Poly(&i); break;
		case 3: data_val = p1.get_Final_Poly(&i); break;
		}

		//if not at beginning, displays + or -
		if (i != size) {
			if (data_val < 0) {
				data_val *= -1;
				cout << " - ";
			}
			else
				cout << " + ";
		}

		//examples for each format: x^3, x, 3
		if (i > 1) {
			cout << data_val << "x^" << i;
		}
		else if (i == 1) {
			cout << data_val << "x";
		}
		else {
			cout << data_val;
		}
	}
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
	display_Poly(p2, "The first polynomial (P1) is entered: ", 1);

	//gets size, fills in Second_Poly, displays
	number_of_terms(p2, false, "second polynomial (P2): ");
	specify_coefficients(p2, false);
	display_Poly(p2, "The second polynomial (P2) is entered: ", 2);

	//adds both poly, display
	p2.set_Add_Sub(true);
	display_Poly(p2, "Addition of polynomials       -> P1 + P2 = ", 3);

	//clears to ensure it will not retain past values
	p2.set_Final_Clear();

	//subtracts both poly, display
	p2.set_Add_Sub(false);
	display_Poly(p2, "Subtraction of polynomials     -> P1 - P2 = ", 3);

	//clears Final_Poly
	p2.set_Final_Clear();

	//multiplies both poly, display
	p2.set_Multiplication();
	display_Poly(p2, "Multiplication of polynomials -> P1 * P2 = ", 3);

	//data result multiplies value from player and the data from First_Poly
	//position is set to get number with greatest power, size - i ex:
	//3x^2 + x + 1 size = 3, position = 3-1 = 2 key = 2 (3x^2), 3-2 key = 1 (x), 3-3 key = 0 (1)
	const double player_val = inputInteger("\n\tEnter a constant value: ");
	double data_result = 0;
	int position = 0;

	for (int i = 1; i <= p2.get_First_Size(); i++) {
		position = p2.get_First_Size() - i;
		data_result = player_val * p2.get_First_Poly(&position);
		p2.set_First_Poly(&i, &data_result);
	}

	//displays new First_Poly
	display_Poly(p2, to_string(player_val) + "* Polynomial(P1) = ", 1);

	//multiplies value with Second_Poly elements, then displays
	for (int i = 1; i <= p2.get_Second_Size(); i++) {
		position = p2.get_Second_Size() - i;
		data_result = player_val * p2.get_Second_Poly(&position);
		p2.set_Second_Poly(&i, &data_result);
	}

	display_Poly(p2, to_string(player_val) + " * Polynomial(P2) = ", 2);

}
