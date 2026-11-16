#ifndef MANAGER_H
#define MANAGER_H

#include "Alkalmazott.h"
#include <vector>

class Manager : public Alkalmazott {
private:
    std::vector<Alkalmazott*> beosztottak;

public:
    static const std::string MANAGER_MUNKAKOR;

    Manager(const std::string& vezetekNev, const std::string& keresztNev, int szuletesEv, const std::string& munkakor = MANAGER_MUNKAKOR);
    virtual ~Manager() = default;

    void addAlkalmazott(Alkalmazott* a);
    void deleteAlkalmazott(int id);
    int beosztottakSzama() const;

    void print(std::ostream& os = std::cout) const override;
};

#endif