#ifndef ROOM_H
#define ROOM_H

#include "Npc.h"
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
        vector<Npc*> people;
        vector<Room*> exits;
        bool key;
        bool tool;

    public:
        Room();
        Room(string,string,vector<Clothes*>,vector<Item*>,vector<Npc*>,bool,bool);
        string getDescription() const;
        void setDescription(string);
        vector<Clothes*> getAccesClothes();
        void setAccessClothes(vector<Clothes*>);
        
        int getNumberOfCharacters();
        Npc* getNpc(string);
        int getNpcIndex(Npc*);
        bool removeCharacter(string);
        vector<Npc*> getOtherCharactersInRoom(Npc*);

        Room* getExit(string);
        void setExits(vector<Room*>);

        Item* getItem(string);
        void addItem(Item*);
        void setItem(vector<Item*>);
        void setPeople(vector<Npc*>);
        void removeItem(Item*);

        string getName();
        void setName(string);

        bool needsKey();
        bool needsTool();
        

};


#endif