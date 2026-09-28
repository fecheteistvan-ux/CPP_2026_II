#include "Point.h"
#include <cmath>

Point::Point(int x, int y) : x(x), y(y) {}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

double Point::distanceTo(const Point& point) const {
    int dx = x - point.x;
    int dy = y - point.y;
    return std::sqrt(dx * dx + dy * dy);
}