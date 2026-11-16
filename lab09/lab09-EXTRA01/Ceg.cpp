#include "Ceg.h"

Alkalmazott* Ceg::findAlkalmazottById(int id) const {
    for (auto* a : alkalmazottak) {
        if (a->getId() == id) {
            return a;
        }
    }
    return nullptr;
}

Manager* Ceg::findManagerById(int id) const {
    Alkalmazott* a = findAlkalmazottById(id);
    return dynamic_cast<Manager*>(a);
}

Ceg::~Ceg() {
    for (auto* a : alkalmazottak) {
        delete a;
    }
    alkalmazottak.clear();
}

void Ceg::alkalmaz(Alkalmazott* a) {
    if (a) {
        alkalmazottak.push_back(a);
    }
}

void Ceg::elbocsat(int id) {
    for (auto* a : alkalmazottak) {
        Manager* m = dynamic_cast<Manager*>(a);
        if (m) {
            m->deleteAlkalmazott(id);
        }
    }

    for (auto it = alkalmazottak.begin(); it != alkalmazottak.end(); ++it) {
        if ((*it)->getId() == id) {
            delete *it;
            alkalmazottak.erase(it);
            return;
        }
    }
}

void Ceg::hozzarendel(int managerId, int alkalmazottId) {
    Manager* m = findManagerById(managerId);
    Alkalmazott* a = findAlkalmazottById(alkalmazottId);
    if (m && a) {
        m->addAlkalmazott(a);
    }
}

void Ceg::levalaszt(int managerId, int alkalmazottId) {
    Manager* m = findManagerById(managerId);
    if (m) {
        m->deleteAlkalmazott(alkalmazottId);
    }
}

void Ceg::listazOsszes(std::ostream& os) const {
    for (const auto* a : alkalmazottak) {
        os << *a;
    }
}

void Ceg::listazManagerek(std::ostream& os) const {
    for (const auto* a : alkalmazottak) {
        const Manager* m = dynamic_cast<const Manager*>(a);
        if (m) {
            os << *m;
        }
    }
}