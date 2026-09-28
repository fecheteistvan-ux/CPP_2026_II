#include "PointSet.h"
#include <iostream>
#include <random>
#include <algorithm>
#include <set>
#include <cmath>

static bool containsPoint(const vector<Point>& points, int x, int y) {
    for (const auto& p : points) {
        if (p.getX() == x && p.getY() == y) {
            return true;
        }
    }
    return false;
}

PointSet::PointSet(int n) : n(n) {
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, M);


    while (points.size() < static_cast<size_t>(n)) {
        int x = dist(mt);
        int y = dist(mt);
        if (!containsPoint(points, x, y)) {
            points.emplace_back(x, y);
        }
    }

    computeDistances();
}

void PointSet::computeDistances() {
    distances.clear();
    for (size_t i = 0; i < points.size(); ++i) {
        for (size_t j = i + 1; j < points.size(); ++j) {
            distances.push_back(points[i].distanceTo(points[j]));
        }
    }
}

double PointSet::maxDistance() const {
    if (distances.empty()) return 0.0;
    return *max_element(distances.begin(), distances.end());
}

double PointSet::minDistance() const {
    if (distances.empty()) return 0.0;
    return *min_element(distances.begin(), distances.end());
}

int PointSet::numDistances() const {
    return static_cast<int>(distances.size());
}

void PointSet::printPoints() const {
    for (const auto& p : points) {
        cout << "(" << p.getX() << ", " << p.getY() << ") ";
    }
    cout << endl;
}

void PointSet::printDistances() const {
    for (double d : distances) {
        cout << d << " ";
    }
    cout << endl;
}

void PointSet::sortPointsX() {
    sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
        if (a.getX() != b.getX()) {
            return a.getX() < b.getX();
        }
        return a.getY() < b.getY();
    });
}

void PointSet::sortPointsY() {
    sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
        if (a.getY() != b.getY()) {
            return a.getY() < b.getY();
        }
        return a.getX() < b.getX();
    });
}

void PointSet::sortDistances() {
    sort(distances.begin(), distances.end());
}

int PointSet::numDistinctDistances() {
    sortDistances();
    if (distances.empty()) return 0;

    int count = 1;
    for (size_t i = 1; i < distances.size(); ++i) {
        if (abs(distances[i] - distances[i - 1]) > 1e-5) {
            count++;
        }
    }
    return count;
}