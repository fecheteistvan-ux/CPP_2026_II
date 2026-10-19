#pragma once
# include <string>
# include <vector>
# include <iostream>
#include "QuizItem.h"
class Quiz{
    private:
       static int counter;
       int id;
       std::string name;
       std::vector<QuizItem> items;
       bool isReady ;
    public:
        explicit Quiz(const std::string& name);
        void addItem(const QuizItem& item);
        void finalize();
        int getId() const;
        std::string getName() const;
        std::vector<QuizItem> getItems() const;
        bool getIsReady() const;
};