#ifndef PLACE_H
#define PLACE_H

#include <string>

class Place {
protected:
    std::string name;

public:
    explicit Place(const std::string& placeName) : name(placeName) {}
    virtual ~Place() = default; 

    // Prevent slicing and double-frees
    Place(const Place&) = delete;
    Place& operator=(const Place&) = delete;

    std::string getName() const { return name; }
    
    virtual void traverse() = 0; 
};

#endif 