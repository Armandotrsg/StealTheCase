#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <vector>
#include "Clothes.h"
#include "Item.h"
#include "Character.h"

using namespace std;

class Room{
    private:
        string description;
        Clothes accessClothes;
        vector<Item*> items;
        bool needsKey;
        vector<Character*> people;
        Room* exits[4];

    public:
        Room();
        Room(string,Clothes*,Item*,Character*);
        string getDescription() const;
        void setDescription(string);
        Clothes* getAccesClothes();
        void setAccessClothes(Clothes*);
        bool hasKey();
        int getNumberOfCharacter();
        Character* getCharacter(Character*);
        
        

};


#endif