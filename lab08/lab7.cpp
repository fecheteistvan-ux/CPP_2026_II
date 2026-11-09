#include "Lab7.h"

bool hasFruitWithSubstring(const std::vector<std::string>& fruits, const std::string& target) {
    auto it = std::find_if(fruits.begin(), fruits.end(), [&target](const std::string& fruit) {
        return fruit.find(target) != std::string::npos;
    });
    return it != fruits.end();
}

bool areAllEven(const std::vector<int>& numbers) {
    return std::all_of(numbers.begin(), numbers.end(), [](int n) {
        return n % 2 == 0;
    });
}

void doubleElements(std::vector<int>& numbers) {
    std::for_each(numbers.begin(), numbers.end(), [](int& n) {
        n *= 2;
    });
}

std::size_t countFiveLetterMonths(const std::vector<std::string>& months) {
    return std::count_if(months.begin(), months.end(), [](const std::string& m) {
        return m.length() == 5;
    });
}

void sortDescendingLambda(std::vector<double>& numbers) {
    std::sort(numbers.begin(), numbers.end(), [](double a, double b) {
        return a > b;
    });
}

void sortDescendingFunctor(std::vector<double>& numbers) {
    std::sort(numbers.begin(), numbers.end(), std::greater<double>());
}

void sortByTemperature(std::vector<std::pair<std::string, double>>& monthlyTemps) {
    std::sort(monthlyTemps.begin(), monthlyTemps.end(), 
        [](const std::pair<std::string, double>& a, const std::pair<std::string, double>& b) {
            return a.second < b.second;
        }
    );
}

void sortByAbsoluteValue(std::vector<double>& numbers) {
    std::sort(numbers.begin(), numbers.end(), [](double a, double b) {
        return std::abs(a) < std::abs(b);
    });
}

void lowercaseFirstLetter(std::vector<std::string>& months) {
    std::for_each(months.begin(), months.end(), [](std::string& m) {
        if (!m.empty()) {
            m[0] = static_cast<char>(std::tolower(static_cast<unsigned char>(m[0])));
        }
    });
}

void sortByCustomAlphabet(std::vector<std::string>& months, std::string& alphabet) {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(alphabet.begin(), alphabet.end(), g);

    std::vector<int> rank(256, 0);
    int currentRank = 0;
    std::for_each(alphabet.begin(), alphabet.end(), [&rank, &currentRank](char c) {
        rank[static_cast<unsigned char>(c)] = currentRank++;
    });

    std::sort(months.begin(), months.end(), [&rank](const std::string& a, const std::string& b) {
        return std::lexicographical_compare(
            a.begin(), a.end(),
            b.begin(), b.end(),
            [&rank](char c1, char c2) {
                return rank[static_cast<unsigned char>(c1)] < rank[static_cast<unsigned char>(c2)];
            }
        );
    });
}