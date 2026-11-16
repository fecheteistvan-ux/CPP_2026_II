#include "Alkalmazott.h"

int Alkalmazott::nextId = 1;

Alkalmazott::Alkalmazott(const std::string& vezetekNev, const std::string& keresztNev, int szuletesEv, const std::string& munkakor)
    : Szemely(vezetekNev, keresztNev, szuletesEv), id(nextId++), munkakor(munkakor) {}

int Alkalmazott::getId() const {
    return id;
}

std::string Alkalmazott::getMunkakor() const {
    return munkakor;
}

void Alkalmazott::print(std::ostream& os) const {
    os << "Alkalmazott " << id << " " << vezetekNev << " " << keresztNev << " " << munkakor << "\n";
}