#include <iostream>
#include "Polynomial.h"
int main() {
    double c1[] = {1, -3, 2};
    Polynomial p1(2, c1);

    double c2[] = {2, 1};
    Polynomial p2(1, c2);

    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;

    cout << "Fokszam (p1): " << p1.degree() << endl;
    cout << "Ertek (p1, x=2): " << p1.evaluate(2) << endl;

    Polynomial p1_copy = p1;
    cout << "p1_copy: " << p1_copy << endl;

    Polynomial p_der = p1.derivative();
    cout << "Derivalt (p1): " << p_der << endl;

    cout << "p1[0]: " << p1[0] << endl;

    Polynomial p_neg = -p1;
    cout << "-p1: " << p_neg << endl;

    Polynomial p_sum = p1 + p2;
    cout << "p1 + p2: " << p_sum << endl;

    Polynomial p_diff = p1 - p2;
    cout << "p1 - p2: " << p_diff << endl;

    Polynomial p_prod = p1 * p2;
    cout << "p1 * p2: " << p_prod << endl;
    return 0;
}