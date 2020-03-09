#pragma once
using namespace std;



class Complex {
private:
	double parte_reala, parte_fractionara;
public:
	//constructor implicit
	Complex();

	//constructor de copiere
	Complex(const Complex&);

	//functia de copiere
	Complex operator= (Complex c);

	//returneaza ceva
	double show_comp();

	//returneaza ceva
	double show_exp();

	//Face adunarea
	Complex operator+ (Complex c);

	//Face inmultire
	Complex operator* (Complex c);
	
	//Face inpartire
	Complex operator/ (Complex c);

	//ABS
	double abs();

	//De adaugat polar form


	//destructor
	~Complex();

	//aici punem metodele

};
