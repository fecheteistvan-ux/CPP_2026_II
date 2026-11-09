#include <iostream>
#include "File.h"
#include "Directory.h"

using namespace std;

int main() {
    cout << "=== Fajlrendszer Szimulacio ===" << endl << endl;

    // 1. Gyökér könyvtár létrehozása
    Directory* root = new Directory("root");

    // 2. Struktúra felépítése
    cout << "Fajlrendszer felepitese..." << endl;

    // Documents könyvtár és fájlok
    Directory* documents = new Directory("documents");
    documents->add(new File("report.txt", 1500));
    documents->add(new File("notes.txt", 800));

    // Pictures könyvtár és fájlok
    Directory* pictures = new Directory("pictures");
    pictures->add(new File("photo1.jpg", 2048000));
    pictures->add(new File("photo2.jpg", 1856000));

    // Hozzáadás a gyökérhez operator+= segítségével
    *root += documents;
    *root += pictures;
    *root += new File("readme.txt", 500);

    // 3. Teljes struktúra megjelenítése az operator<< segítségével
    cout << endl << "Teljes fajlrendszer:" << endl;
    cout << "=====================" << endl;
    cout << *root;

    // 4. Teljes méret kiírása
    cout << endl << "Teljes meret: " << root->getSize() << " bytes" << endl;

    // 5. Keresés név alapján
    cout << endl << "--- Kereses teszt ---" << endl;
    string searchTarget = "photo1.jpg";
    cout << "Kereses: " << searchTarget << endl;
    FileSystemItem* foundItem = root->find(searchTarget);
    if (foundItem) {
        cout << "Talalat! Megtalalt elem: ";
        foundItem->display();
    } else {
        cout << "Elem nem található." << endl;
    }

    // 6. Elem eltávolítása operator-= segítségével
    cout << endl << "--- Torles teszt (photo1.jpg eltavolitasa) ---" << endl;
    *pictures -= "photo1.jpg";
    cout << "Torles utáni struktura:" << endl;
    cout << *root;

    // 7. Klónozás és Deep Copy tesztelése
    cout << endl << "--- Klónozas / Deep Copy teszt ---" << endl;
    Directory* clonedRoot = dynamic_cast<Directory*>(root->clone());

    // Módosítsuk az eredeti könyvtárat, hogy igazoljuk a mély másolat függetlenségét
    *documents += new File("extra.txt", 300);

    cout << "Eredeti gyoker (extra.txt hozzaadasa után):" << endl;
    cout << *root;

    cout << endl << "Klonozott gyoker (valtozatlan kell maradjon):" << endl;
    cout << *clonedRoot;

    // 8. Relációs operátor teszt (operator<)
    cout << endl << "--- Operator< teszt ---" << endl;
    File fileA("a.txt", 100);
    File fileB("b.txt", 200);
    if (fileA < fileB) {
        cout << fileA.getName() << " abc-rendben megelozi a következot: " << fileB.getName() << endl;
    }

    // Memória felszabadítása
    delete root;
    delete clonedRoot;

    return 0;
}