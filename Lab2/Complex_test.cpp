#include "Complex_test.h"
#include "Complex.h"
#include <iostream>
#include <cassert>

void test_constructor() {
    //@author: Stefan
    Complex a;
    Complex b(2, 3);
    assert(b.get_real_part() == 2);
    assert(b.get_imaginary_part() == 3);
    Complex c(b);
    assert(c.get_real_part() == 2);
    assert(c.get_imaginary_part() == 3);
    a = b;
    assert(a.get_real_part() == 2);
    assert(a.get_imaginary_part() == 3);
}

void test_add() {
    //@author: Stefan
    Complex a(3, 6), b(-3, 9.3);
    Complex rez = a + a;
    assert(rez.get_real_part() == 6);
    assert(rez.get_imaginary_part() == 12);
    rez = a + b;
    assert(rez.get_real_part() == 0);
    assert(rez.get_imaginary_part() == 15.3);

}

void test_division() {
    //@author: Stefan
    Complex a(3, 6), b(3, 9);
    Complex rez = a / a;
    assert(rez.get_real_part() == 1);
    assert(rez.get_imaginary_part() == 0);
    rez = a / b;
    assert(rez.get_real_part() == 0.7);
    assert(rez.get_imaginary_part() == -0.1);

}

void test_abs() {
    Complex a(3, 4);
    double abs_rez = a.abs();
    assert(abs_rez == 5);
    Complex b(0, 1);
    abs_rez = b.abs();
    assert(abs_rez == 1);
    Complex c(0, 1);
    abs_rez = c.abs();
    assert(abs_rez == 1);
}

void test_computepolar() {
    // @author: Victor
	Complex a(3, 4);
	a.compute_polar();
    double r = a.get_r(), theta = a.get_theta();
    assert(r == 5);
}

void test_showcomp() {
    // @author: Victor
    Complex a(5, 2);
    char* buff = a.show_comp();
    assert(buff != NULL);
}

void test_showexp() {
    // @author: Victor
    Complex a(5, 2);
    a.compute_polar();
    char* buff = a.show_exp();
    assert(buff != NULL);
}

void test_showpolar() {
    // @author: Victor
    Complex a(5, 2);
    a.compute_polar();
    char* buff = a.show_polar();
    assert(buff != NULL);
}

void run_all_tests() {
    test_constructor();
    test_add();
    test_division();
    test_abs();
	test_computepolar();
    test_showcomp();
    test_showexp();
    test_showpolar();
}