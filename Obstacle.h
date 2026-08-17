#ifndef OBSTACLE_H
#define OBSTACLE_H


class Traveller; 

class Obstacle {
public:
    virtual ~Obstacle() = default;
    Obstacle() = default;
    
    Obstacle(const Obstacle&) = delete;
    Obstacle& operator=(const Obstacle&) = delete;

    virtual bool overcome(Traveller* context) = 0;
};


class CactusObstacle : public Obstacle {
public:
    CactusObstacle() = default;
    bool overcome(Traveller* context) override;
};

class WhirlpoolObstacle : public Obstacle {
public:
    WhirlpoolObstacle() = default;
    bool overcome(Traveller* context) override;
};

class ThicketObstacle : public Obstacle {
public:
    ThicketObstacle() = default;
    bool overcome(Traveller* context) override;
};

#endif 