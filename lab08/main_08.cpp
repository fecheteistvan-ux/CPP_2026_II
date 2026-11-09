#include <iostream>
#include <vector>
#include <string>
#include "Lab7.h"

using namespace std;

int main() {
    cout << "=== 7. GYAKORLAT: Algoritmusok es Lambdak ===" << endl << endl;

    cout << "--- 1. Feladat ---" << endl;
    vector<string> fruits { "melon", "strawberry", "raspberry", "apple", "banana", "walnut", "lemon" };
    string searchPattern = "berry";
    bool found = hasFruitWithSubstring(fruits, searchPattern);
    cout << "Tartalmaz-e a tomb '" << searchPattern << "' reszletet? " << (found ? "Igen" : "Nem") << endl;

    cout << endl << "--- 2. Feladat ---" << endl;
    vector<int> numbers1 { 2, 4, 6, 8, 10 };
    vector<int> numbers2 { 2, 3, 6, 8, 10 };
    cout << "numbers1 mind paros: " << (areAllEven(numbers1) ? "Igen" : "Nem") << endl;
    cout << "numbers2 mind paros: " << (areAllEven(numbers2) ? "Igen" : "Nem") << endl;

    cout << endl << "--- 3. Feladat ---" << endl;
    vector<int> numbers3 { 1, 2, 3, 4, 5 };
    printVector(numbers3, "Eredeti szamok");
    doubleElements(numbers3);
    printVector(numbers3, "Megduplazott szamok");

    cout << endl << "--- 4. Feladat ---" << endl;
    vector<string> months {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    cout << "Ot betus honapok szama: " << countFiveLetterMonths(months) << endl;

    cout << endl << "--- 5. Feladat ---" << endl;
    vector<double> reals1 { 3.14, -1.5, 42.0, 0.0, -9.81, 2.71 };
    vector<double> reals2 = reals1;

    sortDescendingLambda(reals1);
    printVector(reals1, "Csokkeno rendezes (Lambda)");

    sortDescendingFunctor(reals2);
    printVector(reals2, "Csokkeno rendezes (greater<>)");

    cout << endl << "--- 6. Feladat ---" << endl;
    vector<pair<string, double>> monthlyTemps {
        {"Jan", -1.5}, {"Feb", 0.5}, {"Mar", 5.2}, {"Apr", 11.0},
        {"May", 16.3}, {"Jun", 19.8}, {"Jul", 22.1}, {"Aug", 21.5},
        {"Sep", 16.8}, {"Oct", 10.9}, {"Nov", 5.1}, {"Dec", 0.2}
    };
    sortByTemperature(monthlyTemps);
    cout << "Honapok atlaghomerseklet szerint novekvo sorrendben:" << endl;
    for_each(monthlyTemps.begin(), monthlyTemps.end(), [](const pair<string, double>& p) {
        cout << "  " << p.first << ": " << p.second << " °C\n";
    });

    cout << endl << "--- 7. Feladat ---" << endl;
    vector<double> reals3 { -10.5, 3.2, -1.1, 8.4, -5.0, 0.5 };
    printVector(reals3, "Eredeti tomb");
    sortByAbsoluteValue(reals3);
    printVector(reals3, "Rendezve abszolut ertek szerint");

    cout << endl << "--- 8. Feladat ---" << endl;
    lowercaseFirstLetter(months);
    printVector(months, "Honapok kis kezdobetukkel");

    cout << endl << "--- 9. Feladat ---" << endl;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    sortByCustomAlphabet(months, alphabet);
    cout << "Kevert abece: " << alphabet << endl;
    printVector(months, "Honapok a furcsa abece szerint rendezve");

    return 0;
}