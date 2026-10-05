#ifndef POINTSET_H
#define POINTSET_H

#include "Point.h"
#include <vector>

using namespace std;

class PointSet {
    vector<Point> points;
    int n;
    vector<double> distances;
    void computeDistances();

public:
    // konstruktor: előállítja a points vektort
    // kiszámítja a pontok közötti távolságokat (distances vektor)
    PointSet(int n = 100);
    // maximum kiválasztás a tavolsag vektorból
    double maxDistance() const;
    // minimum kiválasztás a tavolsag vektorból
    double minDistance() const;
    // összesen hány távolság értelmezhető n különböző pont között
    int numDistances() const;
    // a pontok vektor kiíratása
    void printPoints() const;
    // a tavolsagok vektor kiíratása
    void printDistances() const;
    // növekvő sorrendbe rendezi a pontokat x koordináta szerint
    void sortPointsX();
    // u. a. y koordináta szerint
    void sortPointsY();
    // a tavolsagok vektor rendezése
    void sortDistances();
    // hány darab különböző távolságot tartalmaz a tavolsagok vektor
    int numDistinctDistances();
};

#endif /* POINTSET_H */