#ifndef TERRAIN_H
#define TERRAIN_H

#include <string>

class Terrain {
protected:
    std::string name;

public:
    explicit Terrain(const std::string& terrainName) : name(terrainName) {}
    virtual ~Terrain() = default;

    Terrain(const Terrain&) = delete;
    Terrain& operator=(const Terrain&) = delete;

    virtual int getMovementCost() const = 0;
    virtual std::string getName() const { return name; }
};

class SandTerrain : public Terrain {
public:
    SandTerrain();
    int getMovementCost() const override;
};

class WaterTerrain : public Terrain {
public:
    WaterTerrain();
    int getMovementCost() const override;
};

class GrassTerrain : public Terrain {
public:
    GrassTerrain();
    int getMovementCost() const override;
};

#endif 