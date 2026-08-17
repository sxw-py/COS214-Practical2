#include "Obstacle.h"
#include "Traveller.h"
#include <iostream>

bool CactusObstacle::overcome(Traveller* context) {
    if (!context) return false;

    std::cout << "[Desert] A dense patch of spiky cacti blocks the path!" << std::endl;
    
    if (context->getStamina() >= 15) {
        std::cout << "         You carefully navigate through the spikes." << std::endl;
        context->setStamina(context->getStamina() - 15);
        return true;
    } else {
        std::cout << "         You are too tired to navigate the spikes safely. Path blocked!" << std::endl;
        return false;
    }
}

bool WhirlpoolObstacle::overcome(Traveller* context) {
    if (!context) return false;

    std::cout << "[Ocean] A massive whirlpool pulls at you!" << std::endl;
    
    
    if (context->getFuel() >= 30) {
        std::cout << "         You hit the throttle and burn 30 fuel to escape the vortex!" << std::endl;
        context->setFuel(context->getFuel() - 30);
        return true;
    } else {
        std::cout << "         Not enough fuel to escape the current! Path blocked!" << std::endl;
        return false;
    }
}

bool ThicketObstacle::overcome(Traveller* context) {
    if (!context) return false;

    std::cout << "[Forest] A massive fallen tree and dense thicket are in the way." << std::endl;
    
    
    if (context->getMoney() >= 20.0) {
        std::cout << "         You pay a local $20 to help clear the thicket." << std::endl;
        context->setMoney(context->getMoney() - 20.0);
        return true;
    } else if (context->getStamina() >= 25) {
        std::cout << "         You spend hours chopping wood, losing 25 stamina." << std::endl;
        context->setStamina(context->getStamina() - 25);
        return true;
    }
    
    std::cout << "         You lack the money and energy to clear the path. Path blocked!" << std::endl;
    return false;
}