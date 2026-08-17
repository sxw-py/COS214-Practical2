#include "Terrain.h"

SandTerrain::SandTerrain() : Terrain("Sand Dunes") {}

int SandTerrain::getMovementCost() const {
    return 3; //movement cost/km
}


WaterTerrain::WaterTerrain() : Terrain("Deep Ocean") {}

int WaterTerrain::getMovementCost() const {
    return 5; 
}

GrassTerrain::GrassTerrain() : Terrain("Amazon Forest") {}

int GrassTerrain::getMovementCost() const {
    return 1; 
}