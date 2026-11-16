#ifndef SZEMELY_H
#define SZEMELY_H

#include <string>
#include <iostream>

class Szemely {
protected:
    std::string vezetekNev;
    std::string keresztNev;
    int szuletesEv;

public:
    Szemely(const std::string& vezetekNev, const std::string& keresztNev, int szuletesEv);
    virtual ~Szemely() = default;

    std::string getVezetekNev() const;
    std::string getKeresztNev() const;
    int getSzuletesEv() const;

    virtual void print(std::ostream& os = std::cout) const;
};

std::ostream& operator<<(std::ostream& os, const Szemely& sz);

#endif