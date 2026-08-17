#ifndef DRIVING_MODE_H
#define DRIVING_MODE_H

#include "TravelMode.h"

class DrivingMode : public TravelMode {
public:
    DrivingMode() = default;
    ~DrivingMode() override = default;

    void move(Traveller* context, int distance, Terrain* currentTerrain) override;
    std::string getModeName() const override;
};

#endif // DRIVING_MODE_H