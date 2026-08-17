#ifndef REGION_H
#define REGION_H

#include "Place.h"
#include <vector>

class Region : public Place {
private:
    std::vector<Place*> children;

public:
    explicit Region(const std::string& placeName);
    
    // Custom destructor for leak-free map cleanup
    ~Region() override; 

    void traverse() override; 

   
    // Only the Region has the physical ability to manage children
    void add(Place* child);
    void remove(Place* child);
};

#endif 