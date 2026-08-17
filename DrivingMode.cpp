#include "DrivingMode.h"
#include "WalkingMode.h" 
#include "Traveller.h"
#include <iostream>

void DrivingMode::move(Traveller* context, int distance) {
    if (!context) return;

    std::cout << "[Action] Driving for " << distance << " km." << std::endl;
    
    // Driving costs 2 fuel per km, but 0 stamina
    context->setFuel(context->getFuel() - (distance * 2));

    // Must walk if out of fuel
    if (context->getFuel() <= 0) {
        std::cout << "[Transition] Out of gas! Abandoning the vehicle and walking." << std::endl;
        context->setMode(new WalkingMode());
    }
}

std::string DrivingMode::getModeName() const {
    return "Driving";
}