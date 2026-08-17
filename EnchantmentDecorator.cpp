#include "EnchantmentDecorator.h"

EnchantmentDecorator::EnchantmentDecorator(Place* p, std::string effect) : PlaceDecorator(p), effectName(effect) {}

void EnchantmentDecorator::print() {
    std::cout << "[Enchantment] Active Effect: " << this->effectName << std::endl;
    PlaceDecorator::print();
}

void EnchantmentDecorator::traverse() {
    std::cout << "[Enchantment] Traversing with active effect: " << this->effectName << std::endl;
    PlaceDecorator::traverse();
}

EnchantmentDecorator::~EnchantmentDecorator(){
   
}