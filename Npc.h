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
        Npc(string, Clothes*, Item*);

        Item* getDropItem();
        bool getDistracted();
        bool getNeutralized();

        void setDropItem(Item*);
        void setDistracted(bool);
        void setNeutralized(bool);



};

#endif