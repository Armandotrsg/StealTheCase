#include "Room.h"

Room::Room(){
    this->description = "";
    this->accessClothes[0] = nullptr;
    this->accessClothes[1] = nullptr;
    for (int i = 0; i < 4; i++){
        this->exits[i] = nullptr;
    }
    this->name = "";
    this->key = false;
    this->tool = false;
}

Room::Room(string name,string description,vector<Clothes*> accessClothes,vector<Item*> items, vector<Character*> people,vector<Room*> exits,bool key,bool tool){
    setDescription(description);
    setAccessClothes(accessClothes);
    setItem(items);
    setPeople(people);
    setExit(exits);
    this->name = name;
    this->key = key;
    this->tool = tool;
}

string Room::getName(){
    return this->name;
}

void Room::setName(string name){
    this->name = name;
}

string Room::getDescription() const{
    return this->description;
}

void Room::setDescription(string description){
    this->description = description;
}

vector<Clothes*> Room::getAccesClothes(){
    return this->accessClothes;
}

void Room::setAccessClothes(vector<Clothes*> accesClothes){
    for (int i = 0; i < 2; i++){
        this->accessClothes.push_back(accessClothes[i]);
    }
}

void Room::setItem(vector<Item*> item){
    for (int i = 0; i < items.size(); i++){
        this->items.push_back(items[i]);
    }
}

void Room::setPeople(vector<Character*> people){
    for (int i = 0; i < people.size(); i++){
        this->people.push_back(people[i]);
    }
}

Room* Room::getExit(string roomName){
    for (int i = 0; this->exits.size(); i++){
        if (this->exits[i]->getName() == roomName){
            return this->exits[i];
        }
    }
    cout << "No hay ningún cuarto en esta salida con este nombre\n";
    return nullptr;
}

void Room::setExit(vector<Room*>){
    for (int i = 0; i < 4; i++){
        this->exits.push_back(exits[i]);
    }
}

Item* Room::getItem(string itemName){
    for (auto &item : this->items){
        if (item->getName() == itemName){
            return item;
        }
    }
    cout << "No hay ningún item que tenga este nombre en el cuarto" << endl;
    return nullptr;
}

void Room::addItem(Item* newItem){
    this->items.push_back(newItem);
}

void Room::removeItem(Item* dropped){
    for (int i = 0; i < this->items.size(); i++){
        if (this->items[i]->getName() == dropped->getName()){
            Item* random;
            this->items[i] = random;
        }
    }
}

bool Room::needsKey(){
    return this->key;
}

bool Room::needsTool(){
    return this->tool;
}
