#ifndef BIOME_FACTORY_H
#define BIOME_FACTORY_H


class Terrain;
class NPC;
class Obstacle;


class BiomeFactory {
public:
    virtual ~BiomeFactory() = default;
    BiomeFactory() = default;
   
    BiomeFactory(const BiomeFactory&) = delete;
    BiomeFactory& operator=(const BiomeFactory&) = delete;

    virtual Terrain* createTerrain() = 0;
    virtual NPC* createNPC() = 0;
    virtual Obstacle* createObstacle() = 0;
};


class DesertFactory : public BiomeFactory {
public:
    DesertFactory() = default;
    Terrain* createTerrain() override;
    NPC* createNPC() override;
    Obstacle* createObstacle() override;
};

class OceanFactory : public BiomeFactory {
public:
    OceanFactory() = default;
    Terrain* createTerrain() override;
    NPC* createNPC() override;
    Obstacle* createObstacle() override;
};

class ForestFactory : public BiomeFactory {
public:
    ForestFactory() = default;
    Terrain* createTerrain() override;
    NPC* createNPC() override;
    Obstacle* createObstacle() override;
};

#endif 