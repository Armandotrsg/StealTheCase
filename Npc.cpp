#include "Npc.h"

Npc::Npc(){
    this->distracted = false;
    this->neutralized = false;
}

Npc::Npc(string nombre, Clothes* ropa, Item* objeto): Character(nombre, ropa){
    this->dropItem = objeto;
    this->distracted = false;
    this->neutralized = false;
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

void Npc::setDropItem(Item* objeto){
    this->dropItem = objeto;
}

void Npc::setDistracted(bool distracted){
    this->distracted = distracted;
}

void Npc::setNeutralized(bool neutralized){
    this->neutralized = neutralized;
}