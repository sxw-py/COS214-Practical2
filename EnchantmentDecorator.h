#ifndef ENCHANTMENTDECORATOR_H
#define ENCHANTMENTDECORATOR_H
#include "PlaceDecorator.h"
#include <iostream>


class EnchantmentDecorator : public PlaceDecorator{
    private:
        std::string effectName;
    public:
        EnchantmentDecorator(Place* p, std::string effect);
        void print() override;
        void traverse() override;
        virtual ~EnchantmentDecorator();
    
};

#endif