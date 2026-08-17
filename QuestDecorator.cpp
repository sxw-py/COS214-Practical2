#include "QuestDecorator.h"
#include <iostream>

QuestDecorator::QuestDecorator(Place* p, std::string qName) : PlaceDecorator(p), questName(qName), isCompleted(false) {}

void QuestDecorator::enter() {
    std::cout << "[Quest Log] Entering quest area for: ' " << this->questName << std::endl;
    if (!this->isCompleted){
        std::cout << "[Quest Event] You have objective updates pending here !" << std::endl;
    }
    PlaceDecorator::enter();
}



void QuestDecorator::traverse() {
    std::cout << "[Quest Zone] Traversing quest area: " << this->questName << std::endl;
    PlaceDecorator::traverse();
}

void QuestDecorator::print(){
    std::cout << "[Quest Zone] Quest: " << this->questName << "[" << (isCompleted ? "Completer" : "Active") << "]" << std::endl;
    PlaceDecorator* dec = dynamic_cast<PlaceDecorator*>(this->getComponent());
    if (dec){
        dec->print();
    }
}

QuestDecorator::~QuestDecorator(){
   
}
