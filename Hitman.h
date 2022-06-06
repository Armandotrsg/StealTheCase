#ifndef HITMAN_H
#define HITMAN_H

#include "Character.h"
#include "Item.h"

class Hitman: public Character{

    private:
        vector<Item*> inventory; //Heredado a protagonista únicamente
        bool detected;
        bool backPack;
    
    public:
        Hitman();
        Hitman(string,Room*,Clothes*); //Sin items al inicio
        Item* getItem(int);
        Item* seekItem(string);
        void addItem(Item*);
        bool hasBackPack();
        bool move(string); //Devuelve si sí puede caminar y se mueve
        void printAllItems();
        Item* dropItem(string);

};

#endif