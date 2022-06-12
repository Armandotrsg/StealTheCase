#ifndef HITMAN_H
#define HITMAN_H

#include "Character.h"
#include "Room.h"
#include "Item.h"
#include <vector>

class Hitman: public Character{

    private:
        vector<Item*> inventory; //Heredado a protagonista únicamente
        bool detected;
        bool backPack;
        Room* location;
    
    public:
        Hitman();
        Hitman(string,Clothes*,Room*); //Sin items al inicio
        int getItemIndex(Item*);
        Item* seekItem(string);
        Item* getItemType(string);

        void addItem(Item*);
        bool hasBackPack();
        bool move(string); //Devuelve si sí puede caminar y se mueve
        void viewInventory();
        void dropItem(string);

        Room* getLocation();
        void setLocation(Room*);
        
        int getInventorySpaceUsed(); //Suma el peso de todos los items

        void changeClothes(Clothes*);
};

#endif