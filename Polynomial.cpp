#include "Polynomial.h"

//CONSTRUCTORS:
//sets every size to 0, sets lower limit to -1 for later use in loop
Polynomial::Polynomial() {
	first_size = 0;
	second_size = 0;
	final_size = 0;
	lower_limit = -1;
	choice = 0;
}

//MUTATORS:
//Precondition: pointer to address of size
//Postcondition: sets first_size
void Polynomial::set_First_Size(const int* size) {
	first_size = (*size);
}

//Precondition: pointer to address of size
//Postcondition: sets second_size
void Polynomial::set_Second_Size(const int* size) {
	second_size = (*size);
}

//Precondition: pointer to address of iterator and value
//Postcondition: will set values in first polynomial hashmap
//Notice: value in iter will be the exponent (^4), value in data is the coefficient
//if iter points to value 1 and size is 5, iter (5-1) = (^4), and stores the correct data with exponent key
void Polynomial::set_First_Poly(const int* iter, const double* data) {
	First_Poly[(first_size - (*iter))] = (*data) * 1.00;
}

//Precondition: pointer to address of iterator and value
//Postcondition: will set values in second polynomial hashmap
//Notice: value in iter will be the exponent (^4), value in data is the coefficient
//if iter points to value 1 and size is 5, iter (5-1) = (^4), and stores the correct data with exponent key
void Polynomial::set_Second_Poly(const int* iter, const double* data) {
	Second_Poly[(second_size - (*iter))] = (*data) * 1.00;
}

//Precondition: N/A
//Postcondition: clears First_Poly
void Polynomial::set_First_Clear() {
	First_Poly.clear();
}

//Precondition: N/A
//Postcondition: clears Final_Poly
void Polynomial::set_Final_Clear() {
	Final_Poly.clear();
}

//Precondition: must have full First_Poly
//Postcondition: will set up Final_Poly with the derivative of the polynomial
//Notice: hash map starts at size - 2 and ends at 0 (limit -1) due to it being changed by power
//example: 2x^2+1x+2 size = 3, key = 1 data = 4 (4x^1), key = 0 data = 1  (1)
void Polynomial::set_Derive() {
	for (int i = first_size - 1; i > 0; i--) {
		Final_Poly[(i - 1)] = i * get_First_Poly(&i) * 1.00;
	}

	final_size = first_size - 2;
	lower_limit = -1;
}

//Precondition: must have full First_Poly
//Postcondition: will set up Final_Poly with the integral of the polynomial
//Notice: hash map starts at size and ends at 1 (limit 0) due to it being changed by power
//example: 2x^2+1x+2 size = 3, key = 3 data = 2/3 (2/3x^3), key = 2 data = 1/2  (1/2x^2), key = 1 data = 2 (2x)
void Polynomial::set_Integral() {
	for (int i = first_size - 1; i > -1; i--) {
		Final_Poly[(i + 1)] = get_First_Poly(&i) / (i + 1);
	}
	final_size = first_size;
	lower_limit = 0;
}

//Precondition:choice to chose between subtracting/adding First_Poly and Second_Poly(both must be filled)
//Postcondition: fills Final_Poly with subtracted/added polynomials
//size of it will be minus a 1 (power), end will be 0 (limit is -1) 
void Polynomial::set_Add_Sub(const bool& choice) {

	//finds the greatest size to add on to the last polynomials
	//stores value from first and second hash map, used in calculations
	int greater_size = second_size;
	double value_1 = 0, value_2 = 0;

	if (first_size > second_size)
		greater_size = first_size;

	final_size = greater_size - 1;
	lower_limit = -1;

	//if they are out of boundary, sets value as 0
	//else assings proper value and carries subtraction or addition
	for (int i = 0; i < greater_size; i++) {
		if (i >= First_Poly.size()) {
			value_1 = 0;
			value_2 = Second_Poly[i];
		}
		else if (i >= Second_Poly.size()) {
			value_1 = First_Poly[i];
			value_2 = 0;
		}
		else {
			value_1 = First_Poly[i];
			value_2 = Second_Poly[i];
		}

		if (choice)
			Final_Poly[i] = value_1 + value_2;
		else
			Final_Poly[i] = value_1 - value_2;
	}
}

//Precondition: First_Poly and Second_Poly must be filled
//Postcondition: multiplies all values and stores into Final_Poly
//size of it will be minus a 1 (power), end will be 0 (limit is -1) 
void Polynomial::set_Multiplication() {

	//value get result of multiplied coefficients
	lower_limit = -1;
	double value = 0;

	//goes through the first coefficient of First_Poly, multiplies with all elements of Second Poly
	//if it is already in the hadh map, adds with the number stored, otherwise places in
	for (int i = 0; i < first_size; i++) {
		for (int j = 0; j < second_size; j++) {
			value = First_Poly[i] * Second_Poly[j];

			if (Final_Poly.find((i + j)) != Final_Poly.end()) {
				Final_Poly[(i + j)] = Final_Poly[(i + j)] + value;
			}
			else {
				Final_Poly[(i + j)] = value;
			}
		}
	}

	//calculates size 
	final_size = static_cast<int>(Final_Poly.size()) - 1;
}

//Precondition: number must be from 1-3
//Postcondition: returns choice for use in the friennd outstream
void Polynomial::set_Choice(const int& number) {
	choice = number;
}

//ACCESSORS:
//Precondition: N/A (initialized first_size)
//Postcondition: returns first_size
int Polynomial::get_First_Size() const {
	return first_size;
}

//Precondition: N/A (initialized second_size)
//Postcondition: returns second_size
int Polynomial::get_Second_Size() const {
	return second_size;
}

//Precondition: N/A (initialized final_size)
//Postcondition: returns final_size
int Polynomial::get_Final_Size() const {
	return final_size;
}

//Precondition: N/A (initialized lower_limit)
//Postcondition: returns lower_limit
int Polynomial::get_Limit() const {
	return lower_limit;
}

//Precondition: N/A
//Postcondition: returns true if First_Poly empty, else false
bool Polynomial::get_First_Empty() const {
	if (First_Poly.empty()) {
		return true;
	}

	return false;
}

//Precondition: First_Poly must be filled, pointer pointing at address of iter
//Postcondition: returns value at value First_Poly the value ofpointer
double Polynomial::get_First_Poly(const int* iter) const {
	return First_Poly.at(*iter);
}

//Precondition: Second_Poly must be filled, pointer pointing at address of iter
//Postcondition: returns value Second_Poly from at the value of pointer
double Polynomial::get_Second_Poly(const int* iter) const {
	return Second_Poly.at(*iter);
}

//Precondition: Final_Poly must be filled, pointer pointing at address of iter
//Postcondition: returns value Final_Poly from at the value of pointer
double Polynomial::get_Final_Poly(const int* iter) const {
	return Final_Poly.at(*iter);
}

//Precondition: outstream to display, class Polynomial, choice gives you the ability to display 1-First_Poly
// 2-Second_Poly, 3-Final_Poly, must have filled the correct hash map to display
//Postcondition: displays polynomial to be displayed in main
ostream& operator<<(ostream& out, const Polynomial& p1) {

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
	switch (p1.choice) {
	case 1: size = p1.get_First_Size() - 1; break;
	case 2: size = p1.get_Second_Size() - 1; break;
	case 3: size = p1.get_Final_Size(); limit = p1.get_Limit();  break;
	}

	//gains first data (ex: 3x^3+2x^2+x+8, will get 3x^3 first, then 2x^2....)
	for (int i = size; i > p1.get_Limit(); i--) {
		switch (p1.choice) {
		case 1: data_val = p1.get_First_Poly(&i); break;
		case 2: data_val = p1.get_Second_Poly(&i); break;
		case 3: data_val = p1.get_Final_Poly(&i); break;
		}

		//if not at beginning, displays + or -
		if (i != size) {
			if (data_val < 0) {
				data_val *= -1;
				out << " - ";
			}
			else
				out << " + ";
		}

		//examples for each format: x^3, x, 3
		if (i > 1) {
			out << data_val << "x^" << i;
		}
		else if (i == 1) {
			out << data_val << "x";
		}
		else {
			out << data_val;
		}
	}

	return out;
}
