#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <vector>

#include "Room.h"
#include "Item.h"
#include "Clothes.h"

using namespace std;

class Character{
    private:
        string name;
        Clothes* disguise;
        
    public:
        Character();
        Character(string,Clothes*);
        string getName();
        void setName(string);
        Clothes* getDisguise() const;
};


#endif