#include "NPC.h"
#include "Traveller.h" 
#include <iostream>

void MerchantNPC::interact(Traveller* context) {
    if (!context) return; 

    std::cout << "[Desert] A wandering Merchant offers to trade!" << std::endl;
    std::cout << "         'I'll buy your map data for R150!'" << std::endl;
    
    context->setMoney(context->getMoney() + 150.0);
    std::cout << "[System] Money increased to R" << context->getMoney() << "." << std::endl;
}

void MermaidNPC::interact(Traveller* context) {
    if (!context) return; 

    std::cout << "[Ocean] A Mermaid sings a soothing melody." << std::endl;
    std::cout << "        Your exhaustion fades away!" << std::endl;
    
   
    context->setStamina(100);
    std::cout << "[System] Stamina restored to " << context->getStamina() << "." << std::endl;
}

void WoodsmanNPC::interact(Traveller* context) {
    if (!context) return;

    std::cout << "[Forest] A friendly Woodsman waves at you." << std::endl;
    std::cout << "         'Here, take this spare fuel for your journey!'" << std::endl;
    
    context->setFuel(context->getFuel() + 40);
    std::cout << "[System] Fuel increased to " << context->getFuel() << "." << std::endl;
}