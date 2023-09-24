#pragma once
#include <unordered_map> //for my hashmap, attempting a more efficient dynamic allocation

class Polynomial {
private:
	typedef double value_type;
	int first_size; //size of First_Poly
	int second_size; //size of Second_Poly
	int final_size; //size of Final_Poly
	int lower_limit; //lower limit (boundary) of Final_Poly
	std::unordered_map<int, value_type> First_Poly; //stores power, stores coefficient
	std::unordered_map<int, value_type> Second_Poly; //stores power, stores coefficient
	std::unordered_map<int, value_type> Final_Poly; //stores power, stores coefficient, is used for answers or storage

public:
	//CONSTRUCTORS:
	Polynomial(); //for option 1

	//MUTATORS:
	void set_First_Size(const int*);
	void set_Second_Size(const int*);
	void set_First_Poly(const int*, const double*);
	void set_Second_Poly(const int*, const double*);
	void set_First_Clear();
	void set_Final_Clear();
	void set_Derive();
	void set_Integral();
	void set_Add_Sub(const bool&);
	void set_Multiplication();


	//ACCESSORS:
	int get_First_Size() const;
	int get_Second_Size() const;
	int get_Final_Size() const;
	int get_Limit() const;
	bool get_First_Empty() const;
	double get_First_Poly(const int*) const;
	double get_Second_Poly(const int*) const;
	double get_Final_Poly(const int*) const;
};
