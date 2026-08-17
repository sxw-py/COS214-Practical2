#include "Traveller.h"
#include "TravelMode.h" 
#include <iostream>

// Constructor takes ownership of the dynamically allocated initial mode
Traveller::Traveller(TravelMode* initialMode) 
    : currentMode(initialMode), stamina(100), fuel(50), money(200.0) {
    
    // If someone tries to create a Traveller with a null state, we catch it.
    if (this->currentMode == nullptr) {
        std::cerr << "[Warning] Traveller created with a null state!" << std::endl;
    }
}


Traveller::~Traveller() {
    delete this->currentMode;
    this->currentMode = nullptr; 
}

void Traveller::setMode(TravelMode* newMode) {
   
    if (newMode == nullptr || this->currentMode == newMode) {
        return; 
    }

    TravelMode* oldMode = this->currentMode;
    this->currentMode = newMode;
    delete oldMode; 
}

void Traveller::move(int distance) {
    if (this->currentMode) {
        this->currentMode->move(this, distance);
    }
}

//Getters and Setters for resources
int Traveller::getStamina() const {
     return stamina; 

    }
void Traveller::setStamina(int amount) {
     stamina = amount; 
}

int Traveller::getFuel() const {
     return fuel;
 }


void Traveller::setFuel(int amount) {
     fuel = amount; 
}

double Traveller::getMoney() const {
     return money; 
}
void Traveller::setMoney(double amount) { 
     money = amount; 
}