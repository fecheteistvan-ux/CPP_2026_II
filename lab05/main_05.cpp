#include <iostream>
#include <cassert>
#include "Matrix.h"
using namespace std;
Matrix createSquareMatrix(int size) {
    Matrix m(size, size);
    m.fillMatrix(1);
    return m;
}
int main() {
    cout << "**************************************\n";
    cout << " Konstruktor teszt\n";
    cout << "**************************************\n";
    Matrix m1(2, 3);
    m1.fillMatrix(5);
    cout << "m1:\n" << m1 << endl;
    assert(m1.getRows() == 2 && m1.getCols() == 3);
    cout << "**************************************\n";
    cout << " + operator teszt\n";
    cout << "**************************************\n";
    Matrix m2(2, 3);
    m2.fillMatrix(2);
    Matrix m3 = m1 + m2;
    cout << "m3 = m1 + m2:\n" << m3 << endl;
    assert(m3(0,0) == 7);
    cout << "**************************************\n";
    cout << " + operator (hibás méret) teszt\n";
    cout << "**************************************\n";
    try {
        Matrix m4(3,3);
        m4.fillMatrix(1);
        Matrix m5 = m1 + m4;
        assert(false); // ide nem szabad eljutni
    } catch (out_of_range& e) {
        cout << "Kivetel helyesen elkapva: " << e.what() << endl;
    }
    cout << "**************************************\n";
    cout << " = operator (copy assignment)\n";
    cout << "**************************************\n";
    Matrix m6(2, 3);
    m6.fillMatrix(0);
    m6 = m3;
    cout << "m6:\n" << m6 << endl;
    assert(m6(0,0) == 7);
    cout << "**************************************\n";
    cout << " Copy constructor teszt\n";
    cout << "**************************************\n";
    Matrix m7(m6);
    cout << "m7 (copy of m6):\n" << m7 << endl;
    assert(m7(0,0) == 7);
    cout << "**************************************\n";
    cout << " Move constructor teszt\n";
    cout << "**************************************\n";
    Matrix m8 = std::move(createSquareMatrix(3));
    cout << "m8 (moved from temporary):\n" << m8 << endl;
    assert(m8.isSquare() && m8.getRows() == 3 && m8.getCols() == 3);
    cout << "**************************************\n";
    cout << " * operator teszt\n";
    cout << "**************************************\n";
    Matrix ma(2, 3), mb(3, 2);
    ma.fillMatrix(1);
    mb.fillMatrix(2);
    Matrix mc = ma * mb;
    cout << "mc = ma * mb:\n" << mc << endl;
    assert(mc.getRows() == 2 && mc.getCols() == 2);
    assert(mc(0,0) == 6); // 1*2 + 1*2 + 1*2 = 6
    cout << "**************************************\n";
    cout << " Index operator teszt\n";
    cout << "**************************************\n";
    cout << "mc[0][0] = " << mc[0][0] << endl;
    assert(mc[0][0] == 6);
    cout << "**************************************\n";
    cout << " Biztonságos index operatorok tesztje (operator())\n";
    cout << "**************************************\n";
    // operator()(row,col) — írás és olvasás
    Matrix safe(2,2);
    safe.fillMatrix(0.0);
    safe(0,1) = 42.5;
    assert(safe(0,1) == 42.5);
    cout << "**************************************\n";
    cout << " Move assignment teszt\n";
    cout << "**************************************\n";
    Matrix md(2,2);
    md = std::move(mc);
    cout << "md (after move):\n" << md << endl;
    assert(md(0,0) == 6);
    cout << "**************************************\n";
    cout << "Minden teszt sikeresen lefutott!\n";
    cout << "**************************************\n";
    return 0;
}