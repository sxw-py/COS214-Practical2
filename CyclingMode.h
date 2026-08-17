#ifndef CYCLING_MODE_H
#define CYCLING_MODE_H

#include "TravelMode.h"

class CyclingMode : public TravelMode {
public:
    CyclingMode() = default;
    ~CyclingMode() override = default;

    void move(Traveller* context, int distance, Terrain* currentTerrain) override;
    std::string getModeName() const override;
};

#endif // CYCLING_MODE_H