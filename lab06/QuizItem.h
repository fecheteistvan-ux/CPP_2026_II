# pragma once
#include <string>
#include <vector>

class QuizItem {
private:
        static int counter;
        int id;
        std::string question;
        std::vector<std::string> answers;
        int correctAnswer;
public:
        QuizItem(const std::string& question, const std::vector<std::string>& answers, int correctAnswer);

        int getId() const;
        std::string getQuestion() const;
        std::vector<std::string> getAnswers() const;
        int getCorrectAnswer() const;

};
