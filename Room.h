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
        vector<Clothes*> accessClothes; //Ropa con la que puedes acceder al cuarto sin ser detectado
        vector<Item*> items; //Items en el cuarto
        vector<Npc*> people; //Npc's en el cuarto
        bool key; //Si el cuarto necesita llave
        bool tool; //Si el cuarto necesita herramienta
        vector<Room*> exits; //Salidas del cuarto

    public:
        Room();
        Room(string,string,bool,bool);
        string getDescription();
        void setDescription(string);
        vector<Clothes*> getAccesClothes();
        void addAccessClothes(Clothes*);
        void addNpc(Npc*);
        
        int getNumberOfCharacters(); //Número de personajes en el cuarto
        vector<Npc*> getAllCharacters();
        Npc* getNpc(string);
        int getNpcIndex(Npc*); //Regresa el índice en el vector del Npc
        bool removeCharacter(string); //Quita el personaje ingresado or nombre del cuarto
        vector<Npc*> getOtherCharactersInRoom(Npc*);

        Room* getExit(string);
        vector<Room*> getAllExits();
        void addExit(Room*);

        
        Item* getItem(string); 
        void setItem(Item*);
        void removeItem(Item*);

        string getName();
        void setName(string);

        bool needsKey();
        bool needsTool();

        void setKey(bool);
        void setTool(bool);
        
        friend ostream& operator << (ostream&,Room&);

};


#endif