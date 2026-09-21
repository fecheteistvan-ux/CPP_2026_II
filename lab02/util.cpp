#include "util.h"
#include <cmath>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

double distance(const Point& a, const Point& b) {
    int dx = a.getX() - b.getX();
    int dy = a.getY() - b.getY();
    return std::sqrt(dx * dx + dy * dy);
}

bool isSquare(const Point& a, const Point& b, const Point& c, const Point& d) {

    vector<double> distances = {
        distance(a, b),
        distance(a, c),
        distance(a, d),
        distance(b, c),
        distance(b, d),
        distance(c, d)
    };

    sort(distances.begin(), distances.end());
    return distances[0] > 0 &&
           distances[0] == distances[1] &&
           distances[1] == distances[2] &&
           distances[2] == distances[3] &&
           distances[4] == distances[5];
}
void testIsSquare(const char * filename) {
    ifstream ifs(filename);
    if (!ifs.is_open()) {
        cerr << "Hiba!file " << filename << endl;
        return;
    }

    int x1, y1, x2, y2, x3, y3, x4, y4;

    while (ifs >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4) {
        Point a(x1, y1);
        Point b(x2, y2);
        Point c(x3, y3);
        Point d(x4, y4);

        cout << "A(" << a.getX() << ", " << a.getY() << "), "
             << "B(" << b.getX() << ", " << b.getY() << "), "
             << "C(" << c.getX() << ", " << c.getY() << "), "
             << "D(" << d.getX() << ", " << d.getY() << ") -> ";

        if (isSquare(a, b, c, d)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    ifs.close();
}

Point* createArray(int numPoints) {
    if (numPoints <= 0) {
        return nullptr;
    }

    Point* points = new Point[numPoints];

    for (int i = 0; i < numPoints; ++i) {
        int x = rand() % 2001;
        int y = rand() % 2001;
        points[i] = Point(x, y);
    }

    return points;
}

void printArray(Point* points, int numPoints) {
    if (points == nullptr || numPoints <= 0) {
        cout << "A tomb ures vagy nem letezik." << endl;
        return;
    }

    for (int i = 0; i < numPoints; ++i) {
        cout << i + 1 << ". pont: ";
        points[i].print();
    }
}
std::pair<Point, Point> closestPoints(Point* points, int numPoints) {
    if (points == nullptr || numPoints < 2) {
        return make_pair(Point(), Point());
    }

    double minDistance = std::numeric_limits<double>::max();
    pair<Point, Point> result;


    for (int i = 0; i < numPoints - 1; ++i) {
        for (int j = i + 1; j < numPoints; ++j) {
            double d = distance(points[i], points[j]);
            if (d < minDistance) {
                minDistance = d;
                result = make_pair(points[i], points[j]);
            }
        }
    }

    return result;
}
std::pair<Point, Point> farthestPoints(Point* points, int numPoints) {
    if (points == nullptr || numPoints < 2) {
        return make_pair(Point(), Point());
    }

    double maxDistance = -1.0;
    pair<Point, Point> result;

    for (int i = 0; i < numPoints - 1; ++i) {
        for (int j = i + 1; j < numPoints; ++j) {
            double d = distance(points[i], points[j]);
            if (d > maxDistance) {
                maxDistance = d;
                result = make_pair(points[i], points[j]);
            }
        }
    }

    return result;
}
void sortPoints(Point* points, int numPoints) {
    if (points == nullptr || numPoints <= 0) {
        return;
    }

    std::sort(points, points + numPoints, [](const Point& a, const Point& b) {
        return a.getX() < b.getX();
    });

    cout << "\nPontok x koordinata szerint rendezve:" << endl;
    printArray(points, numPoints);
}
Point* farthestPointsFromOrigin(Point* points, int numPoints) {
    if (points == nullptr || numPoints <= 0) {
        return nullptr;
    }

    int count = (numPoints < 10) ? numPoints : 10;
    Point* result = new Point[count];
    Point origin(0, 0);

    vector<pair<double, Point>> topPoints;

    for (int i = 0; i < numPoints; ++i) {
        double d = distance(origin, points[i]);

        if (topPoints.size() < 10) {
            topPoints.push_back({d, points[i]});
            sort(topPoints.begin(), topPoints.end(), [](const pair<double, Point>& a, const pair<double, Point>& b) {
                return a.first < b.first;
            });
        } else if (d > topPoints[0].first) {
            topPoints[0] = {d, points[i]};
            sort(topPoints.begin(), topPoints.end(), [](const pair<double, Point>& a, const pair<double, Point>& b) {
                return a.first < b.first;
            });
        }
    }

    for (int i = 0; i < count; ++i) {
        result[i] = topPoints[i].second;
    }

    return result;
}
void deletePoints(Point* points) {
    delete[] points;

    cout << "Sikeres Memoria Felszabadiatas!"<<endl;
}