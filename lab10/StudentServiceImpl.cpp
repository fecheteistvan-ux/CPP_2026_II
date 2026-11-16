#include "StudentServiceImpl.h"
#include <stdexcept>

bool StudentServiceImpl::isEnrolled(int id) const {
    try {
        dao->findById(id);
        return true;
    } catch (const out_of_range &) {
        return false;
    }
}

vector<string> StudentServiceImpl::getSubjects(int id) const {
    Student s = dao->findById(id);
    vector<string> subjects;
    for (const auto &pair : s.getGrades()) {
        subjects.push_back(pair.first);
    }
    return subjects;
}

double StudentServiceImpl::getResultBySubject(int id, const string &subject) const {
    return dao->findById(id).getGrade(subject);
}

double StudentServiceImpl::getAverage(int id) const {
    return dao->findById(id).getAverage();
}

bool StudentServiceImpl::isPassed(int id) const {
    Student s = dao->findById(id);
    const auto &grades = s.getGrades();
    if (grades.empty()) {
        return false;
    }
    for (const auto &pair : grades) {
        if (pair.second < 5.0) {
            return false;
        }
    }
    return s.getAverage() >= 6.0;
}