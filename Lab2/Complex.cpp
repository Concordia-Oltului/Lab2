#include "Complex.h"
#include <iostream>
#include <cmath>

using namespace std;

Complex::Complex(){
	// @author: Stefan
	real_part = 0;
	imaginary_part = 0;
};

Complex::Complex(double real, double img){
	// @author: Stefan
	real_part = real;
	imaginary_part = img;
};

Complex::Complex(const Complex& c) {
	// @author: Stefan
	real_part = c.real_part;
	imaginary_part = c.imaginary_part;
}

Complex Complex::operator= (const Complex& c) {
	/*
	Copy attributs value from one complex number to the otherone
	Input:
		c - Complex
	Output:
		Complex

	@author: Stefan
	*/
	real_part = c.real_part;
	imaginary_part = c.imaginary_part;
	return *this;
}

double Complex::get_real_part() {
	// @author: Stefan
	return real_part;
}

double Complex::get_imaginary_part() {
	// @author: Stefan
	return imaginary_part;
}

Complex Complex::operator+(Complex c) {
	/*
	Adds 2 complex elements and returns the result
	Input:
		c - Complex
	Output:
		Complex

	@author: Stefan
	*/
	Complex rez;
	rez.real_part = real_part + c.real_part;
	rez.imaginary_part = imaginary_part + c.imaginary_part;
	return rez;
}

Complex Complex::operator/(Complex c) {
	/*
	Divides 2 complex elements and returns the result
	Input:
		c - Complex
	Output:
		Complex

	@author: Stefan
	*/

	Complex rez;
	//z1 = a1 + b1*i
	//z2 = a2 + b2*i
	//rez = (a1*a2 + b1*b2)/(a2*a2 + b2*b2) + (a2*b1 - a1*b2)/(a2*a2 + b2*b2) * i
	//				^ Real Part ^					^ Imaginary Part ^
	double denominator = (c.real_part * c.real_part + c.imaginary_part * c.imaginary_part);
	rez.real_part = (real_part * c.real_part + imaginary_part * c.imaginary_part) / denominator;
	rez.imaginary_part = (c.real_part * imaginary_part - real_part * c.imaginary_part) / denominator;
	return rez;
}

double Complex::abs() {
	/*
	Returns the absolute value of the Complex number
	Input:
		-
	Output:
		double
	@author Stefan
	*/

	double rez;
	rez = sqrt(real_part * real_part + imaginary_part * imaginary_part);
	return rez;
}







Complex::~Complex() {
	
}
