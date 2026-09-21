#ifndef UTIL_H
#define UTIL_H

#include "point.h"
#include <utility>
double distance(const Point& a, const Point& b);
bool isSquare(const Point& a, const Point& b, const Point& c, const Point& d);
void testIsSquare(const char * filename);
Point* createArray(int numPoints);
void printArray(Point* points, int numPoints);
std::pair<Point, Point> closestPoints(Point* points, int numPoints);
std::pair<Point, Point> farthestPoints(Point* points, int numPoints);
void sortPoints(Point* points, int numPoints);
Point* farthestPointsFromOrigin(Point* points, int numPoints);
void deletePoints(Point* points);
#endif /* UTIL_H */