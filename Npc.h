#ifndef NPC_H
#define NPC_H

#include "Character.h"


class Npc: public Character{
    private:
        Item* dropItem;
        bool distracted;
        bool neutralized;

    public:
        Npc();
        Npc(string, Clothes*, Item*, bool, bool);

        Item* getDropItem();
        bool getDistracted();
        bool getNeutralized();

        Item* setDropItem(Item*);
        bool setDistracted(bool);
        bool setNeutralized(bool);



};

#endif