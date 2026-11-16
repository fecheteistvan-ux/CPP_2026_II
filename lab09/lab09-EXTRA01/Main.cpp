#include <iostream>
#include "Ceg.h"
#include "Manager.h"
#include "Alkalmazott.h"

using namespace std;

int main() {
    Ceg ceg;

    Manager* m1 = new Manager("Kovacs", "Janos", 1980);
    Manager* m2 = new Manager("Nagy", "Anna", 1985);
    Manager* m3 = new Manager("Szabo", "Peter", 1978);

    Alkalmazott* e1 = new Alkalmazott("Toth", "Gabor", 1990, "fejleszto");
    Alkalmazott* e2 = new Alkalmazott("Horvath", "Ester", 1992, "tesztelo");
    Alkalmazott* e3 = new Alkalmazott("Varga", "Zoltan", 1988, "fejleszto");
    Alkalmazott* e4 = new Alkalmazott("Kiss", "Bela", 1995, "dizajner");
    Alkalmazott* e5 = new Alkalmazott("Molnar", "Katalin", 1993, "devops");
    Alkalmazott* e6 = new Alkalmazott("Fekete", "Andras", 1991, "fejleszto");
    Alkalmazott* e7 = new Alkalmazott("Feher", "Laura", 1996, "hr_asszisztens");

    ceg.alkalmaz(m1);
    ceg.alkalmaz(m2);
    ceg.alkalmaz(m3);
    ceg.alkalmaz(e1);
    ceg.alkalmaz(e2);
    ceg.alkalmaz(e3);
    ceg.alkalmaz(e4);
    ceg.alkalmaz(e5);
    ceg.alkalmaz(e6);
    ceg.alkalmaz(e7);

    cout << "=== OSSZES ALKALMAZOTT LISTAJA ===" << endl;
    ceg.listazOsszes();

    ceg.hozzarendel(m1->getId(), e1->getId());
    ceg.hozzarendel(m1->getId(), e2->getId());
    ceg.hozzarendel(m1->getId(), e3->getId());

    ceg.hozzarendel(m2->getId(), e4->getId());
    ceg.hozzarendel(m2->getId(), e5->getId());

    ceg.hozzarendel(m3->getId(), e6->getId());
    ceg.hozzarendel(m3->getId(), e7->getId());

    cout << endl << "=== MANAGEREK ES BEOSZTOTTAK (Hozzarendeles utan) ===" << endl;
    ceg.listazManagerek();

    cout << endl << "=== ALKALMAZOTT ATHELYEZESE (ID " << e1->getId() << " áthelyezése M1 -> M2) ===" << endl;
    ceg.levalaszt(m1->getId(), e1->getId());
    ceg.hozzarendel(m2->getId(), e1->getId());

    cout << endl << "=== MANAGEREK ES BEOSZTOTTAK (Athelyezes utan) ===" << endl;
    ceg.listazManagerek();

    return 0;
}