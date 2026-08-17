#include "BiomeFactory.h"
#include "NPC.h"
#include "Obstacle.h"
#include "Terrain.h"



Terrain* DesertFactory::createTerrain() {
    return new SandTerrain();
}

NPC* DesertFactory::createNPC() {
    return new MerchantNPC();
}

Obstacle* DesertFactory::createObstacle() {
    return new CactusObstacle();
}


Terrain* OceanFactory::createTerrain() {
    return new WaterTerrain(); 
}

NPC* OceanFactory::createNPC() {
    return new MermaidNPC();
}

Obstacle* OceanFactory::createObstacle() {
    return new WhirlpoolObstacle();
}


Terrain* ForestFactory::createTerrain() {
    return new GrassTerrain();
}

NPC* ForestFactory::createNPC() {
    return new WoodsmanNPC();
}

Obstacle* ForestFactory::createObstacle() {
    return new ThicketObstacle();
}