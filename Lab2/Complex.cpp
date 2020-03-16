#include "Complex.h"
#include <iostream>
#include <cmath>
#include <string>
#include <stdio.h>

using namespace std;

//changes - added theta & r in constructors; added PI definition; added compute_polar; added theta & r getters; show_comp, show_exp definition

#define PI 3.14159265

Complex::Complex(){
	// @author: Stefan
	real_part = 0;
	imaginary_part = 0;
	r = 0;
	theta = 0;
};

Complex::Complex(double real, double img){
	// @author: Stefan
	real_part = real;
	imaginary_part = img;
	r = 0;
	theta = 0;
};

Complex::Complex(const Complex& c) {
	// @author: Stefan
	real_part = c.real_part;
	imaginary_part = c.imaginary_part;
	if (c.r != 0)
	{
		r = c.r;
		theta = c.theta;
	}
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
	if (c.r != 0)
	{
		r = c.r;
		theta = c.theta;
	}
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

double Complex::get_r() {
	// @author: Victor
	return r;
}

double Complex::get_theta() {
	// @author: Victor
	return theta;
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


void Complex::compute_polar() {
	/*
	Computes the polar form arguments of a complex number
	Input:
		-
	Output:
		-
	@author: Victor
	*/
	r = abs();
	if (real_part > 0)
	{
		theta = atan(imaginary_part / real_part);
	}
	else
		theta = atan(imaginary_part / real_part) + PI;
}


char* Complex::show_comp() {
	// @author: Victor
	char* buffer = new char[50];
	sprintf(buffer, "z = %.2f + %.2fi", real_part, imaginary_part);
	return buffer;
}

char* Complex::show_exp() {
	// @author: Victor
	char* buffer = new char[50];
	sprintf(buffer, "z = %.2f * e ^ (i*%.2f)", r, theta);
	return buffer;
}

char* Complex::show_polar() {
	// @author: Victor
	char* buffer = new char[50];
	sprintf(buffer, "z = %.2f(cos(%.2f) + isin(%.2f))", r, theta, theta);
	return buffer;
}


Complex::~Complex() {
	
}
