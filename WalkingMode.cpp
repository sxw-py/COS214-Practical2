#include "WalkingMode.h"
#include "CyclingMode.h" 
#include "DrivingMode.h"
#include "Traveller.h"
#include "Terrain.h"
#include <iostream>

void WalkingMode::move(Traveller* context, int distance, Terrain* currentTerrain) {
    if (!context || !currentTerrain) return; 

// Already dead tired
    if (context->getStamina() <= 0) {
        std::cout << "[Exhausted] You have 0 stamina. You collapse and cannot walk any further!" << std::endl;
        if (context->getMoney() >= 50.0) {
            std::cout << "[Rescue] You paid R50 for an emergency taxi!" << std::endl;
            context->setMoney(context->getMoney() - 50.0);
            context->setFuel(20); 
            context->setMode(new DrivingMode());
        } else {
            std::cout << "[Game Over] You are stranded with no money and no stamina." << std::endl;
        }
        return; 
    }

   
    int baseCost = 5;
    int terrainCost = currentTerrain->getMovementCost();
    int totalStaminaDrain = distance * baseCost * terrainCost;

    std::cout << "[Action] Walking " << distance << " km through " << currentTerrain->getName() << "." << std::endl;
    std::cout << "         (Stamina Cost: " << totalStaminaDrain << ")" << std::endl;
    
    context->setStamina(context->getStamina() - totalStaminaDrain);  

    /// If we have a lot of money, skip the bike and buy a car!
    if (context->getMoney() >= 500.0) {
        std::cout << "[Transition] You are wealthy enough! Spending R500 to buy a car." << std::endl;
        context->setMoney(context->getMoney() - 500.0);
        
        //Start off with a full tank 
        context->setFuel(100); 
        context->setMode(new DrivingMode());
    }
    // If we don't have car money, but we are tired and have bike money...
    else if (context->getStamina() < 20 && context->getMoney() >= 100.0) {
        std::cout << "[Transition] Too tired to walk! Spending R100 to buy a bicycle." << std::endl;
        context->setMoney(context->getMoney() - 100.0);
        
        context->setMode(new CyclingMode());
    }
}

std::string WalkingMode::getModeName() const {
    return "Walking";
}