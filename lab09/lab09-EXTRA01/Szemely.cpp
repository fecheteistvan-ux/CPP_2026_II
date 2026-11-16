#include "Szemely.h"

Szemely::Szemely(const std::string& vezetekNev, const std::string& keresztNev, int szuletesEv)
    : vezetekNev(vezetekNev), keresztNev(keresztNev), szuletesEv(szuletesEv) {}

std::string Szemely::getVezetekNev() const {
    return vezetekNev;
}

std::string Szemely::getKeresztNev() const {
    return keresztNev;
}

int Szemely::getSzuletesEv() const {
    return szuletesEv;
}

void Szemely::print(std::ostream& os) const {
    os << "Szemely " << vezetekNev << " " << keresztNev << " (" << szuletesEv << ")\n";
}

std::ostream& operator<<(std::ostream& os, const Szemely& sz) {
    sz.print(os);
    return os;
}