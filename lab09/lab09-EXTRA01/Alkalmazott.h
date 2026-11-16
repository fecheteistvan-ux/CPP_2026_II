#ifndef ALKALMAZOTT_H
#define ALKALMAZOTT_H

#include "Szemely.h"

class Alkalmazott : public Szemely {
private:
    static int nextId;

protected:
    int id;
    std::string munkakor;

public:
    Alkalmazott(const std::string& vezetekNev, const std::string& keresztNev, int szuletesEv, const std::string& munkakor);
    virtual ~Alkalmazott() = default;

    int getId() const;
    std::string getMunkakor() const;

    void print(std::ostream& os = std::cout) const override;
};

#endif