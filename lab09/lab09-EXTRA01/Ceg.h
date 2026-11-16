#ifndef CEG_H
#define CEG_H

#include "Alkalmazott.h"
#include "Manager.h"
#include <vector>
#include <iostream>

class Ceg {
private:
    std::vector<Alkalmazott*> alkalmazottak;

    Alkalmazott* findAlkalmazottById(int id) const;
    Manager* findManagerById(int id) const;

public:
    Ceg() = default;
    ~Ceg();

    void alkalmaz(Alkalmazott* a);
    void elbocsat(int id);
    void hozzarendel(int managerId, int alkalmazottId);
    void levalaszt(int managerId, int alkalmazottId);

    void listazOsszes(std::ostream& os = std::cout) const;
    void listazManagerek(std::ostream& os = std::cout) const;
};

#endif