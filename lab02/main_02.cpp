#include <iostream>
#include "point.h"
#include "util.h"
#include <cstdlib>
#include <ctime>
using namespace std;
int main(int argc, char** argv) {
    Point p1(2,3);
    cout<<"p1( "<<p1.getX()<<","<<p1.getY()<<")"<<endl;
    Point p2(100, 200);
    cout<<"p2( "<<p2.getX()<<","<<p2.getY()<<")"<<endl;
    Point * pp1 = new Point(300, 400);
    Point * pp2 = new Point(500, 1000);
    cout<<"pp1( "<<pp1->getX()<<","<<pp1->getY()<<")"<<endl;
    cout<<"pp2( "<<pp2->getX()<<","<<pp2->getY()<<")"<<endl;



    cout << "p1 es p2 tavolsaga: " << distance(p1, p2) << endl;



    Point a(0, 0);
    Point b(0, 2);
    Point c(2, 2);
    Point d(2, 0);

    if (isSquare(a, b, c, d)) {
        cout << "A megadott pontok negyzetet alkotnak!" << endl;
    } else {
        cout << "A megadott pontok NEM alkotnak negyzetet!" << endl;
    }

    testIsSquare("points.txt");

    srand(time(nullptr));

    int n = 5;
    Point* myPoints = createArray(n);

    cout << "A generalt pontok:" << endl;
    printArray(myPoints, n);

    pair<Point, Point> closest = closestPoints(myPoints, n);
    cout << "\nA legkozelebbi pontpar:" << endl;
    cout << "Point 1: "; closest.first.print();
    cout << "Point 2: "; closest.second.print();
    cout << "Tavolsaguk: " << distance(closest.first, closest.second) << endl;


    pair<Point, Point> farthest = farthestPoints(myPoints, n);
    cout << "\nA legtavolabbi pontpar:" << endl;
    cout << "Point 1: "; farthest.first.print();
    cout << "Point 2: "; farthest.second.print();
    cout << "Tavolsaguk: " << distance(farthest.first, farthest.second) << endl;

    cout <<  "Eredeti pontok :" << endl;
    printArray(myPoints, n);

    sortPoints(myPoints, n);

    int count = (n < 10) ? n : 10;
    Point* farthest10 = farthestPointsFromOrigin(myPoints, n);

    cout << "\nAz origotol legtavolabbi " << count << " pont:" << endl;
    printArray(farthest10, count);


    deletePoints(pp1);
    deletePoints(pp2);
    deletePoints(myPoints);

    return 0;

}