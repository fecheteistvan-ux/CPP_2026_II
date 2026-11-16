#include "Student.h"

Student::Student(int id, const string &firstName, const string &lastName)
    : id(id), firstName(firstName), lastName(lastName) {}

int Student::getId() const {
    return id;
}

void Student::setId(int id) {
    this->id = id;
}

const string &Student::getFirstName() const {
    return firstName;
}

const string &Student::getLastName() const {
    return lastName;
}

void Student::addGrade(const string &subject, double grade) {
    grades[subject] = grade;
}

double Student::getGrade(const string &subject) const {
    return grades.at(subject);
}

const map<string, double> &Student::getGrades() const {
    return grades;
}

void Student::computeAverage() {
    if (grades.empty()) {
        average = 0.0;
        return;
    }

    double sum = 0.0;
    for (const auto &pair : grades) {
        if (pair.second < 5.0) {
            average = 0.0;
            return;
        }
        sum += pair.second;
    }
    average = sum / static_cast<double>(grades.size());
}

double Student::getAverage() const {
    return average;
}

ostream &operator<<(ostream &os, const Student &student) {
    os << "ID: " << student.id << " | " << student.lastName << " " << student.firstName << "\n";
    for (const auto &pair : student.grades) {
        os << "\t" << pair.first << ": " << pair.second << "\n";
    }
    os << "\tAverage: " << student.average;
    return os;
}