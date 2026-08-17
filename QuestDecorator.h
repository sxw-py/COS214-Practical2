#ifndef QUESTDECORATOR_H
#define QUESTDECORATOR_H
#include "PlaceDecorator.h"
#include <iostream>


class QuestDecorator : public PlaceDecorator{
    private:
        std::string questName;
        bool isCompleted;
    public:
        QuestDecorator(Place* p, std::string qName);
        void enter() override;
        void traverse() override;
        void print() override;
        virtual ~QuestDecorator();
    
};

#endif