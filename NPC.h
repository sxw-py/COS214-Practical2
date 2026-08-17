#ifndef NPC_H
#define NPC_H


class Traveller; 


class NPC {
public:
    NPC() = default;
    virtual ~NPC() = default;
    NPC(const NPC&) = delete;
    NPC& operator=(const NPC&) = delete;

    // The interact method uses the Traveller to manipulate stamina/money
    virtual void interact(Traveller* context) = 0;
};


class MerchantNPC : public NPC {
public:
    MerchantNPC() = default;
    void interact(Traveller* context) override;
};

class MermaidNPC : public NPC {
public:
    MermaidNPC() = default;
    void interact(Traveller* context) override;
};

class WoodsmanNPC : public NPC {
public:
    WoodsmanNPC() = default;
    void interact(Traveller* context) override;
};

#endif