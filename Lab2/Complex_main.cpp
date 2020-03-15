#include <iostream>
#include <fstream>
#include "Complex_test.h"
#include "Complex.h"

void sort_betrag(Complex s[], int n) {
    /*
    Sort elements from s via abs
    Input:
        s - Complex array
        n - int
    Output:
        -
    @author: Stefan
    */
    bool sch = true;
    while (sch)
    {
        sch = false;
        for (int i = 0; i < n-1; i++) {
            if (s[i].abs() > s[i + 1].abs()) {
                Complex aux;
                aux = s[i];
                s[i] = s[i + 1];
                s[i + 1] = aux;
                sch = true;
            }
        }
    }
}

Complex Sum_all(Complex s[], int n) {
    /*
    Calculate sum of all elements from s
    Input:
        s - Complex array
        n - int
    Output:
        Complex
    @author: Stefan
    */
    Complex rez(0, 0);
    for (int i = 0; i < n; i++)
        rez = rez + s[i];
    return rez;
}


int main()
{
    Complex s[100];
    ifstream fin("int.txt");
    int n;
    double a, b;
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> a;
        fin >> b;
        Complex x(a, b);
        s[i] = x;
    }

    sort_betrag(s,n);
    Complex x = Sum_all(s, n);
    cout << x.get_real_part() << " " << x.get_imaginary_part();
    run_all_tests();

    return 0;
}