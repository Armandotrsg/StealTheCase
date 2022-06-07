#ifndef ROOM_H
#define ROOM_H


#include "Clothes.h"
#include "Item.h"
#include "Character.h"

using namespace std;

class Room{
    private:
        string description;
        vector<Clothes*> accessClothes;
        vector<Item*> items;
        vector<Character*> people;
        vector<Room*> exits;

    public:
        Room();
        Room(string,vector<Clothes*>,vector<Item*>,vector<Character*>,vector<Room*>);
        string getDescription() const;
        void setDescription(string);
        vector<Clothes*> getAccesClothes();
        void setAccessClothes(vector<Clothes*>);
        
        int getNumberOfCharacter();
        Character* getCharacter(Character*);
        Room* getExit(string);
        void setExit(vector<Room*>);

        Item* getItem(string);
        void addItem(Item*);
        void setItem(vector<Item*>);
        void setPeople(vector<Character*>);
        

};


#endif