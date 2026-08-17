#include "Region.h"
#include <iostream>
#include <algorithm> // Required for std::find

// Pass the string up to the base Place constructor
Region::Region(const std::string& placeName) : Place(placeName) {}


Region::~Region() {
    for (Place* child : children) {
        delete child; 
    }
    children.clear(); 
}

void Region::add(Place* child) {
    if (child == nullptr) {
        std::cerr << "[Warning] Attempted to add a null Place to " << this->getName() << "!" << std::endl;
        return;
    }
    children.push_back(child);
}

void Region::remove(Place* child) {
    if (child == nullptr) return;

    auto it = std::find(children.begin(), children.end(), child);
    if (it != children.end()) {

        children.erase(it);
    }
}


void Region::traverse() {
    std::cout << "\n[Region] Entering " << this->getName() << "..." << std::endl;
    
    for (Place* child : children) {
        
        child->traverse(); 
    }
    
    std::cout << "[Region] Leaving " << this->getName() << ".\n" << std::endl;
}