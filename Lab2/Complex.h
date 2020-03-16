#pragma once
#include <string>

using namespace std;

class Complex {
private:
	double real_part, imaginary_part;
public:
	//constructor implicit
	Complex();

	//constructor explicit
	Complex(double real, double img);

	//constructor de copiere
	Complex(const Complex& c);

	//functia de copiere
	Complex operator= (const Complex& c);

	//Returns real_part of the complex number 
	double get_real_part();

	//Returns imaginary_part of the complex number 
	double get_imaginary_part();

	//returneaza forma algebrica
	char* show_comp();

	//returneaza forma exponentiala
	char* show_exp();

	//returneaza forma polara
	char* show_polar();

	//Face adunarea
	Complex operator+ (Complex c);

	//Face inmultire
	Complex operator* (Complex c);
	
	//Face inpartire
	Complex operator/ (Complex c);

	//ABS
	double abs();

	//forma polara
	double compute_polar();


	//destructor
	~Complex();

	//aici punem metodele

};
