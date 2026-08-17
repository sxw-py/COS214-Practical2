#include "DrivingMode.h"
#include "WalkingMode.h" 
#include "Traveller.h"
#include "Terrain.h"
#include <iostream>

void DrivingMode::move(Traveller* context, int distance, Terrain* currentTerrain) {
    if (!context || !currentTerrain) return;

int baseFuelCost = 2;
    int terrainCost = currentTerrain->getMovementCost();
    int totalFuelDrain = distance * baseFuelCost * terrainCost;

    std::cout << "[Action] Driving " << distance << " km through " << currentTerrain->getName() << "." << std::endl;
    std::cout << "         (Fuel Cost: " << totalFuelDrain << ")" << std::endl;
    
    context->setFuel(context->getFuel() - totalFuelDrain);

    // Guarded transition
    if (context->getFuel() <= 0) {
        std::cout << "[Transition] Out of gas! Abandoning the vehicle and walking." << std::endl;
        context->setMode(new WalkingMode());
    }
}

std::string DrivingMode::getModeName() const {
    return "Driving";
}