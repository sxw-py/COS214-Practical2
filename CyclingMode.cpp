#include "CyclingMode.h"
#include "WalkingMode.h" 
#include "Traveller.h"
#include "Terrain.h"
#include <iostream>

void CyclingMode::move(Traveller* context, int distance, Terrain* currentTerrain) {
    if (!context || !currentTerrain) return;

int baseCost = 1;
    int terrainCost = currentTerrain->getMovementCost();
    int totalStaminaDrain = distance * baseCost * terrainCost;

    std::cout << "[Action] Cycling " << distance << " km through " << currentTerrain->getName() << "." << std::endl;
    std::cout << "         (Stamina Cost: " << totalStaminaDrain << ")" << std::endl;
    
    context->setStamina(context->getStamina() - totalStaminaDrain);

    // Guarded transition
    if (context->getStamina() <= 0) {
        std::cout << "[Transition] Completely exhausted! Falling off the bike and walking." << std::endl;
        context->setMode(new WalkingMode());
    }
}

std::string CyclingMode::getModeName() const {
    return "Cycling";
}