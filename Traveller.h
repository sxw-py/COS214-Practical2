#ifndef TRAVELLER_H
#define TRAVELLER_H

// Forward declare the interface, DO NOT include "TravelMode.h" here
class TravelMode; 

class Traveller {
private:
    TravelMode* currentMode;
    int stamina;
    int fuel;
    double money;

public:
    // Constructor requires an initial state to prevent a null starting state
    explicit Traveller(TravelMode* initialMode);

    // Virtual destructor for safe cleanup
    virtual ~Traveller();

    // DEFENSIVE C++11: Prevent copy and assignment to avoid double-freeing 'currentMode'
    Traveller(const Traveller&) = delete;
    Traveller& operator=(const Traveller&) = delete;

    // Core functionality
    void move(int distance);
    void setMode(TravelMode* newMode);

    // Resource Getters and Setters
    int getStamina() const;
    void setStamina(int amount);

    int getFuel() const;
    void setFuel(int amount);

    double getMoney() const;
    void setMoney(double amount);
};

#endif // TRAVELLER_H