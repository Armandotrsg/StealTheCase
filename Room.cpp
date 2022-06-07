#include "Room.h"

Room::Room(){
    this->description = "";
    this->accessClothes[0] = nullptr;
    this->accessClothes[1] = nullptr;
    for (int i = 0; i < 4; i++){
        this->exits[i] = nullptr;
    }
}

Room::Room(string description,vector<Clothes*> accessClothes,vector<Item*> items, vector<Character*> people,vector<Room*> exits){
    setDescription(description);
    setAccessClothes(accessClothes);
    setItem(items);
    setPeople(people);
    setExit(exits);
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

void Room::setExit(vector<Room*>){
    for (int i = 0; i < 4; i++){
        this->exits.push_back(exits[i]);
    }
}

Item* getItem(string itemName){
    for (auto &item : this->items){
        if (item->getDescription() == itemName){
            return item;
        }
    }
    cout << "No hay ningún item que tenga este nombre en el cuarto" << endl;
    return nullptr;
}

void Room::addItem(Item* newItem){
    this->items.push_back(newItem);
}




