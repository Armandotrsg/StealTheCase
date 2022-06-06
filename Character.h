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
        Room* location;
        Clothes* disguise;
        
    public:
        Character();
        Character(string,Room*,Clothes*);
        string getName();
        void setName(string);
        Room* getLocation();
        void setLocation(Room*);
        Clothes* getDisguise() const;
        void setDisguise(Clothes*);

};


#endif