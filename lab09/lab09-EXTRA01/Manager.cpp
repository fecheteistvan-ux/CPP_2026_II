#include "Manager.h"

const std::string Manager::MANAGER_MUNKAKOR = "manager";

Manager::Manager(const std::string& vezetekNev, const std::string& keresztNev, int szuletesEv, const std::string& munkakor)
    : Alkalmazott(vezetekNev, keresztNev, szuletesEv, munkakor) {}

void Manager::addAlkalmazott(Alkalmazott* a) {
    if (a) {
        beosztottak.push_back(a);
    }
}

void Manager::deleteAlkalmazott(int id) {
    for (auto it = beosztottak.begin(); it != beosztottak.end(); ++it) {
        if ((*it)->getId() == id) {
            beosztottak.erase(it);
            return;
        }
    }
}

int Manager::beosztottakSzama() const {
    return static_cast<int>(beosztottak.size());
}

void Manager::print(std::ostream& os) const {
    os << "Manager " << id << " " << vezetekNev << " " << keresztNev << " beosztottjai:\n";
    for (const auto* b : beosztottak) {
        os << "  ";
        b->print(os);
    }
}