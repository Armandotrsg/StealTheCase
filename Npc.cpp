#include "Npc.h"

Npc::Npc(){
    this->distracted = false;
    this->neutralized = false;
}

Npc::Npc(string nombre, Clothes* ropa, Item* objeto, bool distracted, bool neutralized): Character(nombre, ropa){
    this->dropItem = objeto;
    this->distracted = distracted;
    this->neutralized = neutralized;
}

Item* Npc::getDropItem(){
    return this->dropItem;
}

bool Npc::getDistracted(){
    return this->distracted;
}

bool Npc::getNeutralized(){
    return this->neutralized;
}

Item* Npc::setDropItem(Item* objeto){
    this->dropItem = objeto;
}

bool Npc::setDistracted(bool distracted){
    this->distracted = distracted;
}

bool Npc::setNeutralized(bool neutralized){
    this->neutralized = neutralized;
}