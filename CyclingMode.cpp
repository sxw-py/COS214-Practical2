#include "CyclingMode.h"
#include "WalkingMode.h" 
#include "Traveller.h"
#include <iostream>

void CyclingMode::move(Traveller* context, int distance) {
    if (!context) return;

    std::cout << "[Action] Cycling for " << distance << " km." << std::endl;
    
    // Cycling is highly efficient, only 1 stamina per km
    context->setStamina(context->getStamina() - (distance * 1));

    // If we are completely exhausted, we must get off and walk
    if (context->getStamina() <= 0) {
        std::cout << "[Transition] Completely exhausted! Falling off the bike and walking." << std::endl;
        context->setMode(new WalkingMode());
    }
}

std::string CyclingMode::getModeName() const {
    return "Cycling";
}