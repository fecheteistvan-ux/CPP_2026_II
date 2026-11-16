#include <iostream>
#include "Student.h"
#include "GraduationDao.h"
#include "StudentService.h"
#include "StudentServiceImpl.h"

using namespace std;

int main() {
    cout << "--- 1. Student osztaly tesztelese ---" << endl;
    Student testStudent(100, "Janos", "Kovacs");
    testStudent.addGrade("math", 8.5);
    testStudent.addGrade("romanian", 7.0);
    testStudent.addGrade("hungarian", 9.0);
    testStudent.computeAverage();
    cout << testStudent << endl << endl;

    cout << "--- 2. GraduationDao osztaly tesztelese ---" << endl;
    string subjects[]{"math", "romanian", "hungarian"};
    int numSubjects = sizeof(subjects) / sizeof(subjects[0]);

    GraduationDao dao(2023);
    dao.enrollStudents("names.txt");
    cout << "Number of enrolled students: " << dao.numEnrolled() << endl;

    for (int i = 0; i < numSubjects; ++i) {
        dao.readGradesSubject(subjects[i], subjects[i] + ".txt");
    }
    dao.computeAverage();
    cout << "Number of passed students: " << dao.numPassed() << endl << endl;

    cout << "--- 3. StudentService tesztelese ---" << endl;
    StudentService *service = new StudentServiceImpl(&dao);
    cout << "Individual results: " << endl;
    int id = 0;
    while (id != -1) {
        cout << "Enter ID (-1 for EXIT): ";
        cin >> id;
        if (id == -1) {
            break;
        }
        if (!service->isEnrolled(id)) {
            cout << "Student id=" << id << " not found" << endl;
            continue;
        }
        cout << "Student id=" << id << " results:" << endl;
        bool passed = service->isPassed(id);
        cout << "\tpassed: " << (passed ? "yes" : "no") << endl;
        if (!passed) {
            continue;
        }
        vector<string> studentSubjects = service->getSubjects(id);
        for (int i = 0; i < static_cast<int>(studentSubjects.size()); ++i) {
            cout << "\t" << studentSubjects[i] << ": "
                 << service->getResultBySubject(id, studentSubjects[i]) << endl;
        }
        cout << "\taverage: " << service->getAverage(id) << endl;
    }

    delete service;
    return 0;
}