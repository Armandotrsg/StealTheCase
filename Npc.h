#ifndef NPC_H
#define NPC_H

#include "Character.h"


class Npc: public Character{ //Clase derivada de Character
    private:
        Item* dropItem; //Estos personajes tienen un solo item
        bool distracted; //Pueden distraerse
        

    public:
        Npc();
        Npc(string, Clothes*, Item*);

        Item* getDropItem();
        bool getDistracted();
        

        void setDropItem(Item*);
        void setDistracted(bool);
        



};

#endif