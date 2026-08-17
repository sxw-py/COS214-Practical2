#include "WalkingMode.h"
#include "CyclingMode.h" 
#include "DrivingMode.h"
#include "Traveller.h"
#include <iostream>

void WalkingMode::move(Traveller* context, int distance) {
    if (!context) return; 

    std::cout << "[Action] Walking for " << distance << " km." << std::endl;
    
    // Walking costs 5 stamina per km
    context->setStamina(context->getStamina() - (distance * 5));

    //Dead tired (end of the road)
    if (context->getStamina() <= 0) {
        std::cout << "[Exhausted] You have 0 stamina. You collapse and cannot walk any further." << std::endl;
        return;
    }

    /// If we have a lot of money, skip the bike and buy a car!
    if (context->getMoney() >= 500.0) {
        std::cout << "[Transition] You are wealthy enough! Spending $500 to buy a car." << std::endl;
        context->setMoney(context->getMoney() - 500.0);
        
        //Start off with a full tank 
        context->setFuel(100); 
        context->setMode(new DrivingMode());
    }
    // If we don't have car money, but we are tired and have bike money...
    else if (context->getStamina() < 20 && context->getMoney() >= 100.0) {
        std::cout << "[Transition] Too tired to walk! Spending $100 to buy a bicycle." << std::endl;
        context->setMoney(context->getMoney() - 100.0);
        
        context->setMode(new CyclingMode());
    }
}

std::string WalkingMode::getModeName() const {
    return "Walking";
}