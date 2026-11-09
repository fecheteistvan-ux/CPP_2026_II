#ifndef LAB7_H
#define LAB7_H

#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <functional>
#include <cmath>
#include <cctype>
#include <random>
#include <numeric>

bool hasFruitWithSubstring(const std::vector<std::string>& fruits, const std::string& target);
bool areAllEven(const std::vector<int>& numbers);
void doubleElements(std::vector<int>& numbers);
std::size_t countFiveLetterMonths(const std::vector<std::string>& months);
void sortDescendingLambda(std::vector<double>& numbers);
void sortDescendingFunctor(std::vector<double>& numbers);
void sortByTemperature(std::vector<std::pair<std::string, double>>& monthlyTemps);
void sortByAbsoluteValue(std::vector<double>& numbers);
void lowercaseFirstLetter(std::vector<std::string>& months);
void sortByCustomAlphabet(std::vector<std::string>& months, std::string& alphabet);

template <typename T>
void printVector(const std::vector<T>& vec, const std::string& label = "") {
    if (!label.empty()) {
        std::cout << label << ": ";
    }
    std::for_each(vec.begin(), vec.end(), [](const T& item) {
        std::cout << item << " ";
    });
    std::cout << "\n";
}

#endif