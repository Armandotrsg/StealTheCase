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
        bool key;
        bool tool;
        vector<Room*> exits;

    public:
        Room();
        Room(string,string,bool,bool);
        string getDescription();
        void setDescription(string);
        vector<Clothes*> getAccesClothes();
        void addAccessClothes(Clothes*);
        void addNpc(Npc*);
        
        int getNumberOfCharacters();
        vector<Npc*> getAllCharacters();
        Npc* getNpc(string);
        int getNpcIndex(Npc*);
        bool removeCharacter(string);
        vector<Npc*> getOtherCharactersInRoom(Npc*);

        Room* getExit(string);
        vector<Room*> getAllExits();
        void addExit(Room*);

        
        Item* getItem(string); //solo para inicializar
        void setItem(Item*);
        void removeItem(Item*);

        string getName();
        void setName(string);

        bool needsKey();
        bool needsTool();

        bool setKey(bool);
        bool setTool(bool);
        
        friend ostream& operator << (ostream&,Room&);

};


#endif