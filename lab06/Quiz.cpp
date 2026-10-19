#include "Quiz.h"

#include "QuizItem.h"


int Quiz::counter = 0;
Quiz::Quiz(const std::string& name)
:name(name) , isReady(false) {
 this->id = ++counter;
}
void Quiz::addItem(const QuizItem &item) {
  if (!isReady) {
      items.push_back(item);
  }else {
      std::cerr << "Le van zarva a kviz" << std::endl;
  }
}
void Quiz::finalize() {
    isReady = true;
}
int Quiz::getId() const {
    return id;
}
std::string Quiz::getName() const {
    return name;
}
std::vector<QuizItem> Quiz::getItems() const {
    return items;
}
bool Quiz::getIsReady() const {
    return isReady;
}