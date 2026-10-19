#include <iostream>
#include "QuizItem.h"
#include "Quiz.h"
#include "User.h"
#include "QuizGame.h"

int main() {

    QuizItem q1("Mi C++-ban a kimeneti folyam?", {"cin", "cout", "printf"}, 1); // 1 = "cout"
    QuizItem q2("Melyik adattípus tárol egész számot?", {"int", "double", "std::string"}, 0); // 0 = "int"
    Quiz myQuiz("C++ Alapismeretek");
    myQuiz.addItem(q1);
    myQuiz.addItem(q2);
    myQuiz.finalize();
    User player("Teszt Elek");
    QuizGame game(player, myQuiz);
    game.play();

    player.displayResults();

    return 0;
}