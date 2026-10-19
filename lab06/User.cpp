#include "User.h"
#include <iostream>

int User::counter = 0;

User::User(const std::string& name)
    : name(name) {
    this->id = ++counter;
}

void User::addResult(int quizId, double score) {
    results[quizId] = score;
}

void User::displayResults() const {
    std::cout << "--- " << name << " eredményei ---\n";
    if (results.empty()) {
        std::cout << "Még nincs kitöltött kvíz.\n";
        return;
    }

    for (const auto& entry : results) {
        std::cout << "Kvíz ID: " << entry.first << " -> Eredmény: " << entry.second << "%\n";
    }
}
int User::getId() const {
    return id;
}

std::string User::getName() const {
    return name;
}

const std::map<int, double>& User::getResults() const {
    return results;
}