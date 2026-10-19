//
// Created by Istva on 19.10.2026.
//

#ifndef CPP_2026_USER_H
#define CPP_2026_USER_H


#include <string>
#include <map>

class User {
private:
    static int counter;
    int id;
    std::string name;
    std::map<int, double> results;

public:

    explicit User(const std::string& name);
    void addResult(int quizId, double score);
    void displayResults() const;
    int getId() const;
    std::string getName() const;
    const std::map<int, double>& getResults() const;
};

#endif //CPP_2026_USER_H