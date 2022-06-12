#ifndef ROOM_H
#define ROOM_H

#include "Character.h"
#include "Clothes.h"
#include "Item.h"

#include <vector>

using namespace std;

class Room{
    private:
        string name;
        string description;
        vector<Clothes*> accessClothes;
        vector<Item*> items;
        vector<Character*> people;
        vector<Room*> exits;
        bool key;
        bool tool;

    public:
        Room();
        Room(string,string,vector<Clothes*>,vector<Item*>,vector<Character*>,vector<Room*>,bool,bool);
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
        void removeItem(Item*);

        string getName();
        void setName(string);

        bool needsKey();
        bool needsTool();
        

};


#endif