#include "QuizGame.h"
#include <iostream>


QuizGame::QuizGame(User& user, Quiz& quiz) 
    : user(user), quiz(quiz) {}

void QuizGame::play() {

    if (!quiz.getIsReady()) {
        std::cout << "Hiba: A kviz még nincs lezárva (finalize()), nem indítható el a játék!\n";
        return;
    }

    const auto& items = quiz.getItems();
    if (items.empty()) {
        std::cout << "A kvíz nem tartalmaz egyetlen kérdést sem.\n";
        return;
    }

    std::cout << "========================================\n";
    std::cout << "  Kvíz indítása: " << quiz.getName() << "\n";
    std::cout << "  Játékos: " << user.getName() << "\n";
    std::cout << "========================================\n\n";

    int correctAnswersCount = 0;

    for (size_t i = 0; i < items.size(); ++i) {
        const auto& item = items[i];
        
        std::cout << i + 1 << ". Kérdés: " << item.getQuestion() << "\n";

        const auto& answers = item.getAnswers();
        for (size_t j = 0; j < answers.size(); ++j) {
            std::cout << "  " << j + 1 << ") " << answers[j] << "\n";
        }

        int choice = 0;
        std::cout << "Válaszd ki a helyes válasz számát (1-" << answers.size() << "): ";
        std::cin >> choice;

        int choiceIndex = choice - 1;
        if (choiceIndex == item.getCorrectAnswer()) {
            std::cout << "-> Helyes válasz!\n\n";
            correctAnswersCount++;
        } else {
            std::cout << "-> Helytelen válasz!\n\n";
        }
    }

    double score = (static_cast<double>(correctAnswersCount) / items.size()) * 100.0;

    std::cout << "----------------------------------------\n";
    std::cout << "A kvíz véget ért!\n";
    std::cout << "Eredményed: " << correctAnswersCount << " / " << items.size() 
              << " (" << score << "%)\n";
    std::cout << "----------------------------------------\n";

    user.addResult(quiz.getId(), score);
}