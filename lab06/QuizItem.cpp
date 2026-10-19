#include "QuizItem.h"

int QuizItem::counter = 0;

QuizItem::QuizItem(const std::string &question, const std::vector<std::string> &answers, int correnctAnswer)
    : question(question), answers(answers), correctAnswer(correnctAnswer)
{
    id = ++counter;
}
int QuizItem::getId()const {
    return id;
}
std::string QuizItem::getQuestion()const {
    return question;
}
std::vector<std::string> QuizItem::getAnswers() const {
    return answers;
}
int QuizItem::getCorrectAnswer() const {
    return correctAnswer;
}
