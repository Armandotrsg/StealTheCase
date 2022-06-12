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

Room::Room(string name,string description,vector<Clothes*> accessClothes,vector<Item*> items, vector<Npc*> people,bool key,bool tool){
    setDescription(description);
    setAccessClothes(accessClothes);
    setItem(items);
    setPeople(people);
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

void Room::setPeople(vector<Npc*> people){
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

void Room::setExits(vector<Room*> exits){
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
            this->items.erase(this->items.begin()+i);
        }
    }
}

bool Room::needsKey(){
    return this->key;
}

bool Room::needsTool(){
    return this->tool;
}

Npc* Room::getNpc(string name){
    for (int i = 0; i < this->people.size(); i++){
        if(this->people[i]->getName() == name){
            return this->people[i];
        }
    }
    return nullptr;
}

int Room::getNpcIndex(Npc* npc){
    
    for (int i = 0; i < this->people.size(); i++){
        if(this->people[i] == npc){
            return i;
        }
        
    }
    return -1;
}

int Room::getNumberOfCharacters(){
    int suma = 0;
    for (int i = 0; i< this->people.size(); i++){
        if (this->people[i]->getName() != "" || this->people[i] != nullptr){
            suma += 1;
        }
    }
    return suma;
}

bool Room::removeCharacter(string neutralized){
    bool detected = false;
    Npc* killed = getNpc(neutralized);
    if (killed != nullptr){
        if (getNumberOfCharacters() > 1){
            int numDistracted = 0;
            vector<Npc*> otherNpc = getOtherCharactersInRoom(killed);
            for (auto& other : otherNpc){
                if(other->getDistracted()){
                    numDistracted++;
                }
            }
            if (numDistracted <= otherNpc.size()){
                detected = true;
            } else {
                addItem(killed->getDropItem());
                Clothes* nuevaRopa = killed->getDisguise();
                addItem(nuevaRopa); //Checar si hay error porque el método pide un item, no ropa
                int index = getNpcIndex(killed);
                this->people.erase(this->people.begin()+index);
            }
        } else{
            addItem(killed->getDropItem());
            Clothes* nuevaRopa = killed->getDisguise();
            addItem(nuevaRopa);
            int index = getNpcIndex(killed);
            this->people.erase(this->people.begin()+index);
        }
        
    } else {
        cout << "No hay ningún personaje con este nombre en el cuarto\n";
    }
    
    return detected;
}

vector<Npc*> Room::getOtherCharactersInRoom(Npc* actual){
    vector<Npc*> other;
    for (auto &npc : this->people){
        if (npc != actual){
            other.push_back(npc);
        }
    }
    return other;
}