#ifndef WALKING_MODE_H
#define WALKING_MODE_H

#include "TravelMode.h"

class WalkingMode : public TravelMode {
public:
    WalkingMode() = default;
    ~WalkingMode() override = default;

    void move(Traveller* context, int distance) override;
    std::string getModeName() const override;
};

#endif // WALKING_MODE_H