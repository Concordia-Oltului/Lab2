#include <iostream>
#include "Complex_test.h"
#include "Complex.h"


int main()
{
    Complex a;
    Complex b(2, 3);
    Complex c(b);
    a = b;

    run_all_tests();

    return 0;
}