#include "GraduationDao.h"
#include <fstream>
#include <stdexcept>

void GraduationDao::enrollStudents(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Cannot open file: " + filename);
    }

    int id;
    string lastName, firstName;
    while (file >> id >> lastName >> firstName) {
        students.emplace(id, Student(id, firstName, lastName));
    }
}

void GraduationDao::readGradesSubject(const string &subject, const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Cannot open file: " + filename);
    }

    int id;
    double grade;
    while (file >> id >> grade) {
        auto it = students.find(id);
        if (it != students.end()) {
            it->second.addGrade(subject, grade);
        }
    }
}

void GraduationDao::computeAverage() {
    for (auto &pair : students) {
        pair.second.computeAverage();
    }
}

int GraduationDao::numEnrolled() const {
    return static_cast<int>(students.size());
}

int GraduationDao::numPassed() const {
    int passedCount = 0;
    for (const auto &pair : students) {
        const Student &s = pair.second;
        if (s.getAverage() >= 6.0) {
            passedCount++;
        }
    }
    return passedCount;
}

Student GraduationDao::findById(int id) const {
    return students.at(id);
}

double GraduationDao::getAverageBySubject(const string &subject) const {
    double sum = 0.0;
    int count = 0;

    for (const auto &pair : students) {
        const auto &grades = pair.second.getGrades();
        auto it = grades.find(subject);
        if (it != grades.end()) {
            sum += it->second;
            count++;
        }
    }

    return count > 0 ? (sum / count) : 0.0;
}