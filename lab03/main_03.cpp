#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include "PointSet.h"

using namespace std;

// --- Teszt esetek ---
void testPoint() {
    Point p1(0, 0);
    Point p2(3, 4);
    assert(p1.getX() == 0 && p1.getY() == 0);
    assert(p2.getX() == 3 && p2.getY() == 4);
    assert(abs(p1.distanceTo(p2) - 5.0) < 1e-5);
    cout << "[OK] Point tesztek sikeresek." << endl;
}

void testPointSetBasic() {
    int n = 5;
    PointSet pSet(n);


    assert(pSet.numDistances() == 10);
    assert(pSet.minDistance() <= pSet.maxDistance());

    pSet.sortPointsX();
    pSet.sortDistances();
    assert(pSet.numDistinctDistances() >= 1 && pSet.numDistinctDistances() <= 10);

    cout << "[OK] PointSet alapveto tesztek sikeresek." << endl;
}


void runLabExperiment() {
    cout << "\n=== LABOR KISÉRLET ===" << endl;
    int n = 2;
    cout << "Pontok\tMinTav\t  MaxTav\t#tavolsagok\t#kulonbozotavolsagok" << endl;
    cout << fixed;

    for (int i = 0; i < 12; ++i) {
        PointSet pSet(n);
        cout << setw(6) << n << " ";
        cout << setw(8) << setprecision(2) << pSet.minDistance() << " ";
        cout << setw(8) << setprecision(2) << pSet.maxDistance() << " ";
        cout << setw(10) << pSet.numDistances() << " ";
        cout << setw(16) << pSet.numDistinctDistances() << endl;

        n = n << 1; // n duplázása (2, 4, 8, 16, ...)
    }
}

int main() {
    cout << "--- Egységtesztek futtatasa ---" << endl;
    testPoint();
    testPointSetBasic();

    runLabExperiment();

    return 0;
}