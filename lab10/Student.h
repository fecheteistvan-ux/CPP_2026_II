#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <map>
#include <iostream>
#include <stdexcept>

using namespace std;

class Student {
private:
    int id;
    string firstName;
    string lastName;
    map<string, double> grades;
    double average{0.0};

public:
    Student(int id, const string &firstName, const string &lastName);
    int getId() const;
    void setId(int id);
    const string &getFirstName() const;
    const string &getLastName() const;
    void addGrade(const string &subject, double grade);
    double getGrade(const string &subject) const; // throws out_of_range for nonexistent subject
    const map<string, double> &getGrades() const;
    void computeAverage();
    double getAverage() const;
    friend ostream &operator<<(ostream &os, const Student &student);
};

#endif // STUDENT_H