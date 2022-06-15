#include "Room.h"

Room::Room(){
    this->description = "";
    this->name = "";
    this->key = false;
    this->tool = false;
}

Room::Room(string name,string description,bool key,bool tool){
    this->description = description;
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

string Room::getDescription(){
    string fullDescription = this->name;
    fullDescription = fullDescription + ":\n" + this->description;
    fullDescription = fullDescription + "\nPersonajes en el cuarto: ";
    for (int i = 0; i < this->people.size(); i++){
        fullDescription = fullDescription + "\n- " + this->people[i]->getName();
    }
    fullDescription = fullDescription + "\nItems en el cuarto: ";
    for (int i = 0; i < this->items.size(); i++){
        if (this->items[i]->getName() != ""){
            fullDescription = fullDescription + "\n- " + this->items[i]->getName();
        }
    }
    fullDescription += "\n";
    return fullDescription;
}

void Room::setDescription(string description){
    this->description = description;
}

vector<Clothes*> Room::getAccesClothes(){
    return this->accessClothes;
}

void Room::addAccessClothes(Clothes* access){
    this->accessClothes.push_back(access);
}

void Room::setItem(Item* item){
    this->items.push_back(item);
}

void Room::addNpc(Npc* npc){
    this->people.push_back(npc);
}

Room* Room::getExit(string roomName){
    for (int i = 0; i < this->exits.size(); i++){
        if (this->exits[i]->getName() == roomName){
            return this->exits[i];
        }
    }
    cout << "No hay ningún cuarto en esta salida con este nombre\n";
    
    return nullptr;
}

vector<Room*> Room::getAllExits(){
    return this->exits;
}

void Room::addExit(Room* exit){
    this->exits.push_back(exit);
}

//Allright here

Item* Room::getItem(string itemName){
    for (auto &item : this->items){
        if (item->getName() == itemName){
            return item;
        }
    }
    cout << "No hay ningún item que tenga este nombre en el cuarto" << endl;
    return nullptr;
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

vector<Npc*> Room::getAllCharacters(){
    return this->people;
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
            if (numDistracted < otherNpc.size()){
                detected = true;
                cout << "Has sido detectado, hay más de un personaje en el cuarto.\nTienes que distraer a los otros personajes";
            } else {
                if(killed->getDropItem()->getName() != ""){
                    setItem(killed->getDropItem());
                }
                Item* nuevaRopa = killed->getDisguise();
                setItem(nuevaRopa); //Checar si hay error porque el método pide un item, no ropa
                int index = getNpcIndex(killed);
                this->people.erase(this->people.begin()+index);
            }
        } else{
            if(killed->getDropItem()->getName() != ""){
                    setItem(killed->getDropItem());
                }
            Item* nuevaRopa = killed->getDisguise();
            setItem(nuevaRopa);
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
