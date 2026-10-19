//
// Created by Istva on 19.10.2026.
//

#ifndef CPP_2026_QUIZGAME_H
#define CPP_2026_QUIZGAME_H


#include "User.h"
#include "Quiz.h"

class QuizGame {
private:
    User& user;
    Quiz& quiz;

public:

    QuizGame(User& user, Quiz& quiz);
    void play();
};

#endif //CPP_2026_QUIZGAME_H